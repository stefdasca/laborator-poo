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
    this->link = a;
    this->problem_tags = b;
    this->difficulty = c;
    this->solution = d;
}

void Task::set_data(std::string a, std::vector<std::string> b, int c, std::string d)
{
    link = a;
    problem_tags = b;
    difficulty = c;
    solution = d;
}

Task Task::operator=(const Task& task)
{
    this->link = task.link;
    this->problem_tags = task.problem_tags;
    this->difficulty = task.difficulty;
    this->solution = task.solution;
    return *this;
}

Task::Task(const Task& task)
{
    link = task.link;
    problem_tags = task.problem_tags;
    difficulty = task.difficulty;
    solution = task.solution;
}


std::ostream& operator<<(std::ostream& output, const Task& task)
{
    output << "Link task: " << task.link << '\n';
    output << "Categorii: ";
    std::vector<std::string> s = task.problem_tags;
    for (auto tag : s)
    {
        output << tag << " ";
    }
    output << '\n';
    output << "Dificultate " << task.difficulty << '\n';
    output << "Link solutie " << task.solution << '\n';
    return output;
}



std::string Educational_Task::get_Help()
{
    return solution;
}

std::string Educational_Task::get_Hint(int nr)
{
    if(nr >= problem_tags.size())
        return "Nu exista atatea taguri";
    return problem_tags[nr];
}

int Task::getDifficulty() const {
    return difficulty;
}

void Task::setDifficulty(int difficulty) {
    Task::difficulty = difficulty;
}

Task::~Task() = default;

Educational_Task::~Educational_Task() = default;

void Task::add_difficulty(int val)
{
    int x = getDifficulty() + val;
    setDifficulty(x);
}

void Educational_Task::add_difficulty(int val)
{
    int x = getDifficulty() + val;
    setDifficulty(x);
}
