#include "Robot.h"

using namespace std;

Task:: Task(int temp_id, string temp_name, int temp_priority)
{
    id = temp_id;

    priority = temp_priority;

    name = temp_name;

    state = "未执行";

}

int Task:: get_id() const
{
    return id;
}

void Task:: set_id(int temp)
{
    id = temp;
}

string Task:: get_name() const
{
    return name;
}

void Task:: set_name(string temp)
{
    name = temp;
}

string Task:: get_state() const
{
    return state;
}

void Task:: set_state()
{
    state = "已执行";
}

int Task:: get_priority() const 
{
    return priority;
}

void Task:: set_priority(int temp)
{
    priority = temp;
}