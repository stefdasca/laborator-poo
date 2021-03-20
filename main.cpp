#include <iostream>
#include <vector>
#include "teachers.h"

int actions;

int main()
{
    std::cin >> actions;
    Teachers teacherlist;
    for(int i = 1; i <= actions; ++i)
    {
        int type;
        std::cin >> type;
        if(type == 0) // feedback general
        {
            std::string feedback;
            std::cin >> feedback;
            teacherlist.add_feedback(feedback);
        }
        if(type == 1) // feedback pentru un profesor
        {
            int wh;
            std::string feedback;
            std::cin >> wh >> feedback;
            teacherlist.detailed_feedback(wh, feedback);
        }
        if(type == 2) // nou profesor
        {
            std::string nume, adresa;
            std::cin >> nume >> adresa;
            teacherlist.add_teacher(nume, adresa);
        }
        if(type == 3) // nou elev
        {
            std::string nume;
            int clasa;
            int teacher;
            std::cin >> nume >> clasa >> teacher;
            Elev student(nume, clasa);
            Profesor pr = teacherlist.getdata(teacher);
            pr.add_elev(student);
        }
        if(type == 4) // nou algoritm 
        {
            std::string nume_algoritm, nume_elev;
            std::cin >> nume_elev >> nume_algoritm;
            int val = teacherlist.getstudent(nume_elev); 
            Profesor x = teacherlist.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            e.insertalgo(nume_algoritm);
        }
    }
    return 0;
}
