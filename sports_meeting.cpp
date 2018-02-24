#include "sports_meeting.h"
#include "qdebug.h"

Sports_Meeting::Sports_Meeting()
{
    state_n=0;
    p_game_num=0;
    p_player_num=0;
    p_school_num=0;
}
void Sports_Meeting::add_player(Obj_Player &player)//添加一个运动员
{
    if(player.id==-1)//此学生没有报名
    {
        players[p_player_num]=player;
        p_player_num+=1;
    }
    long i = p_player_num-1;
    players[i].id = i;
    aao_copy_data_base->set_game_id(player.student_id, i);
}

long Sports_Meeting::num_of_player()//返回运动员总数
{
    return p_player_num;
}
int Sports_Meeting::num_of_school()//学院数量
{
    return p_school_num;
}

int Sports_Meeting::place_to_point(int p)//个人名次-院加分映射
{
    switch(p)
    {
    case 1:
        return 9;
    case 2:
        return 5;
    case 3:
        return 3;
    case 4:
        return 2;
    case 5:
        return 1;
    }
    return 0;
}
long Sports_Meeting::aao_get_player_id(long student_id)//利用教务数据库从学号获得号码牌
{
    return aao_copy_data_base->search_student_gameid(student_id);
}
Obj_Player Sports_Meeting::aao_get_player(long student_id)//利用教务数据库从学号获得Player
{
    return aao_copy_data_base->search_student(student_id);
}

//state==0
void Sports_Meeting::set_up_aao_copy(AAO_Copy* a_c)//指定获得数据的AAO_Copy
{
    aao_copy_data_base = a_c;
}

void Sports_Meeting::sign_up(int game_id, long student_id)//按学号给该学生报名id为game_id的项目
{
    if(state_n!=0)return;
    int gid = (aao_copy_data_base->search_student_gameid(student_id));
    if(gid==-2)return;//无此人
    if(gid==-1)//有此人但不在系统中，没有号码牌
    {
        Obj_Player npy=aao_copy_data_base->search_student(student_id);
        npy.id = p_player_num;
        players[p_player_num]=npy;p_player_num+=1;
        aao_copy_data_base->set_game_id(student_id, npy.id);//分配号码牌
        gid = npy.id;
    }
    games[game_id].add_player(&players[gid]);
}
void Sports_Meeting::unsign(int game_id, long student_id)//把这个学生从那个项目中除名
{
    if(state_n!=0)return;
    Obj_Player py = (aao_copy_data_base->search_student(student_id));
    games[game_id].delete_player(py.id);
}

Single_Game* Sports_Meeting::add_game()//添加一个项目，并返回它的指针
{
    if(state_n!=0)return NULL;
    games[p_game_num]=Single_Game();
    p_game_num+=1;
    return &games[p_game_num-1];
}
void Sports_Meeting::delete_game(int game_id)//删除一个项目
{
    if(state_n!=0)return;
    int i;
    for(i=game_id+1;i<p_game_num;i++)
    {
        games[i-1]=games[i];
    }
    p_game_num-=1;
}
void Sports_Meeting::print_check()//输出核对表
{
    std::ostringstream *outputs;
    outputs = new std::ostringstream[num_of_school()];
    int i;
    for(i=0;i<num_of_school();i++)
    {
        outputs[i]<<schools[i].name<<"学生报名信息核对表"<<std::endl;
        outputs[i]<<"学号;姓名;性别;所报项目;号码牌;"<<std::endl;
    }
    Obj_Player* py;
    for(i=0;i<num_of_game();i++)
    {
        std::queue<Obj_Player*> pys;
        games[i].output_signed_players(pys);
        while(!pys.empty())
        {
            py = pys.front();pys.pop();
            int sid = py->school_id;
            outputs[sid]<<py->student_id<<";"<<py->name<<";";
            if(py->gender == true)
            {
                outputs[sid]<<"男;";
            }
            else
            {
                outputs[sid]<<"女;";
            }
            outputs[sid]<<games[i].name<<";";
            if(py->id<1000)outputs[sid]<<"0";
            if(py->id<100)outputs[sid]<<"0";
            if(py->id<10)outputs[sid]<<"0";
            outputs[sid]<<py->id<<";";
            outputs[sid]<<std::endl;
        }
    }
    std::ofstream oss;
    oss.open("output.txt");

    for(i=0;i<num_of_school();i++)
    {
        oss<<outputs[i].str();
    }
}

int Sports_Meeting::num_of_game()
{
    return p_game_num;
}
void Sports_Meeting::copy_school()//从教务系统中抄写学校信息
{
    p_school_num = aao_copy_data_base->num_of_school();
    for(int i=0;i<p_school_num;i++)
    {
        schools[i] = aao_copy_data_base->get_school(i);
    }
}

//state==0||state==1
void Sports_Meeting::load_aao_backup()//读取保存在自己系统中的教务拷贝数据
{
    std::ifstream iss;
    iss.open("SM_Students.txt");
    long i,n;
    iss>>n;
    qDebug()<<"Sports_Meeting::load_aao_backup() n="<<n;
    for(i=0;i<n;i++)
    {
        Obj_Player py;
        iss>>py.student_id;
        iss>>py.id;
        iss>>py.gender;
        iss>>py.degree;
        iss>>py.att_year;
        iss>>py.level;
        iss>>py.school_id;
        iss>>py.name;
        players[i]=py;p_player_num++;
    }
    iss.close();
    iss.open("SM_Schools.txt");
    iss>>n;
    for(i=0;i<n;i++)
    {
        AAO_School as;
        iss>>as.id;
        iss>>as.name;
        as.points_sum_female=0;
        as.points_sum_male=0;
        schools[p_school_num]=as;p_school_num++;
    }
    iss.close();
}
void Sports_Meeting::save_aao_backup()//保存保存在自己系统中的教务拷贝数据
{
    std::ofstream oss;
    oss.open("SM_Students.txt");
    long i,n;
    n=p_player_num;
    oss<<n<<std::endl;
    for(i=0;i<n;i++)
    {
        Obj_Player py;
        py = players[i];
        oss<<py.student_id<<" ";
        oss<<py.id<<" ";
        oss<<py.gender<<" ";
        oss<<py.degree<<" ";
        oss<<py.att_year<<" ";
        oss<<py.level<<" ";
        oss<<py.school_id<<" ";
        oss<<py.name<<std::endl;
    }
    oss.close();
    oss.open("SM_Schools.txt");
    n=p_school_num;
    oss<<n<<std::endl;
    for(i=0;i<n;i++)
    {
        AAO_School as;
        as=schools[i];
        oss<<as.id<<" ";
        oss<<as.name<<std::endl;
    }
    oss.close();
}

void Sports_Meeting::output_sign_up_information(std::queue<Obj_Player*> &pys, int n, int school_id)//输出指定学院的指定项目的所有报名的运动员
{
    std::queue<Obj_Player*> sub;
    games[n].output_signed_players(sub);
    while(!sub.empty())
    {
        if(sub.front()->school_id==school_id)pys.push(sub.front());
        sub.pop();
    }
}
void Sports_Meeting::output_sign_up_information(std::queue<Obj_Player*> &pys, int n)//输出指定项目的所有报名的运动员
{
    std::queue<Obj_Player*> sub;
    games[n].output_signed_players(pys);
}
void Sports_Meeting::output_games(std::queue<Single_Game*> &gms)//输出所有的参赛项目
{
    int i;
    for(i=0;i<p_game_num;i++)
    {
        gms.push(&games[i]);
    }
}
Single_Game* Sports_Meeting::get_game(int n)//返回第n个参赛项目
{
    return &games[n];
}
Obj_Player* Sports_Meeting::get_player(long n)//获得号码牌为n的player
{
    return &players[n];
}

//比赛状态
int Sports_Meeting::state(){return state_n;}//返回比赛的进行状态
int Sports_Meeting::push_state()//推进比赛的状态
{
    if(state_n!=0)return -1;
    state_n=1;
    for(int i=0; i<p_game_num; i++)
    {
        games[i].push_state();
    }
    return 0;
}
//state==1
void Sports_Meeting::count_points()//计算各学院的男/女总分
{
    int i,j;
    //重置所有总分
    for(i=0;i<p_school_num;i++)
    {
        schools[i].points_sum_male=0;
        schools[i].points_sum_female=0;
    }
    //读取各个项目的加分并加到总分中
    std::queue<Obj_Player*> rank_list;
    for(i=0;i<p_game_num;i++)
    {
        games[i].output_final_ranking(rank_list);
        for(j=1;j<=5;j++)
        {
            if(rank_list.empty())break;
            if(rank_list.front()->gender)
            {
                schools[rank_list.front()->school_id].points_sum_male += place_to_point(j);
            }
            else
            {
                schools[rank_list.front()->school_id].points_sum_female += place_to_point(j);
            }
            rank_list.pop();
        }
    }
}


void Sports_Meeting::set_up_file_helper(File_Helper &file_helper)
{
    int i;
    for(i=0;i<p_player_num;i++)
    {
        file_helper.add_player(players[i]);
    }
}
