#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class B;
B main_v;

class A
{
public:
    int f()
    {
        main_v.a;
    }
};
class B
{
public:
    A a;
};

int main(int argc, char *argv[])
{
    return 0;
}
