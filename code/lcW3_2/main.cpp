#include "TaskScheduler.h"

using namespace std;

int main()
{
    TaskScheduler taskScheduler;

    string command;

    while(true)
    {
        cin >> command; //命令

        if (command == "添加机器人")
        {
            taskScheduler.robot_add();
        }
        else if (command == "删除机器人")
        {
            taskScheduler.robot_delete();
        }
        else if (command == "添加任务")
        {
            taskScheduler.robot_task_add();
        }
        else if (command == "删除任务")
        {
            taskScheduler.robot_task_delete();
        }
        else if (command == "执行任务")
        {
            taskScheduler.robot_task_exe();
        }
        else if (command == "查询任务")
        {
            taskScheduler.robot_taskInfo_output();
        }
        else if (command == "获取机器人列表")
        {
            taskScheduler.get_robot_list();
        }
        else if (command == "退出")
        {
            break;
        }
        else 
        {
            break;
        }
            
    }

    return 0;

}

