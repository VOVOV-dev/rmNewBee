#include "Robot.h"

using namespace std;

int main()
{
    Robot robot;

    string command;

    cout << "机器人命名：" << endl;// 机器人命名
    string temp; 
    cin >> temp;
    robot.set_name(temp);

    robot.task_initialize(); //初始化

    while(true)
    {
        cin >> command; //命令

        if (command == "添加")
        {
            robot.task_add();
        }
        else if (command == "执行")
        {
            robot.task_exe();
        }
        else if (command == "显示")
        {
            robot.taskInfo_output();
        }
        else if (command == "退出")
        {
            robot.undo_output();

            break;
            
        }
        else 
        {
            cout << "无效命令" << endl;
        }

            
    }

    return 0;

}

