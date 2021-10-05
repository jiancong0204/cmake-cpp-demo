#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>

#include "logger/logger.hpp"

namespace Printer {
class Printer {
public:
    Printer() = default;
    ~Printer() = default;
    void Print();
    void SetCode(const int& code);

private:
    int code_;
};
} // namespace Printer

#endif // PRINTER_H