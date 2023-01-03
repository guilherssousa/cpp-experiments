#include <cstdint>
#include <iomanip>

#include "read_save_file.h"

class Pokemon {
    public:
        uint8_t species; // 1 byte long
        uint16_t current_hp; // 2 bytes long
        uint8_t level; // 1 byte long
        uint8_t status_condition; // 1 byte long
        uint8_t type_1; // 1 byte long
        uint8_t type_2; // 1 byte long
        uint8_t catch_rate; // 1 byte long
        uint8_t held_item; // 1 byte long
        uint8_t move_1; // 1 byte long
        uint8_t move_2; // 1 byte long
        uint8_t move_3; // 1 byte long
        uint8_t move_4; // 1 byte long
        uint16_t original_trainer_id; // 2 bytes long
        uint32_t experience_points; // 4 bytes long
        uint16_t hp_ev; // 2 bytes long
        uint16_t attack_ev; // 2 bytes long
        uint16_t defense_ev; // 2 bytes long
        uint16_t speed_ev; // 2 bytes long
        uint16_t special_ev; // 2 bytes long 
        uint16_t iv; // 2 bytes long
        uint8_t move_1_pp; // 1 byte long
        uint8_t move_2_pp; // 1 byte long
        uint8_t move_3_pp; // 1 byte long
        uint8_t move_4_pp; // 1 byte long
        uint8_t level_2; // 1 byte long
        uint16_t max_hp; // 2 bytes long 
        uint16_t attack; // 2 bytes long 
        uint16_t defense; // 2 bytes long
        uint16_t speed; // 2 bytes long
        uint16_t special;  // 2 bytes long
};

const int POKEMON_PARTY_OFFSET_START = 0x2F34;
const uint8_t POKEMON_PARTY_OFFSET = 0x2C;

int main() {
    std::ifstream save = readSaveFile("./save.sav");

    Pokemon pokemon[6];

    for (int i = 0; i < 6; i++) {
        save.seekg(POKEMON_PARTY_OFFSET_START + (i * POKEMON_PARTY_OFFSET));

        // knowing the size of the data type, we can read it directly into the struct
        save.read((char*)&pokemon[i], sizeof(Pokemon));

        
    }

    for (int i = 0; i < 6; i++) {
        Pokemon poke = pokemon[i];

        std::cout << "\n\n\n\n" << std::endl;
        std::cout << "Pokemon " << i << std::endl;
        std::cout << "Species: " << (int)poke.species << std::endl;
        std::cout << "Current HP: " << (int)poke.current_hp << std::endl;
        std::cout << "Level: " << (int)poke.level << std::endl;
        std::cout << "Status Condition: " << (int)poke.status_condition << std::endl;
        std::cout << "Type 1: " << (int)poke.type_1 << std::endl;
        std::cout << "Type 2: " << (int)poke.type_2 << std::endl;
        std::cout << "Catch Rate: " << (int)poke.catch_rate << std::endl;
        std::cout << "Held Item: " << (int)poke.held_item << std::endl;
        std::cout << "Move 1: " << (int)poke.move_1 << std::endl;
        std::cout << "Move 2: " << (int)poke.move_2 << std::endl;
        std::cout << "Move 3: " << (int)poke.move_3 << std::endl;
        std::cout << "Move 4: " << (int)poke.move_4 << std::endl;
        std::cout << "Original Trainer ID: " << (int)poke.original_trainer_id << std::endl;
        std::cout << "Experience Points: " << (int)poke.experience_points << std::endl;
        std::cout << "HP EV: " << (int)poke.hp_ev << std::endl;
        std::cout << "Attack EV: " << (int)poke.attack_ev << std::endl;
        std::cout << "Defense EV: " << (int)poke.defense_ev << std::endl;
        std::cout << "Speed EV: " << (int)poke.speed_ev << std::endl;
        std::cout << "Special EV: " << (int)poke.special_ev << std::endl;
    }
}