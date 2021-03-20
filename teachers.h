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
        void add_feedback(std::string feedback);
        void detailed_feedback(int wh, std::string feedback);
        void add_teacher(std::string nume, std::string adresa);
        Profesor getdata(int nr);
        int getstudent(std::string nume_elev);
};
