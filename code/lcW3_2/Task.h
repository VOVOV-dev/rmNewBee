#include<iostream>

class Task 
{
    private:
        int id = 0; // 任务id
        int priority = 0; // 任务优先级
        std:: string name; // 任务名称
        std:: string state; // 任务状态 

        
    public: 
        Task(int temp_id, std:: string temp_name, int temp_priority);

        int get_id() const;
        void set_id(int temp);

        std:: string get_name() const;
        void set_name(std:: string temp);

        std:: string get_state() const;
        void set_state();

        int get_priority() const;
        void set_priority(int temp);
    
    bool operator < (const Task& other) const
    {
        return this->priority < other.priority;
    }    

};