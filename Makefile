# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:04:30 by mbendidi          #+#    #+#              #
#    Updated: 2024/12/23 17:33:43 by mbendidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = includes
LIBFT = libft
OBJ_DIR = obj
HEADER = -I $(INC_DIR) -I libft/inc
RM = rm -f

SRC_FILES = push.c push_swap.c rev_rotate.c rotate.c sort.c swap.c utils.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

TOTAL = $(words $(SRC_FILES))
COUNT = 0
BAR_WIDTH = 40

all: $(OBJ_DIR) $(LIBFT)/libft.a $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(LIBFT)/libft.a -o $(NAME)
	@printf "\r\033[K"
	@printf "%0*s100%%%s\n" $(BAR_WIDTH) "=" " push_swap compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@(\
		PCT=$$((100*$(COUNT)/$(TOTAL))); \
		BAR_LEN=$$(( $(BAR_WIDTH)*$(COUNT)/$(TOTAL) )); \
		printf "\r\033[K%.*s%d%%" $$BAR_LEN "========================================" $$PCT; \
	)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@echo "Cleanup done."

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a
	@echo "All cleaned."

re: fclean all

norm:
	@norminette $(SRC) $(INC_DIR) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
