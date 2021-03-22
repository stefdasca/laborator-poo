#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "profesor.h"
#include "task.h"

class Firma
{

    std::vector<Profesor> profesori;
    std::vector<std::string> feedback_lists;
    std::map<std::string, int> elevi;
    std::vector<Task> tasklist;

    public:
        Firma();
        Firma(std::vector<Profesor> a, std::vector<std::string> b, std::map<std::string, int> c, std::vector<Task> d);
        ~Firma();
        
        friend std::ostream& operator<<(std::ostream& output, const Firma& firma);
        Firma operator=(const Firma& firma);

        void add_feedback(std::string feedback);
        void detailed_feedback(int wh, std::string feedback);
        void add_teacher(std::string nume, std::string adresa);
        Profesor getdata(int nr);
        int getstudent(std::string nume_elev);
        void add_task(Task tsk);
};
