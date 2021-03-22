#include "task.h"

Task::Task()
{
    link = "";
    problem_tags.clear();
    difficulty = 0;
    solution = "";
}

Task::Task(std::string a, std::vector<std::string> b, int c, std::string d)
{
    this -> link = a;
    this -> problem_tags = b;
    this -> difficulty = c;
    this -> solution = d;
}

Task::~Task()
{
    link = "";
    problem_tags.clear();
    difficulty = 0;
    solution = "";
}

Task Task::operator=(const Task& task)
{
    this -> link = task.link;
    this -> problem_tags = task.problem_tags;
    this -> difficulty = task.difficulty;
    this -> solution = task.solution;
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Task& task)
{
    output << "Link task: " << task.link << '\n';
    output << "Categorii: ";
    std::vector<std::string> s = task.problem_tags;
    for(auto tag : s)
    {
        output << tag << " ";
    }
    output << '\n';
    output << "Dificultate " << task.difficulty << '\n';
    output << "Link solutie " << task.solution << '\n';
}