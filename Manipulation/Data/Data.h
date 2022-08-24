#include "../Global/Global_structs.h"

// Интерфейс

__menu menu_main_args[];
__menu menu[];                          // Основное меню
__menu additional_functions[];          // Дополннительные функции
__menu change_data1[];                  // Меню изменения данных пользователя (1го уровня)
__menu change_data1_1[];                // Меню изменения финансового состояния пользователя (2го уровня)
__menu change_data1_2[];
__menu change_data1_3[];
__menu change_data1_4[];
__menu skills_menu[];
__menu aims_menu[];
__menu tasks_menu[];

// Вывод

__common about_user[];                  // Статы пользователя
__common* p_about_user;
__common users_wealth[];                // Финансовое состояние пользователя
__common* p_users_wealth;
__skills skills[];                      // Навыки
__skills* p_skills;
__aims aims[];                          // Цели
__aims* p_aims;
__tasks tasks[];                        // Задачи
__tasks* p_tasks;
__main_name main_name[];