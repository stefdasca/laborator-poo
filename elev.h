#include <iostream>
#include <vector>
#include <string>

class Elev
{
    std::string Nume;
    int clasa;
    std::vector<std::string> Algorithms, Problems;

    public:
        Elev(std::string a, int b)
        {
            clasa = b;
            Nume = a;
        }
        void insertalgo(std::string s)
        {
            Algorithms.push_back(s);
        }
        std::string getname()
        {
            return Nume;
        }
};

