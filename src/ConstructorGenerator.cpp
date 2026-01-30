#include <iostream>
#include <string>
#include <vector>

class ConstructorGenerator {
public:
    ConstructorGenerator(const std::string& className, const std::vector<std::pair<std::string, std::string>>& params) 
      : className(className), params(params) {}

    void generate() {
        std::cout << "class " << className << " {\n";
        std::cout << "public:\n";
        std::cout << "    " << className << " (";

        for (size_t i = 0; i < params.size(); ++i) {
            std::cout << params[i].second << " " << params[i].first;
            if (i < params.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ") : ";

        for (size_t i = 0; i < params.size(); ++i) {
            std::cout << params[i].first << "( " << params[i].first << " )";
            if (i < params.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " {}\n";
        std::cout << "};\n";
    }

private:
    std::string className;
    std::vector<std::pair<std::string, std::string>> params;
};

int main() {
    ConstructorGenerator generator("MyClass", { {"intVal", "int"}, {"floatVal", "float"}, {"stringVal", "std::string"} });
    generator.generate();
    return 0;
}