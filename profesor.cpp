#include "profesor.h"

Profesor::Profesor(std::string b, std::string c)
{
    nr_elevi = 0;
    nume = b;
    adresa = c;
}

void Profesor::add_feedback(std::string s)
{
    feedback.push_back(s);
}

void Profesor::add_elev(Elev e)
{
    elevi.push_back(e);
    std::string x = e.getname();
    link[x] = elevi.size() - 1;
}

int Profesor::getlink(std::string nume_elev)
{
    return link[nume_elev];
}

Elev Profesor::getstudent(int poz)
{
    return elevi[poz];
}
