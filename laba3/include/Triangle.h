
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <vector>

class Triangle : public Figure {
private:
    std::vector<Point> vertices;
    
public:
    // Конструкторы для разных способов создания
    Triangle();
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(double side); // Равносторонний треугольник
    Triangle(const std::vector<Point>& vertices);
    
    // Правило пяти
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    
    // Обязательные методы по ТЗ
    Point calculateCenter() const override;
    double calculateArea() const override;
    void printVertices(std::ostream& os) const override;
    void readData(std::istream& is) override;
    operator double() const override;
    
    // Дополнительные методы
    std::shared_ptr<Figure> clone() const override;
    bool isValid() const override;
    void printInfo(std::ostream& os) const override;
    
    // Геттеры
    const std::vector<Point>& getVertices() const { return vertices; }
    bool isEquilateral() const;
    
private:
    void validateTriangle() const;
    double distance(const Point& p1, const Point& p2) const;
};

#endif
