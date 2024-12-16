#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Logger {
public:
    void logInfo(const std::string& message) {
        std::cout << "[INFO]: " << message << std::endl;
    }

    void logError(const std::string& message) {
        std::cerr << "[ERROR]: " << message << std::endl;
    }
};

class FileReader {
public:
    explicit FileReader(const std::string& filePath) : filePath_(filePath) {}

    std::vector<std::string> readLines() {
        std::ifstream file(filePath_);
        std::vector<std::string> lines;
        std::string line;

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filePath_);
        }

        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        return lines;
    }

private:
    std::string filePath_;
};

int main() {
    Logger logger;
    try {
        FileReader reader("data.txt");
        auto lines = reader.readLines();

        logger.logInfo("Successfully read " + std::to_string(lines.size()) + " lines from file.");

        // Далі можна виконати обробку рядків...
        for (const auto& line : lines) {
            // Обробка кожного рядка
        }

    }
    catch (const std::exception& ex) {
        logger.logError("Exception: " + std::string(ex.what()));
    }

    return 0;
}
