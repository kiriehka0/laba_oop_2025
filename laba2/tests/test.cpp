#include <gtest/gtest.h>
#include "binary.h"

// Тесты конструкторов
TEST(BinaryTest, Constructors) {
    // Конструктор с размером
    Binary b1(4, 1);
    EXPECT_EQ(b1.toString(), "1111");
    
    // Конструктор из initializer_list
    Binary b2{1, 0, 1, 0};
    EXPECT_EQ(b2.toString(), "1010");
    
    // Конструктор из строки
    Binary b3("1100");
    EXPECT_EQ(b3.toString(), "1100");
}

// Тесты арифметических операций
TEST(BinaryTest, ArithmeticOperations) {
    Binary b1{1, 1, 0, 0};  // 1100
    Binary b2{0, 1, 0, 1};  // 1010
    
    Binary sum = b1.add(b2);
    EXPECT_EQ(sum.toString(), "0110");
    
    Binary diff = b1.subtract(b2);
    EXPECT_EQ(diff.toString(), "0010");
}

// Тесты операций сравнения
TEST(BinaryTest, ComparisonOperations) {
    Binary b1{1, 1, 1, 1};  // 1111
    Binary b2{0, 1, 0, 1};  // 1010
    
    EXPECT_FALSE(b1.equals(b2));
    EXPECT_FALSE(b1.less(b2));
    EXPECT_TRUE(b1.greater(b2));
}

// Тесты иммутабельности
TEST(BinaryTest, Immutability) {
    Binary original{1, 0, 1, 0};
    Binary copy = original.copyBinary();
    
    EXPECT_TRUE(original.equals(copy));
    
    Binary modified = original.add(Binary(4, 1));
    EXPECT_TRUE(original.equals(copy));  // Оригинал не изменился
}

// Тесты исключений - исправленный синтаксис
TEST(BinaryTest, Exceptions) {
    // Правильный синтаксис EXPECT_THROW
    EXPECT_THROW({
        Binary b(0, 1);
    }, std::invalid_argument);
    
    EXPECT_THROW({
        Binary b{0, 1, 2};
    }, std::invalid_argument);
    
    EXPECT_THROW({
        Binary b("102");
    }, std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
