#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include <vector>

class Square : public Figure {
private:
    std::vector<Point> vertices;
    
public:
    Square();
    Square(const Point& center, double side);
    Square(double side);  // Конструктор только со стороной
    Square(const Point& bottomLeft, double width, double height);  // Добавим параметр height чтобы отличать
    Square(const std::vector<Point>& vertices);
    
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    
    Point calculateCenter() const override;
    double calculateArea() const override;
    void printVertices(std::ostream& os) const override;
    void readData(std::istream& is) override;
    operator double() const override;
    
    std::shared_ptr<Figure> clone() const override;
    bool isValid() const override;
    void printInfo(std::ostream& os) const override;
    
    double getSide() const;
    
private:
    void validateSquare() const;
    double distance(const Point& p1, const Point& p2) const;
};

#endif
