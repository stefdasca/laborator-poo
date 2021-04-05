#include "firma.h"

Firma::Firma()
{
    profesori.clear();
    feedback_lists.clear();
    elevi.clear();
    positions.clear();
    tasklist.clear();
}

Firma::Firma(const Firma& f)
{
    profesori = f.profesori;
    feedback_lists = f.feedback_lists;
    elevi = f.elevi;
    positions = f.positions;
    tasklist = f.tasklist;
}

Firma::Firma(std::vector<Profesor> a, std::vector<std::string> b, std::vector<Elev> c, std::map<std::string, int> x, std::vector<Task> d)
{
    profesori = a;
    feedback_lists = b;
    elevi = c;
    positions = x;
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
    this->profesori = firma.profesori;
    this->feedback_lists = firma.feedback_lists;
    this->elevi = firma.elevi;
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Firma& Firma)
{
    output << "Lista profesori: " << '\n';
    for (int i = 0; i < (int)Firma.profesori.size(); ++i)
    {
        Profesor prof = Firma.profesori[i];
        output << prof.getname() << " ";
    }
    output << '\n';
    output << "Lista feedback: " << '\n';
    for (int i = 0; i < (int)Firma.feedback_lists.size(); ++i)
    {
        std::string feedback = Firma.feedback_lists[i];
        output << feedback << " ";
    }
    return output;
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
    Profesor y = profesori[wh - 1];
    y.add_feedback(feedback);
    int val = y.rate_feedback(feedback);
    y.add_score(val);
}

Profesor Firma::getdata(int nr)
{
    return profesori[nr - 1];
}

Elev Firma::getstudent(std::string nume_elev)
{
    return elevi[positions[nume_elev]];
}

int Firma::find_position(std::string nume_elev)
{
    return positions[nume_elev];
}

void Firma::add_task(Task tsk)
{
    tasklist.push_back(tsk);
}

void Firma::add_student(Elev e)
{
    elevi.push_back(e);
    positions[e.getname()] = (int) elevi.size() - 1;
}

void Firma::modify_position(int poz, Elev e)
{
    elevi[poz] = e;
}
