#include <iostream>
#include <vector>


int main(int argc,char** argv){
    uint16_t RLZ = 0x7DEC;
    std::cout << "Введите кол-во тактов цикла:" << std::endl;
    uint count,i;
    std::cin >> count;
    while(i < count){
        auto bit = (RLZ&0x01)^((RLZ>>7)&0x01); // Сначала считываем 16-й бит, затем сдвигаем на 7,чтобы с конца считать 9-й бит
        RLZ = (RLZ>>1)|(bit<<15);
        //std::cout << "Такт:" << i << '\t';
        std::cout << bit;
        //std::cout<< std::endl;
        i++;
    }
    std::cout <<'\n' <<"Генерация окончена" << std::endl;
}