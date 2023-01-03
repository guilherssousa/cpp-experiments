#include <fstream>
#include <iostream>
#include <iomanip>

#include "read_save_file.h"

int main() {
    std::ifstream save = readSaveFile("./save.sav");

    char c;
    int i = 0;
    while (save.get(c)) {
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)(unsigned char)c << " ";
        if (++i % 16 == 0) std::cout << std::endl << "0x" << std::hex << i << "\t";
    }

    save.close();
    
    return 0;
}