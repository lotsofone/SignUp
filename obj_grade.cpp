#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <obj_grade.h>
#include <qdebug.h>


Obj_Grade::Obj_Grade(std::string u, int sft, int time_f, bool rv)
{
    time_type=time_f;value=0;buff=0;unit=u;shift=sft;reverse=rv;
    if(shift<0)shift=0;
    played=false;
}
void Obj_Grade::log_grade(float point)//录入成绩值
{
    int i;
    for(i=0;i<shift;i++)point*=10;
    value = (long)(point+0.5);
    played = true;
}
int Obj_Grade::log_grade(std::string string_grade)//以字符串输入录入成绩值
{
    long i;
    std::istringstream iss(string_grade);
    float G;
    if(time_type==0)//不是时间对象
    {
        if(iss>>G)
        {
            for(i=0;i<shift;i++)G*=10;
            value = (long)(G+0.5);
            played = true;
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        double ans=0;
        char u_input;
        while(iss>>G)
        {
            iss>>u_input;
            switch(u_input){
            case 'd':
                ans+=G*86400;break;
            case 'h':
                ans+=G*3600;break;
            case 'm':
                ans+=G*60;break;
            case 's':
                ans+=G;break;
            default:
                return -1;
            }
        }
        for(i=0;i<shift;i++)ans*=10;
        value = (long)(ans+0.5);
        played = true;
        return 1;
    }
}
int Obj_Grade::log_drug_test(bool result)//录入兴奋剂检验结果
{
    if(!played)//成绩还未能录入
    {
        return -1;//兴奋剂检验需在成绩录入后进行
    }
    if(!result)
    {
        buff=-1;//合格
    }
    else
    {
        buff=1;//阳性，使用了兴奋剂
    }
    return 1;
}
void Obj_Grade::reset_log()//重置成绩
{
    buff = 0;played = false;
}

std::string Obj_Grade::grade_string()//获得成绩的string表示
{
    std::ostringstream oss;
    if(!played)return "未参赛";
    if(buff==1)return "使用兴奋剂";
    //首先把value拆成两部分
    long p1,p2;
    long dv;
    int i;
    dv=1;
    for(i=0;i<shift;i++)
    {
        dv*=10;
    }
    p1 = value/dv; p2 = value%dv;
    //然后根据time_type和shift输出数值部分
    if(time_type)
    {
        if(p1>=3600)
        {
            oss<<p1/3600;
            oss<<"时";
        }
        if(p1>=60)
        {
            oss<<((p1/60)%60)<<"分";
        }
        oss<<p1%60;
    }
    else
    {
        oss<<p1;
    }
    //数值部分的小数部分输出
    if(shift>0)
    {
        oss<<".";
        dv=1;
        for(i=0;i<shift;i++)
        {
            dv*=10;
        }
        for(i=0;i<shift;i++)
        {
            dv/=10;
            oss<<((p2/dv)%10);
        }
    }
    //输出单位
    if(time_type)
    {
        oss<<"秒";
    }
    else
    {
        oss<<unit;
    }
    //兴奋剂检验通过标识
    if(buff==-1&&played)oss<<"√";
    return oss.str();
}

//下面是设定数值时的方法
void Obj_Grade::set_time_type(bool t){time_type=t;};
void Obj_Grade::set_reverse(bool r){reverse=r;};
void Obj_Grade::set_unit(std::string u){unit = u;};
int Obj_Grade::change_shift(int sft)
{
    if(sft<0)return -1;
    if(sft==shift)return 1;
    int ca = sft;
    if(sft>shift)
    {
        for(;sft>shift;sft--)
        {
            value*=10;
        }
    }
    else
    {
        for(;sft<shift;sft++)
        {
            value/=10;
        }
    }
    shift=ca;
    return 1;
}

//读取必要属性
bool Obj_Grade::get_time_type(){return time_type;}
bool Obj_Grade::get_reverse(){return reverse;}
std::string Obj_Grade::get_unit(){return unit;}
int Obj_Grade::get_shift(){return shift;}

//value变量
long Obj_Grade::get_value(){return value;};
void Obj_Grade::set_value(long v){value = v;}
//比较两个成绩

int Obj_Grade::compare(Obj_Grade &u1, Obj_Grade &u2)
{
    if(!u1.played&&!u2.played)return 0;
    if(u1.played&&!u2.played)return 1;
    if(!u1.played&&u2.played)return -1;
    //u1.played&&u2.played
    if((u1.buff==1)&&(u2.buff==1))return 0;
    if(!(u1.buff==1)&&(u2.buff==1))return 1;
    if((u1.buff==1)&&!(u2.buff==1))return -1;
    //u1.buff!=1&&u2.buff!=1
    if(u1.value==u2.value)return 0;
    if(u1.reverse)
    {
        if(u1.value>u2.value)return -1;return 1;
    }
    else
    {
        if(u1.value>u2.value)return 1;return -1;
    }
    qDebug()<<"error";
}
void Obj_Grade::load_data(std::ifstream &iss)
{
    iss>>value>>buff>>played;
}
void Obj_Grade::save_data(std::ofstream &oss)
{
    oss<<value<<" "<<buff<<" "<<played<<" ";
}

bool operator > (Obj_Grade &u1, Obj_Grade &u2)//比较成绩谁高谁低
{
    return Obj_Grade::compare(u1,u2)==1;
}
bool operator < (Obj_Grade &u1, Obj_Grade &u2)
{
    return Obj_Grade::compare(u1,u2)==-1;
}
bool operator == (Obj_Grade &u1, Obj_Grade &u2)
{
    return Obj_Grade::compare(u1,u2)==0;
}
/*
bool operator > (Obj_Grade &u1, Obj_Grade &u2)//比较成绩谁高谁低
{
    if(u1.played&&!u2.played)return true;//是否参赛作为第一比较条件。没参赛就会被排在最后面
    if(!u1.played)return false;
    if(u1.buff==1)return false;//兴奋剂使用作为第二比较条件
    if(!(u1.buff==1)&&u2.buff==1)return true;
    return ((u1.value-u2.value)>0&&!u1.reverse)||((u1.value-u2.value)<0&&u1.reverse);
}
bool operator < (Obj_Grade &u1, Obj_Grade &u2)
{
    if(!u1.played&&u2.played)return true;//是否参赛作为第一比较条件。没参赛就会被排在最后面
    if(!u2.played)return false;
    if(u2.buff==1)return false;//兴奋剂使用作为第二比较条件
    if(u1.buff==1&&!(u2.buff==1))return true;
    return ((u1.value-u2.value)>0&&!u1.reverse)||((u1.value-u2.value)<0&&u1.reverse);
}
bool operator == (Obj_Grade &u1, Obj_Grade &u2)
{
    if(u1.played!=u2.played)return false;
    if(!u1.played)
    {
        return true;
    }
    else
    {
        if((u1.buff==1)!=(u2.buff==1))return false;
        if(u1.buff==1)
        {
            return true;
        }
        else
        {
            return u1.value == u2.value;
        }
    }
}
*/
