#include <iostream>
#include <stdio.h>
#include "single_game.h"
#include "obj_teamrun.h"
#include "obj_player.h"
#include "obj_grade.h"

Single_Game::Single_Game()
{
    state_n=0;
    num_per_team=8;
    num_in_final=8;
    p_player_num=0;
    p_pre_run_num=0;
}

int Single_Game::generate_to_pre()//从报名信息中进行随机分配，进入小组赛
{
    Obj_Player** Scrambled_Players;
    Obj_Player* ca;
    Obj_TeamRun* curtr;
    Scrambled_Players = new Obj_Player*[p_player_num];
    int i,j;
    for(i=0;i<p_player_num;i++)Scrambled_Players[i]=players[i];
    //洗牌算法打乱
    for(i=p_player_num;i>0;i--)
    {
        j = rand()%i;
        ca = Scrambled_Players[i-1];
        Scrambled_Players[i-1] = Scrambled_Players[j];
        Scrambled_Players[j] = ca;
    }
    //将打乱后的运动员放入小组的TeamRun中
    for(i=0;i<p_player_num;i++)
    {
        if(i%num_per_team==0)
        {
            pre_runs[p_pre_run_num]=final_run; p_pre_run_num++;
            curtr = &pre_runs[p_pre_run_num-1];
        }
        curtr->add_player(Scrambled_Players[i]);
    }
    //qDebug()<<pre_runs[1].num_of_players();
    delete Scrambled_Players;
    return 1;
}

int Single_Game::generate_to_final()//从小组赛中取得成绩并排名，进入决赛
{
    qDebug()<<"Single_Game::generate_to_final()  start";
    Obj_TeamRun ranker = final_run;//虚拟一个teamrun类，利用其排序功能实现找出前几名的目的
    unsigned int i;
    std::queue<Obj_Player*> pys;
    std::queue<Obj_Grade*> gds;
    std::queue<Obj_Player*> pys_t;
    std::queue<Obj_Grade*> gds_t;
    //从小组赛中取出所有的运动员及其对应成绩，得到对应的pys和gds变量
    for(i=0;i<p_pre_run_num;i++)
    {
        pre_runs[i].output_player_list(pys_t, gds_t);
        while(!pys_t.empty())
        {
            pys.push(pys_t.front());
            pys_t.pop();
            gds.push(gds_t.front());
            //qDebug()<<gds_t.front()->get_value();
            gds_t.pop();
        }
    }
    //输入ranker
    while(!pys.empty())
    {
        ranker.add_player(pys.front());
        pys.pop();
    }
    ranker.output_player_list(pys_t, gds_t);
    //按顺序添加的player，输出也会按顺序。下面把gds的成绩一个个录入gds_t中
    while(!gds_t.empty())
    {
        //gds_t.front()->set_value(gds.front()->get_value());
        *gds_t.front()=*gds.front();
        //qDebug()<<gds_t.front()->get_value();
        gds.pop();
        gds_t.pop();
    }
    /*for(i=0;i<ranker.num_of_players();i++)
    {
        qDebug()<<ranker.get_grade(i)->get_value();
    }*/
    //取得排名
    qDebug()<<"Single_Game::generate_to_final()  before count_ranking()";
    ranker.output_ranking(pys);
    qDebug()<<"Single_Game::generate_to_final()  count_ranking success";
    //加入决赛
    int j;
    for(j=0;j<num_in_final;j++)
    {
        if(pys.empty())//特殊情况，报名人数小于决赛设置的人数了
        {
            num_in_final=j;break;
        }
        final_run.add_player(pys.front());
        pys.pop();
    }
    qDebug()<<"Single_Game::generate_to_final()  success";
    return 0;
}

//state_n==0，报名中所需要做的操作：
//更改成绩类型。这些操作也可以在比赛中进行---------------------------------------------------------------
void Single_Game::set_time_type(bool t)
{
    final_run.set_time_type(t);
    unsigned int i;
    unsigned int n=get_pre_team_num();
    for(i=0;i<n;i++)
    {
        pre_runs[i].set_time_type(t);
    }
}
void Single_Game::set_reverse(bool r)
{
    final_run.set_reverse(r);
    unsigned int i;
    unsigned int n=get_pre_team_num();
    for(i=0;i<n;i++)
    {
        pre_runs[i].set_reverse(r);
    }
}
void Single_Game::set_unit(std::string u)
{
    final_run.set_unit(u);
    unsigned int i;
    unsigned int n=get_pre_team_num();
    for(i=0;i<n;i++)
    {
        pre_runs[i].set_unit(u);
    }
}
int Single_Game::change_shift(int sft)
{
    if(final_run.change_shift(sft)==-1)return -1;
    int i;
    int n=p_pre_run_num;
    for(i=0;i<n;i++)
    {
        pre_runs[i].change_shift(sft);
    }
    return 1;
}
//获取成绩类型。-------------------------------------------------------------------------------
bool Single_Game::get_time_type(){return final_run.get_time_type();}
bool Single_Game::get_reverse(){return final_run.get_reverse();}
std::string Single_Game::get_unit(){return final_run.get_unit();}
int Single_Game::get_shift(){return final_run.get_shift();}
//比赛项目的属性的设置-------------------------------------------------------------------------------
int Single_Game::get_num_per_team(){return num_per_team;}//返回小组赛每次最多的参赛学生数量
int Single_Game::get_num_in_final(){return num_in_final;}//返回决赛最大名额
int Single_Game::set_num_per_team(int v)//设置。出错返回-1
{
    if(state_n>0)return -1;
    if(v<=0)return -1;
    num_per_team=v;return v;
}
int Single_Game::set_num_in_final(int v)//设置。出错返回-1
{
    if(state_n>0)return -1;
    if(v<=1)return -1;
    num_in_final=v;return v;
}
//运动员的操作，添加，删除，输出数量---------------------------------------------------------------------------------
void Single_Game::add_player(Obj_Player *player)//添加运动员
{
    unsigned int i;
    for(i=0;i<p_player_num;i++)
    {
        if(players[i]==player||players[i]->id==player->id)return;//查重
    }
    players[p_player_num]=player; p_player_num++;
}
long Single_Game::num_of_players(){return p_player_num;}//返回比赛的运动员的数量

int Single_Game::delete_player(long player_id)//根据号码牌在此比赛中将运动员除名
{
    int i;
    for(i=0;i<p_player_num;i++)
    {
        if(players[i]->id==player_id)
        {
            int j;
            for(j=i+1;j<p_player_num;j++)
            players[j-1]=players[j];
            p_player_num--;
            return 0;//找到该运动员并删除
        }
    }
    return -1;//未找到该运动员
}
int Single_Game::delete_at(long n)//移除列表中下标为n的学生
{
    if(n<0||n>=p_player_num)return 1;
    int j;
    for(j=n+1;j<p_player_num;j++)
    players[j-1]=players[j];
    p_player_num--;
    return 0;
}

//当前比赛状态
int Single_Game::state(){return state_n;}//返回比赛进行的状态
int Single_Game::push_state()//推进比赛状态，未开始推进为开始，开始推进为结束
{
    if(state_n>=2)return -1;
    state_n+=1;
    if(state_n==1)generate_to_pre();
    if(state_n==2)generate_to_final();
    return 0;
}
//输出运动员列表-------------------------------------------------------------------------------
void Single_Game::output_signed_players(std::queue<Obj_Player*> &ops)//输出报名的所有运动员
{
    while(!ops.empty())ops.pop();
    unsigned int i;
    for(i=0;i<p_player_num;i++)
    {
        ops.push(players[i]);
    }
}
//state_n>0：
//输出各个比赛的运动员列表
int Single_Game::get_pre_team_num(){return p_pre_run_num;}//输出小组赛的个数

void Single_Game::output_pre_list(std::queue<Obj_Player*> &ops, int n)//输出这个小组赛的所有运动员
{
    pre_runs[n].output_player_list(ops);
}
void Single_Game::output_pre_list(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds, int n)//输出这个小组赛的所有运动员及其成绩
{
    pre_runs[n].output_player_list(ops, gds);
}
void Single_Game::output_final_list(std::queue<Obj_Player*> &ops)//输出参加决赛的所有运动员
{
    final_run.output_player_list(ops);
}
void Single_Game::output_final_list(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds)//输出参加决赛的所有运动员及其成绩
{
    final_run.output_player_list(ops, gds);
}

Obj_Player* Single_Game::get_pre_player(int i, int n){return pre_runs[n].get_player(i);}
Obj_Grade* Single_Game::get_pre_grade(int i, int n){return pre_runs[n].get_grade(i);}
Obj_Player* Single_Game::get_final_player(int i){return final_run.get_player(i);}
Obj_Grade* Single_Game::get_final_grade(int i){return final_run.get_grade(i);}
//运动员排名的输出
void Single_Game::output_final_ranking(std::queue<Obj_Player*> &ops)//输出决赛的运动员排名
{
    final_run.output_ranking(ops);
}
void Single_Game::output_final_ranking(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds)//输出决赛的运动员排名
{
    final_run.output_ranking(ops, gds);
}
void Single_Game::output_pre_ranking(std::queue<Obj_Player*> &ops, int n)//输出小组赛的运动员排名
{
    pre_runs[n].output_ranking(ops);
}
void Single_Game::output_pre_ranking(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds, int n)//输出小组赛的运动员排名
{
    pre_runs[n].output_ranking(ops, gds);
}

//信息的保存与读取
void Single_Game::load_data(std::ifstream &iss, File_Helper *file_helper)
{
    iss>>name;
    int tg;
    iss>>tg; set_time_type(tg==1);
    iss>>tg; set_reverse(tg==1);
    std::string cst; iss>>cst; set_unit(cst);
    iss>>tg; change_shift(tg);
    iss>>num_per_team>>num_in_final;

    int player_num, pid;
    iss>>player_num;
    int j;
    for(j=0;j<player_num;j++)
    {
        iss>>pid;
        add_player(file_helper->get_player(pid));
    }
    int sn;iss>>sn;//状态变量 0报名中 1预赛中 2决赛中
    if(sn==0)return;//还在等待报名完成状态，后面将是下一个文件的信息了
    //将有小组信息
    state_n=1;
    int gn;
    iss>>gn;//小组的数量
    int i;
    Obj_TeamRun* curtr;
    for(i=0;i<gn;i++)
    {
        pre_runs[p_pre_run_num]=final_run;p_pre_run_num++;
        curtr = &pre_runs[p_pre_run_num-1];
        curtr->load_data(iss, file_helper);
    }
    if(sn==1)return;//==1表示没有更多信息。
    state_n=2;
    //否则还需要读取final run的信息
    final_run.load_data(iss, file_helper);
}
void Single_Game::save_data(std::ofstream &oss)
{
    oss<<name<<std::endl;
    oss<<"  "<<get_time_type()<<" ";
    oss<<get_reverse()<<" ";
    oss<<get_unit()<<" ";
    oss<<get_shift()<<" ";
    oss<<num_per_team<<" "<<num_in_final<<std::endl;
    oss<<"  "<<p_player_num<<std::endl;
    oss<<"    ";
    int i;
    for(i=0;i<p_player_num;i++)
    {
        oss<<players[i]->id<<" ";
    }
    oss<<std::endl;
    oss<<"  "<<state_n<<std::endl;
    if(state_n==0)return;
    oss<<"  "<<p_pre_run_num<<std::endl;
    for(i=0;i<p_pre_run_num;i++)
    {
        pre_runs[i].save_data(oss);
    }
    if(state_n==1)return;
    final_run.save_data(oss);
}
