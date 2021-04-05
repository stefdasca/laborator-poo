#include "elev.h"

Elev::Elev(std::string a, int b, std::string c)
{
    Profesor = c;
    clasa = b;
    Nume = a;
    Algorithms.clear();
    Problems = 0;
    tasks.clear();
}

Elev::Elev()
{
    Nume = "";
    Profesor = "";
    clasa = 0;
    Algorithms.clear();
    Problems = 0;
    tasks.clear(); 
}

Elev::~Elev()
{
    Nume = "";
    Profesor = "";
    clasa = 0;
    Algorithms.clear();
    Problems = 0;
    tasks.clear();
}

Elev::Elev(const Elev& elev)
{
    Nume = elev.Nume;
    clasa = elev.clasa;
    Profesor = elev.Profesor;
    Algorithms = elev.Algorithms;
    Problems = elev.Problems;
    tasks = elev.tasks;
}

Elev Elev::operator=(const Elev& elev)
{
    this->Nume = elev.Nume;
    this->clasa = elev.clasa;
    this->Profesor = elev.Profesor;
    this->Algorithms = elev.Algorithms;
    this->Problems = elev.Problems;
    this->tasks = elev.tasks;
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Elev& elev)
{
    output << "Nume elev: " << elev.Nume << '\n';
    output << "clasa: " << elev.clasa << '\n';
    output << "Profesor indrumator: " << elev.Profesor << '\n';
    output << "Elevul a invatat " << elev.Algorithms.size() << " algoritmi si tehnici" << '\n';
    output << "Elevul a rezolvat " << elev.Problems << " probleme" << '\n';
    return output;
}

void Elev::insertalgo(std::string s)
{
    Algorithms.push_back(s);
}

void Elev::inserttask(int p)
{
    this->tasks.insert(p);
}

void Elev::solvedtask(int p)
{
    this->tasks.erase(p);
}

std::string Elev::getname()
{
    return Nume;
}


int Elev::get_score()
{
    return Problems;
}
void Elev::update_score(int val)
{
    Problems = val;
}
