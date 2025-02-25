#include "task.h"
#include <vector>


class Robot 
{
    private:
        std::string name; // 机器人名称
        std::vector<Task> task; // 任务列表
        int task_count = 0; //当前列表中任务数量
    
    public:
        void task_initialize();
        void taskInfo_output();
        void task_add();
        void task_delete();
        void task_exe();
        void undo_output();
        void set_name(std::string temp);

        Robot();
        ~Robot(); 
        
};