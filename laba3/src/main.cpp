#include <iostream>
#include <memory>
#include <limits>
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

void printMenu() {
    std::cout << "\n=== Figure Management System ===" << std::endl;
    std::cout << "1. Add Triangle" << std::endl;
    std::cout << "2. Add Square" << std::endl;
    std::cout << "3. Add Rectangle" << std::endl;
    std::cout << "4. Remove Figure" << std::endl;
    std::cout << "5. Print All Figures Info" << std::endl;
    std::cout << "6. Calculate Total Area" << std::endl;
    std::cout << "7. Clear All Figures" << std::endl;
    std::cout << "8. Test Array Operations" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Choose option: ";
}

void addTriangle(Array& array) {
    std::cout << "Enter triangle data:" << std::endl;
    std::cout << "Format 1: x1 y1 x2 y2 x3 y3 (coordinates of 3 vertices)" << std::endl;
    std::cout << "Format 2: side (for equilateral triangle)" << std::endl;
    std::cout << "Input: ";
    
    auto triangle = std::make_shared<Triangle>();
    std::cin >> *triangle;
    array.addFigure(triangle);
    std::cout << "Triangle added successfully!" << std::endl;
}

void addSquare(Array& array) {
    std::cout << "Enter square data:" << std::endl;
    std::cout << "Format 1: centerX centerY side" << std::endl;
    std::cout << "Format 2: bottomLeftX bottomLeftY side" << std::endl;
    std::cout << "Input: ";
    
    auto square = std::make_shared<Square>();
    std::cin >> *square;
    array.addFigure(square);
    std::cout << "Square added successfully!" << std::endl;
}

void addRectangle(Array& array) {
    std::cout << "Enter rectangle data:" << std::endl;
    std::cout << "Format 1: centerX centerY width height" << std::endl;
    std::cout << "Format 2: bottomLeftX bottomLeftY width height" << std::endl;
    std::cout << "Input: ";
    
    auto rectangle = std::make_shared<Rectangle>();
    std::cin >> *rectangle;
    array.addFigure(rectangle);
    std::cout << "Rectangle added successfully!" << std::endl;
}

void testArrayOperations(Array& array) {
    std::cout << "\n=== Testing Array Operations ===" << std::endl;
    
    // Создаем тестовый массив
    Array testArray;
    testArray.addFigure(std::make_shared<Triangle>(2.0));
    testArray.addFigure(std::make_shared<Square>(Point(0, 0), 3.0));
    
    std::cout << "Original array:" << std::endl;
    array.printAllInfo(std::cout);
    
    std::cout << "\nTest array:" << std::endl;
    testArray.printAllInfo(std::cout);
    
    std::cout << "\nAdding arrays:" << std::endl;
    Array sum = array.add(testArray);
    sum.printAllInfo(std::cout);
    
    std::cout << "\nArrays equal: " << (array.equals(testArray) ? "Yes" : "No") << std::endl;
    std::cout << "Original > Test: " << (array.greaterThan(testArray) ? "Yes" : "No") << std::endl;
}

int main() {
    Array figuresArray;
    int choice;
    
    std::cout << "Figure Management System Started" << std::endl;
    
    do {
        printMenu();
        std::cin >> choice;
        
        // Очистка буфера ввода
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        try {
            switch (choice) {
                case 1:
                    addTriangle(figuresArray);
                    break;
                case 2:
                    addSquare(figuresArray);
                    break;
                case 3:
                    addRectangle(figuresArray);
                    break;
                case 4: {
                    if (figuresArray.empty()) {
                        std::cout << "Array is empty!" << std::endl;
                        break;
                    }
                    std::cout << "Enter index to remove (0 to " << figuresArray.size() - 1 << "): ";
                    size_t index;
                    std::cin >> index;
                    figuresArray.removeFigure(index);
                    std::cout << "Figure removed successfully!" << std::endl;
                    break;
                }
                case 5:
                    figuresArray.printAllInfo(std::cout);
                    break;
                case 6:
                    std::cout << "Total area of all figures: " << figuresArray.totalArea() << std::endl;
                    break;
                case 7:
                    figuresArray.clear();
                    std::cout << "All figures cleared!" << std::endl;
                    break;
                case 8:
                    testArrayOperations(figuresArray);
                    break;
                case 9:
                    std::cout << "Goodbye!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid option! Please try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    } while (choice != 9);
    
    return 0;
}
