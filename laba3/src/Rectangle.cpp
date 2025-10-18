#include "Rectangle.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

Rectangle::Rectangle() : vertices(4) {}

Rectangle::Rectangle(double width, double height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive");
    }
    
    vertices = {
        Point(0, 0),
        Point(width, 0),
        Point(width, height),
        Point(0, height)
    };
}

Rectangle::Rectangle(const Point& center, double width, double height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive");
    }
    
    double halfWidth = width / 2;
    double halfHeight = height / 2;
    vertices = {
        Point(center.x - halfWidth, center.y - halfHeight),
        Point(center.x + halfWidth, center.y - halfHeight),
        Point(center.x + halfWidth, center.y + halfHeight),
        Point(center.x - halfWidth, center.y + halfHeight)
    };
}

// УДАЛЯЕМ КОНФЛИКТУЮЩИЙ КОНСТРУКТОР
// Rectangle::Rectangle(const Point& bottomLeft, double width, double height) {
//     if (width <= 0 || height <= 0) {
//         throw std::invalid_argument("Width and height must be positive");
//     }
//     
//     vertices = {
//         bottomLeft,
//         Point(bottomLeft.x + width, bottomLeft.y),
//         Point(bottomLeft.x + width, bottomLeft.y + height),
//         Point(bottomLeft.x, bottomLeft.y + height)
//     };
// }

Rectangle::Rectangle(const std::vector<Point>& vertices) : vertices(vertices) {
    if (vertices.size() != 4) {
        throw std::invalid_argument("Rectangle must have exactly 4 vertices");
    }
    validateRectangle();
}

Point Rectangle::calculateCenter() const {
    double centerX = 0, centerY = 0;
    for (const auto& vertex : vertices) {
        centerX += vertex.x;
        centerY += vertex.y;
    }
    return Point(centerX / 4, centerY / 4);
}

double Rectangle::calculateArea() const {
    return getWidth() * getHeight();
}

void Rectangle::printVertices(std::ostream& os) const {
    os << "Rectangle vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << ", ";
    }
}

void Rectangle::readData(std::istream& is) {
    double first;
    if (!(is >> first)) {
        throw std::runtime_error("Invalid input format for rectangle");
    }
    
    double second, third, fourth;
    if (is >> second >> third >> fourth) {
        // Четыре числа: centerX, centerY, width, height
        *this = Rectangle(Point(first, second), third, fourth);
    } else {
        // Одно или два числа
        is.clear();
        double height;
        if (is >> height) {
            // Два числа: width, height
            *this = Rectangle(first, height);
        } else {
            // Одно число: width (создаем квадрат)
            *this = Rectangle(first, first);
        }
    }
}

Rectangle::operator double() const {
    return calculateArea();
}

std::shared_ptr<Figure> Rectangle::clone() const {
    return std::make_shared<Rectangle>(*this);
}

bool Rectangle::isValid() const {
    if (vertices.size() != 4) return false;
    
    // Проверяем, что противоположные стороны равны и параллельны
    double width1 = distance(vertices[0], vertices[1]);
    double width2 = distance(vertices[2], vertices[3]);
    double height1 = distance(vertices[1], vertices[2]);
    double height2 = distance(vertices[3], vertices[0]);
    
    double diag1 = distance(vertices[0], vertices[2]);
    double diag2 = distance(vertices[1], vertices[3]);
    
    return std::abs(width1 - width2) < 1e-9 && 
           std::abs(height1 - height2) < 1e-9 &&
           std::abs(diag1 - diag2) < 1e-9;
}

void Rectangle::printInfo(std::ostream& os) const {
    os << "Rectangle - ";
    Figure::printInfo(os);
    os << ", Width: " << getWidth() << ", Height: " << getHeight();
}

double Rectangle::getWidth() const {
    return distance(vertices[0], vertices[1]);
}

double Rectangle::getHeight() const {
    return distance(vertices[1], vertices[2]);
}

void Rectangle::validateRectangle() const {
    if (!isValid()) {
        throw std::invalid_argument("Invalid rectangle");
    }
}

double Rectangle::distance(const Point& p1, const Point& p2) const {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

// Реализация правил пяти
Rectangle::Rectangle(const Rectangle& other) : vertices(other.vertices) {}

Rectangle::Rectangle(Rectangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}
// ДОБАВИТЬ В КОНЕЦ ФАЙЛА:
bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (!otherRect) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (!(vertices[i] == otherRect->vertices[i])) {
            return false;
        }
    }
    return true;
}
