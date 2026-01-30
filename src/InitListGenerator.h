# InitListGenerator.h

// This header file declares a class responsible for generating initialization lists.
// The primary function is to create a well-formed initialization list based on constructor parameters.

#ifndef INIT_LIST_GENERATOR_H
#define INIT_LIST_GENERATOR_H

#include <iostream>
#include <string>
#include <vector>

class InitListGenerator {
public:
    // Constructor that takes various parameters
    InitListGenerator(int a, double b, const std::string& c);

    // Generates the initialization list as a string
    std::string generateInitList();

private:
    // Member variables to hold constructor parameters
    int m_a;
    double m_b;
    std::string m_c;
};

#endif // INIT_LIST_GENERATOR_H