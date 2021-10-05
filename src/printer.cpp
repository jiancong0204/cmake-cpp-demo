#include "printer.h"

void Printer::Printer::Print()
{
    LOG(INFO) << Logger::MAGENT << code_ << Logger::END;
}

void Printer::Printer::SetCode(const int& code)
{
    code_ = code;
}