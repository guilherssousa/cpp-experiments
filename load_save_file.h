#ifndef LOAD_SAVE_FILE_H
#define LOAD_SAVE_FILE_H

#include <fstream>
#include <iostream>

std::ifstream::pos_type filesize(const char* filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

extern const char * load_save_file(const char* path, const int& expectedFileSize) {
    FILE* file = fopen(path, "rb");

    char* data = new char[expectedFileSize];

    if(file == NULL) {
        throw std::logic_error("External: It is not possible to open the saveFile.");
    }

    if(expectedFileSize != filesize(path)) throw std::logic_error("External: The saveFile is not the expected size.");

    fread(data, expectedFileSize, 1, file);

    std::fclose(file);

    return data;
}

#endif