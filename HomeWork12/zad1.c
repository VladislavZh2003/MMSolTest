#include <stdio.h>
#include <stdarg.h>
//#include <conio.h>
#include <time.h>

int printf_time(const char *format, ...);

int main()
{
    printf_time("%d %d", 10, 20);

    return 0;
}

int printf_time(const char *format, ...)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%d.%d.%d - %d:%d:%d]", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

}


// int main()
// {
//     time_t t;
//     t = time(NULL);
//     struct tm tm = *localtime(&t);
//     printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
//     getch();
//     return 0;
// }


// int main()
// {
//     time_t t;
//     t = time(NULL);
//     struct tm tm;
// 	tm = *localtime(&t);
//     printf("Current Time: %d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
//     getch();
//     return 0;
// }
