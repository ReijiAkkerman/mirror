#include "../Global/Global_structs.h"

// Интерфейс

__menu menu_main_args[2];
__menu menu[8];                          // Основное меню
__menu additional_functions[1];          // Дополннительные функции
__menu change_data1[4];                  // Меню изменения данных пользователя (1го уровня)
__menu change_data1_1[2];                // Меню изменения финансового состояния пользователя (2го уровня)
__menu change_data1_2[8];
__menu change_data1_3[7];
__menu change_data1_4[7];
__menu skills_menu[2];
__menu aims_menu[2];
__menu tasks_menu[2];

// Вывод

__common about_user[3];                  // Статы пользователя
__common* p_about_user;
__common users_wealth[3];                // Финансовое состояние пользователя
__common* p_users_wealth;
__skills skills[5];                      // Навыки
__skills* p_skills;
__aims aims[5];                          // Цели
__aims* p_aims;
__tasks tasks[5];                        // Задачи
__tasks* p_tasks;
__main_name main_name[4];