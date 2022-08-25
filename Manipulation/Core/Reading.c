#include <stdio.h>
#include <stdlib.h>

#include "../Global/headers/Global_variables.h"
#include "../Data/headers/Data.h"

void _short_reading_skills(char* p_temp);
void _short_reading_aims(char* p_temp);
void _short_reading_tasks(char* p_temp);

void _reading(void) {                       // считывает данные с файла
    *p_common_struct_counter = 0;
    *p_skills_struct_counter = 0;
    *p_aims_struct_counter = 0;
    *p_tasks_struct_counter = 0;
    *p_common_choice_counter = 0;
    *p_skills_choice_counter = 0;
    *p_aims_choice_counter = 0;
    *p_tasks_choice_counter = 0;
    *p_struct_counter = 0;
    int number;
    char* full_path = malloc(256);
    char temp[256];
    char* p_temp = temp;
    FILE* fp;
    if((fp = fopen("Data/filename.txt", "r")) == NULL) {
        perror("Ошибка чтения имени файла");
        exit(0);
    }
    fgets(full_path, 256, fp);
    fclose(fp);
    if((fp = fopen(full_path, "r")) == NULL) {
        perror("Ошибка чтения файла");
        exit(0);
    }    
    while((fgets(temp, 256, fp)) != NULL) {
// common
        switch(struct_counter) {
            case 0:
                if(common_struct_counter < 3) {
                    number = _r_num_strToInt(temp);
                    about_user[common_struct_counter].value_common = number;
                    (*p_common_struct_counter)++;
                }
                if(common_struct_counter == 3) {
                    *p_common_struct_counter = 0;
                    (*p_struct_counter)++;
                }
                break;
            case 1:
                if(common_struct_counter < 3) {
                    number = _r_num_strToInt(temp);
                    users_wealth[common_struct_counter].value_common = number;
                    (*p_common_struct_counter)++;
                }
                if(common_struct_counter == 3)
                    (*p_struct_counter)++;
                break;
// skills
            case 2:
                _short_reading_skills(p_temp);
                if(skills_struct_counter == 5)
                    (*p_struct_counter)++;
                break;
// aims
            case 3:
                _short_reading_aims(p_temp);
                if(aims_struct_counter == 5)
                    (*p_struct_counter)++;
                break;
// tasks
            case 4:
                _short_reading_tasks(p_temp);
                if(tasks_struct_counter == 5)
                    (*p_struct_counter)++;
                break;
        }
    }
    fclose(fp);
}

int _r_num_strToInt(char* str_arg) {        // возвращает число полученное изначально в строковом формате - в формате числа
    int x = 0;
    int t = 0;
    _r_text_size(str_arg);
    p_array[0]--;
    int num_array[array[0]];
    for(int i = 0; i < array[0]; i++)
        num_array[i] = str_arg[i] & 0x0f;
    for(int i = array[0]; i > 0; i--) {
        int factor = _r_digits_multiply(i);
        x += num_array[t] * factor;
        t++;
    }
    return x;
}

int _r_digits_multiply(int digits) {        // возвращает числу записанному ранее в строковом формате - нужную разрядность
    int x = 1;
    for(int i = 0; i < digits - 1; i++)
        x *= 10;
    return x;
}

char* _r_clear_text(char* p_temp) {         // возвращает текст без последующего за ним в изначальном формате мусора
    _r_text_size(p_temp);
    p_array[0]--;
    char* str_array = malloc(array[0]);
    for(int i = 0; i < array[0]; i++)
        str_array[i] = p_temp[i];
    return str_array;
}

void _short_reading_skills(char* p_temp) {  // упрощает запись навыков в функции _reading
    char* str_array;
    int x;
    switch(skills_choice_counter) {
        case 0:
            str_array = _r_clear_text(p_temp);
            skills[skills_struct_counter].skill_name = str_array;
            break;
        case 1:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].skill_level = x;
            break;
        case 2:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].today_received_exp = x;
            break;
        case 3:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].today_full_exp = x;
            break;
        case 4:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].today_percentage = x;
            break;
        case 5:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].current_exp = x;
            break;
        case 6:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].full_exp = x;
            break;
        case 7:
            x = _r_num_strToInt(p_temp);
            skills[skills_struct_counter].common_percentage = x;
            break;
    }
    (*p_skills_choice_counter)++;
    if(skills_choice_counter == 8) {
        *p_skills_choice_counter = 0;
        (*p_skills_struct_counter)++;
    }
}

void _short_reading_aims(char* p_temp) {    // упрощает запись целей в функции _reading
    char* str_array;
    int x;
    switch(aims_choice_counter) {
        case 0:
            str_array = _r_clear_text(p_temp);
            aims[aims_struct_counter].aim_name = str_array;
            break;
        case 2:
            x = _r_num_strToInt(p_temp);
            aims[aims_struct_counter].today_received_exp = x;
            break;
        case 3:
            x = _r_num_strToInt(p_temp);
            aims[aims_struct_counter].today_full_exp = x;
            break;
        case 4:
            x = _r_num_strToInt(p_temp);
            aims[aims_struct_counter].today_percentage = x;
            break;
        case 5:
            x = _r_num_strToInt(p_temp);
            aims[aims_struct_counter].current_exp = x;
            break;
        case 6:
            x = _r_num_strToInt(p_temp);
            aims[aims_struct_counter].full_exp = x;
            break;
        case 7:
            x = _r_num_strToInt(p_temp);
            aims[aims_struct_counter].common_percentage = x;
            break;
    }
    (*p_aims_choice_counter)++;
    if(aims_choice_counter == 1)
        *p_aims_choice_counter = 2;
    if(aims_choice_counter == 8) {
        *p_aims_choice_counter = 0;
        (*p_aims_struct_counter)++;
    }
}

void _short_reading_tasks(char* p_temp) {   // упрощает запись задач в функции _reading
    char* str_array;
    int x;
    switch(tasks_choice_counter) {
        case 0:
            str_array = _r_clear_text(p_temp);
            tasks[tasks_struct_counter].task_name = str_array;
            break;
        case 2:
            x = _r_num_strToInt(p_temp);
            tasks[tasks_struct_counter].today_received_exp = x;
            break;
        case 3:
            x = _r_num_strToInt(p_temp);
            tasks[tasks_struct_counter].today_full_exp = x;
            break;
        case 4:
            x = _r_num_strToInt(p_temp);
            tasks[tasks_struct_counter].today_percentage = x;
            break;
        case 5:
            x = _r_num_strToInt(p_temp);
            tasks[tasks_struct_counter].current_exp = x;
            break;
        case 6:
            x = _r_num_strToInt(p_temp);
            tasks[tasks_struct_counter].full_exp = x;
            break;
        case 7:
            x = _r_num_strToInt(p_temp);
            tasks[tasks_struct_counter].common_percentage = x;
            break;
    }
    (*p_tasks_choice_counter)++;
    if(tasks_choice_counter == 1)
        *p_tasks_choice_counter = 2;
    if(tasks_choice_counter == 8) {
        *p_tasks_choice_counter = 0;
        (*p_tasks_struct_counter)++;
    }
}