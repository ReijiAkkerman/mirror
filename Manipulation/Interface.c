#include <stdio.h>

#include "Global/Global_variables.h"
#include "Data/Data.h"

void _additional_functions1(void);      // создает и обрабатывает выбор меню с дополнительными функциями
void _print_menu(void);                 // печатает меню и передает выбор пользователя в соответствующую переменную
void _print_char_num(void);             // уведомляет пользователя о необходимости ввести размер таблицы и записывает данные в соответствующую переменную
void _change_table_size(void);          // записывает размер таблицы

void _change_data_menu1(void);          // обрабатывает выбранный пункт для меню изменения данных
void _print_change_data_menu1(void);    // печатает меню для изменения данных пользователя

void _change_data_menu1_1(void);        // обрабатывает выбранный пункт для изменения информации о деньгах
void _print_change_data_menu1_1(void);  // печатает меню для изменения информации о деньгах

void _change_data_menu1_2(void);
void _print_change_data_menu1_2(void);
void _change_data_menu1_2_1(void);
void _print_change_data_menu1_2_1(void);

void _change_data_menu1_3(void);
void _print_change_data_menu1_3(void);
void _change_data_menu1_3_1(void);
void _print_change_data_menu1_3_1(void);

void _change_data_menu1_4(void);
void _print_change_data_menu1_4(void);
void _change_data_menu1_4_1(void);
void _print_change_data_menu1_4_1(void);

void _menu() {                          // обрабатывает выбранный пользователем пункт
    while(main_choice1 != 8) {          // пока пользователь не укажет выход из программы 
        _print_menu();                  // печатаем меню для пользователя
        switch(main_choice1) {
            case 1:
                _preparing();
                _output();              // выводим на экран информацию о пользователе
                break;
            case 2:
                _additional_functions1();
                break;
            case 3:
                _change_data_menu1();
                break;
            case 4:
                
                break;
            case 5:
                _reading();             // считываем данные с последнего созданного файла
                _daily();
                break;
            case 6:
                _print_char_num();      // изменяем размер таблицы
                break;
            case 7:
                break;
        }
    }
}

void _change_data_menu1(void) {         // изменяет данные пользователя
    _print_change_data_menu1();
    switch(degrees[0]) {
        case 1:
            _change_data_menu1_1();
            break;
        case 2:
            _change_data_menu1_2();
            break;
        case 3:
            _change_data_menu1_3();
            break;
        case 4:
            _change_data_menu1_4();
            break;
    }
}

void _print_change_data_menu1(void) {   // печатает меню изменения данных
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data1[0].str1, change_data1[1].str1, change_data1[2].str1, change_data1[3].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[0]);
    printf("\n");
}




void _change_data_menu1_1(void) {       // обрабатывает выбор пользователя на изменения финансового состояния по валютам
    _print_change_data_menu1_1();
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

void _print_change_data_menu1_1(void) { // печатает меню выбора валюты
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data1_1[0].str1, change_data1_1[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}




void _change_data_menu1_2(void) {
    _print_change_data_menu1_2();
    switch(degrees[1]) {
        case 1:
            _change_data_menu1_2_1();
            break;
        case 2:
            _change_data_menu1_2_1();
            break;
    }
}

void _print_change_data_menu1_2(void) {
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, skills_menu[0].str1, skills_menu[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu1_2_1(void) {
    _print_change_data_menu1_2_1();
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

void _print_change_data_menu1_2_1(void) {
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data1_2[0].str1, change_data1_2[1].str1, change_data1_2[2].str1, change_data1_2[3].str1, change_data1_2[4].str1, change_data1_2[5].str1, change_data1_2[6].str1, change_data1_2[7].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}




void _change_data_menu1_3(void) {
    _print_change_data_menu1_3();
    switch(degrees[1]) {
        case 1:
            _change_data_menu1_3_1();
            break;
        case 2:
            _change_data_menu1_3_1();
            break;
    }
}

void _print_change_data_menu1_3(void) {
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, aims_menu[0].str1, aims_menu[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu1_3_1(void) {
    _print_change_data_menu1_3_1();
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

void _print_change_data_menu1_3_1(void) {
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data1_3[0].str1, change_data1_3[1].str1, change_data1_3[2].str1, change_data1_3[3].str1, change_data1_3[4].str1, change_data1_3[5].str1, change_data1_3[6].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}




void _change_data_menu1_4(void) {
    _print_change_data_menu1_4();
    switch(degrees[1]) {
        case 1:
            _change_data_menu1_4_1();
            break;
        case 2:
            _change_data_menu1_4_1();
            break;
    }
}

void _print_change_data_menu1_4(void) {
    printf("%s\n\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, tasks_menu[0].str1, tasks_menu[1].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[1]);
    printf("\n");
}

void _change_data_menu1_4_1(void) {
    _print_change_data_menu1_4_1();
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

void _print_change_data_menu1_4_1(void) {
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, change_data1_4[0].str1, change_data1_4[1].str1, change_data1_4[2].str1, change_data1_4[3].str1, change_data1_4[4].str1, change_data1_4[5].str1, change_data1_4[6].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[2]);
    printf("\n");
}




void _print_additional_functions(void) {// печатает меню с дополнительными функциями
    printf("%s\n\n\t%s\n\n%s", menu_main_args[0].str1, additional_functions[0].str1, menu_main_args[1].str1);
    scanf("%hd", &degrees[0]);
    printf("\n");
}

void _additional_functions1(void) {     // обрабатывает выбор пользователя из меню с доп. функциями
    _print_additional_functions();
    switch(degrees[0]) {
        case 1:
            _writing();
            
            break;
    }
}




void _1_start(void) {                   // записывает размер таблицы
    _print_char_num();                  // уведомляем пользователя о необходимости задать размер таблицы
    _menu();                            // обрабатываем выбранный пользователем пункт
}

void _print_menu(void) {                // печатает меню и передает выбор пользователя в соответствующую переменную
    printf("%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s", menu_main_args[0].str1, menu[0].str1, menu[1].str1, menu[2].str1, menu[3].str1, menu[4].str1, menu[5].str1, menu[6].str1, menu[7].str1, menu_main_args[1].str1);     
    scanf("%hd", &main_choice);         // считать выбор пользователя и записать в соответствующую переменную
    main_choice1 = main_choice;         // присвоить переменной отвечающей за выход из программы значение которое выбрал пользователь
    printf("\n");                       // отступ по вертикали
}

void _print_char_num(void) {            // уведомляет пользователя о необходимости ввести размер таблицы и записывает данные в соответствующую переменную
    printf("Введите размер таблицы в символах: ");      // уведомляем пользователя
    scanf("%hd", &table_size);                          // считываем размер таблицы и передаем в переменную для дальнейшей обработки
    if((table_size % 2) == 0)
        (*p_table_size)++;
    printf("\n");                                       // отступ по вертикали
    printf("Размер таблицы успешно изменен!\n");
    printf("\n");
}