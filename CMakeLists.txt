project(mirror)

set(source 

start_program.c
Manipulation/Core/Output.c
Manipulation/Core/Preparing.c
Manipulation/Core/Reading.c
Manipulation/Core/Time.c
Manipulation/Core/Writing.c
Manipulation/Data/Data.c
Manipulation/Global/Global_variables.c
Manipulation/Interface/Interface.c
Manipulation/Interface/Menu_2/Menu_2.c
Manipulation/Interface/Menu_3/Menu_3.c
Manipulation/Interface/Menu_4/Menu_4.c

)

add_executable(a.out ${source})