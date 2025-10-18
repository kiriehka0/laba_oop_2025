#include "../include/Triangle.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

Triangle::Triangle() : vertices(3) {}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
    vertices = {p1, p2, p3};
    validateTriangle();
}

Triangle::Triangle(double side) {
    if (side <= 0) throw std::invalid_argument("Side must be positive");
    
    double height = side * std::sqrt(3) / 2;
    vertices = {
        Point(0, 0),
        Point(side, 0),
        Point(side / 2, height)
    };
}

Triangle::Triangle(const std::vector<Point>& vertices) : vertices(vertices) {
    if (vertices.size() != 3) {
        throw std::invalid_argument("Triangle must have exactly 3 vertices");
    }
    validateTriangle();
}

Point Triangle::calculateCenter() const {
    double centerX = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
    double centerY = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;
    return Point(centerX, centerY);
}

double Triangle::calculateArea() const {
    double x1 = vertices[0].x, y1 = vertices[0].y;
    double x2 = vertices[1].x, y2 = vertices[1].y;
    double x3 = vertices[2].x, y3 = vertices[2].y;
    
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

void Triangle::printVertices(std::ostream& os) const {
    os << "Triangle vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << ", ";
    }
}

void Triangle::readData(std::istream& is) {
    std::vector<Point> newVertices;
    
    // Пытаемся прочитать как координаты вершин
    for (int i = 0; i < 3; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            // Если не удалось прочитать координаты, пробуем прочитать как сторону
            is.clear();
            double side;
            if (is >> side) {
                *this = Triangle(side);
                return;
            } else {
                throw std::runtime_error("Invalid input format for triangle");
            }
        }
        newVertices.emplace_back(x, y);
    }
    
    vertices = newVertices;
    validateTriangle();
}

Triangle::operator double() const {
    return calculateArea();
}

std::shared_ptr<Figure> Triangle::clone() const {
    return std::make_shared<Triangle>(*this);
}

bool Triangle::isValid() const {
    if (vertices.size() != 3) return false;
    
    // Проверяем, что точки не коллинеарны
    double area = calculateArea();
    return area > 1e-9; // Не нулевая площадь
}

bool Triangle::isEquilateral() const {
    if (!isValid()) return false;
    
    double a = distance(vertices[0], vertices[1]);
    double b = distance(vertices[1], vertices[2]);
    double c = distance(vertices[2], vertices[0]);
    
    return std::abs(a - b) < 1e-9 && std::abs(b - c) < 1e-9;
}

void Triangle::printInfo(std::ostream& os) const {
    os << "Triangle - ";
    Figure::printInfo(os);
    if (isEquilateral()) {
        os << " (Equilateral)";
    }
}

void Triangle::validateTriangle() const {
    if (!isValid()) {
        throw std::invalid_argument("Invalid triangle: points are collinear");
    }
}

double Triangle::distance(const Point& p1, const Point& p2) const {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

// Реализация правил пяти
Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}
