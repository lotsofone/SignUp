#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;

const int current_year = 2016;

int get_num_of_school()
{
    ifstream iss;
    iss.open("AAO_Copy_Schools.txt");
    int n;
    iss>>n;
    return n;
}

int random_jumper()
{
    long r=rand()%1000;
    if(r<10)return -3;
    if(r<40)return -2;
    if(r<90)return -1;
    if(r<955)return 0;
    if(r<980)return 1;
    if(r<995)return 2;
    if(r<1000)return 3;
    return 0;
}
string generata_one_name()
{
    int sz = 5+rand()%8;
    int i;
    char ch;
    string ans;
    for(i=0;i<sz;i++)
    {
        ch = rand()%52 +65;
        if(ch>90)ch+=6;
        ans+=ch;
        //cout<<ch;
    }
    return ans;
}
void generate_student(int att_year, long num_per_level)
{
    ofstream oss;
    oss.open("AAO_Copy_Students.txt", ios::app);

    int num_of_school = get_num_of_school();
    int idb4;
    int level;
    for(idb4=0;idb4<num_per_level;idb4++)
    {
        level = current_year - att_year + 1;
        level += random_jumper();
        if(level>=4)level=4;
        if(level<=1)level=1;
        //学号 -1 性别(男1女0) 学位(1大学生2在读硕士3在读博士) 入学年份 年级(考虑留级与跳级) 学院号 名字
        oss<<att_year;

        if(idb4<1000)oss<<0;
        if(idb4<100)oss<<0;
        if(idb4<10)oss<<0;
        oss<<idb4;

        oss<<" -1 ";
        oss<<rand()%2<<" 1 "<<att_year<<" "<<level<<" "<<rand()%num_of_school<<" "<<generata_one_name();
        oss<<endl;
    }

}

int main(int argc, char* argv[])
{
    long n1=8000;
    ofstream oss;
    oss.open("AAO_Copy_Students.txt");
    oss<<n1*4<<endl;
    srand((GetTickCount()%32768*107)+n1);
    generate_student(2013, n1);
    generate_student(2014, n1);
    generate_student(2015, n1);
    generate_student(2016, n1);
    return 0;
}
