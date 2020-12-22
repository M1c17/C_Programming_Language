#include <stdio.h>

/*Rewrite the programs day_of_year and month_day with pointers instead of indexes */

int day_of_year(int year, int month, int day);
void month_day(int year_day, int year, int *month, int *day);

static char day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(){

    int year, month, day, year_day;

    for ( year = 2016; year <= 2020; ++year){
        for (year_day = 1; year_day <= 366; ++year_day){
            month_day(year_day, year, &month, &day);
            if ((day_of_year(year, month, day)) == -1){
                printf("Error: Invalid Date\n");
            }else if ((day_of_year(year, month, day)) != year_day){
                printf("Error: %d not equal %d\n", year_day, day_of_year(year, month, day));
            }else{
                printf("year_day %d\t", year_day);
                printf("year: %d, month: %d, day: %d\n", year, month, day);
            }
        }
    }
    return 0;
}

int day_of_year(int year, int month, int day){

    int leap;
    leap = (year %4 == 0 && year%100 != 0) || year%400 == 0;
    // point p in the first month of the correct array ? leap : not leap
    // char *p = &day_table[leap][1];
    char *p = day_table[leap];

    if (month < 1 || month > 12){
        return -1;
    }
    if (day < 1 || day > day_table[leap][month]){
        return -1;
    }

    while (--month){
        //move pointer to next month
        // p += sizeof(char);
        p++;
        day += *p;
        // ++p;
    }
    return day;
}


void month_day(int year_day, int year, int *month, int *day){

    int i, leap;

    leap = (year %4 == 0 && year%100 != 0) || year%400 == 0;
    // char *p = &day_table[leap][1];
    char *p = day_table[leap];
    
    if (year < 1){
        *month = -1;
        *day = -1; 
        return;
    }

    for (i = 1; year_day > *++p; ++i){
        year_day -= *p;
        //++p;
    }

    if (*month > 12 && year_day > day_table[leap][12]){
        *month = -1;
        *day = -1;
    }
    else{
        *month = i;
        //*month = p - *(day_table + leap);
        *day = year_day;
    }
}