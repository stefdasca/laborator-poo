#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "profesor.h"

class Teachers
{

    std::vector<Profesor> profesori;
    std::vector<std::string> feedback_lists;
    std::map<std::string, int> elevi;
    public:
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
        Profesor getdata(int nr)
        {
            return profesori[nr];
        }
        int getstudent(std::string nume_elev)
        {
            return elevi[nume_elev];
        }
};
