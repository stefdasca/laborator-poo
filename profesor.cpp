#include "profesor.h"

Profesor::Profesor(std::string b, std::string c)
{
    nr_elevi = 0;
    cnt_feedbacks = 0;
    score_feedbacks = 0;
    nume = b;
    adresa = c;
    elevi.clear();
    feedback.clear();
    link.clear();
}

Profesor::Profesor()
{
    nr_elevi = 0;
    cnt_feedbacks = 0;
    score_feedbacks = 0;
    nume = "";
    adresa = "";
    elevi.clear();
    feedback.clear();
    link.clear();
}

Profesor::~Profesor()
{
    nr_elevi = 0;
    cnt_feedbacks = 0;
    score_feedbacks = 0;
    nume = "";
    adresa = "";
    elevi.clear();
    feedback.clear();
    link.clear();
}

Profesor::Profesor(const Profesor& profesor)
{
    nr_elevi = profesor.nr_elevi;
    nume = profesor.nume;
    adresa = profesor.adresa;
    elevi = profesor.elevi;
    feedback = profesor.feedback;
    link = profesor.link;
    cnt_feedbacks = profesor.cnt_feedbacks;
    score_feedbacks = profesor.score_feedbacks;
}

Profesor Profesor::operator=(const Profesor& profesor)
{
    this->nr_elevi = profesor.nr_elevi;
    this->nume = profesor.nume;
    this->adresa = profesor.adresa;
    this->elevi = profesor.elevi;
    this->feedback = profesor.feedback;
    this->link = profesor.link;
    this->cnt_feedbacks = profesor.cnt_feedbacks;
    this->score_feedbacks = profesor.score_feedbacks;
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Profesor& profesor)
{
    output << "Nume profesor: " << profesor.nume << '\n';
    output << "Profesorul a indrumat " << profesor.nr_elevi << " elevi" << '\n';
    return output;
}

void Profesor::add_feedback(std::string s)
{
    feedback.push_back(s);
}

void Profesor::add_elev(int x)
{
    elevi.push_back(x);
}

int Profesor::get_link(std::string nume_elev)
{
    if(link.find(nume_elev) == link.end())
        return -1;
    return link[nume_elev];
}


std::string Profesor::get_name()
{
    return this->nume;
}


int Profesor::rate_feedback(std::string s) // un scor bazat pe cuvintele ce apar in sir
{
    int scor = 0;
    std::map<std::string, int> cuvinte;
    cuvinte["bun"] = 1; cuvinte["excelent"] = 2; cuvinte["clare"] = 1; cuvinte["dedicat"] = 2; cuvinte["activ"] = 1; cuvinte["punctual"] = 1;
    cuvinte["foarte bun"] = 1; cuvinte["organizat"] = 1; cuvinte["adaptabil"] = 1; cuvinte["calitate"] = 1; cuvinte["slab"] = -1;
    cuvinte["serios"] = 1; cuvinte["neserios"] = -2; cuvinte["multumit"] = 1; cuvinte["nemultumit"] = -2;
    cuvinte["implicat"] = 1; cuvinte["neimplicat"] = -2; cuvinte["lipsa"] = -1; cuvinte["dezinteresat"] = -2;
    cuvinte["neclare"] = -2; cuvinte["calm"] = 1;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        std::string x;
        for (int j = i; j < (int)s.size(); ++j)
        {
            x += s[j];
            if (cuvinte.find(x) != cuvinte.end())
                scor += cuvinte[x];
        }
    }
    return scor;
}

void Profesor::add_score(int val)
{
    this->cnt_feedbacks++;
    this->score_feedbacks += val;
}
