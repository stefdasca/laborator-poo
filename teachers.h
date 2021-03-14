#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "profesor.h"

class Teachers
{
    public:

    std::vector<Profesor> profesori;
    std::vector<std::string> feedback_lists;
    std::map<std::string, int> elevi;
    void add_feedback(std::string feedback)
    {
        feedback_lists.push_back(feedback);
    }
    void detailed_feedback(int wh, std::string feedback)
    {
        Profesor y = profesori[wh];
        y.add_feedback(feedback);
    }
    void add_teacher(std::string nume, std::string adresa)
    {
        Profesor x(nume, adresa);
        profesori.push_back(x);
    }
};
