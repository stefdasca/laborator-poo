#include <iostream>
#include <vector>
#include <string>
#include <set>

class Task
{
protected:
    std::string link;
    std::vector<std::string> problem_tags;
    int difficulty;
    std::string solution;

public:

    Task();
    Task(std::string a, std::vector<std::string> b, int c, std::string d);
    ~Task();
    Task(const Task& t);

    friend std::ostream& operator<<(std::ostream& output, const Task& task);
    Task operator=(const Task& task);
    void setdata(std::string a, std::vector<std::string> b, int c, std::string d);
    virtual void tip_problema();

};

class EducationalTask : public Task
{
    public:
        std::string getHint(int nr);
        std::string getHelp();
        void tip_problema();
};
