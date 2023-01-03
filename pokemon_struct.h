#include <vector>
#include <cstdint>
#include <iostream>

#ifndef GEN1POKEMON_STRUCT_H
#define GEN1POKEMON_STRUCT_H

class Gen1Pokemon {
    public:
        Gen1Pokemon(std::vector<uint8_t> data) {
            if(data.size() != 44) throw std::logic_error("Pokemon: The data is not the expected size.");

            species = data[0];
            current_hp = (data[1] << 8) | data[2];
            level = data[3];
            status_condition = data[4];
            type_1 = data[5];
            type_2 = data[6];
            catch_rate_held_item = data[7];
            move_1 = data[8];
            move_2 = data[9];
            move_3 = data[10];
            move_4 = data[11];
            original_trainer_id = (data[12] << 8) | data[13];
            experience_points = (data[14] << 16) | (data[15] << 8) | data[16];
            hp_ev = (data[17] << 8) | data[18];
            attack_ev = (data[19] << 8) | data[20];
            defense_ev = (data[21] << 8) | data[22];
            speed_ev = (data[23] << 8) | data[24];
            special_ev = (data[25] << 8) | data[26];
            move_1_pp = data[29];
            move_2_pp = data[30];
            move_3_pp = data[31];
            move_4_pp = data[32];
            level_2 = data[33];
            max_hp = (data[34] << 8) | data[35];
            attack = (data[36] << 8) | data[37];
            defense = (data[38] << 8) | data[39];
            speed = (data[40] << 8) | data[41];
            special = (data[42] << 8) | data[43];

            parseIvs(data[27], data[28]);

            return;
        };
        void print() {
            std::cout << "Species: " << (int)species << std::endl;
            std::cout << "Current HP: " << (int)current_hp << std::endl;
            std::cout << "Level: " << (int)level << std::endl;
            std::cout << "Status Condition: " << (int)status_condition << std::endl;
            std::cout << "Type 1: " << (int)type_1 << std::endl;
            std::cout << "Type 2: " << (int)type_2 << std::endl;
            std::cout << "Catch Rate/Held Item: " << (int)catch_rate_held_item << std::endl;
            std::cout << "Move 1: " << (int)move_1 << std::endl;
            std::cout << "Move 2: " << (int)move_2 << std::endl;
            std::cout << "Move 3: " << (int)move_3 << std::endl;
            std::cout << "Move 4: " << (int)move_4 << std::endl;
            std::cout << "Original Trainer ID: " << (int)original_trainer_id << std::endl;
            std::cout << "Experience Points: " << (int)experience_points << std::endl;
            std::cout << "HP EV: " << (int)hp_ev << std::endl;
            std::cout << "Attack EV: " << (int)attack_ev << std::endl;
            std::cout << "Defense EV: " << (int)defense_ev << std::endl;
            std::cout << "Speed EV: " << (int)speed_ev << std::endl;
            std::cout << "Special EV: " << (int)special_ev << std::endl;
            std::cout << "Attack IV: " << (int)attack_iv << std::endl;
            std::cout << "Defense IV: " << (int)defense_iv << std::endl;
            std::cout << "Speed IV: " << (int)speed_iv << std::endl;
            std::cout << "Special IV: " << (int)special_iv << std::endl;
            std::cout << "Move 1 PP: " << (int)move_1_pp << std::endl;
            std::cout << "Move 2 PP: " << (int)move_2_pp << std::endl;
            std::cout << "Move 3 PP: " << (int)move_3_pp << std::endl;
            std::cout << "Move 4 PP: " << (int)move_4_pp << std::endl;
            std::cout << "Level 2: " << (int)level_2 << std::endl;
            std::cout << "Max HP: " << (int)max_hp << std::endl;
            std::cout << "Attack: " << (int)attack << std::endl;
            std::cout << "Defense: " << (int)defense << std::endl;
            std::cout << "Speed: " << (int)speed << std::endl;
            std::cout << "Special: " << (int)special << std::endl;
            return;
        };
        uint8_t species; // 1 byte long
        uint16_t current_hp; // 2 bytes long
        uint8_t level; // 1 byte long
        uint8_t status_condition; // 1 byte long
        uint8_t type_1; // 1 byte long
        uint8_t type_2; // 1 byte long
        uint8_t catch_rate_held_item; // 1 byte long
        uint8_t move_1; // 1 byte long
        uint8_t move_2; // 1 byte long
        uint8_t move_3; // 1 byte long
        uint8_t move_4; // 1 byte long
        uint16_t original_trainer_id; // 2 bytes long
        uint32_t experience_points; // 3 bytes long
        uint16_t hp_ev; // 2 bytes long
        uint16_t attack_ev; // 2 bytes long
        uint16_t defense_ev; // 2 bytes long
        uint16_t speed_ev; // 2 bytes long
        uint16_t special_ev; // 2 bytes long 
        uint16_t attack_iv; // 2 bytes long
        uint16_t defense_iv; // 2 bytes long
        uint16_t speed_iv; // 2 bytes long
        uint16_t special_iv; // 2 bytes long
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
    private:
        void parseIvs(const int attack_defense, const int speed_special) {
            attack_iv = attack_defense >> 4;
            defense_iv = attack_defense & 0x0F;
            speed_iv = speed_special >> 4;
            special_iv = speed_special & 0x0F;
        }
};

#endif