#include <gtest/gtest.h>
#include "binary.h"

// Тестовая группа для конструкторов
class BinaryConstructorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Код инициализации, если нужен
    }

    void TearDown() override {
        // Код очистки, если нужен
    }
};

// Тесты конструкторов
TEST_F(BinaryConstructorTest, SizeAndValueConstructor) {
    Binary b1(4, 1);
    EXPECT_EQ(b1.toString(), "1111");
    
    Binary b2(4, 0);
    EXPECT_EQ(b2.toString(), "0000");
}

TEST_F(BinaryConstructorTest, InitializerListConstructor) {
    Binary b1{1, 0, 1, 0};
    EXPECT_EQ(b1.toString(), "1010");
    
    Binary b2{0, 0, 0, 1};
    EXPECT_EQ(b2.toString(), "1000");
}

TEST_F(BinaryConstructorTest, StringConstructor) {
    Binary b1("1100");
    EXPECT_EQ(b1.toString(), "1100");
    
    Binary b2("1010");
    EXPECT_EQ(b2.toString(), "1010");
}

// Тесты арифметических операций
TEST(BinaryArithmeticTest, Addition) {
    Binary b1{1, 1, 0, 0};  // 1100
    Binary b2{0, 1, 0, 1};  // 1010
    
    Binary sum = b1.add(b2);
    EXPECT_EQ(sum.toString(), "0110");
}

TEST(BinaryArithmeticTest, Subtraction) {
    Binary b1{1, 1, 0, 0};  // 1100
    Binary b2{0, 1, 0, 1};  // 1010
    
    Binary diff = b1.subtract(b2);
    EXPECT_EQ(diff.toString(), "0010");
}

TEST(BinaryArithmeticTest, Copy) {
    Binary b1{1, 1, 0, 0};  // 1100
    Binary copy = b1.copyBinary();
    
    EXPECT_EQ(copy.toString(), "1100");
    EXPECT_TRUE(b1.equals(copy));
}

TEST(BinaryArithmeticTest, AdditionWithOverflow) {
    Binary b1{1, 1, 1, 1};  // 1111
    Binary b2{0, 0, 0, 1};  // 1000
    
    Binary sum = b1.add(b2);
    EXPECT_EQ(sum.toString(), "0111");
}

// Тесты операций сравнения
TEST(BinaryComparisonTest, Equality) {
    Binary b1{1, 1, 1, 1};  // 1111
    Binary b2{0, 1, 0, 1};  // 1010
    Binary b3{1, 1, 1, 1};  // 1111
    
    EXPECT_TRUE(b1.equals(b3));
    EXPECT_FALSE(b1.equals(b2));
}

TEST(BinaryComparisonTest, LessThan) {
    Binary b1{1, 1, 1, 1};  // 1111
    Binary b2{0, 1, 0, 1};  // 1010
    
    EXPECT_TRUE(b2.less(b1));
    EXPECT_FALSE(b1.less(b2));
}

TEST(BinaryComparisonTest, GreaterThan) {
    Binary b1{1, 1, 1, 1};  // 1111
    Binary b2{0, 1, 0, 1};  // 1010
    
    EXPECT_TRUE(b1.greater(b2));
    EXPECT_FALSE(b2.greater(b1));
}

// Тесты иммутабельности
TEST(BinaryImmutabilityTest, OriginalUnchangedAfterOperations) {
    Binary original{1, 0, 1, 0};  // 1010
    std::string originalString = original.toString();
    
    // Выполняем операции
    Binary copy = original.copyBinary();
    Binary sum = original.add(Binary(4, 1));
    Binary diff = original.subtract(Binary(4, 1));
    
    // Проверяем, что оригинал не изменился
    EXPECT_EQ(original.toString(), originalString);
    EXPECT_TRUE(original.equals(copy));
}

// Тесты исключений - правильный синтаксис
TEST(BinaryExceptionTest, ZeroSizeException) {
    try {
        Binary invalid(0, 1);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument&) {
        SUCCEED();
    } catch (...) {
        FAIL() << "Expected std::invalid_argument but got different exception";
    }
}

TEST(BinaryExceptionTest, InvalidDigitInInitializerList) {
    try {
        Binary invalid{0, 1, 2};
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument&) {
        SUCCEED();
    } catch (...) {
        FAIL() << "Expected std::invalid_argument but got different exception";
    }
}

TEST(BinaryExceptionTest, InvalidCharacterInString) {
    try {
        Binary invalid("102");
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument&) {
        SUCCEED();
    } catch (...) {
        FAIL() << "Expected std::invalid_argument but got different exception";
    }
}

TEST(BinaryExceptionTest, DifferentSizesInOperations) {
    Binary b1(4, 1);
    Binary b2(5, 1);
    
    try {
        Binary sum = b1.add(b2);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument&) {
        SUCCEED();
    } catch (...) {
        FAIL() << "Expected std::invalid_argument but got different exception";
    }
}

// Тесты геттеров
TEST(BinaryGettersTest, SizeAndDigits) {
    Binary b{1, 0, 1, 0};  // 1010
    
    EXPECT_EQ(b.getSize(), 4);
    EXPECT_EQ(b.getDigit(0), 1);
    EXPECT_EQ(b.getDigit(1), 0);
    EXPECT_EQ(b.getDigit(2), 1);
    EXPECT_EQ(b.getDigit(3), 0);
}

TEST(BinaryGettersTest, OutOfRangeException) {
    Binary b{1, 0, 1, 0};  // 1010
    
    try {
        b.getDigit(4);
        FAIL() << "Expected std::out_of_range";
    } catch (const std::out_of_range&) {
        SUCCEED();
    } catch (...) {
        FAIL() << "Expected std::out_of_range but got different exception";
    }
}

// Главная функция (gtest_main позаботится об этом, но на всякий случай)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
