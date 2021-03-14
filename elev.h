#include <iostream>
#include <vector>
#include <string>

class Elev
{
    public:
        std::string Nume;
        int clasa;
        std::vector<std::string> Algorithms, Problems;

        Elev(std::string a, int b)
        {
            clasa = b;
            Nume = a;
        }
};

