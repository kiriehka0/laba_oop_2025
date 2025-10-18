#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>
#include <stdexcept>
#include "Figure.h"

class Array {
private:
    std::vector<std::shared_ptr<Figure>> figures;
    
public:
    Array() = default;
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array() = default;
    
    // Основные операции
    void addFigure(std::shared_ptr<Figure> figure);
    void removeFigure(size_t index);
    std::shared_ptr<Figure> getFigure(size_t index) const;
    size_t size() const;
    bool empty() const;
    void clear();
    
    // Операции по ТЗ
    double totalArea() const;
    void printAllInfo(std::ostream& os) const;
    
    // Арифметические операции
    Array add(const Array& other) const;
    Array subtract(const Array& other) const;
    Array copy() const;
    
    // Операции сравнения
    bool equals(const Array& other) const;
    bool lessThan(const Array& other) const;
    bool greaterThan(const Array& other) const;
};

#endif
