#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;

string generata_one_school()
{
    int sz = 5+rand()%15;
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

void generate_schools(int num)
{
    ofstream ofs;
    ofs.open("D:/AAO generator/AAO_generator/AAO_Copy_Schools.txt");
    //初始化随机数
    srand((GetTickCount()%32768)*107+num);
    int i;
    cout<<num<<endl;
    ofs<<num<<endl;
    for(i=0;i<num;i++)
    {
        cout<<i<<" "<<generata_one_school()<<" School"<<endl;
        ofs<<i<<" "<<generata_one_school()<<" School"<<endl;
    }
}

void ssopt()
{
    ofstream ofs;
    ofs.open("AAO_Copy_Schools.txt");
    ofs<<"17"<<endl;
    ofs<<"0 文法学院"<<endl;
    ofs<<"1 马克思主义学院"<<endl;
    ofs<<"2 外国语学院"<<endl;
    ofs<<"3 艺术学院"<<endl;
    ofs<<"4 工商管理学院"<<endl;
    ofs<<"5 理学院"<<endl;
    ofs<<"6 资源与土木工程学院"<<endl;
    ofs<<"7 冶金学院"<<endl;
    ofs<<"8 材料科学与工程学院"<<endl;
    ofs<<"9 机械工程与自动化学院"<<endl;
    ofs<<"10 信息科学与工程学院"<<endl;
    ofs<<"11 计算机科学与工程学院"<<endl;
    ofs<<"12 软件学院"<<endl;
    ofs<<"13 中荷生物医学与信息工程学院"<<endl;
    ofs<<"14 生命科学与健康学院"<<endl;
    ofs<<"15 江河建筑学院"<<endl;
    ofs<<"16 国防教育学院"<<endl;
    ofs.close();
}

/*
int main(int argc, char* argv[])
{
    int n;
    //cout<<"输入学院数量"<<endl;
    //cin>>n;
    ssopt();
    n=17;
    //generate_schools(n);
    return 0;
}
/**/
