# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouloube <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 12:51:57 by aouloube          #+#    #+#              #
#    Updated: 2016/10/18 16:37:27 by aouloube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = fractol

CC = gcc

LIB = libft/libft.a

FLAG = -Wall -Wextra -Werror -O3

LIBGRPH = -lmlx -framework OpenGL -framework Appkit

INC = fractol.h

OBJ =  julia.o mandelbrot.o tricorn.o burning_ship.o sword.o chameleon.o\
	   fractol.o\
	   key_mouse.o key_hook.o key_hook_2.o\

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
	@make -C libft/
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*            FRACTOL          *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*            GCC       OK [✓] *| \033[33;0m"
	@echo "\033[33;34m |*            AR RC     OK [✓] *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |* =======  COMPLETED 😎  ===== *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m \n"

%.o : %.c $(INC)
	@$(CC) -c $(FLAG) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*       FRACTOL - CLEAN       *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |* =======  ALL CLEAN  🚮 ===== *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m \n"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
