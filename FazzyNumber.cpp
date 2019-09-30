#include <iostream>
#include <cassert>
#include "FazzyNumber.h"
  

Fazzy::Fazzy(double l, double r)
{
    if (l <= r) {
        this->l = l;
        this->r = r;
    } else {
        this->l = r;
        this->r = l;
    }
}


Fazzy::Fazzy()
{
    this->l = 0;
    this->r = 0;
}

Fazzy Fazzy::plus(const Fazzy& A)
{
    Fazzy res;
    res.l = this->l + A.l;
    res.r = this->r + A.r;
    return res;
}

Fazzy Fazzy::minus(const Fazzy& A)
{
    Fazzy res;
    res.l = this->l - A.r;
    res.r = this->r - A.l;
    return res;
}

Fazzy Fazzy::mult(const Fazzy& A)
{
    Fazzy res;
    double max, min, tmp[4];
    tmp[0] = this->l * A.l;
    tmp[1] = this->l * A.r;
    tmp[2] = this->r * A.l;
    tmp[3] = this->r * A.r;
    max = tmp[0];
    min = tmp[3];
    for (int i = 1; i < 4; i++)
    {
        if (tmp[i] > max) max = tmp[i];
        if (tmp[3-i] < min) min = tmp[3-i];
    }
    res.l = min;
    res.r = max;
    return res;
}

Fazzy Fazzy::div(const Fazzy& A)
{
    if (A.l * A.r > 0) {
        Fazzy res;
        double max, min, tmp[4];
        tmp[0] = this->l / A.l;
        tmp[1] = this->l / A.r;
        tmp[2] = this->r / A.l;
        tmp[3] = this->r / A.r;
        max = tmp[0];
        min = tmp[3];
        for (int i = 1; i < 4; i++)
        {
            if (tmp[i] > max) max = tmp[i];
            if (tmp[3-i] < min) min = tmp[3-i];
        }
        res.l = min;
        res.r = max;
        return res;
    } else assert(0);
}

Fazzy Fazzy::rev()
{
    if (this->l * this->r > 0)
        {
            Fazzy res;
            res.l = 1/this->r;
            res.r = 1/this->l;
            return res;
        } else assert(0);
}

bool Fazzy::is_more_then(const Fazzy& A)
{
    double mid1, mid2;
    mid1 = this->l + (this->r - this->l) / 2;
    mid2 = A.l + (A.r - A.l) / 2;
    return mid1 > mid2;
}

void Fazzy::write(std::ostream& os) const
{
  os << "[" << this->l << "; " << this->r << "]" << '\n';
}

  
