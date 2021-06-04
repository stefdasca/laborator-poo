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
    type = 8: se primeste numarul de ordine al unui elev si se afiseaza informatiile despre elev
    type = 9: se primesc detaliile unei probleme la care un elev are nevoie de ajutor
    type = 10: se primesc detaliile unei probleme si se adauga un scor de dificultate
    type = 11: se creeaza un task sablon
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

    int cnt_student = 0;
    for (int i = 1; i <= actions; ++i)
    {
        int type;
        f >> type;
        if (type == 0) // feedback general
        {
            std::string feedback;
            f >> feedback;
            company.add_feedback(feedback);
        }
        if (type == 1) // feedback pentru un profesor
        {
            int wh;
            std::string feedback;
            f >> wh >> feedback;
            company.detailed_feedback(wh, feedback);
        }
        if (type == 2) // nou profesor
        {
            std::string nume, adresa;
            f >> nume >> adresa;
            company.add_teacher(nume, adresa);
        }
        if (type == 3) // nou elev
        {
            std::string nume;
            int clasa;
            int teacher;
            f >> nume >> clasa >> teacher;
            try
            {
                Profesor pr = company.get_data(teacher);
                Elev student(nume, clasa, pr.get_name());
                ++cnt_student;
                pr.add_elev(cnt_student);
                company.add_student(student);
            }
            catch(std::length_error &err)
            {
                std::cout << err.what() << std::endl;
            }
        }
        if (type == 4) // nou algoritm 
        {
            std::string nume_algoritm, nume_elev;
            f >> nume_elev >> nume_algoritm;
            try
            {
                Elev e = company.get_student(nume_elev);
                e.insert_algo(nume_algoritm);
            }
            catch(std::length_error &err)
            {
                std::cout << err.what() << std::endl;
            }
        }
        if (type == 5) // nou task
        {
            std::string task_name;
            f >> task_name;
            int cnt_tags;
            f >> cnt_tags;
            std::vector<std::string> tags(cnt_tags);
            for (int x = 0; x < cnt_tags; ++x)
                f >> tags[x];
            int difficulty;
            f >> difficulty;
            std::string solution;
            f >> solution;
            int tip;
            f >> tip;
            if (tip == 0)
            {
                Task problema(task_name, tags, difficulty, solution);
                company.add_task(problema);
            }
            else
            {
                Educational_Task problema;
                problema.set_data(task_name, tags, difficulty, solution);
                company.add_edu_task(problema);
                std::cout << problema.get_Help() << '\n';
            }
        }
        if (type == 6) // tema noua
        {
            std::string nume_elev;
            int task_number;
            f >> nume_elev >> task_number;
            Elev e = company.get_student(nume_elev);
            e.insert_task(task_number);
        }

        if (type == 7) // un elev a rezolvat o problema
        {
            std::string nume_elev;
            int task_number;
            f >> nume_elev >> task_number;
            Elev e = company.get_student(nume_elev);
            e.solved_task(task_number);
            e.update_score(e.get_score() + 1);
            int poz = company.find_position(nume_elev);
            if(poz != -1)
                company.modify_position(poz, e);
        }
        if (type == 8) // afisam informatiile despre un elev
        {
            std::string nume_elev;
            f >> nume_elev;
            Elev e = company.get_student(nume_elev);
            std::cout << e << std::endl;
        }

        if (type == 9) // un elev are nevoie de hint
        {
            std::string nume_elev;
            int task_number;
            f >> nume_elev >> task_number;
            Elev e = company.get_student(nume_elev);
            try
            {
                Educational_Task tsk = company.get_edu_task(task_number);
                std::string help_hand = tsk.get_Hint(0);
                e.insert_algo(help_hand);
            }
            catch(std::length_error &err)
            {
                std::cout << err.what() << std::endl;
            }
        }
        if (type == 10) // dificultate
        {
            int tip, position, value;
            f >> tip >> position >> value;
            try
            {
                company.add_difficulty(tip, position, value);
            }
            catch(std::length_error &err)
            {
                std::cout << err.what() << std::endl;
            }
        }
        if(type == 11) 
        {
            int tip;
            f >> tip;
            if(tip == 1)
            {
                Task t = task_template::easy_task();
                company.add_task(t);
            }
            if(tip == 2)
            {
                Task t = task_template::medium_task();
                company.add_task(t);
            }
            if(tip == 3)
            {
                Task t = task_template::hard_task();
                company.add_task(t);
            }
        }

    }
    return 0;
}
