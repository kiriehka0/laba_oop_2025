#include "Square.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

Square::Square() : vertices(4) {}

Square::Square(const Point& center, double side) {
    if (side <= 0) throw std::invalid_argument("Side must be positive");
    
    double halfSide = side / 2;
    vertices = {
        Point(center.x - halfSide, center.y - halfSide),
        Point(center.x + halfSide, center.y - halfSide),
        Point(center.x + halfSide, center.y + halfSide),
        Point(center.x - halfSide, center.y + halfSide)
    };
}

Square::Square(const Point& bottomLeft, double side) {
    if (side <= 0) throw std::invalid_argument("Side must be positive");
    
    vertices = {
        bottomLeft,
        Point(bottomLeft.x + side, bottomLeft.y),
        Point(bottomLeft.x + side, bottomLeft.y + side),
        Point(bottomLeft.x, bottomLeft.y + side)
    };
}

Square::Square(const std::vector<Point>& vertices) : vertices(vertices) {
    if (vertices.size() != 4) {
        throw std::invalid_argument("Square must have exactly 4 vertices");
    }
    validateSquare();
}

Point Square::calculateCenter() const {
    double centerX = 0, centerY = 0;
    for (const auto& vertex : vertices) {
        centerX += vertex.x;
        centerY += vertex.y;
    }
    return Point(centerX / 4, centerY / 4);
}

double Square::calculateArea() const {
    double side = distance(vertices[0], vertices[1]);
    return side * side;
}

void Square::printVertices(std::ostream& os) const {
    os << "Square vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << ", ";
    }
}

void Square::readData(std::istream& is) {
    double first;
    if (!(is >> first)) {
        throw std::runtime_error("Invalid input format for square");
    }
    
    // Пытаемся прочитать второе число
    double second;
    if (is >> second) {
        // Есть второе число - это центр и сторона
        double third;
        if (is >> third) {
            *this = Square(Point(first, second), third);
        } else {
            throw std::runtime_error("Invalid input format for square");
        }
    } else {
        // Нет второго числа - это нижний левый угол и сторона
        is.clear();
        *this = Square(Point(0, 0), first);
    }
}

Square::operator double() const {
    return calculateArea();
}

std::shared_ptr<Figure> Square::clone() const {
    return std::make_shared<Square>(*this);
}

bool Square::isValid() const {
    if (vertices.size() != 4) return false;
    
    // Проверяем, что все стороны равны и углы 90 градусов
    double side1 = distance(vertices[0], vertices[1]);
    double side2 = distance(vertices[1], vertices[2]);
    double side3 = distance(vertices[2], vertices[3]);
    double side4 = distance(vertices[3], vertices[0]);
    
    double diag1 = distance(vertices[0], vertices[2]);
    double diag2 = distance(vertices[1], vertices[3]);
    
    return std::abs(side1 - side2) < 1e-9 && 
           std::abs(side2 - side3) < 1e-9 && 
           std::abs(side3 - side4) < 1e-9 &&
           std::abs(diag1 - diag2) < 1e-9;
}

void Square::printInfo(std::ostream& os) const {
    os << "Square - ";
    Figure::printInfo(os);
    os << ", Side: " << getSide();
}

double Square::getSide() const {
    return distance(vertices[0], vertices[1]);
}

void Square::validateSquare() const {
    if (!isValid()) {
        throw std::invalid_argument("Invalid square: not a perfect square");
    }
}

double Square::distance(const Point& p1, const Point& p2) const {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

// Реализация правил пяти
Square::Square(const Square& other) : vertices(other.vertices) {}

Square::Square(Square&& other) noexcept : vertices(std::move(other.vertices)) {}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}
