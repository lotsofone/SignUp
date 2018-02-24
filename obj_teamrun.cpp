#include <stdio.h>
#include <iostream>

#include "obj_teamrun.h"

Obj_TeamRun::Obj_TeamRun()
{
    game_id=0;name="null";
    p_state=0;
    sort_ok=false;
    grade_type = Obj_Grade();
}
Obj_TeamRun::Obj_TeamRun(int igame_id, std::string iname, Obj_Grade &gt)
{
    game_id=igame_id; name=iname;
    p_state=0;
    grade_type=gt;
    sort_ok=false;
};
//排序获得排名，以及排名输出功能------------------------------------------------------------------
void Obj_TeamRun::count_ranking()//更新排名
{
    std::priority_queue<struct cmp_unit> heap;
    cmp_unit ca;
    unsigned int i;
    //把信息输入堆中
    for(i=0;i<players.size();i++)
    {
        ca.player = players[i];
        ca.grade = &grades[i];
        //qDebug()<<QString::fromStdString(grades[i].grade_string());
        heap.push(ca);
    }
    sorted_players.resize(players.size());//排名列表的数量和运动员数量一致
    sorted_grades.resize(players.size());
    //取出堆中内容，得到排序后的结果
    for(i=0;i<players.size();i++)
    {
        sorted_players[i] = heap.top().player;
        sorted_grades[i] = heap.top().grade;
        heap.pop();
    }
    /*for(i=0;i<players.size();i++)
    {
        qDebug()<<QString::fromStdString(sorted_grades[i]->grade_string());
    }*/
    sort_ok=true;
}
void Obj_TeamRun::output_ranking(std::queue<Obj_Player*> &ops)//按排名输出玩家
{
    unsigned int i;
    count_ranking();

    /*for(i=0;i<players.size();i++)
    {
        qDebug()<<QString::fromStdString(grades[i].grade_string());
    }*/

    while(!ops.empty())ops.pop();
    for(i=0;i<players.size();i++)
    {
        ops.push(sorted_players[i]);
    }
}
void Obj_TeamRun::output_ranking(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds)//按排名输出玩家和成绩
{
    unsigned int i;
    count_ranking();

    while(!ops.empty())ops.pop();
    while(!gds.empty())gds.pop();
    for(i=0;i<players.size();i++)
    {
        ops.push(sorted_players[i]);
        gds.push(sorted_grades[i]);
        //qDebug()<<sorted_grades[i]->get_value();
    }
}

//更改成绩类型。-------------------------------------------------------------------------------
void Obj_TeamRun::set_time_type(bool t)
{
    unsigned int i;
    grade_type.set_time_type(t);
    for(i=0;i<grades.size();i++)grades[i].set_time_type(t);
}
void Obj_TeamRun::set_reverse(bool r)
{
    unsigned int i;
    grade_type.set_reverse(r);
    for(i=0;i<grades.size();i++)grades[i].set_reverse(r);
}
void Obj_TeamRun::set_unit(std::string u)
{
    unsigned int i;
    grade_type.set_unit(u);
    for(i=0;i<grades.size();i++)grades[i].set_unit(u);
}
int Obj_TeamRun::change_shift(int sft)
{
    unsigned int i;
    if(grade_type.change_shift(sft)==-1)return -1;
    for(i=0;i<grades.size();i++)grades[i].change_shift(sft);
    return 1;
}
//获得成绩类型
bool Obj_TeamRun::get_time_type(){return grade_type.get_time_type();}
bool Obj_TeamRun::get_reverse(){return grade_type.get_reverse();}
std::string Obj_TeamRun::get_unit(){return grade_type.get_unit();}
int Obj_TeamRun::get_shift(){return grade_type.get_shift();}
//运动员的操作，添加，删除，输出数量---------------------------------------------------------------------------------
void Obj_TeamRun::add_player(Obj_Player *player)//添加运动员
{
    unsigned int i;
    for(i=0;i<players.size();i++)
    {
        if(players[i]==player||player->id==players[i]->id)return;//查重
    }
    players.push_back(player);
    grades.push_back(grade_type);
    sort_ok=false;
}
long Obj_TeamRun::num_of_players()//返回比赛的运动员的数量
{
    return players.size();
}
int Obj_TeamRun::delete_player(long player_id)//根据号码牌在此比赛中将运动员除名
{
    unsigned int i;
    for(i=0;i<players.size();i++)
    {
        if((*players[i]).id==player_id)
        {
            players.erase(players.begin()+i);
            grades.erase(grades.begin()+i);
            sort_ok=false;
            return 1;//找到该运动员并删除
        }
    }
    return -1;//未找到该运动员
};
int Obj_TeamRun::state(){return p_state;}//返回比赛进行的状态
int Obj_TeamRun::push_state()//推进比赛状态，未开始推进为开始，开始推进为结束
{
    if(p_state==2)return -1;//已经结束啦
    p_state+=1;return 1;
}
Obj_Player* Obj_TeamRun::get_player(int i){return players[i];}
Obj_Grade* Obj_TeamRun::get_grade(int i)
{
    //qDebug()<<QString::fromStdString(grades[i].grade_string());
    //qDebug()<<grades[i].get_shift();
    return &grades[i];
}
//输出运动员列表-------------------------------------------------------------------------------
void Obj_TeamRun::output_player_list(std::queue<Obj_Player*> &ops)//输出运动员的队列
{
    unsigned int i;
    while(!ops.empty())ops.pop();
    for(i=0;i<players.size();i++)
    {
        ops.push(players[i]);
    }
}
void Obj_TeamRun::output_player_list(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds)//输出运动员的队列及其成绩
{
    unsigned int i;
    while(!ops.empty())ops.pop();
    while(!gds.empty())gds.pop();
    for(i=0;i<players.size();i++)
    {
        ops.push(players[i]);
        gds.push(&grades[i]);
        //qDebug()<<grades[i].get_value();
    }
}
void Obj_TeamRun::load_data(std::ifstream &iss, File_Helper *file_helper)
{
    //建立小组并读取每个小组的运动员信息
    int trn;
    iss>>trn;
    int pid;
    int j;
    for(j=0;j<trn;j++)
    {
        iss>>pid;
        add_player(file_helper->get_player(pid));
        //再读取成绩信息
        grades[j].load_data(iss);
    }
    iss>>p_state;//读取当前状态
}
void Obj_TeamRun::save_data(std::ofstream &oss)
{
    oss<<"    ";
    oss<<players.size()<<" ";
    unsigned int i;
    for(i=0;i<players.size();i++)
    {
        oss<<players[i]->id<<" ";
        grades[i].save_data(oss);
    }
    oss<<p_state<<std::endl;
}
