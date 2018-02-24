#include "aao_copy.h"

AAO_Copy::AAO_Copy()
{
    students_num=0;
    students_copy = new Obj_Player[0];
    schools_num=0;
    schools_copy = new AAO_School[0];
}

AAO_Copy::~AAO_Copy()
{
    delete students_copy;
    delete schools_copy;
}

long AAO_Copy::sub_search_student_i(long aao_id)//通过学号找到下标
{
    long left,mid,right;
    left = 0; right = students_num;
    while(1)
    {
        mid = (left+right)/2;
        if(students_copy[mid].student_id==aao_id)return mid;
        if(students_copy[mid].student_id>aao_id)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
        if(left>=right)
        {
            return -1;
        }
    }
}

void AAO_Copy::load_data()//从文件中读取信息，重建两个copy数组，把教务处拷贝的信息读入两个copy数组中，并设定学生和学院数量
{
    long i;
    delete students_copy;
    delete schools_copy;
    std::ifstream iss;
    //读取学生信息
    iss.open("AAO_Copy_Students.txt");
    iss>>students_num;
    qDebug()<<"students_num="<<students_num;
    students_copy = new Obj_Player[students_num];
    for(i=0;i<students_num;i++)
    {
        //学号 -1 性别(男1女0) 学位(1大学生2在读硕士3在读博士) 入学年份 年级(考虑留级与跳级) 学院号 名字
        iss>>students_copy[i].student_id;
        iss>>students_copy[i].id;
        iss>>students_copy[i].gender;
        iss>>students_copy[i].degree;
        iss>>students_copy[i].att_year;
        iss>>students_copy[i].level;
        iss>>students_copy[i].school_id;
        iss>>students_copy[i].name;
    }
    iss.close();

    iss.open("AAO_Copy_Schools.txt");
    iss>>schools_num;
    schools_copy = new AAO_School[schools_num];
    for(i=0;i<schools_num;i++)
    {
        iss>>schools_copy[i].id;
        iss>>schools_copy[i].name;
        schools_copy[i].points_sum_female=0;
        schools_copy[i].points_sum_male=0;
    }
    iss.close();
}
void AAO_Copy::save_data()//把信息保存，主要是为了保存报名的号码牌信息
{
    long i;
    std::ofstream oss;
    oss.open("AAO_Copy_Students.txt");
    oss<<students_num<<std::endl;
    for(i=0;i<students_num;i++)
    {
        oss<<students_copy[i].student_id<<" ";
        oss<<students_copy[i].id<<" ";
        oss<<students_copy[i].gender<<" ";
        oss<<students_copy[i].degree<<" ";
        oss<<students_copy[i].att_year<<" ";
        oss<<students_copy[i].level<<" ";
        oss<<students_copy[i].school_id<<" ";
        oss<<students_copy[i].name<<std::endl;
    }
    oss.close();
}
Obj_Player AAO_Copy::search_student(long aao_id)//根据学号搜寻学生信息，返回搜索到的学生。若没搜到，返回一个不存在的学生，通过其student_id=-1来表示。
//若搜到，则返回该学生对象。其id=-1表示没有报名任何项目，其他值表示已经至少报名一个项目并已经分配号码牌号码
{
    long left,mid,right;
    left = 0; right = students_num;
    while(1)
    {
        mid = (left+right)/2;
        if(students_copy[mid].student_id==aao_id)return students_copy[mid];
        if(students_copy[mid].student_id>aao_id)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
        if(left>=right)
        {
            Obj_Player fff;
            fff.student_id=-1;
            return fff;
        }
    }
}
long AAO_Copy::search_student_gameid(long aao_id)//根据学号搜索学生信息，返回搜索到的学生在运动会系统中的id(号码牌)。若学生未报名，返回-1。若无此学生，返回-2
{
    long left,mid,right;
    left = 0; right = students_num;
    while(1)
    {
        mid = (left+right)/2;
        if(students_copy[mid].student_id==aao_id)return students_copy[mid].id;
        if(students_copy[mid].student_id>aao_id)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
        if(left>=right)
        {
            return -2;
        }
    }
}
void AAO_Copy::set_game_id(long aao_id, long game_id)//给这个学号的学生设置号码牌，方面将来的查询
{
    long i = sub_search_student_i(aao_id);
    if(i==-1)return;
    students_copy[i].id=game_id;
}
AAO_School AAO_Copy::get_school(int school_id)//根据学院id，获得学院信息
{
    return schools_copy[school_id];
}
int AAO_Copy::num_of_school(){return schools_num;}
long AAO_Copy::get_student_id_randomly()//随机返回一个学生id
{
    return students_copy[rand()%students_num].student_id;
}
