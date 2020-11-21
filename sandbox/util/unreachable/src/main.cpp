#include <core/util/unreachable.h>

#include <cstdio>

using namespace caverneer;

int main()
{
    UNREACHABLE("This is %s reachable!", "totally");

    printf("Hello, world!");
}
