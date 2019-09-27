#include <iostream>
#include "FazzyNumber.h"

int main()
{
    double tmp_l, tmp_r;

    std::cout << "Ввод левой и правой границ отрезка А:" << '\n';
    std::cin >> tmp_l;
    std::cin >> tmp_r;
    Fazzy A(tmp_l, tmp_r);

    std::cout << "Ввод левой и правой границ отрезка Б:" << '\n';
    std::cin >> tmp_l;
    std::cin >> tmp_r;
    Fazzy B(tmp_l, tmp_r);

    Fazzy res1;
    res1 = A.plus(B);
    std::cout << "A+B: ";
    res1.write(std::cout);

    Fazzy res2;
    res2 = A.minus(B);
    std::cout << "A-B: ";
    res2.write(std::cout);

    Fazzy res3;
    res3 = A.mult(B);
    std::cout << "A*B: ";
    res3.write(std::cout);

    Fazzy res4;
    res4 = A.div(B);
    std::cout << "A/B (если возможно): ";
    res4.write(std::cout);

    Fazzy res5;
    res5 = A.rev();
    std::cout << "A^-1 (если возможно): ";
    res5.write(std::cout);

    bool res6;
    res6 = A.is_more_then(B);
    std::cout << std::boolalpha;
    std::cout << "A > B (?): " << res6 << '\n';
    return 0;
}
