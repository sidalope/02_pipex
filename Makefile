# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisani <abisani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 11:37:56 by abisani           #+#    #+#              #
#    Updated: 2025/12/02 23:21:22 by abisani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

NAME = pipex

LIBFT = libft/libft.a

SRC_DIR = src
SRC_FILES = pipex.c file_handling.c cmd_parsing.c processes.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c $(SRC_DIR)/pipex.h
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME) $(TEST_EXECUTABLE)
	@make -C libft fclean

re: fclean all
