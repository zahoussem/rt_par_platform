project(rtLib)
add_executable(
        test
        headers/time_operations.h
	headers/sched_functions.h
	headers/structures.h
        files/time_operations.c
	files/sched_functions.c
	files/structures.c
        main.c

)
