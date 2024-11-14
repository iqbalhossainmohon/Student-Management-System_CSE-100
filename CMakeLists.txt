cmake_minimum_required(VERSION 3.28)
project(SDP_SMS C)

set(CMAKE_C_STANDARD 17)

add_executable(SDP_SMS main.c
        admin.h
        admin.c
        teacher.h
        teacher.c
        student.h
        student.c
        file_operations.h
        file_operations.c)


# add_executable(admin admin.c)
# add_executable(teacher teacher.c)
# add_executable(student student.c)
# add_executable(file_operations file_operations.c)
