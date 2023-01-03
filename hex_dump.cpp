#include <fstream>
#include <iostream>
#include <iomanip>

std::ifstream readSaveFile(std::string path) {
    std::ifstream file(path, std::ios::binary);

    if(file.is_open()) {
        return file;
    }

    throw std::logic_error("It is not possible to open the saveFile.");
}

int main() {
    std::ifstream save = readSaveFile("./save.sav");

    char c;
    int i = 0;
    while (save.get(c)) {
        // add the row prefix


        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)(unsigned char)c << " ";
        if (++i % 16 == 0) std::cout << std::endl << "0x" << std::hex << i << "\t";
    }

    save.close();
    
    return 0;
}