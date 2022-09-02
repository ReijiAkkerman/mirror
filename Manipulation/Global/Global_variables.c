#include "headers/Global_structs.h"

    // Интерфейс

// Переменные

unsigned short int main_choice = 0;          // выбор пункта меню
unsigned short int main_choice1 = 0;         // переменная для выхода из цикла

// Массивы

unsigned short int degrees[] = {0, 0, 0, 0, 0, 0, 0};

    // Запись

// Переменные

int option_of_path = 1;                 // вариант выбора папки
int choice;
int* p_choice = &choice;

// Массивы

int times_sizes[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // Чтение

// Переменные

int struct_counter = 0;
int* p_struct_counter = &struct_counter;
int common_choice_counter = 0;
int* p_common_choice_counter = &common_choice_counter;
int skills_choice_counter = 0;
int* p_skills_choice_counter = &skills_choice_counter;
int aims_choice_counter = 0;
int* p_aims_choice_counter = &aims_choice_counter;
int tasks_choice_counter = 0;
int* p_tasks_choice_counter = &tasks_choice_counter;

// Массивы

const int struct_array[] = {3, 3, 8, 7, 7};

    // Обработка 

// Переменные 

const int amount_of_structures = 5;

    // Вывод

// Переменные

unsigned short int table_size = 0;      // ширина таблицы в символах
unsigned short int* p_table_size = &table_size;
const int str_amount = 62;              // количество строк необходимых для вывода таблицы
int num_size_str_array = 0;             // номер выводимой строки таблицы
int* p_num_size_str_array = &num_size_str_array;
int common_struct_counter = 0;          // номер используемой структуры common
int* p_common_struct_counter = &common_struct_counter;
int skills_struct_counter = 0;          // номер используемой структуры skills
int* p_skills_struct_counter = &skills_struct_counter;
int aims_struct_counter = 0;            // номер используемой структуры aims
int* p_aims_struct_counter = &aims_struct_counter;
int tasks_struct_counter = 0;           // номер используемой структуры tasks
int* p_tasks_struct_counter = &tasks_struct_counter;
int main_name_counter = 0;              // номер используемого заголовка подтаблицы
int* p_main_name_counter = &main_name_counter;

int digits = 0;                         // количество разрядов последнего вычисленного в соотв. функции числа
int* p_digits = &digits;
int relative_spaces_amount = 0;         // количество третьей части пробелов
int* p_relative_spaces_amount = &relative_spaces_amount;

const int indent = 6;                   // отступ
int space_divider = 0;                  // делитель для определения фиксированного количества пробелов в строках пятого, шестого и седьмого типов
int* p_space_divider = &space_divider;

char temp_char_array[100];              // временный массив для обработки строковых элементов структур
char* p_temp_char_array = temp_char_array;

// Массивы

const int str_array[] = {1, 2, 8, 2, 1, 3, 4, 3, 1, 3, 4, 4, 3, 1,
2, 8, 2, 1, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 1,
2, 8, 2, 1, 2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2, 1,
2, 8, 2, 1, 2, 7, 2, 7, 2, 7, 2, 7, 2, 7, 2, 1
};                                      // массив типов строк для правильного построения таблицы

int size_str_array[62];                 // массив с размерами для каждой строки 
int* p_size_str_array = size_str_array;

int array[4] = {0, 0, 0, 0};                        // [0]-количество байт в строке без '\0' [1]-количество пробелов [2]-количество байт занимаемое чисто кириллическими символами [3]-количество места занимаемое символами визуально при выводе на дисплей
int* p_array = array;                               // массив размеров кириллической строки
int sum_two_cyrillic_texts[4] = {0, 0, 0, 0};       // суммы занимаемых от сложения двух кириллических текстов по категориям описанным в массиве array[4]
int* p_sum_two_cyrillic_texts = sum_two_cyrillic_texts;

    // Время

// Переменные

int high_year_pointer = 2;                          // указатель высокосности года( если указатель = 0 - то год высокосный)
int* p_high_year_pointer = &high_year_pointer;
int month_counter = 0;                              // порядковый номер месяца
int* p_month_counter = &month_counter;
const int first_day_of_week = 2;                    // самый первый день недели
int time_zone = 3;                                  // часовой пояс (временная зона)
int* p_time_zone = &time_zone;

// Массивы

int time_array[] = {0, 0, 0, 0, 0, 0, 0, 0};        // [0]-год, [1]-месяц, [2]-день, [3]-час, [4]-минута, [5]-секунда, [6]-день недели, [7]-время полученное вызовом функции time(NULL)
int* p_time_array = time_array;
int amount_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};        // количество дней в месяце
int* p_amount_days_in_month = amount_days_in_month;
int last_day_pointer = 0;                           // указывает последним ли является текущий месяц, если 1 то последний
int* p_last_day_pointer = &last_day_pointer;