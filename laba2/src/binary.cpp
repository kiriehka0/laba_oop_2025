#include "binary.h"
#include <algorithm>
#include <sstream>

// Конструктор по умолчанию
Binary::Binary() : size(0), data(nullptr) {}

// Конструктор с размером и значением
Binary::Binary(const size_t & n, unsigned char t) : size(n) {
    if (n == 0) {
        throw std::invalid_argument("Size must be greater than 0");
    }
    if (t != 0 && t != 1) {
        throw std::invalid_argument("Binary digit must be 0 or 1");
    }
    
    data = new unsigned char[n];
    for (size_t i = 0; i < n; ++i) {
        data[i] = t;
    }
}

// Конструктор из initializer_list
Binary::Binary(const std::initializer_list<unsigned char> &t) : size(t.size()) {
    if (t.size() == 0) {
        throw std::invalid_argument("Initializer list cannot be empty");
    }
    
    data = new unsigned char[size];
    size_t i = 0;
    for (auto it = t.begin(); it != t.end(); ++it, ++i) {
        if (*it != 0 && *it != 1) {
            throw std::invalid_argument("Binary digits must be 0 or 1");
        }
        data[i] = *it;
    }
}

// Конструктор из строки
Binary::Binary(const std::string &t) : size(t.length()) {
    if (t.empty()) {
        throw std::invalid_argument("String cannot be empty");
    }
    
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        char c = t[i];
        if (c == '0') {
            data[i] = 0;
        } else if (c == '1') {
            data[i] = 1;
        } else {
            throw std::invalid_argument("String must contain only '0' and '1'");
        }
    }
}

// Конструктор копирования
Binary::Binary(const Binary& other) {
    copy(other);
}

// Конструктор перемещения
Binary::Binary(Binary&& other) noexcept {
    move(std::move(other));
}

// Деструктор
Binary::~Binary() noexcept {
    delete[] data;
}

// Оператор присваивания копированием
Binary& Binary::operator=(const Binary& other) {
    if (this != &other) {
        delete[] data;
        copy(other);
    }
    return *this;
}

// Оператор присваивания перемещением
Binary& Binary::operator=(Binary&& other) noexcept {
    if (this != &other) {
        delete[] data;
        move(std::move(other));
    }
    return *this;
}

// Сложение
Binary Binary::plus(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    
    Binary result(size);
    unsigned char carry = 0;
    for (size_t i = 0; i < size; ++i) {
        unsigned char sum = data[i] + other.data[i] + carry;
        result.data[i] = sum % 2;
        carry = sum / 2;
    }
    return result;
}

// Вычитание
Binary Binary::minus(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    
    Binary result(size);
    unsigned char borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        int diff = data[i] - other.data[i] - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.data[i] = diff;
    }
    return result;
}

// Копирование
Binary Binary::copy() const {
    return Binary(*this);
}

// Сравнение на равенство
bool Binary::equals(const Binary& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

// Сравнение на меньше
bool Binary::less(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    
    for (size_t i = size; i > 0; --i) {
        if (data[i - 1] < other.data[i - 1]) {
            return true;
        } else if (data[i - 1] > other.data[i - 1]) {
            return false;
        }
    }
    return false;
}

// Сравнение на больше
bool Binary::greater(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    
    for (size_t i = size; i > 0; --i) {
        if (data[i - 1] > other.data[i - 1]) {
            return true;
        } else if (data[i - 1] < other.data[i - 1]) {
            return false;
        }
    }
    return false;
}

// Геттеры
size_t Binary::getSize() const {
    return size;
}

unsigned char Binary::getDigit(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Преобразование в строку
std::string Binary::toString() const {
    std::string result;
    for (size_t i = size; i > 0; --i) {
        result += (data[i - 1] == 0) ? '0' : '1';
    }
    return result;
}

// Вспомогательные методы
void Binary::copy(const Binary& other) {
    size = other.size;
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

void Binary::move(Binary&& other) noexcept {
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
}
