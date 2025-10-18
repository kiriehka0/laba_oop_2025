#include <gtest/gtest.h>
#include <sstream>
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

TEST(TriangleTest, CreationAndArea) {
    Triangle triangle(3.0);
    EXPECT_NEAR(static_cast<double>(triangle), 3.897, 0.001);
    EXPECT_TRUE(triangle.isValid());
    EXPECT_TRUE(triangle.isEquilateral());
}

TEST(TriangleTest, VerticesCreation) {
    Triangle triangle(Point(0, 0), Point(3, 0), Point(0, 4));
    EXPECT_NEAR(static_cast<double>(triangle), 6.0, 1e-9);
    EXPECT_TRUE(triangle.isValid());
    EXPECT_FALSE(triangle.isEquilateral());
}

TEST(SquareTest, CreationAndArea) {
    Square square(Point(0, 0), 5.0);
    EXPECT_NEAR(static_cast<double>(square), 25.0, 1e-9);
    EXPECT_TRUE(square.isValid());
}

TEST(RectangleTest, CreationAndArea) {
    Rectangle rectangle(Point(0, 0), 4.0, 6.0);
    EXPECT_NEAR(static_cast<double>(rectangle), 24.0, 1e-9);
    EXPECT_TRUE(rectangle.isValid());
}

TEST(ArrayTest, BasicOperations) {
    Array array;
    EXPECT_TRUE(array.empty());
    
    array.addFigure(std::make_shared<Triangle>(2.0));
    array.addFigure(std::make_shared<Square>(Point(0, 0), 3.0));
    
    EXPECT_EQ(array.size(), 2);
    EXPECT_FALSE(array.empty());
    EXPECT_GT(array.totalArea(), 0);
}

TEST(ArrayTest, AddAndRemove) {
    Array array;
    auto triangle = std::make_shared<Triangle>(2.0);
    array.addFigure(triangle);
    
    EXPECT_EQ(array.size(), 1);
    
    array.removeFigure(0);
    EXPECT_TRUE(array.empty());
}

TEST(ArrayTest, CopyOperations) {
    Array array1;
    array1.addFigure(std::make_shared<Triangle>(2.0));
    
    Array array2 = array1.copy();
    EXPECT_TRUE(array1.equals(array2));
    
    Array array3 = array1.add(array2);
    EXPECT_EQ(array3.size(), 2);
}

TEST(FigureTest, InputOutput) {
    std::stringstream ss;
    ss << "0 0 3 0 0 4";
    
    Triangle triangle;
    ss >> triangle;
    
    EXPECT_TRUE(triangle.isValid());
    EXPECT_NEAR(static_cast<double>(triangle), 6.0, 1e-9);
}
// Добавляем в существующий файл тестов

TEST(ComparisonTest, TriangleEquality) {
    Triangle triangle1(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle triangle2(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle triangle3(Point(0, 0), Point(4, 0), Point(0, 3));
    
    EXPECT_TRUE(triangle1 == triangle2);
    EXPECT_FALSE(triangle1 == triangle3);
}

TEST(ComparisonTest, SquareEquality) {
    Square square1(Point(0, 0), 5.0);
    Square square2(Point(0, 0), 5.0);
    Square square3(Point(1, 1), 5.0);
    
    EXPECT_TRUE(square1 == square2);
    EXPECT_FALSE(square1 == square3);
}

TEST(ComparisonTest, RectangleEquality) {
    Rectangle rect1(Point(0, 0), 4.0, 6.0);
    Rectangle rect2(Point(0, 0), 4.0, 6.0);
    Rectangle rect3(Point(0, 0), 5.0, 6.0);
    
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(ComparisonTest, DifferentTypesNotEqual) {
    Triangle triangle(Point(0, 0), Point(3, 0), Point(0, 4));
    Square square(Point(0, 0), 6.0); // Такая же площадь как у треугольника
    
    EXPECT_FALSE(triangle == square);
    EXPECT_FALSE(square == triangle);
}

TEST(ArrayComparisonTest, ArrayEquality) {
    Array array1;
    array1.addFigure(std::make_shared<Triangle>(3.0));
    array1.addFigure(std::make_shared<Square>(Point(0, 0), 2.0));
    
    Array array2;
    array2.addFigure(std::make_shared<Triangle>(3.0));
    array2.addFigure(std::make_shared<Square>(Point(0, 0), 2.0));
    
    Array array3;
    array3.addFigure(std::make_shared<Triangle>(4.0)); // Другой треугольник
    
    EXPECT_TRUE(array1 == array2);
    EXPECT_FALSE(array1 == array3);
}

TEST(ArrayComparisonTest, DifferentSizesNotEqual) {
    Array array1;
    array1.addFigure(std::make_shared<Triangle>(3.0));
    
    Array array2;
    array2.addFigure(std::make_shared<Triangle>(3.0));
    array2.addFigure(std::make_shared<Square>(Point(0, 0), 2.0));
    
    EXPECT_FALSE(array1 == array2);
}
// ДОБАВИТЬ В КОНЕЦ ФАЙЛА (перед main):

TEST(ComparisonTest, TriangleEquality) {
    Triangle triangle1(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle triangle2(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle triangle3(Point(0, 0), Point(4, 0), Point(0, 3));
    
    EXPECT_TRUE(triangle1 == triangle2);
    EXPECT_FALSE(triangle1 == triangle3);
}

TEST(ComparisonTest, SquareEquality) {
    Square square1(Point(0, 0), 5.0);
    Square square2(Point(0, 0), 5.0);
    Square square3(Point(1, 1), 5.0);
    
    EXPECT_TRUE(square1 == square2);
    EXPECT_FALSE(square1 == square3);
}

TEST(ComparisonTest, RectangleEquality) {
    Rectangle rect1(Point(0, 0), 4.0, 6.0);
    Rectangle rect2(Point(0, 0), 4.0, 6.0);
    Rectangle rect3(Point(0, 0), 5.0, 6.0);
    
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(ComparisonTest, DifferentTypesNotEqual) {
    Triangle triangle(Point(0, 0), Point(3, 0), Point(0, 4));
    Square square(Point(0, 0), 6.0);
    
    EXPECT_FALSE(triangle == square);
    EXPECT_FALSE(square == triangle);
}

TEST(ArrayComparisonTest, ArrayOperatorEquality) {
    Array array1;
    array1.addFigure(std::make_shared<Triangle>(3.0));
    array1.addFigure(std::make_shared<Square>(Point(0, 0), 2.0));
    
    Array array2;
    array2.addFigure(std::make_shared<Triangle>(3.0));
    array2.addFigure(std::make_shared<Square>(Point(0, 0), 2.0));
    
    Array array3;
    array3.addFigure(std::make_shared<Triangle>(4.0));
    
    EXPECT_TRUE(array1 == array2);
    EXPECT_FALSE(array1 == array3);
}

TEST(ArrayComparisonTest, DifferentSizesNotEqual) {
    Array array1;
    array1.addFigure(std::make_shared<Triangle>(3.0));
    
    Array array2;
    array2.addFigure(std::make_shared<Triangle>(3.0));
    array2.addFigure(std::make_shared<Square>(Point(0, 0), 2.0));
    
    EXPECT_FALSE(array1 == array2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
