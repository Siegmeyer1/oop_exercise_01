#ifndef _FAZZY_H_
#define _FAZZY_H_


class Fazzy {
private:
    double l;
    double r;
public:
    Fazzy(double, double);
    Fazzy();
    Fazzy plus(const Fazzy&);
    Fazzy minus(const Fazzy&);
    Fazzy mult(const Fazzy&);
    Fazzy div(const Fazzy&);
    Fazzy rev();
    bool is_more_then(const Fazzy&);
    void write(std::ostream& os) const;
};


#endif
