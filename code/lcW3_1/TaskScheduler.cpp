#include "TaskScheduler.h"



void TaskScheduler:: robot_taskInfo_output()
{
    std::string temp; //获取查询的机器人名称

    std::cin >> temp;

    robot_task_list[temp].taskInfo_output(); // 输出任务列表

}

void TaskScheduler:: robot_add()
{
    std::string temp; //暂存机器人名称

    std::cin >> temp;

    robot_task_list.insert(std::pair<std::string,Robot>(temp,Robot())); // 插入机器人

    robot_task_list[temp].set_name(temp); // 设置机器人名称

    robot_count++; // 机器人数量+1

}

void TaskScheduler:: robot_delete()
{
    std::string temp; //要删除机器人名称

    std::cin >> temp;

    robot_task_list.erase(temp); // 删除机器人

    robot_count--; // 机器人数量-1

}

void TaskScheduler:: robot_task_add()
{
    std::string temp; //添加任务机器人名称

    std::cin >> temp;

    robot_task_list[temp].task_add(); // 添加任务

}

void TaskScheduler:: robot_task_delete()
{
    std::string temp; //删除任务的机器人名称

    std::cin >> temp;

    robot_task_list[temp].task_delete(); // 删除任务

} 

void TaskScheduler:: robot_task_exe()
{
    std::string temp; //执行任务机器人名称

    std::cin >> temp;

    robot_task_list[temp].task_exe(); // 执行任务
    
}

void TaskScheduler:: get_robot_list()
{
    std::map<std::string,Robot>::iterator it; // 迭代器

    for (it = robot_task_list.begin(); it != robot_task_list.end(); it++) // 输出机器人列表
    {
        std::cout << it->first << std::endl;
    }

}

TaskScheduler::TaskScheduler()
{
    robot_count = 0;
}

