
// In C++, the #ifndef, #define, and #endif preprocessor directives
// are used to create include guards. Include guards are used to
// prevent a header file from being included more than once in a
// single source file.

#ifndef READ_SAVE_FILE_H
#define READ_SAVE_FILE_H

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

// When the preprocessor processes this file, it checks whether the
// READ_SAVE_FILE macro is defined. If it is not defined, the preprocessor
// defines it and includes the contents of the header file. If the
// READ_SAVE_FILE macro is already defined, the preprocessor skips the
// contents of the header file.

// This is useful when you have multiple source files that include the
// same header file. Without include guards, the header file would be
// included multiple times, which could cause errors or duplicate definitions.
// With include guards, the header file is included only once, even if it is
// included in multiple source files.

// It is a good practice to use include guards in all header files to prevent
// potential problems caused by multiple inclusion. The name of the macro used
// in the include guards should be unique to the header file. It is common to
// use the name of the header file in uppercase, with all periods replaced by
// underscores, as in the example above.