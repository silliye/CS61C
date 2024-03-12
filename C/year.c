/**
* Display the number of days in a month.
* @author : fuck you 
* @date : Sept 19, 2023
* @version : 1.0.0
*/


#include <stdio.h>
#define NO_OF_MONTHS 12

int is_leap_year(int year) {
    return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0;
}

int main() {
    int normal_year_days[NO_OF_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_year_days[NO_OF_MONTHS] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, year;

    printf("Please enter a month and year (1=Jan., 2=Feb., etc.) ");
    do {
        scanf("%d %d", &month, &year);
        if ((month < 1) || (month > 12)) {
            break;
        } 
        else if(is_leap_year(year) ) {
            printf("\nThe number of days in month : year (%d  %d) is %d\n", month, year, leap_year_days[month - 1]);
        }
        else {
            printf("\nThe number of days in month : year (%d  %d) is %d\n", month, year, normal_year_days[month - 1]);
        }
    } while (1);
}
