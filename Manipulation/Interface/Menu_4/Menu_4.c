#include <stdio.h>

#include "../../Global/headers/Global_variables.h"
#include "../../Data/headers/Data.h"
#include "Menu_4.h"

void _add_data3(void) {
    _print_add_data3();
    switch(degrees[0]) {
        case 1:
            _add_data3_1();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            _add_data3_4();
            break;
    }
}

void _print_add_data3(void) {                        // Над какой категорией работать
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4[0].str1, change_data4[1].str1, change_data4[2].str1, change_data4[3].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[0]);
    printf("\n");
}

void _add_data3_1(void) {
    _print_add_data3_1();
    switch(degrees[1]) {
        case 1:
            _add_data3_1_1();
            break;
        case 2:
            _add_data3_1_2();
            break;
    }
}

void _print_add_data3_1(void) {
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data4_1[0].str1, change_data4_1[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _add_data3_1_1(void) {
    _print_add_data3_1_1();
    int x = 0;
    switch(degrees[2]) {
        case 1:
            printf("Введите сумму доходов: ");
            scanf("%d", &x);
            users_wealth[1].value_common += x;
            break;
        case 2:
            printf("Введите сумму расходов: ");
            scanf("%d", &x);
            users_wealth[1].value_common -= x;
            break;
    }
}

void _print_add_data3_1_1(void) {                      // Действия с финанасами
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, add_data3_1[0].str1, add_data3_1[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}

void _add_data3_1_2(void) {
    _print_add_data3_1_1();
    int x = 0;
    switch(degrees[2]) {
        case 1:
            printf("Введите сумму доходов: ");
            scanf("%d", &x);
            printf("\n");
            break;
        case 2:
            printf("Введите сумму расходов: ");
            scanf("%d", &x);
            printf("\n");
            break;
    }
}

void _add_data3_4(void) {
    _print_add_data3_4();
    switch(degrees[1]) {
        case 1:
            _add_data3_4_2();
            break;
        case 2:
            _add_data3_4_2();
            break;
    }
}

void _print_add_data3_4(void) {
    printf("%s\n\n\t1. %s\n\t2. %s\n\n%s", menu_main_args[0].str1, tasks[0].task_name, tasks[1].task_name, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _add_data3_4_2(void) {
    _print_add_data3_4_2();
    switch(degrees[2]) {
        case 1:
            printf("Введите полученный опыт: ");
            scanf("%d", &tasks[degrees[1] - 1].today_received_exp);
            printf("\n");
            break;
    }
}

void _print_add_data3_4_2(void) {
    printf("%s\n\n\t1. Полученный опыт за сегодня.\n\n%s", menu_main_args[0].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}