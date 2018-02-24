#ifndef SPORTS_MEETING_H
#define SPORTS_MEETING_H
#include "single_game.h"
#include "aao_copy.h"

class Sports_Meeting
{
    Obj_Player players[33000];//登记过的所有运动员
    long p_player_num;
    AAO_Copy* aao_copy_data_base;//所获取数据的来源
    Single_Game games[500];//所有的项目
    int p_game_num;
    int p_school_num;//学院数量
    int place_to_point(int p);//个人名次-院加分映射
    long aao_get_player_id(long student_id);//利用教务数据库从学号获得号码牌
    Obj_Player aao_get_player(long student_id);//利用教务数据库从学号获得Player
public:
    AAO_School schools[1000];//学院信息
    int state_n;//状态 -1从教务处读数据库 0报名中 1陆续进行各项赛事
    std::string name;//赛事名字
    Sports_Meeting();
    //state==0
    void set_up_aao_copy(AAO_Copy* a_c);//指定获得数据的AAO_Copy
    void sign_up(int n, long student_id);//按学号给该学生报名id为n的项目
    void unsign(int n, long student_id);//把这个学生从那个项目中除名
    long num_of_player();//返回运动员总数
    int num_of_school();//学院数量

    Single_Game* add_game();//添加一个项目，并返回它的指针
    void delete_game(int n);//删除一个项目
    void print_check();//输出核对表
    //state==0||state==1
    void load_aao_backup();//读取保存在自己系统中的教务数据
    void save_aao_backup();//保存保存在自己系统中的教务拷贝数据
    void add_player(Obj_Player &player);//添加一个运动员
    void output_sign_up_information(std::queue<Obj_Player*> &pys, int n, int school_id);//输出指定学院的指定项目的所有报名的运动员
    void output_sign_up_information(std::queue<Obj_Player*> &pys, int n);//输出指定项目的所有报名的运动员
    void output_games(std::queue<Single_Game*> &gms);//输出所有的参赛项目
    Single_Game* get_game(int n);//返回第n个参赛项目
    Obj_Player* get_player(long n);//获得号码牌为n的player
    void set_up_file_helper(File_Helper &file_helper);
    int num_of_game();//返回项目个数
    void copy_school();//从教务系统中抄写学校信息
    //比赛状态
    int state();//返回比赛的进行状态
    int push_state();//推进比赛的状态
    //state==1
    void count_points();//计算各学院的男/女总分
};

#endif // SPORTS_MEETING_H
