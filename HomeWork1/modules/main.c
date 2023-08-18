
// ============================================================================
// MMSolution - 2023 - Day 02 ::
// ============================================================================



#include <stdio.h>
//#include "my_math.c" << - ГРЕШКА ОТ ВЧЕРА /ПРЕДИШНОТО УПРАЖНЕНИЕ/ ! ! !
#include "my_math.h" // << включване на хедъра : "my_math.h"



int main() {

double number = 5.75684; // declare and define 
double calc_square = square(number);
double calc_cube = cube(number);


printf("The square of %.5f is %.5f \n", number, calc_square);

printf("The cube of %.5f is %.5f \n", number, calc_cube);


return 0;

} // end of main()



/*

HOW TO COMPILE ::

[ 1 ] : in one row :
> gcc main.c my_math.c -lm -o program -Wall -Wextra -Werror
{ OR }
> gcc my_main.c my_math.c -lm -o program -Wall -Wextra

OR 

[ 2 ] : by linker :
> gcc -c my_math.c -o my_math.o 
> gcc -c my_main.c -o my_main.o
> gcc my_math.o my_main.o -lm -o program


*/
