#include <time.h>
#include <stdio.h>

#include "../Global/headers/Global_variables.h"

void _calc_days_months_years_and_day_of_week(void);     // считает дни, месяцы, годы и дни недели
int _calc_hours(void);                                  // считает часы, возвращает дни
int _calc_minutes(void);                                // считает минуты, возвращает часы
int _calc_seconds(void);                                // считает секунды, возвращает минуты

void _time(void) {                                      // заполняет массив отвечающий за время значениями текущего времени
    p_time_array[7] = time(NULL);
    _calc_days_months_years_and_day_of_week();
}
// time_array
void _calc_days_months_years_and_day_of_week(void) {    // считает дни, месяцы, годы и дни недели
    int days = _calc_hours();
    int day_of_week = days % 7;
    day_of_week += first_day_of_week;
    if(day_of_week >= 7)
        day_of_week -= 7;
    p_time_array[6] = day_of_week;
    p_time_array[0] = 1970;
    while(days >= 0) {
        if(days >= amount_days_in_month[month_counter]) {
            days -= amount_days_in_month[month_counter];
            (*p_month_counter)++;
        }
        else {
            if(days > 0) {
                p_time_array[2] = days;
                days -= amount_days_in_month[month_counter];
            }
            else {
                p_time_array[2] = amount_days_in_month[month_counter];
                days = -1;
                p_time_array[1]--;
                *p_last_day_pointer = 1;
            }
        }
        if(month_counter == 12) {
            *p_month_counter = 0;
            (*p_high_year_pointer)++;
            p_time_array[0]++;
        }
        if(high_year_pointer == 4) 
            *p_high_year_pointer = 0;
        if((high_year_pointer == 0) && (month_counter == 0)) {
            p_amount_days_in_month[1] = 29;
        }
        if((high_year_pointer != 0) && (amount_days_in_month[1] == 29)) {
            p_amount_days_in_month[1] = 28;
        }
    }
    if(last_day_pointer == 0)
        p_time_array[1] = month_counter + 1;
    else
        if(month_counter == 0)
            p_time_array[1] = 12;
        else
            p_time_array[1] = month_counter;
    *p_month_counter = 0;
    *p_high_year_pointer = 2; 
}

int _calc_hours(void) {                                 // считает часы, возвращает дни
    int hours = _calc_minutes();
    hours += time_zone;                 // закоментировать если некорректно работает создание даты по времени, и наоборот
    int days;
    p_time_array[3] = hours % 24;
    days = hours / 24;
    days++;
    return days;
}

int _calc_minutes(void) {                               // считает минуты, возвращает часы
    int minutes = _calc_seconds();
    int hours;
    p_time_array[4] = minutes % 60;
    hours = minutes / 60;
    return hours;
}

int _calc_seconds(void) {                               // считает секунды, возвращает минуты
    int minutes;
    p_time_array[5] = time_array[7] % 60;
    minutes = time_array[7] / 60;
    return minutes;
}

// void _time_zero(void) {
//     for(int i = 0; i < 8; i++) {
//         p_time_array[i] = 0;
//     }
// }