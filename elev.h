#include <iostream>
#include <vector>
#include <string>
#include <set>

class Elev
{
    std::string Nume;
    int clasa;
    std::string Profesor;
    std::vector<std::string> Algorithms;
    int Problems;
    std::set<int> tasks;

public:
    Elev();
    Elev(std::string a, int b, std::string c);
    ~Elev();
    Elev(const Elev& e);

    friend std::ostream& operator<<(std::ostream& output, const Elev& elev);
    Elev operator=(const Elev& elev);

    void insertalgo(std::string s);
    void inserttask(int p);
    void solvedtask(int p);
    int get_score();
    void update_score(int val);
    std::string getname();
};
