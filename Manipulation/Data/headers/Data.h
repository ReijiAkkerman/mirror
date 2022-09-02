#include "../../Global/headers/Global_structs.h"

// Интерфейс

__menu menu_main_args[2];                   // Список часто изпользуемых строк
__menu menu[8];                             // Основное меню
__menu additional_functions[1];             // Дополннительные функции
__menu add_data3_1[2];                        // Меню заполнения данных о финансовом состоянии пользователя
__menu change_data4[4];                     // Меню изменения данных пользователя
__menu change_data4_1[2];                   // Меню изменения финансового состояния пользователя
__menu change_data4_2[8];                   // Меню изменения навыков пользователя
__menu change_data4_3[7];                   // Меню изменения целей пользователя
__menu change_data4_4[7];                   // Меню изменения задач пользователя
__menu skills_menu[2];                      // Список навыков
__menu aims_menu[2];                        // Список целей
__menu tasks_menu[2];                       // Список задач

// Вывод

__common about_user[3];                     // Статы пользователя
__common* p_about_user;
__common users_wealth[3];                   // Финансовое состояние пользователя
__common* p_users_wealth;
__skills skills[5];                         // Навыки
__skills* p_skills;
__aims aims[5];                             // Цели
__aims* p_aims;
__tasks tasks[5];                           // Задачи
__tasks* p_tasks;
__main_name main_name[4];                   // Оглавления для таблицы