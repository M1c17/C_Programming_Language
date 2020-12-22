#include <stdio.h>

int day_of_the_year(int yearday, int month, int day);
void month_day(int year, int day_year, int *month, int *day);

static char day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main(){

    int year, month, day, day_year, leap;
   
    for (year = 2000; year <= 2020; year++){
        leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (leap){
            printf("%d\n", year);
        }
    }

    for (year = 2016; year <= 2020; year++){
        for (day_year = 1; day_year <= 366; day_year++){
            month_day(year, day_year, &month, &day);
            printf("day_year: %d, month: %d, day: %d, year: %d\n", day_year, month, day, year);
            //day_of_the_year(year, month, day);
            // if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            //     printf("year: %d, year_day: %d\n", year, day_of_the_year(year, month, day));
            // }
            
        }
    }   
    return 0;
}


/* converts the month and day into day of the year 
day_of_the_year: set day of year from month & day
return day. */
int day_of_the_year(int year, int month, int day){
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    for (i = 1; i < month; i++){
        day += day_table[leap][i];
    }
    return day;
}

/*convert the day of the year in to the day of the month 
month_day: set month, day from day of the year */
void month_day(int year, int day_year, int *month, int *day){

    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    for (i = 1; day_year > day_table[leap][i]; i++){
        day_year -= day_table[leap][i];
    } 
    *month = i;
    *day = day_year;      
}

