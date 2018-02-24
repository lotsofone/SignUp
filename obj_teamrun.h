#ifndef OBJ_TEAMRUN_H
#define OBJ_TEAMRUN_H
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <fstream>

#include "obj_grade.h"
#include "obj_player.h"

class Obj_TeamRun//小组比赛类。预赛小组赛和决赛的比赛都属于这个类使用的范畴
{
private:
    int game_id;//在运动会系统中的ID
    std::string name;//比赛名字
    Obj_Grade grade_type;//用一个Obj_Grade类来表示该比赛的成绩类型。
    int p_state;//比赛状态0未开始1已开始2比赛完成
    std::vector<Obj_Player*> players;//报名了的选手
    std::vector<Obj_Grade> grades;//选手们对应的成绩

    std::vector<Obj_Player*> sorted_players;//用来保存排序完成的排名名单
    std::vector<Obj_Grade*> sorted_grades;//用以保存排序完成的成绩名单
    bool sort_ok;//用来表示这个排序是否有效，每次变更操作时会影响它
    struct cmp_unit//定义一个堆排序使用的结构
    {
        Obj_Player* player;
        Obj_Grade* grade;
        bool operator < (const cmp_unit &a) const {
            return (*grade)<(*a.grade);
        }
    };
public:
    Obj_TeamRun(int igame_id, std::string iname, Obj_Grade &gt);
    Obj_TeamRun();
//排序获得排名，以及排名输出功能------------------------------------------------------------------
    void count_ranking();//更新排名
    void output_ranking(std::queue<Obj_Player*> &ops);//按排名输出所有运动员
    void output_ranking(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds);//按排名输出所有运动员和成绩
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
//运动员的操作，添加，删除，输出数量---------------------------------------------------------------------------------
    void add_player(Obj_Player *player);//添加运动员
    long num_of_players();//返回比赛的运动员的数量
    int delete_player(long player_id);//根据号码牌在此比赛中将运动员除名

    int state();//返回比赛进行的状态
    int push_state();//推进比赛状态，未开始推进为开始，开始推进为结束
    Obj_Player* get_player(int i);
    Obj_Grade* get_grade(int i);
//输出运动员列表-------------------------------------------------------------------------------
    void output_player_list(std::queue<Obj_Player*> &ops);//输出所有运动员
    void output_player_list(std::queue<Obj_Player*> &ops, std::queue<Obj_Grade*> &gds);//输出所有运动员和成绩
//数据的读取与保存
    void load_data(std::ifstream &iss, File_Helper* file_helper);
    void save_data(std::ofstream &oss);
};
#endif
