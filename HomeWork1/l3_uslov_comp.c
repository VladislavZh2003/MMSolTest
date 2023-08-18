#include <stdio.h>
#define DEBUG
int main()
{
#ifdef DEBUG//proverqwame dali debug sashtestwuwa
    printf("Debug mode is on\n");
#else
    printf("Debug mode is off\n");
#endif
    return 0;
}
