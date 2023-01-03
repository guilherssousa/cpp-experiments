
// In C++, the #ifndef, #define, and #endif preprocessor directives
// are used to create include guards. Include guards are used to
// prevent a header file from being included more than once in a
// single source file.

#ifndef READ_SAVE_FILE
#define READ_SAVE_FILE

#include <fstream>
#include <iostream>

extern std::ifstream readSaveFile(std::string path) {
    std::ifstream file(path, std::ios::binary);

    if(file.is_open()) {
        return file;
    }

    throw std::logic_error("It is not possible to open the saveFile.");
}

#endif