#include "../include/Figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.readData(is);
    return is;
}
