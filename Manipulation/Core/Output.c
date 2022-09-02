#include <stdio.h>
#include <stdlib.h>

#include "../Global/headers/Global_variables.h"
#include "../Data/headers/Data.h"

void _value_divider(void);                              // вычисляет подходящий делитель для строки пятого типа 
int _difference_of_spaces(void);                        // возвращает число на какое количество пробелов изменить первую чать строки чтобы части были равными и индекс той строки которой нужно большее количество пробелов
int _free_spaces(void);                                 // возвращает количество свободных пробелов для строк пятого типа
int _free_spaces_2(void);                               // возвращает количество оставшихся свободных пробелов
void _add_x_bytes_2(char* text1, char* text2);          // возвращает массив сумм байт от сложения двух кириллических строк(нужно для увеличения строк с двумя кириллическими аргументами на соответствующее количество байт)
int _table_size(void);                                  // считает количество символов для вывода таблицы

void _str1(char* p_char_array, int* p_counter);         // создает горизонтульную линию таблицы
void _str2(char* p_char_array, int* p_counter);         // создает пустоту внутри таблицы на одной строке
void _str3(char* p_char_array, int* p_counter);         // создает два пустых слота в строке
void _str4(char* p_char_array, int* p_counter);         // создает два заполненных слота в строке
void _str5(char* p_char_array, int* p_counter);         // создает заполненную строку для структуры skills
void _str6(char* p_char_array, int* p_counter);         // создает заполненную строку для структуры aims
void _str7(char* p_char_array, int* p_counter);         // создает заполненную строку для структуры tasks
void _str8(char* p_char_array, int* p_counter);         // создает заголовок подтаблицы

void _output(void) {                                    // вывод таблицы на экран
    *p_num_size_str_array = 0;                          // номер выводимой строки таблицы
    int size_table = _table_size();                     // размер раблицы в байтах
    int counter = 0;                                    // считает порядковый номера байта для заполнения
    int* p_counter = &counter;                          
    char char_array[size_table];                        // массив символов содержащий в себе всю таблицу, и выводимый в качестве строки
    char* p_char_array = char_array;
    _value_divider();
    *p_relative_spaces_amount = table_size / space_divider;

    for(int i = 0; i < str_amount; i++) {
        switch(str_array[i]) {
            case 1:
                _str1(p_char_array, p_counter);
                break;
            case 2:
                _str2(p_char_array, p_counter);
                break;
            case 3:
                _str3(p_char_array, p_counter);
                break;
            case 4:
                _str4(p_char_array, p_counter);
                break;
            case 5:
                _str5(p_char_array, p_counter);
                break;
            case 6:
                _str6(p_char_array, p_counter);
                break;
            case 7:
                _str7(p_char_array, p_counter);
                break;
            case 8:
                _str8(p_char_array, p_counter);
                break;
        }
    }
    char_array[size_table - 1] = '\0';

    printf("%s", char_array);
}

void _str1(char* p_char_array, int* p_counter) {        // создает горизонтульную линию ddтаблицы
    for(int i = 0; i < table_size; i++) {
        p_char_array[*p_counter] = '#';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_num_size_str_array)++;
}

void _str2(char* p_char_array, int* p_counter) {        // создает пустоту внутри таблицы на одной строке
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < table_size - 2; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_num_size_str_array)++;
}

void _str3(char* p_char_array, int* p_counter) {        // создает два пустых слота в строке
    int center = (table_size / 2);
    int a, b, c, d;
    a = 1;                  // первый пробел первой части пробелов
    b = center;         // индекс разделительной решетки
    c = center + 1;             // первый пробел второй части пробелов
    d = size_str_array[num_size_str_array] - 2;      // индекс решетки таблицы

    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = a; i < b; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = c; i < d; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_num_size_str_array)++;
}

void _str4(char* p_char_array, int* p_counter) {        // создает в строке две колонки заполенные аргументами
    int a = _free_spaces_2();                           // количество свободных пробелов
    int b = _difference_of_spaces();                    // разница в пробелах одной части перед другой
    int c = a / 2;                                      // половина оставшихся пробелов
    int d = c + b;                                      // количество свободных пробелов в первой части
    int e = a - d;                                      // количество свободных пробелов во второй части
    char* ca;                                           // число в структуре about_user
    char* cb;                                           // число в структуре users_wealth

    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    _r_text_size(about_user[common_struct_counter].name_common);
    for(int i = 0; i < array[0]; i++) {
        p_char_array[*p_counter] = about_user[common_struct_counter].name_common[i];
        (*p_counter)++;
    }
    for(int i = 0; i < d; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    ca = _r_intToStr(about_user[common_struct_counter].value_common);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ca[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    _r_text_size(users_wealth[common_struct_counter].name_common);
    for(int i = 0; i < array[0]; i++) {
        p_char_array[*p_counter] = users_wealth[common_struct_counter].name_common[i];
        (*p_counter)++;
    }
    for(int i = 0; i < e; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cb = _r_intToStr(users_wealth[common_struct_counter].value_common);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cb[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_common_struct_counter)++;
    (*p_num_size_str_array)++;
}

void _str5(char* p_char_array, int* p_counter) {        // создает заполненную строку для структуры skills
    int a = _free_spaces();                   // количество свободных пробелов
    char* ca;
    char* cb;
    char* cc;
    char* cd;
    char* ce;
    char* cf;
    char* cg;

    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    _r_text_size(skills[skills_struct_counter].skill_name);
    for(int i = 0; i < array[0]; i++) {
        p_char_array[*p_counter] = skills[skills_struct_counter].skill_name[i];
        (*p_counter)++;
    }
    for(int i = 0; i < a; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    ca = _r_intToStr(skills[skills_struct_counter].skill_level);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ca[i];
        (*p_counter)++;
    }
    for(int i = 0; i < relative_spaces_amount; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cb = _r_intToStr(skills[skills_struct_counter].today_received_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cb[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '/';
    (*p_counter)++;
    cc = _r_intToStr(skills[skills_struct_counter].today_full_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cc[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cd = _r_intToStr(skills[skills_struct_counter].today_percentage);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cd[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '%';
    (*p_counter)++;
    for(int i = 0; i < relative_spaces_amount; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    ce = _r_intToStr(skills[skills_struct_counter].current_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ce[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '/';
    (*p_counter)++;
    cf = _r_intToStr(skills[skills_struct_counter].full_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cf[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cg = _r_intToStr(skills[skills_struct_counter].common_percentage);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cg[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '%';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_skills_struct_counter)++;
    (*p_num_size_str_array)++;
}

void _str6(char* p_char_array, int* p_counter) {        // создает заполненную строку для структуры aims
    int a = _free_spaces();
    char* ca;
    char* cb;
    char* cc;
    char* cd;
    char* ce;
    char* cf;

    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    _r_text_size(aims[aims_struct_counter].aim_name);
    for(int i = 0; i < array[0]; i++) {
        p_char_array[*p_counter] = aims[aims_struct_counter].aim_name[i];
        (*p_counter)++;
    }
    for(int i = 0; i < a; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    for(int i = 0; i < relative_spaces_amount; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    ca = _r_intToStr(aims[aims_struct_counter].today_received_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ca[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '/';
    (*p_counter)++;
    cb = _r_intToStr(aims[aims_struct_counter].today_full_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cb[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cc = _r_intToStr(aims[aims_struct_counter].today_percentage);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cc[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '%';
    (*p_counter)++;
    for(int i = 0; i < relative_spaces_amount; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cd = _r_intToStr(aims[aims_struct_counter].current_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cd[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '/';
    (*p_counter)++;
    ce = _r_intToStr(aims[aims_struct_counter].full_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ce[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cf = _r_intToStr(aims[aims_struct_counter].common_percentage);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cf[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '%';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_aims_struct_counter)++;
    (*p_num_size_str_array)++;
}

void _str7(char* p_char_array, int* p_counter) {        // создает заполненную строку для структуры tasks
    int a = _free_spaces();
    char* ca;
    char* cb;
    char* cc;
    char* cd;
    char* ce;
    char* cf;

    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    _r_text_size(tasks[tasks_struct_counter].task_name);
    for(int i = 0; i < array[0]; i++) {
        p_char_array[*p_counter] = tasks[tasks_struct_counter].task_name[i];
        (*p_counter)++;
    }
    for(int i = 0; i < a; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    for(int i = 0; i < relative_spaces_amount; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    ca = _r_intToStr(tasks[tasks_struct_counter].today_received_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ca[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '/';
    (*p_counter)++;
    cb = _r_intToStr(tasks[tasks_struct_counter].today_full_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cb[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cc = _r_intToStr(tasks[tasks_struct_counter].today_percentage);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cc[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '%';
    (*p_counter)++;
    for(int i = 0; i < relative_spaces_amount; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cd = _r_intToStr(tasks[tasks_struct_counter].current_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cd[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '/';
    (*p_counter)++;
    ce = _r_intToStr(tasks[tasks_struct_counter].full_exp);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = ce[i];
        (*p_counter)++;
    }
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    cf = _r_intToStr(tasks[tasks_struct_counter].common_percentage);
    for(int i = 0; i < digits; i++) {
        p_char_array[*p_counter] = cf[i];
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '%';
    (*p_counter)++;
    for(int i = 0; i < indent; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_tasks_struct_counter)++;
    (*p_num_size_str_array)++;
}

void _str8(char* p_char_array, int* p_counter) {        // создает заголовок подтаблицы
    int a = _free_spaces();                             // количество свободных пробелов
    int b = a / 2;                                      // первая часть свободных пробелов
    int c = a - b;                                      // вторая часть свободных пробелов

    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    for(int i = 0; i < b; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    _r_text_size(main_name[main_name_counter].main_name);
    for(int i = 0; i < array[0]; i++) {
        p_char_array[*p_counter] = main_name[main_name_counter].main_name[i];
        (*p_counter)++;
    }
    for(int i = 0; i < c; i++) {
        p_char_array[*p_counter] = ' ';
        (*p_counter)++;
    }
    p_char_array[*p_counter] = '#';
    (*p_counter)++;
    p_char_array[*p_counter] = '\n';
    (*p_counter)++;
    (*p_main_name_counter)++;
    (*p_num_size_str_array)++;
}

void _value_divider(void) {                             // вычисляет подходящий делитель для строки пятого типа 
    if(table_size < 100)
        *p_space_divider = 7;
    if((table_size >= 100) && (table_size < 150))
        *p_space_divider = 6;
    if((table_size >= 150) && (table_size < 200))
        *p_space_divider = 5;
    if((table_size >= 200) && (table_size < 250))
        *p_space_divider = 4;
    if((table_size >= 250) && (table_size < 300))
        *p_space_divider = 3;
}

int _difference_of_spaces(void) {                       // возвращает число на какое количество пробелов изменить первую чать строки чтобы части были равными и индекс той строки которой нужно большее количество пробелов
    int temp;
    int temp1;
    int result;
    int spaces;
    int value1[4];
    int value2[4];
    int v1;
    int v2;
    int num;
    _r_digits_(about_user[common_struct_counter].value_common);
    v1 = digits;
    _r_digits_(users_wealth[common_struct_counter].value_common);
    v2 = digits;
    num = v2 - v1;
    temp1 = num;
    if((table_size % 2) == 0) {
        if(v1 != v2) {
            if((temp1 % 2) == 0) 
                num++;
        }
    }
    _r_text_size(about_user[common_struct_counter].name_common);
    for(int i = 0; i < 4; i++) 
        value1[i] = array[i];
    _r_text_size(users_wealth[common_struct_counter].name_common);
    for(int i = 0; i < 4; i++) 
        value2[i] = array[i];
    result = value2[3] - value1[3];
    spaces = value2[1] - value1[1];
    result += spaces;
    result += num;
    temp = result;
    result /= 2;
    if(temp > 0) {
        if((temp % 2) != 0) {
            result++;
        }
    }
    else {
        if((temp % 2) == 0) {
            if((table_size % 2) == 0) {
                result++;
            }
        }
    }
    return result;
}

int _free_spaces(void) {                                // возвращает количество свободных пробелов для строк пятого типа
    int free_spaces;
    int x = 0;
    switch(str_array[num_size_str_array]) {
        case 5:
            _r_text_size(skills[skills_struct_counter].skill_name);
            _r_digits_(skills[skills_struct_counter].skill_level);
            x += digits;
            _r_digits_(skills[skills_struct_counter].today_received_exp);
            x += digits;
            _r_digits_(skills[skills_struct_counter].today_full_exp);
            x += digits;
            _r_digits_(skills[skills_struct_counter].today_percentage);
            x += digits;
            _r_digits_(skills[skills_struct_counter].current_exp);
            x += digits;
            _r_digits_(skills[skills_struct_counter].full_exp);
            x += digits;
            _r_digits_(skills[skills_struct_counter].common_percentage);
            x += digits;
            free_spaces = size_str_array[num_size_str_array] - array[2] - array[1] - x - 3 - 4 - (indent * 4) - (relative_spaces_amount * 2);
            break;
        case 6:
            _r_text_size(aims[aims_struct_counter].aim_name);
            _r_digits_(aims[aims_struct_counter].today_received_exp);
            x += digits;
            _r_digits_(aims[aims_struct_counter].today_full_exp);
            x += digits;
            _r_digits_(aims[aims_struct_counter].today_percentage);
            x += digits;
            _r_digits_(aims[aims_struct_counter].current_exp);
            x += digits;
            _r_digits_(aims[aims_struct_counter].full_exp);
            x += digits;
            _r_digits_(aims[aims_struct_counter].common_percentage);
            x += digits;
            free_spaces = size_str_array[num_size_str_array] - array[2] - array[1] - x - 3 - 4 - (indent * 4) - (relative_spaces_amount * 2);
            break;
        case 7:
            _r_text_size(tasks[tasks_struct_counter].task_name);
            _r_digits_(tasks[tasks_struct_counter].today_received_exp);
            x += digits;
            _r_digits_(tasks[tasks_struct_counter].today_full_exp);
            x += digits;
            _r_digits_(tasks[tasks_struct_counter].today_percentage);
            x += digits;
            _r_digits_(tasks[tasks_struct_counter].current_exp);
            x += digits;
            _r_digits_(tasks[tasks_struct_counter].full_exp);
            x += digits;
            _r_digits_(tasks[tasks_struct_counter].common_percentage);
            x += digits;
            free_spaces = size_str_array[num_size_str_array] - array[2] - array[1] - x - 3 - 4 - (indent * 4) - (relative_spaces_amount * 2);
            break;
        case 8:
            _r_text_size(main_name[main_name_counter].main_name);
            free_spaces = size_str_array[num_size_str_array] - array[2] - array[1] - 3;
            break;
    }
    return free_spaces;
}

int _free_spaces_2(void) {                              // возвращает количество свободных пробелов
    int free_spaces;
    int x = 0;
    _add_x_bytes_2(about_user[common_struct_counter].name_common, users_wealth[common_struct_counter].name_common);
    _r_digits_(about_user[common_struct_counter].value_common);
    x += digits;
    _r_digits_(users_wealth[common_struct_counter].value_common);
    x += digits;
    free_spaces = size_str_array[num_size_str_array] - sum_two_cyrillic_texts[2] - x - 4 - sum_two_cyrillic_texts[1] - (indent * 4);
    return free_spaces;
}

void _r_text_size(char* text) {                         // считает количество байт занимаемое кириллической строкой, количество пробелов в ней и количество чисто кириллических символов
    p_array[0] = p_array[1] = 0;
    while(text[array[0]] != '\0') {         // пока не встретится нулевой символ
        if(text[array[0]] == ' ')           // если встретился пробел
            p_array[1]++;                   // увеличить на единицу индекс отвечающий за количество пробелов
        p_array[0]++;                       // увеличить на единицу количество прочитанных байт
    }
    p_array[2] = array[0] - array[1];       // вычислить количество чисто кириллических символов
    p_array[3] = array[2] / 2;              // вычислить на какое количество байт нужно увеличить строку от исходного значения
}

char* _r_intToStr(int num) {                            // возвращает число записанное строкой
    int* ptr = _r_digits(num);
    char array[digits + 1];
    char* p_array = array;
    int count = digits;
    for(int i = 0; i < digits; i++) {
        array[i] = ptr[count - 1] | 0x30;
        count--;
    }
    array[digits] = '\0';
    return p_array;
}

int* _r_digits(int num) {                               // возвращает массив цифр из которых состоит полученное число
    int temp = num;
    _r_digits_(num);
    int array[digits];
    int* p_array = array;
    for(int i = 0; i < digits; i++) {
        array[i] = temp % 10;
        temp /= 10;
    }
    return p_array;
}

void _r_digits_(int num) {                              // вычисляет количество разрядов полученного числа
    (*p_digits) = 0;
    if(num != 0) {
        while(num != 0) {
            num /= 10;
            (*p_digits)++;
        }
    }
    else {
        (*p_digits)++;
    }
}

char* _r_chars_cut_out(void) {                          // обрезает массив символов оставляя только используемые символы и в конце один нулевой символ
    for(int i = 0; i < 100; i++)
        p_temp_char_array[i] = '\0';
    _r_text_size(p_temp_char_array);
    char* a = malloc(array[0] + 1);
}

void _add_x_bytes_2(char* text1, char* text2) {         // возвращает массив сумм байт от сложения двух кириллических строк(нужно для увеличения строк с двумя кириллическими аргументами на соответствующее количество байт)
    int value1[4];
    int value2[4];
    _r_text_size(text1);
    for(int i = 0; i < 4; i++) 
        value1[i] = array[i];
    _r_text_size(text2);
    for(int i = 0; i < 4; i++) 
        value2[i] = array[i];
    for(int i = 0; i < 4; i++) 
        p_sum_two_cyrillic_texts[i] = value1[i] + value2[i];
}

void _calc_size_str4(int i) {                           // вычисляет размер строки четвертого типа
    _add_x_bytes_2(about_user[common_struct_counter].name_common, users_wealth[common_struct_counter].name_common);
    p_size_str_array[i] = table_size + sum_two_cyrillic_texts[3] + 1;
    (*p_common_struct_counter)++;
}

void _calc_size_str5_6_7_8(int i) {                     // вычисляет размер строки пятого типа
    switch(str_array[i]) {
        case 5:
            _r_text_size(skills[skills_struct_counter].skill_name);
            (*p_skills_struct_counter)++;
            break;
        case 6:
            _r_text_size(aims[aims_struct_counter].aim_name);
            (*p_aims_struct_counter)++;
            break;
        case 7:
            _r_text_size(tasks[tasks_struct_counter].task_name);
            (*p_tasks_struct_counter)++;
            break;
        case 8:
            _r_text_size(main_name[main_name_counter].main_name);
            (*p_main_name_counter)++;
            break;
    }
    p_size_str_array[i] = table_size + array[3] + 1;
}

int _table_size(void) {                                 // возвращает количество байт необходимое для вывода таблицы
    *p_common_struct_counter = 0;           // номер используемой структуры common
    *p_skills_struct_counter = 0;           // номер используемой структуры skills
    *p_aims_struct_counter = 0;             // номер используемой структуры aims
    *p_tasks_struct_counter = 0;            // номер используемой структуры tasks
    *p_main_name_counter = 0;               // номер используемого заголовка подтаблицы

    int value = 0;
    for(int i = 0; i < str_amount; i++) {
        switch(str_array[i]) {
            case 1:
                p_size_str_array[i] = table_size + 1;
                break;
            case 2:
                p_size_str_array[i] = table_size + 1;
                break;
            case 3:
                p_size_str_array[i] = table_size + 1;
                break;
            case 4:
                _calc_size_str4(i);
                break;
            case 5:
                _calc_size_str5_6_7_8(i);
                break;
            case 6:
                _calc_size_str5_6_7_8(i);
                break;
            case 7:
                _calc_size_str5_6_7_8(i);
                break;
            case 8:
                _calc_size_str5_6_7_8(i);
                break;
        }
        value += size_str_array[i];
    }
    value++;
    *p_common_struct_counter = 0;           // номер используемой структуры common
    *p_skills_struct_counter = 0;           // номер используемой структуры skills
    *p_aims_struct_counter = 0;             // номер используемой структуры aims
    *p_tasks_struct_counter = 0;            // номер используемой структуры tasks
    *p_main_name_counter = 0;               // номер используемого заголовка подтаблицы
    printf("%d\n", value);
    return value;
}