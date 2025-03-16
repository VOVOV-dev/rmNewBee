#include "Task_Manager.h"

#include <iostream>

void Task_Manager::check_out()
{
    while(true)
    {
        int val = out.exchange(0);

        if (val != 0)
        {
            printf("out:%d", val);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }
}

void Task_Manager::run()
{
    handler = std::thread(&Task_Manager::check_out, this);

    while(true)
    {
        std::string cmd;
        std::cin >> cmd;

        if(cmd == "add")
        {
            int key, kind;
            std::cin >> key >> kind;
            add_task(key, kind);
            printf("add finish");
        }
        else if(cmd == "callback")
        {
            int key, msg;
            std::cin >> key >> msg;
            callback(key, msg);
        }
        else if(cmd == "pop")
        {
            pop_task();

            printf("pop finish");
        }
    }
}

void Task_Manager::add_task(int key, int kind)
{
    auto p2 = a.empty() ? &out : a.back();
    a.push_back(new std::atomic<int>(0));
    auto p1 = a.back();

    Taskbase *p = nullptr;
    
    if(kind == 1)
    {
        p = new Task1(key, p1, p2);
    }
    else if(kind == 2)
    {
        p = new Task2(key, p1, p2);
    }
    else if(kind == 3)
    {
        p = new Task3(key, p1, p2);
    }

    task_list.push_back(p);
    task_map[key] = p;

    p->start();

}

void Task_Manager::pop_task()
{
    auto p = task_list.back();

    task_list.pop_back();   
    p -> stop();
    task_map.erase(p->key);

    delete a.back();
    a.pop_back();

    delete p;

}

void Task_Manager::callback(int key, int msg)
{
    if(task_map.count(key))
    {
        task_map[key] -> callback(msg);
    }
    else
    {
        printf("invalid key: %d", key);
    }
}