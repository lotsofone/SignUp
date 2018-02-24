#ifndef AAO_SCHOOL_H
#define AAO_SCHOOL_H
#include <string>

class AAO_School
{
public:
    int id;//学院的id
    long points_sum_male;
    long points_sum_female;
    std::string name;//学院名字
    AAO_School();
    long points_sum();//返回团体总分
    friend bool operator < (const AAO_School &u1, const AAO_School &u2);
};
bool operator < (const AAO_School &u1, const AAO_School &u2);

#endif // AAO_SCHOOL_H
