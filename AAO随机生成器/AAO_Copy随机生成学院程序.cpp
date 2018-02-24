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
    ofs.open("AAO_Copy_Schools.txt", ios::out);
    //初始化随机数
    srand((GetTickCount()%32768*107)+num);
    int i;
    cout<<num<<endl;
    ofs<<num<<endl;
    for(i=0;i<num;i++)
    {
        cout<<i<<" "<<generata_one_school()<<" School"<<endl;
        ofs<<i<<" "<<generata_one_school()<<" School"<<endl;
    }
}

int main(int argc, char* argv[])
{
    int n;
    cout<<"输入学院数量"<<endl;
    cin>>n;
    generate_schools(n);
    return 0;
}
