#ifndef GEN1_CHECKSUM_H
#define GEN1_CHECKSUM_H

#include <fstream>
#include <cstdint>

extern uint8_t gen1_checksum(std::ifstream gen1_savefile) {
    uint8_t checksum = 0xff;

    for (int i = 0x2598; i <= 0x3521; i++) {
        gen1_savefile.seekg(i);
        char c;
        gen1_savefile.get(c);
        checksum -= (uint8_t)c;
    }

    return checksum;
}

#endif