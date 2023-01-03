
#include "load_save_file.h"
#include "pokemon_struct.h"

const int POKEMON_PARTY_OFFSET_START = 0x2F34;
const int POKEMON_PARTY_OFFSET = 0x2C;
const int SAVE_FILE_SIZE = 0x8000;

int main() {
    const char* save = load_save_file("../save.sav", SAVE_FILE_SIZE);

    for(int i = 0; i < 6; i++) {
        const int start = POKEMON_PARTY_OFFSET_START + (i * POKEMON_PARTY_OFFSET);
        const int end = start + POKEMON_PARTY_OFFSET;
        
        // get a chunk of the save file
        std::vector<uint8_t> chunk;
        for(int j = start; j < end; j++) {
            chunk.push_back(save[j]);
        }

        Gen1Pokemon pokemon = Gen1Pokemon(chunk);

        std::cout << "\n\n\n\n" << std::endl;
        std::cout << "Pokemon " << i << std::endl;
        pokemon.print();
    }

    return 0;
}