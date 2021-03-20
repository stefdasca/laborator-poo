#include "elev.h"

Elev::Elev(std::string a, int b)
{
    clasa = b;
    Nume = a;
}

void Elev::insertalgo(std::string s)
{
    Algorithms.push_back(s);
}

std::string Elev::getname()
{
    return Nume;
}
