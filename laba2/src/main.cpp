#include <iostream>
#include "binary.h"

void demonstrateBinary() {
    std::cout << "=== Демонстрация работы класса Binary ===" << std::endl;
    
    try {
        // Создание чисел разными способами
        std::cout << "\n1. Создание двоичных чисел:" << std::endl;
        
        Binary num1(4, 1);                    // 1111
        Binary num2{1, 0, 1, 0};              // 1010
        Binary num3("1100");                  // 1100
        
        std::cout << "num1(4,1): " << num1.toString() << std::endl;
        std::cout << "num2{1,0,1,0}: " << num2.toString() << std::endl;
        std::cout << "num3(\"1100\"): " << num3.toString() << std::endl;
        
        // Арифметические операции
        std::cout << "\n2. Арифметические операции:" << std::endl;
        
        Binary sum = num1.add(num2);
        Binary diff = num1.subtract(num2);
        
        std::cout << "num1 + num2: " << sum.toString() << std::endl;
        std::cout << "num1 - num2: " << diff.toString() << std::endl;
        
        // Операции сравнения
        std::cout << "\n3. Операции сравнения:" << std::endl;
        
        std::cout << "num1 == num2: " << (num1.equals(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 < num2: " << (num1.less(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 > num2: " << (num1.greater(num2) ? "true" : "false") << std::endl;
        
        // Проверка иммутабельности
        std::cout << "\n4. Проверка иммутабельности:" << std::endl;
        Binary original(4, 1);
        Binary result = original.add(Binary(4, 1));
        std::cout << "Оригинал: " << original.toString() << std::endl;
        std::cout << "После сложения: " << result.toString() << std::endl;
        std::cout << "Оригинал не изменился: " << (original.toString() == "1111" ? "true" : "false") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

int main() {
    demonstrateBinary();
    return 0;
}
