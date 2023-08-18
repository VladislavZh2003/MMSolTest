#include <stdio.h>
int main(int argc, char *argv[])
{
    int myNumber = 48;
    int base = 2;
    while (myNumber > 0)
    {
        int remainder = myNumber % base;
        printf("%d - remeinder : %d \n", myNumber, remainder);
        myNumber = myNumber / base;
    } // wnd while
} // end main()