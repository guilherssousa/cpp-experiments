#include <vector>
#include <cstdint>
#include <iostream>
#include <unordered_map>

#ifndef GEN1POKEMON_STRUCT_H
#define GEN1POKEMON_STRUCT_H


const std::unordered_map<int, std::string> pokemon_species = {
    {0, "None"},
    {1,"Rhydon"},{2,"Kangaskhan"},{3,"Nidoran♂"},{4,"Clefairy"},
    {5,"Spearow"},{6,"Voltorb"},{7,"Nidoking"},{8,"Slowbro"},
    {9,"Ivysaur"},{10,"Exeggutor"},{11,"Lickitung"},{12,"Exeggcute"},
    {13,"Grimer"},{14,"Gengar"},{15,"Nidoran♀"},{16,"Nidoqueen"},
    {17,"Cubone"},{18,"Rhyhorn"},{19,"Lapras"},{20,"Arcanine"},
    {21,"Mew"},{22,"Gyarados"},{23,"Shellder"},{24,"Tentacool"},
    {25,"Gastly"},{26,"Scyther"},{27,"Staryu"},{28,"Blastoise"},
    {29,"Pinsir"},{30,"Tangela"},{31,"MissingNo."},{32,"MissingNo."},
    {33,"Growlithe"},{34,"Onix"},{35,"Fearow"},{36,"Pidgey"},{37,"Slowpoke"},
    {38,"Kadabra"},{39,"Graveler"},{40,"Chansey"},{41,"Machok"},{42,"Mr. Mime"},
    {43,"Hitmonlee"},{44,"Hitmonchan"},{45,"Arbok"},{46,"Parasect"},{47,"Psyduck"},
    {48,"Drowzee"},{49,"Golem"},{50,"MissingNo."},{51,"Magmar"},{52,"MissingNo."},
    {53,"Electabuzz"},{54,"Magneton"},{55,"Koffing"},{56,"MissingNo."},{57,"Mankey"},
    {58,"Seel"},{59,"Diglett"},{60,"Tauros"},{61,"MissingNo."},{62,"MissingNo."},
    {63,"MissingNo."},{64, "Farfetch'd"},{65,"Venonat"},{66,"Dragonite"},
    {67,"MissingNo."},{68,"MissingNo."},{69,"MissingNo."},{70,"Doduo"},
    {71,"Poliwag"},{72,"Jynx"},{73,"Moltres"},{74,"Articuno"},{75,"Zapdos"},
    {76,"Ditto"},{77,"Meowth"},{78,"Krabby"},{79,"MissingNo."},{80,"MissingNo."},
    {81,"MissingNo."},{82,"Vulpix"},{83,"Ninetales"},{84,"Pikachu"},{85,"Raichu"},
    {86,"MissingNo."},{87,"MissingNo."},{88,"Dratini"},{89,"Dragonair"},{90,"Kabuto"},
    {91,"Kabutops"},{92,"Horsea"},{93,"Seadra"},{94,"MissingNo."},{95,"MissingNo."},
    {96,"Sandshrew"},{97,"Sandslash"},{98,"Omanyte"},{99,"Omastar"},{100,"Jigglypuff"},
    {101,"Wigglytuff"},{102,"Eevee"},{103,"Flareon"},{104,"Jolteon"},{105,"Vaporeon"},
    {106,"Machop"},{107,"Zubat"},{108,"Ekans"},{109,"Paras"},{110,"Poliwhirl"},
    {111,"Poliwrath"},{112,"Weedle"},{113,"Kakuna"},{114,"Beedrill"},{115,"MissingNo."},
    {116,"Dodrio"},{117,"Primeape"},{118,"Dugtrio"},{119,"Venomoth"},{120,"Dewgong"},
    {121,"MissingNo."},{122,"MissingNo."},{123,"Caterpie"},{124,"Metapod"},{125,"Butterfree"},
    {126,"Machamp"},{127,"MissingNo."},{128,"Golduck"},{129,"Hypno"},{130,"Golbat"},
    {131,"Mewtwo"},{132,"Snorlax"},{133,"Magikarp"},{134,"MissingNo."},{135,"MissingNo."},
    {136,"Muk"},{137,"MissingNo."},{138,"Kingler"},{139,"Cloyster"},{140,"MissingNo."},
    {141,"Electrode"},{142,"Clefable"},{143,"Weezing"},{144,"Persian"},{145,"Marowak"},
    {146,"MissingNo."},{147,"Haunter"},{148,"Abra"},{149,"Alakazam"},{150,"Pidgeotto"},
    {151,"Pidgeot"},{152,"Starmie"},{153,"Bulbasaur"},{154,"Venusaur"},{155,"Tentacruel"},
    {156,"MissingNo."},{157,"Goldeen"},{158,"Seaking"},{159,"MissingNo."},{160,"MissingNo."},
    {161,"MissingNo."},{162,"MissingNo."},{163,"Ponyta"},{164,"Rapidash"},{165,"Rattata"},
    {166,"Raticate"},{167,"Nidorino"},{168,"Nidorina"},{169,"Geodude"},{170,"Porygon"},
    {171,"Aerodactyl"},{172,"MissingNo."},{173,"Magnemite"},{174,"MissingNo."},{175,"MissingNo."},
    {176,"Charmander"},{177,"Squirtle"},{178,"Charmeleon"},{179,"Wartortle"},{180,"Charizard"},
    {181,"MissingNo."},{182,"MissingNo."},{183,"MissingNo."},{184,"MissingNo."},{185,"Oddish"},
    {186,"Gloom"},{187,"Vileplume"},{188,"Bellsprout"},{189,"Weepinbell"},{190,"Victreebel"},
};

class Gen1Pokemon {
    public:
        Gen1Pokemon(std::vector<uint8_t> data) {
            if(data.size() != 44) throw std::logic_error("Pokemon: The data is not the expected size.");

            int species_index(data[0]);

            species = pokemon_species.at(species_index);
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
            std::cout << "Species: " << species;
            std::cout << "\t\tCurrent HP: " << (int)current_hp;
            std::cout << "\t\tLevel: " << (int)level << std::endl;
            std::cout << "Status: " << (int)status_condition;
            std::cout << "\t\tType 1: " << (int)type_1;
            std::cout << "\t\tType 2: " << (int)type_2 << std::endl;
            std::cout << "CR/HI: " << (int)catch_rate_held_item;
            std::cout << "\t\tMove 1: " << (int)move_1;
            std::cout << "\t\tMove 2: " << (int)move_2 << std::endl;
            std::cout << "Move 3: " << (int)move_3;
            std::cout << "\t\tMove 4: " << (int)move_4;
            std::cout << "\t\tOTID: " << (int)original_trainer_id << std::endl;
            std::cout << "XP Points: " << (int)experience_points;
            std::cout << "\t\tHP EV: " << (int)hp_ev;
            std::cout << "\t\tAttack EV: " << (int)attack_ev << std::endl;
            std::cout << "Defense EV: " << (int)defense_ev;
            std::cout << "\t\tSpeed EV: " << (int)speed_ev;
            std::cout << "\t\tSpecial EV: " << (int)special_ev << std::endl;
            std::cout << "Attack IV: " << (int)attack_iv;
            std::cout << "\t\tDefense IV: " << (int)defense_iv;
            std::cout << "\t\tSpeed IV: " << (int)speed_iv << std::endl;
            std::cout << "Special IV: " << (int)special_iv;
            std::cout << "\t\tMove 1 PP: " << (int)move_1_pp;
            std::cout << "\t\tMove 2 PP: " << (int)move_2_pp << std::endl;
            std::cout << "Move 3 PP: " << (int)move_3_pp;
            std::cout << "\t\tMove 4 PP: " << (int)move_4_pp;
            std::cout << "\t\tLevel 2: " << (int)level_2 << std::endl;
            std::cout << "Max HP: " << (int)max_hp;
            std::cout << "\t\tAttack: " << (int)attack;
            std::cout << "\t\tDefense: " << (int)defense << std::endl;
            std::cout << "Speed: " << (int)speed;
            std::cout << "\t\tSpecial: " << (int)special;
            return;
        };
        std::string species;
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