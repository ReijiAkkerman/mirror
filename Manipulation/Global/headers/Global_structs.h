// Интерфейс

typedef struct {
    const char* str1;           // наименование пункта меню
} __menu;

// Структуры

typedef struct {
    char* name_common;          // имя стата
    int value_common;           // значение стата
} __common;

typedef struct {
    char* skill_name;           // имя навыка
    int skill_level;            // уровень владения навыком
    int today_received_exp;     // получено опыта за сегодня
    int today_full_exp;         // нужно получить опыта за сегодня
    int today_percentage;       // полученный опыт от плана на сегодня в процентном соотношении
    int current_exp;            // текущий опыт общий 
    int full_exp;               // нужно получить опыта для перехода к следующему уровню
    int common_percentage;      // общий опыт от плана в процентном соотношении
} __skills;

typedef struct {
    char* aim_name;             // наименование цели
    int today_received_exp;     // получено опыта за сегодня
    int today_full_exp;         // нужно получить опыта за сегодня
    int today_percentage;       // полученный опыт от плана на сегодня в процентном соотношении
    int current_exp;            // текущий опыт общий 
    int full_exp;               // нужно получить опыта для перехода к следующему уровню
    int common_percentage;      // общий опыт от плана в процентном соотношении
} __aims;

typedef struct {
    char* task_name;            // наименование задачи
    int today_received_exp;     // получено опыта за сегодня
    int today_full_exp;         // нужно получить опыта за сегодня
    int today_percentage;       // полученный опыт от плана на сегодня в процентном соотношении
    int current_exp;            // текущий опыт общий 
    int full_exp;               // нужно получить опыта для перехода к следующему уровню
    int common_percentage;      // общий опыт от плана в процентном соотношении
} __tasks;

typedef struct {
    char* subtask_name;         // наименование подзадачи
    int executed_items;         // выполнено пунктов 
    int need_to_exec_items;     // нужно выполнить пунктов 
    int percentage;             // выполненность подзадачи в процентном соотношении
} __subtasks;

typedef struct {
    char* main_name;            // наименование заголовка подтаблицы
} __main_name;