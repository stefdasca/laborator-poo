#include <iostream>
#include <vector>
#include <string>
#include <map>

class Profesor
{

    int nr_elevi;
    int cnt_feedbacks;
    int score_feedbacks;
    std::string nume, adresa;
    std::vector<int> elevi;
    std::vector<std::string> feedback;
    std::map<std::string, int> link;

public:
    Profesor(std::string b, std::string c);
    ~Profesor();
    Profesor();
    Profesor(const Profesor& prof);

    friend std::ostream& operator<<(std::ostream& output, const Profesor& profesor);
    Profesor operator=(const Profesor& Profesor);

    void add_feedback(std::string s);
    void add_elev(int e);
    int get_link(std::string nume_elev);
    std::string get_name();
    int rate_feedback(std::string s);
    void add_score(int val);

};
