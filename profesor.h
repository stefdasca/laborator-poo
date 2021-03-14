#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "elev.h"

class Profesor 
{
    public:

    int nr_elevi;
    std::string nume, adresa;
    std::vector<Elev> elevi;
    std::vector<std::string> feedback;
    std::map<std::string, int> link;

    Profesor(std::string b, std::string c)
    {
        nr_elevi = 0;
        nume = b;
        adresa = c;
    }
    void add_feedback(std::string s)
    {
        feedback.push_back(s);
    }
    void add_elev(Elev e)
    {
        elevi.push_back(e);
        link[e.Nume] = elevi.size() - 1;
    }
};
