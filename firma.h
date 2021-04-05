#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "elev.h"
#include "profesor.h"
#include "task.h"

class Firma
{

    std::vector<Profesor> profesori;
    std::vector<std::string> feedback_lists;
    std::vector<Elev> elevi;
    std::map<std::string, int> positions;
    std::vector<Task> tasklist;

public:
    Firma();
    Firma(std::vector<Profesor> a, std::vector<std::string> b, std::vector<Elev> c, std::map<std::string, int> x, std::vector<Task> d);
    ~Firma();
    Firma(const Firma& f);

    friend std::ostream& operator<<(std::ostream& output, const Firma& firma);
    Firma operator=(const Firma& firma);

    void add_feedback(std::string feedback);
    void detailed_feedback(int wh, std::string feedback);
    void add_teacher(std::string nume, std::string adresa);
    Profesor getdata(int nr);
    Elev getstudent(std::string nume_elev);
    void add_task(Task tsk);
    void add_student(Elev e);
    int find_position(std::string nume_elev);
    void modify_position(int poz, Elev e);
};
