#include <iostream>
#include <cmath>

std::pair<int, int> closet_pair_tonum(int upper_limit){
    for (int x = upper_limit - 1; x > 0; x--){
        for (int y = x - 1; y > 0; y--){
            double result0 = x + y;
            double result1 = x - y;
            if (static_cast<int>(sqrt(result0)) == sqrt(result0) && static_cast<int>(sqrt(result1)) == sqrt(result1)){
                return {x, y};
            }
        }
    }
    return {0, 0}; 
}
