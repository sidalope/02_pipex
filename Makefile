# ****************************************************************************#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 11:37:56 by abisani           #+#    #+#              #
#    Updated: 2026/02/03 12:36:41 by abisani          ###   ########.fr        #
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

BONUS_DIR = src/bonus
BONUS_FILES = pipex_bonus.c init_bonus.c file_handling_bonus.c \
				cmd_parsing_bonus.c processes_bonus.c
BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

bonus: $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c $(SRC_DIR)/pipex.h
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/pipex_bonus.h
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME) $(TEST_EXECUTABLE)
	@make -C libft fclean

re: fclean all
