#ifndef SINGLE_GAME_H
#define SINGLE_GAME_H
#include <vector>
#include "obj_teamrun.h"
#include "obj_player.h"
#include "obj_grade.h"
class Sports_Meeting;
class Single_Game
{
private:
    Obj_TeamRun final_run;//决赛的team run。同时即便这个tramrun一个人也没有，它也用于表示这个Single_Game的成绩类型
    Obj_TeamRun pre_runs[80];//小组赛
    int p_player_num, p_pre_run_num;//运动员和小组赛的个数
    Obj_Player *players[400];//报名这个项目的运动员
    int state_n;//状态变量 0报名中 1预赛中 2决赛中
    int num_per_team;//小组赛一次最大比赛的学生数量
    int num_in_final;//最大决赛名额数量
    int generate_to_pre();//从报名信息中进行随机分配，进入小组赛
    int generate_to_final();//从小组赛中取得成绩并排名，进入决赛
public:
    std::string name;//项目名字
    Single_Game();
//state_n==0，报名中所需要做的操作：
//更改成绩类型。-------------------------------------------------------------------------------
    void set_time_type(bool t);
    void set_reverse(bool r);
    void set_unit(std::string u);
    int change_shift(int sft);
//获取成绩类型。-------------------------------------------------------------------------------
    bool get_time_type();
    bool get_reverse();
    std::string get_unit();
    int get_shift();
//比赛项目的属性的设置-------------------------------------------------------------------------------
    int get_num_per_team();//返回小组赛每次最多的参赛学生数量
    int get_num_in_final();//返回决赛最大名额
    int set_num_per_team(int v);//设置。出错返回-1
    int set_num_in_final(int v);//设置。出错返回-1
//运动员的操作，添加，删除，输出数量---------------------------------------------------------------------------------
    void add_player(Obj_Player *player);//添加运动员
    long num_of_players();//返回比赛的运动员的数量
    int delete_player(long player_id);//根据号码牌在此比赛中将运动员除名
    int delete_at(long n);//移除列表中下标为n的学生
//当前比赛状态
    int state();//返回比赛进行的状态
    int push_state();//推进比赛状态，未开始推进为开始，开始推进为结束
//输出运动员列表-------------------------------------------------------------------------------
    void output_signed_players(std::queue<Obj_Player*> &ops);//输出报名的所有运动员
//state_n>0：
//输出各个比赛的运动员列表
    int get_pre_team_num();//输出小组赛的个数
    void output_pre_list(std::queue<Obj_Player*> &ops, int n);//输出这个小组赛的所有运动员
    void output_pre_list(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds, int n);//输出这个小组赛的所有运动员及其成绩
    void output_final_list(std::queue<Obj_Player*> &ops);//输出参加决赛的所有运动员
    void output_final_list(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds);//输出参加决赛的所有运动员及其成绩
    Obj_Player* get_pre_player(int i, int n);
    Obj_Grade* get_pre_grade(int i, int n);
    Obj_Player* get_final_player(int i);
    Obj_Grade* get_final_grade(int i);
//运动员排名的输出
    void output_final_ranking(std::queue<Obj_Player*> &ops);//输出决赛的运动员排名
    void output_final_ranking(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds);//输出决赛的运动员排名
    void output_pre_ranking(std::queue<Obj_Player*> &ops, int n);//输出小组赛的运动员排名
    void output_pre_ranking(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds, int n);//输出小组赛的运动员排名
//信息的保存与读取
    void load_data(std::ifstream &iss, File_Helper* file_helper);
    void save_data(std::ofstream &oss);
};

#endif // SINGLE_GAME_H
