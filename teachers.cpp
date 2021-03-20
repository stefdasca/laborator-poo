#include "teachers.h"

void Teachers::add_teacher(std::string nume, std::string adresa)
{
    Profesor x(nume, adresa);
    profesori.push_back(x);
}

void Teachers::add_feedback(std::string feedback)
{
    feedback_lists.push_back(feedback);
}

void Teachers::detailed_feedback(int wh, std::string feedback)
{
    Profesor y = profesori[wh];
    y.add_feedback(feedback);
}

Profesor Teachers::getdata(int nr)
{
    return profesori[nr];
}

int Teachers::getstudent(std::string nume_elev)
{
    return elevi[nume_elev];
}
