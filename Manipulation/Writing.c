#include <stdio.h>
#include <stdlib.h>

#include "Global/Global_variables.h"
#include "Data/Data.h"

char* _full_path(void);                                 // возвращает в одной строке имя пути и имя файла данных
char* _filename(void);                                  // возвращает имя файла куда будут записываться итоговые данные
int _filename_size(void);                               // возвращает количество байт требуемое для формирования имени файла данных
char* _path(int option_of_path);                        // возвращает имя пути по которому расположены файлы с данными
int _path_size(void);                                   // возвращает количество байт требуемое для формирования имени пути к файлам данных
char* _data_preparing(void);                            // возвращает массив данных для записи
int _data_size(void);                                   // возвращает количество байт необходимое для создания массива данных
void _short_write_int_skills(char* data_array, char* temp, int* p_struct_counter, int* p_counter, __skills* p_skills);   // сокращенная запись навыков
void _short_write_int_aims(char* data_array, char* temp, int* p_struct_counter, int* p_counter, __aims* p_aims);         // сокращенная запись целей
void _short_write_int_tasks(char* data_array, char* temp, int* p_struct_counter, int* p_counter, __tasks* p_tasks);      // сокращенная запись задач

void _writing(void) {                                   // запись итоговых данных
    char* full_path = _full_path();
    char* a = _data_preparing();
    FILE* fp;
    if((fp = fopen(full_path, "w")) == NULL) {
        perror("Ошибка создания файла");
        exit(0);
    }
    fputs(a, fp);
    fclose(fp);
    if((fp = fopen("filename.txt", "w")) == NULL) {
        perror("Ошибка чтения файла");
        exit(0);
    }
    fputs(full_path, fp);
    fclose(fp);
}

char* _full_path(void) {                                // возвращает в одной строке имя пути и имя файла данных
    int full_path_size;
    char* path = _path(option_of_path);
    int path_size = _path_size();
    char* filename = _filename();
    int filename_size = _filename_size();
    full_path_size = path_size + filename_size;
    char* full_path = malloc(full_path_size);
    int counter = 0;
    for(int i = 0; i < path_size; i++) {
        full_path[counter] = path[i];
        counter++;
    }
    for(int i = 0; i < filename_size; i++) {
        full_path[counter] = filename[i];
        counter++;
    }
    return full_path;
}

char* _filename(void) {                                 // возвращает имя файла куда будут записываться итоговые данные
    int size = _filename_size();
    int counter = 0;
    char* format = ".txt";
    char* p_filename = malloc(size);
    char* ca;
    char* cb;
    char* cc;
    ca = _r_intToStr(time_array[0]);
    for(int i = 0; i < times_sizes[0]; i++) {
        p_filename[counter] = ca[i];
        counter++;
    }
    p_filename[counter] = '.';
    counter++;
    cb = _r_intToStr(time_array[1]);
    for(int i = 0; i < times_sizes[1]; i++) {
        p_filename[counter] = cb[i];
        counter++;
    }
    p_filename[counter] = '.';
    counter++;
    cc = _r_intToStr(time_array[2]);
    for(int i = 0; i < times_sizes[2]; i++) {
        p_filename[counter] = cc[i];
        counter++;
    }
    _r_text_size(format);
    for(int i = 0; i < array[0]; i++) {
        p_filename[counter] = format[i];
        counter++;
    }
    p_filename[counter] = '\0';
    return p_filename;
}

int _filename_size(void) {                              // возвращает количество байт требуемое для формирования имени файла данных
    int size = 0;
    _time();
    _r_digits_(time_array[0]);
    times_sizes[0] = digits;
    size += digits;
    _r_digits_(time_array[1]);
    times_sizes[1] = digits;
    size += digits;
    _r_digits_(time_array[2]);
    times_sizes[2] = digits;
    size += digits + 7;
    return size;
}

char* _path(int option_of_path) {                       // возвращает имя пути по которому расположены файлы с данными
    char* path;
    switch(option_of_path) {
        case 1:
            path = "Data/Reiji/Stats/";
            break;
        case 2:
            path = "Data/Reiji/Money/";
            break;
    }
    return path;
}

int _path_size(void) {                                  // возвращает количество байт требуемое для формирования имени пути к файлам данных
    char* path = _path(option_of_path);
    int size = 0;
    _r_text_size(path);
    size += array[0];
    return size;
}

char* _data_preparing(void) {                           // возвращает массив данных для записи
    *p_common_struct_counter = 0;
    *p_skills_struct_counter = 0;
    *p_aims_struct_counter = 0;
    *p_tasks_struct_counter = 0;
    
    int x = _data_size();
    int counter = 0;
    int* p_counter = &counter;
    *p_choice = 1;
    char* temp;
    char* data_array = malloc(x);
// common
    for(int i = 0; i < 3; i++) {
        temp = _r_intToStr(about_user[common_struct_counter].value_common);
        for(int j = 0; j < digits; j++) {
            data_array[counter] = temp[j];
            counter++;
        }
        data_array[counter] = '\n';
        counter++;
        (*p_common_struct_counter)++;
    }
    *p_common_struct_counter = 0;
    for(int i = 0; i < 3; i++) {
        temp = _r_intToStr(users_wealth[common_struct_counter].value_common);
        for(int j = 0; j < digits; j++) {
            data_array[counter] = temp[j];
            counter++;
        }
        data_array[counter] = '\n';
        counter++;
        (*p_common_struct_counter)++;
    }
// skills
    for(int i = 0; i < 5; i++) {
        _r_text_size(skills[skills_struct_counter].skill_name);
        for(int j = 0; j < array[0]; j++) {
            data_array[counter] = skills[skills_struct_counter].skill_name[j];
            counter++;
        }
        data_array[counter] = '\n';
        counter++;
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        _short_write_int_skills(data_array, temp, p_skills_struct_counter, p_counter, p_skills);
        (*p_skills_struct_counter)++;
        *p_choice = 1;
    }
    *p_choice = 2;
// aims
    for(int i = 0; i < 5; i++) {
        _r_text_size(aims[aims_struct_counter].aim_name);
        for(int j = 0; j < array[0]; j++) {
            data_array[counter] = aims[aims_struct_counter].aim_name[j];
            counter++;
        }
        data_array[counter] = '\n';
        counter++;
        _short_write_int_aims(data_array, temp, p_aims_struct_counter, p_counter, p_aims);
        _short_write_int_aims(data_array, temp, p_aims_struct_counter, p_counter, p_aims);
        _short_write_int_aims(data_array, temp, p_aims_struct_counter, p_counter, p_aims);
        _short_write_int_aims(data_array, temp, p_aims_struct_counter, p_counter, p_aims);
        _short_write_int_aims(data_array, temp, p_aims_struct_counter, p_counter, p_aims);
        _short_write_int_aims(data_array, temp, p_aims_struct_counter, p_counter, p_aims);
        (*p_aims_struct_counter)++;
        *p_choice = 2;
    }
// tasks
    for(int i = 0; i < 5; i++) {
        _r_text_size(tasks[tasks_struct_counter].task_name);
        for(int j = 0; j < array[0]; j++) {
            data_array[counter] = tasks[tasks_struct_counter].task_name[j];
            counter++;
        }
        data_array[counter] = '\n';
        counter++;
        _short_write_int_tasks(data_array, temp, p_tasks_struct_counter, p_counter, p_tasks);
        _short_write_int_tasks(data_array, temp, p_tasks_struct_counter, p_counter, p_tasks);
        _short_write_int_tasks(data_array, temp, p_tasks_struct_counter, p_counter, p_tasks);
        _short_write_int_tasks(data_array, temp, p_tasks_struct_counter, p_counter, p_tasks);
        _short_write_int_tasks(data_array, temp, p_tasks_struct_counter, p_counter, p_tasks);
        _short_write_int_tasks(data_array, temp, p_tasks_struct_counter, p_counter, p_tasks);
        (*p_tasks_struct_counter)++;
        *p_choice = 2;
    }
    data_array[counter] = '\0';
    return data_array;
}

int _data_size(void) {                                  // возвращает количество байт необходимое для создания массива данных
    int counter = 0;
// common
    for(int i = 0; i < 3; i++) {
        _r_digits_(about_user[common_struct_counter].value_common);
        counter += digits;
        _r_digits_(users_wealth[common_struct_counter].value_common);
        counter += digits;
        (*p_common_struct_counter)++;
    }
    counter += 6;
// skills
    for(int i = 0; i < 5; i++) {
        _r_text_size(skills[skills_struct_counter].skill_name);
        counter += array[0];
        _r_digits_(skills[skills_struct_counter].skill_level);
        counter += digits;
        _r_digits_(skills[skills_struct_counter].today_received_exp);
        counter += digits;
        _r_digits_(skills[skills_struct_counter].today_full_exp);
        counter += digits;
        _r_digits_(skills[skills_struct_counter].today_percentage);
        counter += digits;
        _r_digits_(skills[skills_struct_counter].current_exp);
        counter += digits;
        _r_digits_(skills[skills_struct_counter].full_exp);
        counter += digits;
        _r_digits_(skills[skills_struct_counter].common_percentage);
        counter += digits;
        (*p_skills_struct_counter)++;
    }
    counter += 40;
// aims
    for(int i = 0; i < 5; i++) {
        _r_text_size(aims[aims_struct_counter].aim_name);
        counter += array[0];
        _r_digits_(aims[aims_struct_counter].today_received_exp);
        counter += digits;
        _r_digits_(aims[aims_struct_counter].today_full_exp);
        counter += digits;
        _r_digits_(aims[aims_struct_counter].today_percentage);
        counter += digits;
        _r_digits_(aims[aims_struct_counter].current_exp);
        counter += digits;
        _r_digits_(aims[aims_struct_counter].full_exp);
        counter += digits;
        _r_digits_(aims[aims_struct_counter].common_percentage);
        counter += digits;
        (*p_aims_struct_counter)++;
    }
    counter += 35;
// tasks
    for(int i = 0; i < 5; i++) {
        _r_text_size(tasks[tasks_struct_counter].task_name);
        counter += array[0];
        _r_digits_(tasks[tasks_struct_counter].today_received_exp);
        counter += digits;
        _r_digits_(tasks[tasks_struct_counter].today_full_exp);
        counter += digits;
        _r_digits_(tasks[tasks_struct_counter].today_percentage);
        counter += digits;
        _r_digits_(tasks[tasks_struct_counter].current_exp);
        counter += digits;
        _r_digits_(tasks[tasks_struct_counter].full_exp);
        counter += digits;
        _r_digits_(tasks[tasks_struct_counter].common_percentage);
        counter += digits;
        (*p_tasks_struct_counter)++;
    }
    counter += 35;
    counter++;
    *p_common_struct_counter = 0;
    *p_skills_struct_counter = 0;
    *p_aims_struct_counter = 0;
    *p_tasks_struct_counter = 0;
    return counter;
}

void _short_write_int_skills(char* data_array, char* temp, int* p_struct_counter, int* p_counter, __skills* p_skills) {      // сокращенная запись навыков
    switch(choice) {
        case 1:
            temp = _r_intToStr(p_skills[*p_struct_counter].skill_level);
            break;
        case 2:
            temp = _r_intToStr(p_skills[*p_struct_counter].today_received_exp);
            break;
        case 3:
            temp = _r_intToStr(p_skills[*p_struct_counter].today_full_exp);
            break;
        case 4:
            temp = _r_intToStr(p_skills[*p_struct_counter].today_percentage);
            break;
        case 5:
            temp = _r_intToStr(p_skills[*p_struct_counter].current_exp);
            break;
        case 6:
            temp = _r_intToStr(p_skills[*p_struct_counter].full_exp);
            break;
        case 7:
            temp = _r_intToStr(p_skills[*p_struct_counter].common_percentage);
            break;
    }
    for(int j = 0; j < digits; j++) {
        data_array[*p_counter] = temp[j];
        (*p_counter)++;
    }
    data_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_choice)++;
}

void _short_write_int_aims(char* data_array, char* temp, int* p_struct_counter, int* p_counter, __aims* p_aims) {            // сокращенная запись целей
    switch(choice) {
        case 2:
            temp = _r_intToStr(p_aims[*p_struct_counter].today_received_exp);
            break;
        case 3:
            temp = _r_intToStr(p_aims[*p_struct_counter].today_full_exp);
            break;
        case 4:
            temp = _r_intToStr(p_aims[*p_struct_counter].today_percentage);
            break;
        case 5:
            temp = _r_intToStr(p_aims[*p_struct_counter].current_exp);
            break;
        case 6:
            temp = _r_intToStr(p_aims[*p_struct_counter].full_exp);
            break;
        case 7:
            temp = _r_intToStr(p_aims[*p_struct_counter].common_percentage);
            break;
    }
    for(int j = 0; j < digits; j++) {
        data_array[*p_counter] = temp[j];
        (*p_counter)++;
    }
    data_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_choice)++;
}

void _short_write_int_tasks(char* data_array, char* temp, int* p_struct_counter, int* p_counter, __tasks* p_tasks) {         // сокращенная запись задач
    switch(choice) {
        case 2:
            temp = _r_intToStr(p_tasks[*p_struct_counter].today_received_exp);
            break;
        case 3:
            temp = _r_intToStr(p_tasks[*p_struct_counter].today_full_exp);
            break;
        case 4:
            temp = _r_intToStr(p_tasks[*p_struct_counter].today_percentage);
            break;
        case 5:
            temp = _r_intToStr(p_tasks[*p_struct_counter].current_exp);
            break;
        case 6:
            temp = _r_intToStr(p_tasks[*p_struct_counter].full_exp);
            break;
        case 7:
            temp = _r_intToStr(p_tasks[*p_struct_counter].common_percentage);
            break;
    }
    for(int j = 0; j < digits; j++) {
        data_array[*p_counter] = temp[j];
        (*p_counter)++;
    }
    data_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_choice)++;
}