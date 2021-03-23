#include <iostream>
#include <vector>
#include "firma.h"

int actions;

int main()
{
    std::cin >> actions;
    Firma company;
    for(int i = 1; i <= actions; ++i)
    {
        int type;
        std::cin >> type;
        if(type == 0) // feedback general
        {
            std::string feedback;
            std::cin >> feedback;
            company.add_feedback(feedback);
        }
        if(type == 1) // feedback pentru un profesor
        {
            int wh;
            std::string feedback;
            std::cin >> wh >> feedback;
            company.detailed_feedback(wh, feedback);
        }
        if(type == 2) // nou profesor
        {
            std::string nume, adresa;
            std::cin >> nume >> adresa;
            company.add_teacher(nume, adresa);
        }
        if(type == 3) // nou elev
        {
            std::string nume;
            int clasa;
            int teacher;
            std::cin >> nume >> clasa >> teacher;
            Profesor pr = company.getdata(teacher);
            Elev student(nume, clasa, pr.getname());
            pr.add_elev(student);
        }
        if(type == 4) // nou algoritm 
        {
            std::string nume_algoritm, nume_elev;
            std::cin >> nume_elev >> nume_algoritm;
            int val = company.getstudent(nume_elev); 
            Profesor x = company.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            e.insertalgo(nume_algoritm);
        }
        if(type == 5) // nou task
        {
            std::string taskname;
            std::cin >> taskname;
            int cnttags;
            std::cin >> cnttags;
            std::vector<std::string> tags(cnttags);
            for(int x = 0; x < cnttags; ++x)
                std::cin >> tags[x];
            int difficulty;
            std::cin >> difficulty;
            std::string solution;
            std::cin >> solution;
            Task problema(taskname, tags, difficulty, solution);
            company.add_task(problema);
        }
        if(type == 6) // tema noua
        {
            std::string nume_elev;
            int task_number;
            std::cin >> nume_elev >> task_number;
            int val = company.getstudent(nume_elev); 
            Profesor x = company.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            e.inserttask(task_number);
        }

        if(type == 7) // un elev a rezolvat o problema
        {
            std::string nume_elev;
            int task_number;
            std::cin >> nume_elev >> task_number;
            int val = company.getstudent(nume_elev); 
            Profesor x = company.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            e.solvedtask(task_number);
        }
    }
    return 0;
}
