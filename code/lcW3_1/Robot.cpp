#include "TaskScheduler.h"

using namespace std;

Robot::Robot()
{
    task_count = 0; // 初始化任务数量
}

void Robot:: taskInfo_output()
{
    for (int i = 0; i < task_count; i++) // 输出任务列表
    {
        cout << "机器人：" << name
             << "任务ID: " << task.at(i).get_id()
             << " 描述: " << task.at(i).get_name()
             << " 状态: " << task.at(i).get_state() << endl;

    }

}

void Robot:: task_add()
{
    int temp_id;
    string temp;
    
    cin >> temp_id >> temp;

    task.push_back(Task());
    task.at(task_count).set_id(temp_id); // 任务编号
    task.at(task_count).set_name(temp); // 任务名称
    task.at(task_count).initialize(); // 任务状态

    task_count++; // 队列+1

}

void Robot:: task_exe()
{
    for (int i = 0; i < task_count; i++) // 执行任务
    {
        if (task.at(i).get_state() == "未执行")
        {
            task.at(i).set_state();
        }

    }

}


Robot::~Robot()
{
    for (int i = 0; i < task_count; i++) // 输出未执行任务
    {
        if (task.at(i).get_state() == "未执行") // 输出未执行任务
        {
            cout << "机器人: " << name
                 << "未完成任务ID: " << task.at(i).get_id()
                 << " 描述:" << task.at(i).get_name() << endl;

        }

    }
}

void Robot:: set_name(string temp)
{
    name = temp;
}

void Robot:: task_delete()
{
    task.pop_back();

    task_count--;

    cout << "已删除" << endl; 

}