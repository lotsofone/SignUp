#ifndef AAO_COPY_H
#define AAO_COPY_H
#include <string>
#include <stdio.h>
#include "obj_player.h"
#include "aao_school.h"
#include <fstream>
#include <qdebug.h>


class AAO_Copy
{
private:
    Obj_Player* students_copy;
    AAO_School* schools_copy;
    int schools_num;
    std::string filename;
    long students_num;
    long sub_search_student_i(long aao_id);//根据学号搜索学生，返回其在students_copy数组中的下标。若找不到则返回-1;
public:
    AAO_Copy();//构造函数
    ~AAO_Copy();//析构函数
    void load_data();//从文件中读取信息，重建两个copy数组，把教务处拷贝的信息读入两个copy数组中，并设定学生和学院数量
    void save_data();//把信息保存，主要是为了保存报名的号码牌信息
    Obj_Player search_student(long aao_id);//根据学号搜寻学生信息，返回搜索到的学生。若没搜到，返回一个不存在的学生，通过其student_id=-1来表示。
    //若搜到，则返回该学生对象。其id=-1表示没有报名任何项目，其他值表示已经至少报名一个项目并已经分配号码牌号码
    long search_student_gameid(long aao_id);//根据学号搜索学生信息，返回搜索到的学生在运动会系统中的id(号码牌)。若学生未报名，返回-1。若无此学生，返回-2
    void set_game_id(long aao_id, long game_id);//给这个学号的学生设置号码牌，方面将来的查询
    AAO_School get_school(int school_id);//根据学院id，获得学院信息
    int num_of_school();
    long get_student_id_randomly();//随机返回一个学生id
};

#endif // AAO_COPY_H
