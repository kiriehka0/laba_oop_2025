#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    bool operator==(const Point& other) const {
        return std::abs(x - other.x) < 1e-9 && std::abs(y - other.y) < 1e-9;
    }
};

class Figure {
public:
    virtual ~Figure() = default;
    
    // Обязательные методы по ТЗ
    virtual Point calculateCenter() const = 0;
    virtual double calculateArea() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readData(std::istream& is) = 0;
    virtual operator double() const = 0;
    
    // Дополнительные полезные методы
    virtual std::shared_ptr<Figure> clone() const = 0;
    virtual bool isValid() const = 0;
    
    // Для вывода информации
    virtual void printInfo(std::ostream& os) const {
        auto center = calculateCenter();
        os << "Center: (" << center.x << ", " << center.y << "), ";
        os << "Area: " << calculateArea();
    }
};

// Перегрузка операторов как требуется в ТЗ
std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

#endif
