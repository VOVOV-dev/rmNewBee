#include "Robot.h"
#include <map>

class TaskScheduler
{
    private:
        std::map<std::string,Robot> robot_task_list; // 机器人列表
        int robot_count = 0; // 当前列表中机器人数量

    public:
        void robot_taskInfo_output();
        void robot_add();
        void robot_delete();
        void robot_task_add();
        void robot_task_delete();
        void robot_task_exe();
        void get_robot_list();

        TaskScheduler();

};