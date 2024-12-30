# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:04:30 by mbendidi          #+#    #+#              #
#    Updated: 2024/12/30 10:45:56 by mbendidi         ###   ########.fr        #
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
HEADER = -I $(INC_DIR) -I $(LIBFT)/inc
RM = rm -f

SRC_FILES = core/main.c \
            core/init_stack.c \
            core/ft_sort.c \
            core/push_swap.c \
            actions/push.c \
            actions/swap.c \
            actions/rotate.c \
            actions/rev_rotate.c \
            sort/sort.c \
            sort/sort_basic.c \
            sort/sort_chunk.c \
            sort/sort_chunks.c \
            utils/utils.c \
            utils/sort_utils.c \
            utils/helpers.c \
            utils/validation.c \
			utils/ft_is.c \
            utils/a_suprimer.c


SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

TOTAL = $(words $(SRC_FILES))
COUNT = 0
BAR_WIDTH = 40

all: $(OBJ_DIR) $(LIBFT)/libft.a $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADER) $(LIBFT)/libft.a -o $(NAME)
	@printf "\r\033[K"
	@printf "%0*s100%%%s\n" $(BAR_WIDTH) "=" " push_swap compiled"

# Règle pour compiler chaque fichier source en fichier objet
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) # Crée les sous-dossiers de obj/ dynamiquement
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@(\
		PCT=$$((100*$(COUNT)/$(TOTAL))); \
		BAR_LEN=$$(( $(BAR_WIDTH)*$(COUNT)/$(TOTAL) )); \
		printf "\r\033[K%.*s%d%%" $$BAR_LEN "========================================" $$PCT; \
	)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Pour la compilation WASM
WASM_NAME = push_swap
WASM_SOURCES = $(shell find src libft/src -name '*.c' | grep -v 'get_next_line_utils.c')

wasm: $(WASM_SOURCES)
	docker run --rm -v "$(shell pwd):/src" emscripten/emsdk emcc $(WASM_SOURCES) -I $(INC_DIR) -I $(LIBFT)/inc -o $(WASM_NAME).wasm -s WASM=1 -O2

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
	@norminette $(SRCS) $(INC_DIR) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
