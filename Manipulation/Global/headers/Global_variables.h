#define E extern

    // Регулярно использующиеся функции

void _r_text_size(char* text);          // считает количество байт занимаемое кириллической строкой и количество пробелов в ней
int* _r_digits(int num);                // возвращает массив цифр из которых состоит полученное число
void _r_digits_(int num);               // вычисляет количество разрядов полученного числа
char* _r_intToStr(int num);             // создает строку из числа

int _r_num_strToInt(char* str_arg);     // возвращает число полученное изначально в строковом формате - в формате числа
int _r_digits_multiply(int digits);     // возвращает числу записанному ранее в строковом формате - нужную разрядность
char* _r_clear_text(char* p_temp);      // возвращает текст без последующего за ним в изначальном формате мусора
char* _r_chars_cut_out(void);           // обрезает массив символов оставляя только используемые символы и в конце один нулевой символ

void _time(void);                       // заполняет массив отвечающий за время значениями текущего времени

void _daily(void);                      // обновляет выводимые данные каждые день и месяц в соответствующих категориях
void _preparing(void);                  // подготавливает данные к записив целочисленном виде
void _output(void);                     // вывод таблицы на экран
void _reading(void);                    // считывает данные с файла
void _writing(void);                    // запись итоговых данных

    // Интерфейс

// Переменные

E unsigned short int main_choice;       // выбор пункта меню
E unsigned short int main_choice1;      // переменная для выхода из цикла 

// Массивы 

E unsigned short int degrees[];

    // Запись

// Переменные

E int option_of_path;                   // вариант выбора папки
E int choice;                           // 
E int* p_choice;

// Массивы

E int times_sizes[];                    // 

    // Чтение

// Переменные

E int struct_counter;                   //
E int* p_struct_counter;                //
E int common_choice_counter;            //
E int* p_common_choice_counter;         //
E int skills_choice_counter;            //
E int* p_skills_choice_counter;         //
E int aims_choice_counter;              //
E int* p_aims_choice_counter;           //
E int tasks_choice_counter;             //
E int* p_tasks_choice_counter;          //

// Массивы

E const int struct_array[];             //

    // Обработка

// Переменные

E const int amount_of_structures;       //

    // Вывод

// Переменные

E unsigned short int table_size;        // ширина таблицы в символах
E unsigned short int* p_table_size;
E const int str_amount;                 // количество строк необходимое для вывода таблицы
E int num_size_str_array;               // номер выводимой строки таблицы
E int* p_num_size_str_array;
E int common_struct_counter;            // номер используемой структуры common
E int* p_common_struct_counter;
E int skills_struct_counter;            // номер используемой структуры skills
E int* p_skills_struct_counter;
E int aims_struct_counter;              // номер используемой структуры aims
E int* p_aims_struct_counter;
E int tasks_struct_counter;             // номер используемой структуры tasks
E int* p_tasks_struct_counter;
E int main_name_counter;                // номер используемого заголовка подтаблицы
E int* p_main_name_counter;

E int digits;                           // количество разрядов последнего вычисленного в соответствующей функции числа
E int* p_digits;
E int relative_spaces_amount;           // количество третьей части пробелов
E int* p_relative_spaces_amount;

E const int indent;                     // отступ
E int space_divider;                    // делитель для определения фиксированного количества пробелов в строках пятого, шестого и седьмого типов 
E int* p_space_divider;

E char temp_char_array;                 // временный массив для обработки строковых элементов структур
E char* p_temp_char_array;

// Массивы 

E const int str_array[];                // массив типов строк для правильного построения таблицы
E int size_str_array[62];               // массив с размерами для каждой строки
E int* p_size_str_array;

E int array[];                          // [0]-количество байт в строке без '\0' [1]-количество пробелов [2]-количество байт занимаемое чисто кириллическими символами [3]-количество места занимаемое символами визуальнопри выводе на дисплей
E int* p_array;                         // массив размеров кириллической строки
E int sum_two_cyrillic_texts[];         // суммы байт занимаемых результатом от сложения двух кириллических текстов по категориям описанным в массиве array[]
E int* p_sum_two_cyrillic_texts;

    // Время

// Переменные

E int high_year_pointer;                // указатель высокосности года(если указатель = 0 - то год высокосный)
E int* p_high_year_pointer;
E int month_counter;                    // порядковый номер месяца
E int* p_month_counter;
E const int first_day_of_week;          // самый последний день недели
E int time_zone;                        // часовой пояс(временная зона)
E int* p_time_zone;

// Массивы

E int time_array[];                     // [0]-год [1]-месяц [2]-день [3]-час [4]-минута [5]-секунда [6]-день недели [7]-время полученное вызовом функции time(NULL)
E int* p_time_array;
E int amount_days_in_month[];           // количество дней в месяце
E int* p_amount_days_in_month;
E int last_day_pointer;                 // указывает последним ли является текущий месяц, если 1 то последний
E int* p_last_day_pointer;