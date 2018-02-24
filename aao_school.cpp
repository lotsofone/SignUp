#include "aao_school.h"

AAO_School::AAO_School()
{
    points_sum_female=0;
    points_sum_male=0;
}

long AAO_School::points_sum(){return points_sum_female+points_sum_male;}

bool operator < (const AAO_School &u1, const AAO_School &u2)
{
    return u1.points_sum_female+u1.points_sum_male<u2.points_sum_female+u2.points_sum_male;
}
