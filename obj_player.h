#ifndef OBJ_PLAYER_H
#define OBJ_PLAYER_H
#include <string>
class Obj_Player
{
public:
    long student_id;//在教务系统中的id
    long id;//在运动会系统中的id，即号码牌编号
    bool gender;//男1 女0
    int degree;//1大学生 2硕士研究生 3博士研究生
    int att_year;//入学年份
    int level;//当前上几年级。不排除留级生和跳级生的可能
    int school_id;//学院号
    std::string name;//名字
    Obj_Player();
    /*Obj_Player(long igame_id, long istudent_id, std::string iname, bool igender, int icollege_id, int iclass_id,
                int idegree, int iatt_year, int ilevel);*/
    //long id();
};

#endif // OBJ_PLAYER_H
