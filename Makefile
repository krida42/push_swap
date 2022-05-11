# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 02:15:29 by kisikaya          #+#    #+#              #
#    Updated: 2022/03/21 17:15:40 by kisikaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap
INC_PATH = includes/

SRC =	push_swap.c stack_utils.c stack_utils2.c stack_utils3.c \
		stack_utils4.c stack_moves.c stack_moves2.c stack_moves3.c \
		sort_utils.c sort_utils2.c sort_utils3.c mini_utils.c
OBJ = $(SRC:.c=.o)
INCLUDES = push_swap.h

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $^ -I $(INC_PATH) -L ./libft -lft -o push_swap
$(OBJ) : $(INC_PATH)$(INCLUDES)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)
clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : $(NAME)
	echo "" && ./a.out && echo ""

.PHONY : all fclean clean re exec test
