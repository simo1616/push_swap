# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:04:30 by mbendidi          #+#    #+#              #
#    Updated: 2024/12/28 16:35:42 by mbendidi         ###   ########.fr        #
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

SRC_FILES = push.c push_swap.c rev_rotate.c \
			rotate.c sort.c swap.c utils.c \
			sort_utils.c check.c sort_chunk.c \
			sort_funct.c	\
			ft_is.c a_suprimer.c \

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

# pour le test en ligne docker
WASM_NAME = push_swap
WASM_SOURCES = $(shell find src libft/src -name '*.c' | grep -v 'get_next_line_utils.c')

wasm: $(WASM_SOURCES)
	docker run --rm -v "$(shell pwd):/src" emscripten/emsdk emcc $(WASM_SOURCES) -I includes -I libft/inc -o $(WASM_NAME).wasm -s WASM=1 -O2

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
