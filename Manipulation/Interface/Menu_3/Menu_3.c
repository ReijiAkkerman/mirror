#include <stdio.h>

#include "../../Global/headers/Global_variables.h"
#include "../../Data/headers/Data.h"
#include "Menu_3.h"

void _change_data_menu4(void) {         // изменяет данные пользователя
    _print_change_data_menu4();
    switch(degrees[0]) {
        case 1:
            _change_data_menu4_1();
            break;
        case 2:
            _change_data_menu4_2();
            break;
        case 3:
            _change_data_menu4_3();
            break;
        case 4:
            _change_data_menu4_4();
            break;
    }
}

void _print_change_data_menu4(void) {   // печатает меню изменения данных
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4[0].str1, change_data4[1].str1, change_data4[2].str1, change_data4[3].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[0]);
    printf("\n");
}

void _change_data_menu4_1(void) {       // обрабатывает выбор пользователя на изменения финансового состояния по валютам
    _print_change_data_menu4_1();
    switch(degrees[1]) {
        case 1:
            printf("Введите актуальную сумму: ");
            scanf("%d", &users_wealth[1].value_common);
            printf("\n");
            break;
        case 2: 
            printf("Введите актуальную сумму: ");
            scanf("%d", &users_wealth[2].value_common);
            printf("\n");
            break;
    }
}

void _print_change_data_menu4_1(void) { // печатает меню выбора валюты
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4_1[0].str1, change_data4_1[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu4_2(void) {
    _print_change_data_menu4_2();
    switch(degrees[1]) {
        case 1:
            _change_data_menu4_2_1();
            break;
        case 2:
            _change_data_menu4_2_1();
            break;
    }
}

void _print_change_data_menu4_2(void) { // печатает меню выбора навыка
    printf("%s\n\n\t1. %s\n\t2. %s\n\n%s", menu_main_args[0].str1, skills[0].skill_name, skills[1].skill_name, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu4_2_1(void) {
    _print_change_data_menu4_2_1();
    switch(degrees[2]) {
        case 1:
            scanf("%s", skills[degrees[1] - 1].skill_name);
            break;
        case 2:
            scanf("%d", &skills[degrees[1] - 1].skill_level);
            break;
        case 3:
            scanf("%d", &skills[degrees[1] - 1].today_received_exp);
            break;
        case 4:
            scanf("%d", &skills[degrees[1] - 1].today_full_exp);
            break;
        case 5:
            scanf("%d", &skills[degrees[1] - 1].today_percentage);
            break;
        case 6:
            scanf("%d", &skills[degrees[1] - 1].current_exp);
            break;
        case 7:
            scanf("%d", &skills[degrees[1] - 1].full_exp);
            break;
        case 8:
            scanf("%d", &skills[degrees[1] - 1].common_percentage);
            break;
    }
}

void _print_change_data_menu4_2_1(void) {   // печатает меню параметров изменения навыков
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4_2[0].str1, change_data4_2[1].str1, change_data4_2[2].str1, change_data4_2[3].str1, change_data4_2[4].str1, change_data4_2[5].str1, change_data4_2[6].str1, change_data4_2[7].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}

void _change_data_menu4_3(void) {
    _print_change_data_menu4_3();
    switch(degrees[1]) {
        case 1:
            _change_data_menu4_3_1();
            break;
        case 2:
            _change_data_menu4_3_1();
            break;
    }
}

void _print_change_data_menu4_3(void) { // печатает меню выбора цели
    printf("%s\n\n\t1. %s\n\t2. %s\n\n%s", menu_main_args[0].str1, aims[0].aim_name, aims[1].aim_name, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu4_3_1(void) {
    _print_change_data_menu4_3_1();
    switch(degrees[2]) {
        case 1:
            scanf("%s", aims[degrees[1] - 1].aim_name);
            break;
        case 2:
            scanf("%d", &aims[degrees[1] - 1].today_received_exp);
            break;
        case 3:
            scanf("%d", &aims[degrees[1] - 1].today_full_exp);
            break;
        case 4:
            scanf("%d", &aims[degrees[1] - 1].today_percentage);
            break;
        case 5:
            scanf("%d", &aims[degrees[1] - 1].current_exp);
            break;
        case 6:
            scanf("%d", &aims[degrees[1] - 1].full_exp);
            break;
        case 7:
            scanf("%d", &aims[degrees[1] - 1].common_percentage);
            break;
    }
}

void _print_change_data_menu4_3_1(void) {   // печатает меню параметров изменения целей
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4_3[0].str1, change_data4_3[1].str1, change_data4_3[2].str1, change_data4_3[3].str1, change_data4_3[4].str1, change_data4_3[5].str1, change_data4_3[6].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}

void _change_data_menu4_4(void) {
    _print_change_data_menu4_4();
    switch(degrees[1]) {
        case 1:
            _change_data_menu4_4_1();
            break;
        case 2:
            _change_data_menu4_4_1();
            break;
    }
}

void _print_change_data_menu4_4(void) { // печатает меню выбора задачи
    printf("%s\n\n\t1. %s\n\t2. %s\n\n%s", menu_main_args[0].str1, tasks[0].task_name, tasks[1].task_name, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu4_4_1(void) {
    _print_change_data_menu4_4_1();
    switch(degrees[2]) {
        case 1:
            scanf("%s", tasks[degrees[1] - 1].task_name);
            break;
        case 2:
            scanf("%d", &tasks[degrees[1] - 1].today_received_exp);
            break;
        case 3:
            scanf("%d", &tasks[degrees[1] - 1].today_full_exp);
            break;
        case 4:
            scanf("%d", &tasks[degrees[1] - 1].today_percentage);
            break;
        case 5:
            scanf("%d", &tasks[degrees[1] - 1].current_exp);
            break;
        case 6:
            scanf("%d", &tasks[degrees[1] - 1].full_exp);
            break;
        case 7:
            scanf("%d", &tasks[degrees[1] - 1].common_percentage);
            break;
    }
}

void _print_change_data_menu4_4_1(void) {   // печатает меню параметров изменения целелй
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4_4[0].str1, change_data4_4[1].str1, change_data4_4[2].str1, change_data4_4[3].str1, change_data4_4[4].str1, change_data4_4[5].str1, change_data4_4[6].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}
