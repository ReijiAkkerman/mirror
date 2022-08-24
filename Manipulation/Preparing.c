#include <stdio.h>
#include <stdlib.h>

#include "Global/Global_variables.h"
#include "Data/Data.h"

void _skills_preparing(void);
void _aims_preparing(void);
void _tasks_preparing(void);

void _daily(void) {                         // обновляет выводимые данные каждые день и месяц в соответствующих категориях
    char temp[64];
    char* p_temp = temp;
    int temp_date_size[] = {0, 0, 0};
    int temp_date[] = {0, 0, 0};
    int counter = 0;
    _time();
    FILE* fp;
    if((fp = fopen("filename.txt", "r")) == NULL) {
        perror("Ошибка чтения имени файла");
        exit(0);
    }
    fgets(temp, 64, fp);
    _r_text_size(p_temp);
    for(int i = 17; i < array[0] - 3; i++) {
        temp_date_size[counter]++;
        if(temp[i] == '.') 
            counter++;
    }
    char* array_[3];
    array_[0] = malloc(temp_date_size[0]);
    array_[1] = malloc(temp_date_size[1]);
    array_[2] = malloc(temp_date_size[2]);
    counter = 0;
    for(int i = 0; i < 3; i++)
        temp_date_size[i] = 0;
    for(int i = 17; i < array[0] - 3; i++) {
        array_[counter][temp_date_size[counter]] = temp[i];
        temp_date_size[counter]++;
        if(temp[i] == '.')
            counter++;
    }
    for(int i = 0; i < 3; i++)
        temp_date[i] = _r_num_strToInt(array_[i]);
    for(int i = 0; i < 5; i++) {
        if(temp_date[2] != time_array[2]) {
            tasks[i].today_received_exp = 0;
            tasks[i].current_exp = 0;
            aims[i].today_received_exp = 0;
            skills[i].today_received_exp = 0;
        }
        if(temp_date[1] != time_array[1])
            aims[i].current_exp = 0;
    }
}

void _preparing(void) {                     // подготавливает данные к записив целочисленном виде
    *p_skills_struct_counter = 0;
    *p_aims_struct_counter = 0;
    *p_tasks_struct_counter = 0;
    _tasks_preparing();
    _aims_preparing();
    _skills_preparing();
}

void _skills_preparing(void) {              // подготавливает процентное соотношение в skills
    for(int i = 0; i < amount_of_structures; i++) {
        skills[i].current_exp += tasks[i].today_received_exp;
        skills[i].today_full_exp = tasks[i].today_full_exp;
        skills[i].today_received_exp = tasks[i].current_exp;
        tasks[i].today_received_exp = 0;

        if(skills[i].today_full_exp == 0)
            skills[i].today_percentage = 0;
        else
            skills[i].today_percentage = (int)(skills[i].today_received_exp * 100) / skills[i].today_full_exp;
        if(skills[i].full_exp == 0)
            skills[i].common_percentage = 0;
        else
            skills[i].common_percentage = (int)(skills[i].current_exp * 100) / skills[i].full_exp;
    }
}

void _aims_preparing(void) {                // подготавливает процентное соотношение в aims
    for(int i = 0; i < amount_of_structures; i++) {
        aims[i].current_exp += tasks[i].today_received_exp;
        aims[i].today_full_exp = tasks[i].full_exp;
        aims[i].today_received_exp = tasks[i].current_exp;

        if(aims[i].today_full_exp == 0)
            aims[i].today_percentage = 0;
        else
            aims[i].today_percentage = (int)(aims[i].today_received_exp * 100) / aims[i].today_full_exp;
        if(aims[i].full_exp == 0)
            aims[i].common_percentage = 0;
        else
            aims[i].common_percentage = (int)(aims[i].current_exp * 100) / aims[i].full_exp;
    }
}

void _tasks_preparing(void) {               // подготавливает процентное соотношение в tasks
    for(int i = 0; i < amount_of_structures; i++) {
        tasks[i].current_exp += tasks[i].today_received_exp;
        tasks[i].full_exp = tasks[i].today_full_exp;

        if(tasks[i].today_full_exp == 0) 
            tasks[i].today_percentage = 0;
        else
            tasks[i].today_percentage = (int)(tasks[i].today_received_exp * 100) / tasks[i].today_full_exp;
        if(tasks[i].full_exp == 0)
            tasks[i].common_percentage = 0;
        else
            tasks[i].common_percentage = (int)(tasks[i].current_exp * 100) / tasks[i].full_exp;
    }
}