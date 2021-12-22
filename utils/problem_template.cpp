#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class App {
    std::string problem_no;

    bool extract_args(std::vector<std::string> &&args) {
        std::string arg;
        if (args.size() == 2) {
            arg = args[1];
        } else if (args.size() == 1) {
            std::cout << "n:" << std::flush;
            std::getline(std::cin, arg);
        } else {
            std::cout << "usage: " << args[0] << " <n>" << std::endl;
            return false;
        }

        int n;
        try {
            n = std::stoi(arg);
        } catch (const std::exception &e) {
            std::cout << "invalid argument n: `" << arg << "` is not a valid int" << std::endl;
            return false;
        }
        if (n <= 0 || n >= 1000) {
            std::cout << "invalid argument n: `" << arg << "` is not a valid problem number" << std::endl;
            return false;
        }

        std::ostringstream oss;
        oss << std::setw(3) << std::setfill('0') << n;
        problem_no = oss.str();
        return true;
    }

    std::ofstream create_file(const std::filesystem::path &path) {
        std::cout << "creating file: " << path << std::endl;
        return std::ofstream(path);
    }

public:
    explicit App(std::vector<std::string> &&args) {
        if (!extract_args(std::move(args))) {
            return;
        }

        std::filesystem::path source_file = __FILE__;
        auto source_root = source_file.parent_path().parent_path();
        auto problem_dir = source_root / "problems" / problem_no;

        auto root_cmake = source_root / "CMakeLists.txt";
        auto target = "add_subdirectory(problems/" + problem_no + "/)";
        std::cout << "checking if \"" << target << "\" is in: " << root_cmake << std::endl;
        {
            std::ifstream fd(root_cmake);
            while (fd) {
                std::string line;
                std::getline(fd, line);
                if (line.find(target) != std::string::npos) {
                    std::cout << "problem already registered" << std::endl;
                    return;
                }
            }
        }

        std::cout << "registering problem to " << root_cmake << std::endl;
        std::ofstream(root_cmake, std::ios::app) << "\n" << target << "\n";

        std::cout << "creating directory: " << problem_dir << std::endl;
        std::filesystem::create_directories(problem_dir);

        create_file(problem_dir / "CMakeLists.txt") << "add_executable(problem" << problem_no
                                                    << " ../../utils/main.cpp ../../utils/main.h solve.cpp)";
        create_file(problem_dir / "readme.md") << "# Problem " << problem_no << "\n## Problem\n\n\n## Solution\n";
        create_file(problem_dir / "solve.cpp")
                << "#include \"../../utils/main.h\"\n"
                   "#include <iostream>\n"
                   "void solve() {\n"
                   "    std::cout << \"not solved\" << std::endl;\n"
                   "}\n";
    }

    ~App() {
    }
};

int main(int _c, char **_v) {
    App app({_v, _v + _c});
}