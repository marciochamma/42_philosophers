# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 12:46:33 by mchamma           #+#    #+#              #
#    Updated: 2024/05/21 14:51:09 by mchamma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Werror -Wextra -Wall -g3

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(shell find src -name "*.c")
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

INC = -I inc

#--------------------//-------------------#

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(INC) $(LIB) -o $(NAME) -lpthread

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	cc $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all
	make clean

#--------------------//-------------------#

test: test8

testleak: test9

# test: test1 test2 test3 test4 test5 test6 test7 test8
# 	@echo "\n" 

test1:
	@echo test1
	@./philo 1 | grep "wrong input: 2 argment(s)\n" \
		&& echo "Nok" || echo "Ok"

test2:
	@echo test2
	@./philo m | grep "wrong input: 2 argment(s)\n" \
		&& echo "Nok" || echo "Ok"

test3:
	@echo test3
	@./philo | grep "wrong input: 1 argment(s)\n" \
		&& echo "Nok" || echo "Ok"

test4:
	@echo test4
	@./philo 1 1 | grep "wrong input: 3 argment(s)\n" \
		&& echo "Nok" || echo "Ok"

test5:
	@echo test5
	@./philo a 1 1 1 | grep "wrong input: m not a integer\n" \
		&& echo "Nok" || echo "Ok"

test6:
	@echo test6
	@./philo 1 1 1 m | grep "wrong input: m not a integer\n" \
		&& echo "Nok" || echo "Ok"

test7:
	@echo test7
	@./philo $(SEQ2) | grep "wrong input: at least one philosopher\n" \
		&& echo "Nok" || echo "Ok"

test8:
	@echo test8
	@./philo 3 200 200 200 3

test9:
	@echo test9 w/ leaks
	@leaks --atExit -- ./philo 500 200 200 200 200

#--------------------//-------------------#

.PHONY: all clean fclean re