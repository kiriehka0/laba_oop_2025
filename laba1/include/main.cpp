#include <iostream>


int main(){
    int upper_limit;
    std::cout << "Введите верхний предел:";
    std::cin >> upper_limit;
    auto super_result = closet_pair_tonum(upper_limit);
    if (super_result.first == 0){
        std::cout << "Подходящих пар не найдено" << std::endl;
    }else{
        std::cout << "(" << super_result.first << "," << super_result.second << ")" << std::endl;
    }
    return 0;
}
