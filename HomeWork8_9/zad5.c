#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int year : 12;    
    unsigned int month : 4;    
    unsigned int day : 5;     
    unsigned int hour : 5;     
    unsigned int minutes : 6;  
    unsigned int seconds : 6;  
} MyTime;

int isLeapYear(MyTime t) {
    unsigned int year = t.year;
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0;
}

int totalDaysInYear(MyTime t) {
    return isLeapYear(t) ? 366 : 365;
}

void printMonth(MyTime t) {
    const char* monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    printf("%s\n", monthNames[t.month - 1]);
}

int secondsPassed(MyTime t) {
    int days = t.day - 1;
    switch (t.month - 1) {
        case 11: days += 30; 
        case 10: days += 31; 
        case 9: days += 30;  
        case 8: days += 31;  
        case 7: days += 31; 
        case 6: days += 30; 
        case 5: days += 31; 
        case 4: days += 30;  
        case 3: days += 31;  
        case 2: days += isLeapYear(t) ? 29 : 28; 
        case 1: days += 31;  
    }

    int years = t.year - 1970;
    int totalDays = years * totalDaysInYear(t) + days;

    int hours = totalDays * 24 + t.hour;
    int minutes = hours * 60 + t.minutes;
    int seconds = minutes * 60 + t.seconds;

    return seconds;
}

int main() {
    MyTime t = {2023, 8, 7, 12, 30, 45};
    printf("Size of MyTime: %zu bytes\n", sizeof(MyTime));
    printf("Is leap year? %s\n", isLeapYear(t) ? "Yes" : "No");
    printf("Total days in the year: %d\n", totalDaysInYear(t));
    printf("Month: ");
    printMonth(t);
    printf("Seconds passed since January 1, 1970: %d\n", secondsPassed(t));
    return 0;
}