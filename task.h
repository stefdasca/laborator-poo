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
    Task(const Task& t);

    friend std::ostream& operator<<(std::ostream& output, const Task& task);
    Task operator=(const Task& task);
    void set_data(std::string a, std::vector<std::string> b, int c, std::string d);
    virtual void tip_problema() const;
    virtual void add_difficulty(int nr);
    virtual ~Task();
};

class Educational_Task : public Task
{
public:
    std::string get_Hint(int nr);
    std::string get_Help();
    void tip_problema() const override;
    void add_difficulty(int nr) override;
    ~Educational_Task() override;
};
