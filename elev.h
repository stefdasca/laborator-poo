#include <iostream>
#include <vector>
#include <string>

class Elev
{
    std::string Nume;
    int clasa;
    std::vector<std::string> Algorithms, Problems;

    public:
        Elev(std::string a, int b);
        void insertalgo(std::string s);
        std::string getname();
};

