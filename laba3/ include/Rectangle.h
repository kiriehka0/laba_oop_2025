#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <vector>

class Rectangle : public Figure {
private:
    std::vector<Point> vertices;
    
public:
    Rectangle();
    Rectangle(const Point& center, double width, double height);
    Rectangle(const Point& bottomLeft, double width, double height);
    Rectangle(const std::vector<Point>& vertices);
    
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    Point calculateCenter() const override;
    double calculateArea() const override;
    void printVertices(std::ostream& os) const override;
    void readData(std::istream& is) override;
    operator double() const override;
    
    std::shared_ptr<Figure> clone() const override;
    bool isValid() const override;
    void printInfo(std::ostream& os) const override;
    
    double getWidth() const;
    double getHeight() const;
    
private:
    void validateRectangle() const;
    double distance(const Point& p1, const Point& p2) const;
};

#endif
