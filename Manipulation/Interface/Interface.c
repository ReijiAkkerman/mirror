#include <stdio.h>

#include "../Global/headers/Global_variables.h"
#include "../Data/headers/Data.h"
#include "Menu_2/Menu_2.h"
#include "Menu_3/Menu_3.h"

void _confirm(void);                    // подтверждение готовности использования пользовательского меню
void _print_menu(void);                 // печатает меню и передает выбор пользователя в соответствующую переменную
void _print_char_num(void);             // уведомляет пользователя о необходимости ввести размер таблицы и записывает данные в соответствующую переменную

void _menu() {                          // обрабатывает выбранный пользователем пункт
    while(main_choice1 != 8) {          // пока пользователь не укажет выход из программы 
        _print_menu();                  // печатаем меню для пользователя
        switch(main_choice1) {
            case 1:
                _preparing();
                _output();              // выводим на экран информацию о пользователе
                _confirm();
                break;
            case 2:
                _additional_functions1();
                break;
            case 3:
                _change_data_menu3();
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

void _confirm(void) {                   // подтверждение готовности использования пользовательского меню
    int x;
    scanf("%d", &x);
}