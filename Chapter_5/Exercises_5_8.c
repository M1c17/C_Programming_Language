#include <stdio.h>

/* There is no checking error in day_of_year or month_of_day remedy that error */

int day_of_year(int year, int month, int day);
void month_day(int year_day, int year, int *month, int *day);

static char day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(){

    int year, year_day, month, day; 

    for(year = 2019; year <= 2020; ++year){
        for(year_day = 1; year_day <= 366; ++year_day){
            month_day(year_day, year, &month, &day);
            if (day_of_year(year, month, day) == -1){
                printf("Error: Invalid Dates\n");
            }
            else if(day_of_year(year, month, day) != year_day){
                printf("Error: %d not equal %d\n", year_day, day_of_year(year, month, day));
            }
            else{
                //printf("year: %d, year_day: %d, day: %d\n", year, day_of_year(year, month, day), day);
                printf("year_day %d\t", year_day);
                printf("year: %d, month: %d, day: %d\n", year, month, day);  
            }
        }
    }

}

/* converts the month and day into day of the year 
day_of_the_year: set day of year from month & day
return day. */
int day_of_year(int year, int month, int day){

    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    // if (year < 1 ||  month > 12 || month < 1 || day < 1){
    //     return -1;
    // }
    // if (day > day_table[leap][month]){
    //     return -1;
    // }
    if (month < 1 || month > 12){
        return -1;
    }
    if (day < 1 || day > day_table[leap][month]){
        return -1;
    }

     for (i = 1; i < month; i++){
        day += day_table[leap][i];
    }
    return day;
}

/*convert the day of the year in to the day of the month 
month_day: set month, day from day of the year */
void month_day(int year_day, int year, int *month, int *day){

    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (year < 1){
        *month = -1;
        *day = -1;
        return;
    }
    
    for (i = 1; i <= 12 && year_day > day_table[leap][i]; i++){
        year_day -= day_table[leap][i];
    }
    if (i > 12 && year_day > day_table[leap][12]){
        *month = -1;
        *day = -1;
    } else {
        *month = i;
        *day = year_day;
    }
}


