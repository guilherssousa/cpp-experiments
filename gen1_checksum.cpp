#include <iostream>
#include <iomanip>
#include <cstdint>

#include "read_save_file.h"

int main() {
    std::ifstream save = readSaveFile("./save.sav");

    uint8_t checksum = 0xff;

    for (int i = 0x2598; i <= 0x3521; i++) {
        save.seekg(i);
        char c;
        save.get(c);
        checksum -= (uint8_t)c;
    }

    uint8_t save_checksum;

    save.seekg(0x3523);
    save.get((char&)save_checksum);

    if(checksum == save_checksum) std::cout << "Checksums match!" << std::endl;
    else std::cout << "Checksums do not match!" << std::endl;

    std::cout << "Calculated checksum: 0x" << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << (int)checksum << std::endl;
    std::cout << "Save checksum: 0x" << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << (int)save_checksum << std::endl;

    return 0;
}