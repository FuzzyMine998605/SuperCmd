#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <iostream>
#include "hash.h"
using namespace std;

string cmd;
string BadCmd = "Bad Command: ";

void check_noArg();
void check_Arg_Else();
void input();

void input()
{

    while (true)
    {
        printf("SuperCmd> ");
        /*输入提示
        Input prompt*/
        getline(cin, cmd);
        BadCmd.append(cmd);
        BadCmd.append(".");
        check_noArg();
    }
}
void check_noArg()
{
    /*不带参数的命令
    Command without parameters*/

    /*各种命令分别所需执行的操作
    Operations required for various commands*/
    switch (_hash(cmd.c_str()))
    {
    case _hash("cls"):
        system("cls");
        BadCmd = "Bad Command: ";
        /*每次输入后，需要将该变量重设，否则所有输入的内容都会在其中。下同。
        After each input, you need to reset the variable,
        otherwise all the input content will be in it. The same below.*/
        input();
        break;
    case _hash("shutdown"):
        system("shutdown -s -t 0");
        BadCmd = "Bad Command: ";
        break;
    case _hash("reboot"):
        system("shutdown -r -t 0");
        BadCmd = "Bad Command: ";
        break;
    case _hash("notepad"):
        system("start notepad");
        BadCmd = "Bad Command: ";
        break;
    case _hash("mspaint"):
        system("start mspaint");
        BadCmd = "Bad Command: ";
        break;
    case _hash("calc"):
        system("start calc");
        BadCmd = "Bad Command: ";
        break;

    // TODO: 添加其他命令的处理
    default:
        // BadCmd = "Bad Command: ";
        check_Arg_Else();
    }

    // BadCmd = "Bad Command: ";
    input();
}
void check_Arg_Else()
{
    /*带参数的命令或其他命令
    Commands with parameters or other commands*/

    // TODO: 添加其他命令的处理
    if (cmd.substr(0, 4) == "echo")
    {
        system(cmd.c_str());
    }
    else
    {
        /*识别为路径 Recognize as path
        未完成 Not finished
        
        if (cmd.substr(1, 3) == ":/" &&
                            ((cmd[0] >= 'A' && cmd[0] <= 'Z' ) ||
                                                (cmd[0] >= 'a' || cmd[0] <= 'z')))
        {
            system(("start"+cmd).c_str());
        }*/
                                                
            //else
            //{
                printf("%s\n", BadCmd.c_str());
                BadCmd = "Bad Command: ";
            //}
    }

    input();
}
int main()
{
    SetConsoleTitle("SuperCmd");
    input();
    return 0;
}