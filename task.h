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
    virtual void add_difficulty(int nr);
    virtual ~Task();

    int getDifficulty() const;

    void setDifficulty(int difficulty);
};

class Educational_Task : public Task
{
public:
    std::string get_Hint(int nr);
    std::string get_Help();
    void add_difficulty(int nr) override;
    ~Educational_Task() override;
};

class task_template
{
public:
    static Task easy_task() {
        return Task("https://infoarena.ro/problema/adunare", {"implementare"}, 1, "https://infoarena.ro/job_detail/2167325?action=view-source");
    }
    static Task medium_task() {
        return Task("https://codeforces.com/contest/1152/problem/C", {"maths", "number theory"}, 5, "https://codeforces.com/contest/1152/submission/53259956");
    }
    static Task hard_task() {
        return Task("https://infoarena.ro/problema/pwca", {"mate", "dp"}, 9, "https://infoarena.ro/jc2021/solutii");
    }
};
