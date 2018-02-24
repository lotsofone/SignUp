#ifndef OBJ_GRADE_H
#define OBJ_GRADE_H
#include <sstream>
#include <string>
#include <fstream>
#include "file_helper.h"
#include <QDebug>
#include <QString>

class Sports_Meeting;

class Obj_Grade//客观成绩类
{
private:
    long value;//成绩保存的值
    bool time_type;//成绩的类型是否为时间类。false为简单数值类，true为时间类
    bool reverse;//false表示值高的成绩好，否则值低的成绩好
    std::string unit;//成绩的单位
    int shift;//成绩小数点后保留多少位，从long value中截取后面几位
    int buff;//这次成绩的兴奋剂检查信息
    bool played;//是否已经参加了比赛
public:
    Obj_Grade(std::string u="null", int sft=0, int time_f=false, bool rv=false);
    void log_grade(float point);//录入成绩值
    int log_grade(std::string string_grade);//以字符串形式录入成绩
    int log_drug_test(bool result);//录入兴奋剂检验结果
    void reset_log();//重置成绩
    //比较成绩的大小用
    friend bool operator > (Obj_Grade &u1, Obj_Grade &u2);
    friend bool operator < (Obj_Grade &u1, Obj_Grade &u2);
    friend bool operator == (Obj_Grade &u1, Obj_Grade &u2);
    std::string grade_string();//获得成绩的string表示
    //下面是设定数值时的方法
    void set_time_type(bool t);
    void set_reverse(bool r);
    void set_unit(std::string u);
    int change_shift(int sft);
    //读取必要属性
    bool get_time_type();
    bool get_reverse();
    std::string get_unit();
    int get_shift();
    //value变量
    long get_value();
    void set_value(long v);
    //比较两个成绩
    static int compare(Obj_Grade &u1, Obj_Grade &u2);
    //读取与保存
    void load_data(std::ifstream &iss);
    void save_data(std::ofstream &oss);
};

bool operator > (Obj_Grade &u1, Obj_Grade &u2);
bool operator < (Obj_Grade &u1, Obj_Grade &u2);
bool operator == (Obj_Grade &u1, Obj_Grade &u2);
#endif
