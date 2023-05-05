#include <stdio.h>

void action(int a)
{
    printf("%d", a);
}

int main()
{
    void (*action1)(int a, char c) = action;
    action1(1, 'a');
}