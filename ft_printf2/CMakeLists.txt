cmake_minimum_required(VERSION 3.16)
project(ft_printf2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf2 main.c ft_printf.c ft_printf.h ft_printf_utils.c ft_printf_parse.c ft_printf_libft.c ft_printf_c_s.c ft_printf_u_d_i.c ft_printf_libft_add.c)