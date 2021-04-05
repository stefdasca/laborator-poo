/*
    Interfata profesor-elev

    Programul functioneaza preluand datele de intrare din fisierul date.in si prelucreaza datele de intrare, dupa cum urmeaza:

    type = 0: se primeste un feedback general si se adauga la lista de feedbackuri ale companiei
    type = 1: se primeste un feedback pentru un profesor si se adauga la lista de feedbackuri ale profesorului respectiv
    type = 2: se primesc detaliile unui profesor si se adauga profesorul in companie
    type = 3: se primesc detaliile unui elev si se adauga elevul in lista unui profesor
    type = 4: se primesc detaliile studierii unui algoritm de un elev si se adauga informatia in lista de algoritmi al elevului respectiv
    type = 5: se primesc detaliile unei probleme de rezolvat si se adauga problema pentru elevul respectiv
    type = 6: se primesc detaliile unei noi teme de rezolvat si se adauga tema pentru elevul respectiv
    type = 7: se primesc detaliile unei probleme care a fost rezolvata si se sterge problema pentru elevul respectiv
    type = 8: se afiseaza date despre un elev

*/

#include <iostream>
#include <vector>
#include <fstream>
#include "firma.h"


int main()
{
    std::ifstream f("date.in");
    std::ofstream g("date.out");

    int actions;
    f >> actions;
    Firma company;
    
    for(int i = 1; i <= actions; ++i)
    {
        int type;
        f >> type;
        if(type == 0) // feedback general
        {
            std::string feedback;
            f >> feedback;
            company.add_feedback(feedback);
        }
        if(type == 1) // feedback pentru un profesor
        {
            int wh;
            std::string feedback;
            f >> wh >> feedback;
            company.detailed_feedback(wh, feedback);
        }
        if(type == 2) // nou profesor
        {
            std::string nume, adresa;
            f >> nume >> adresa;
            company.add_teacher(nume, adresa);
        }
        if(type == 3) // nou elev
        {
            std::string nume;
            int clasa;
            int teacher;
            f >> nume >> clasa >> teacher;
            Profesor pr = company.getdata(teacher);
            Elev student(nume, clasa, pr.getname());
            pr.add_elev(student);
        }
        if(type == 4) // nou algoritm 
        {
            std::string nume_algoritm, nume_elev;
            f >> nume_elev >> nume_algoritm;
            int val = company.getstudent(nume_elev); 
            Profesor x = company.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            e.insertalgo(nume_algoritm);
        }
        if(type == 5) // nou task
        {
            std::string taskname;
            f >> taskname;
            int cnttags;
            f >> cnttags;
            std::vector<std::string> tags(cnttags);
            for(int x = 0; x < cnttags; ++x)
                f >> tags[x];
            int difficulty;
            f >> difficulty;
            std::string solution;
            f >> solution;
            Task problema(taskname, tags, difficulty, solution);
            company.add_task(problema);
        }
        if(type == 6) // tema noua
        {
            std::string nume_elev;
            int task_number;
            f >> nume_elev >> task_number;
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
            f >> nume_elev >> task_number;
            int val = company.getstudent(nume_elev); 
            Profesor x = company.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            e.solvedtask(task_number);
        }
        if(type == 8) // afisam informatiile despre un elev
        {
            std::string nume_elev;
            f >> nume_elev;
            int val = company.getstudent(nume_elev); 
            Profesor x = company.getdata(val);
            int poz = x.getlink(nume_elev);
            Elev e = x.getstudent(poz);
            g << e << endl;
        }
    }
    return 0;
}
