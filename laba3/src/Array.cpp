#include "Array.h"
#include <iostream>

Array::Array(const Array& other) {
    for (const auto& figure : other.figures) {
        figures.push_back(figure->clone());
    }
}

Array::Array(Array&& other) noexcept : figures(std::move(other.figures)) {}

void Array::addFigure(std::shared_ptr<Figure> figure) {
    if (!figure->isValid()) {
        throw std::invalid_argument("Cannot add invalid figure");
    }
    figures.push_back(figure);
}

void Array::removeFigure(size_t index) {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    figures.erase(figures.begin() + index);
}

std::shared_ptr<Figure> Array::getFigure(size_t index) const {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

size_t Array::size() const {
    return figures.size();
}

bool Array::empty() const {
    return figures.empty();
}

void Array::clear() {
    figures.clear();
}

double Array::totalArea() const {
    double total = 0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    return total;
}

void Array::printAllInfo(std::ostream& os) const {
    if (figures.empty()) {
        os << "Array is empty" << std::endl;
        return;
    }
    
    os << "=== Figures Information ===" << std::endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        os << "Figure " << i << ": ";
        figures[i]->printInfo(os);
        os << std::endl;
    }
    os << "Total figures: " << figures.size() << std::endl;
    os << "Total area: " << totalArea() << std::endl;
}

Array Array::add(const Array& other) const {
    Array result = this->copy();
    for (const auto& figure : other.figures) {
        result.addFigure(figure->clone());
    }
    return result;
}

Array Array::subtract(const Array& other) const {
    Array result = this->copy();
    // Удаляем фигуры, которые есть в другом массиве
    for (size_t i = 0; i < result.figures.size(); ++i) {
        for (const auto& otherFigure : other.figures) {
            if (std::abs(static_cast<double>(*result.figures[i]) - 
                         static_cast<double>(*otherFigure)) < 1e-9) {
                result.removeFigure(i);
                --i;
                break;
            }
        }
    }
    return result;
}

Array Array::copy() const {
    Array result;
    for (const auto& figure : figures) {
        result.addFigure(figure->clone());
    }
    return result;
}

bool Array::equals(const Array& other) const {
    if (figures.size() != other.figures.size()) return false;
    
    for (size_t i = 0; i < figures.size(); ++i) {
        if (std::abs(static_cast<double>(*figures[i]) - 
                     static_cast<double>(*other.figures[i])) > 1e-9) {
            return false;
        }
    }
    return true;
}

bool Array::lessThan(const Array& other) const {
    return this->totalArea() < other.totalArea();
}

bool Array::greaterThan(const Array& other) const {
    return this->totalArea() > other.totalArea();
}
