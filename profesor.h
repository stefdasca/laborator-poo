#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "elev.h"

class Profesor 
{

    int nr_elevi;
    std::string nume, adresa;
    std::vector<Elev> elevi;
    std::vector<std::string> feedback;
    std::map<std::string, int> link;

    public:
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
            std::string x = e.getname();
            link[x] = elevi.size() - 1;
        }
        int getlink(std::string nume_elev)
        {
            return link[nume_elev];
        }
        Elev getstudent(int poz)
        {
            return elevi[poz];
        }
};
