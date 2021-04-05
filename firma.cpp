#include "firma.h"

Firma::Firma()
{
    profesori.clear();
    feedback_lists.clear();
    elevi.clear();
    tasklist.clear();
}

Firma::Firma(const Firma &f)
{
    profesori = f.profesori;
    feedback_lists = f.feedback_lists;
    elevi = f.elevi;
    tasklist = f.tasklist;
}

Firma::Firma(std::vector<Profesor> a, std::vector<std::string> b, std::map<std::string, int> c, std::vector<Task> d)
{
    profesori = a;
    feedback_lists = b;
    elevi = c;
    tasklist = d;
}

Firma::~Firma()
{
    profesori.clear();
    feedback_lists.clear();
    elevi.clear();
}

Firma Firma::operator=(const Firma& firma)
{
    this -> profesori = firma.profesori;
    this -> feedback_lists = firma.feedback_lists;
    this -> elevi = firma.elevi;
    return &this;
}

std::ostream& operator<<(std::ostream& output, const Firma& Firma)
{
    output << "Lista profesori: " << '\n';
    for(int i = 0; i < (int) Firma.profesori.size(); ++i)
    {
        Profesor prof = Firma.profesori[i];
        output << prof.getname() << " ";
    }
    output << '\n';
    output << "Lista feedback: " << '\n';
    for(int i = 0; i < (int) Firma.feedback_lists.size(); ++i)
    {
        std::string feedback = Firma.feedback_lists[i];
        output << feedback << " ";
    }
    return &output;
}

void Firma::add_teacher(std::string nume, std::string adresa)
{
    Profesor x(nume, adresa);
    profesori.push_back(x);
}

void Firma::add_feedback(std::string feedback)
{
    feedback_lists.push_back(feedback);
}

void Firma::detailed_feedback(int wh, std::string feedback)
{
    Profesor y = profesori[wh-1];
    y.add_feedback(feedback);
    int val = y.rate_feedback(feedback);
    y.add_score(val);
}

Profesor Firma::getdata(int nr)
{
    return profesori[nr-1];
}

int Firma::getstudent(std::string nume_elev)
{
    return elevi[nume_elev];
}

void Firma::add_task(Task tsk)
{
    tasklist.push_back(tsk);
}
