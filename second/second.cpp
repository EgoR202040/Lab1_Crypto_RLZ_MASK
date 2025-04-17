#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    std::vector<uint64_t> RLZ = {0x0000043218574BAB,0x5431BAAB98754891};
    std::cout << "Введите кол-во тактов цикла:" << std::endl;
    
    uint32_t count; 
    uint32_t i = 0;
    
    std::cin >> count;
    
    while (i < count) {
        auto bit = (RLZ.at(1) & 0x01) ^ ((RLZ.at(1) >> 31) & 0x01);
        RLZ.at(0) = (RLZ.at(0) >> 1) | (bit << 63);
        RLZ.at(1) = (RLZ.at(1) >> 1) | (bit << 43);
        std::cout << bit;
        i++;
    }
    std::cout << '\n';
    return 0;
}