#include <iostream>
#include <string>
#include <vector>

template<typename T>
std::string generateInitializationList(const T& value) {
    return std::to_string(value); // for primitive types
}

std::string generateInitializationList(const std::string& value) {
    return \"\" + value + \"\"; // for string types
}

template<typename T>
std::string generateInitializationList(const T* ptr) {
    return ptr ? \"&\" + std::string(typeid(T).name()) + \"()\" : \"nullptr\"; // for pointer types
}

class CustomClass {
public:
    int field;
    CustomClass(int val) : field(val) {}
};

std::string generateInitializationList(const CustomClass& obj) {
    return \"CustomClass(\" + std::to_string(obj.field) + \" )\"; // for custom classes
}

template<typename T>
std::string generateInitializationList(const std::vector<T>& vec) {
    std::string list = \"{ \";
    for (const auto& item : vec) {
        list += generateInitializationList(item) + \, \";
    }
    list += \" }\";
    return list;
}

int main() {
    int i = 5;
    std::string str = \"test\";
    CustomClass obj(10);
    int* ptr = nullptr;

    std::cout << \"Initialization List for int: \" << generateInitializationList(i) << std::endl;
    std::cout << \"Initialization List for string: \" << generateInitializationList(str) << std::endl;
    std::cout << \"Initialization List for pointer: \" << generateInitializationList(ptr) << std::endl;
    std::cout << \"Initialization List for custom class: \" << generateInitializationList(obj) << std::endl;

    std::vector<int> vec = {1, 2, 3};
    std::cout << \"Initialization List for vector: \" << generateInitializationList(vec) << std::endl;

    return 0;
}