#include "printer.h"

void Printer::Print() {
    std::cout << code_ << std::endl;
}

void Printer::SetCode(const int& code) {
    code_ = code;
}