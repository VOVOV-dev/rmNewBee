#include<iostream>

class Task 
{
    private:
        int id = 0; // 任务id
        std:: string name; // 任务名称
        std:: string state; // 任务状态 
        
    public: 
        void initialize();

        int get_id();
        void set_id(int temp);

        std:: string get_name();
        void set_name(std:: string temp);

        std:: string get_state();
        void set_state();

};