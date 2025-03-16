#pragma once

#include "Task.h"
#include <atomic>
#include <vector>
#include <thread>
#include <chrono>
#include <map>

class Task_Manager
{
    public:
        std::atomic<int> out = 0;
        std::vector<std::atomic<int>*> a;
        std::vector<Taskbase*> task_list;
        std::map<int, Taskbase*> task_map;
        std::thread handler;
    
        void check_out();
        void run();

        void add_task(int key, int kind);
        void pop_task();
        void callback(int key, int msg);
    
};