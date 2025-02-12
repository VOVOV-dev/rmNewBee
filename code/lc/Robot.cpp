#include "Robot.h"

using namespace std;

void Robot:: task_initialize()
{
    for (int i = 0; i < task_N; i++) // 初始化任务状态
    {
        task[i].initialize();

    }

    task_count = 0; // 初始化任务数量

}

void Robot:: taskInfo_output()
{
    for (int i = 0; i < task_count; i++) // 输出任务列表
    {
        cout << "任务ID: " << task[i].get_id()
             << " 描述: " << task[i].get_name()
             << " 状态: " << task[i].get_state() << endl;

    }

}

void Robot:: task_add()
{
    int temp_id;
    string temp;
    
    cin >> temp_id >> temp;

    task[task_count].set_id(temp_id); // 任务编号
    task[task_count].set_name(temp); // 任务名称

    task_count++; // 队列+1

}

void Robot:: task_exe()
{
    for (int i = 0; i < task_count; i++) // 执行任务
    {
        if (task[i].get_state() == "未执行")
        {
            task[i].set_state();
        } 

    }

}//asdfasdf

void Robot:: undo_output()
{
    for (int i = 0; i < task_count; i++) // 输出未执行任务
    {
        if (task[i].get_state() == "未执行")
        {
            cout << "未完成任务ID: " << task[i].get_id() 
                 << " 描述:" << task[i].get_name() << endl;

        }

    }

}

void Robot:: set_name(string temp)
{
    name = temp;
}