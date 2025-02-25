#include "TaskScheduler.h"

using namespace std;

Robot::Robot()
{
    task_count = 0; // 初始化任务数量
}

void Robot:: taskInfo_output()
{
    for ( const auto& t : task) // 遍历set
    { 
        cout << "机器人：" << name
             << " 任务ID: " << t.get_id()
             << " 描述: " << t.get_name()
             << " 状态: " << t.get_state() 
             << " 优先级:" << t.get_priority() <<endl;
    }

}

void Robot:: task_add()
{
    int temp_id;
    int temp_priority;
    string temp_name;
    
    cin >> temp_id >> temp_name >> temp_priority;

    Task t = Task(temp_id, temp_name, temp_priority);

    auto result = task.insert(t);
    
    if (result.second) 
    { 
        cout << "任务已成功添加" << endl;
    } 
    else 
    {
        cout << "任务插入失败：任务已存在或优先级冲突" << endl;
    }
    
}

void Robot:: task_exe()
{
    for ( const auto& t : task) // 遍历set
    { 
        if(t.get_state() == "未执行")
        {
            int temp_id = t.get_id();
            string temp_name = t.get_name();
            int temp_priority = t.get_priority();

            Task t = Task(temp_id, temp_name, temp_priority);

            t.set_state();

            task.erase(t);

            task.insert(t);

            cout << "机器人: " << name
                << " 执行任务ID: " << t.get_id()
                << " 描述:" << t.get_name() << endl;

            break;
            
        }
        
    }

}


Robot::~Robot()
{
    for ( auto& t : task) // 遍历set
    { 
        cout << "机器人: " << name
                << "未完成任务ID: " << t.get_id()
                << " 描述:" << t.get_name() << endl;

    }
}

void Robot:: set_name(string temp)
{
    name = temp;
}

void Robot:: task_delete()
{
    auto last_it = task.rbegin(); // 获取指向最后一个元素的反向迭代器

    task.erase((++last_it).base()); // 将反向迭代器转换为正向迭代器并删除最后一个元素

    cout << "已删除" << endl; 

}