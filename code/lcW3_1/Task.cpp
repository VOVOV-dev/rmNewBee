#include "Robot.h"

using namespace std;

void Task:: initialize()
{
    state = "未执行";
}

int Task:: get_id()
{
    return id;
}

void Task:: set_id(int temp)
{
    id = temp;
}

string Task:: get_name()
{
    return name;
}

void Task:: set_name(string temp)
{
    name = temp;
}

string Task:: get_state()
{
    return state;
}

void Task:: set_state()
{
    state = "已执行";
}
