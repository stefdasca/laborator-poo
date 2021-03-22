#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "elev.h"

class Profesor 
{

    int nr_elevi;
    int cnt_feedbacks;
    int score_feedbacks;
    std::string nume, adresa;
    std::vector<Elev> elevi;
    std::vector<std::string> feedback;
    std::map<std::string, int> link;

    public:
        Profesor(std::string b, std::string c);
        ~Profesor();
        
        friend std::ostream& operator<<(std::ostream& output, const Profesor& profesor);
        Profesor operator=(const Profesor& Profesor);

        void add_feedback(std::string s);
        void add_elev(Elev e);
        int getlink(std::string nume_elev);
        Elev getstudent(int poz);
        std::string getname();
        int rate_feedback(std::string s);
        void add_score(int val);

};
