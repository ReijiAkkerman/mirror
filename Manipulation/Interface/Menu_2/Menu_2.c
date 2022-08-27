#include <stdio.h>

#include "../../Global/headers/Global_variables.h"
#include "../../Data/headers/Data.h"
#include "Menu_2.h"

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