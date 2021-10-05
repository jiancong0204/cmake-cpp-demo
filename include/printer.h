#include <iostream>

class Printer {
public:
    Printer() = default;
    ~Printer() = default;
    void Print();
    void SetCode(const int& code);
private:
    int code_;
};