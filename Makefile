# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 23:17:14 by jvivas-g          #+#    #+#              #
#    Updated: 2024/10/07 20:03:06 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Lista de archivos fuente y objetos
SOURCES = 	src/main.c \
			src/frees/free.c \
			src/init/init.c \
			src/keys/keys.c \
			src/keys/keys_utils.c \
			src/parse/parse.c \
			src/parse/parse_utils_1.c \
			src/parse/parse_utils_2.c

OBJECTS =	src/main.o \
			src/frees/free.o \
			src/init/init.o \
			src/keys/keys.o \
			src/keys/keys_utils.o \
			src/parse/parse.o \
			src/parse/parse_utils_1.o \
			src/parse/parse_utils_2.o

# Ruta a la libft
LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a

# Ruta a la MLX42
MLX42_DIR = MLX42
BUILD_DIR = $(MLX42_DIR)/build
MLX42 = $(BUILD_DIR)/libmlx42.a

# Flags de compilacion
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address
RM := rm -f
RMDIR := rm -rf
MLX42_INC := -I ./include
LIBS := $(MLX42) -ldl -lglfw -lm

# Regla principal
$(NAME): $(OBJECTS) $(LIBFT) $(MLX42)
	@$(CC) $(CFLAGS) $(OBJECTS) -L $(LIBFT_DIR) -lft $(LIBS) -o $(NAME)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

# Compilar MLX42
$(MLX42):
	@cmake -B $(BUILD_DIR) $(MLX42_DIR)
	@cmake --build $(BUILD_DIR) -j4

# Compilar la librería
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Reglas de compilación para cada archivo objeto
src/main.o: src/main.c
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/frees/free.o: src/frees/free.c
	@echo "Compiling free.c"
	@$(CC) $(CFLAGS) -c src/frees/free.c -o src/frees/free.o

src/init/init.o: src/init/init.c
	@echo "Compiling init.c"
	@$(CC) $(CFLAGS) -c src/init/init.c -o src/init/init.o

src/keys/keys.o: src/keys/keys.c
	@echo "Compiling keys.c"
	@$(CC) $(CFLAGS) -c src/keys/keys.c -o src/keys/keys.o

src/keys/keys_utils.o: src/keys/keys_utils.c
	@echo "Compiling keys_utils.c"
	@$(CC) $(CFLAGS) -c src/keys/keys_utils.c -o src/keys/keys_utils.o

src/parse/parse.o: src/parse/parse.c
	@echo "Compiling parse.c"
	@$(CC) $(CFLAGS) -c src/parse/parse.c -o src/parse/parse.o

src/parse/parse_utils_1.o: src/parse/parse_utils_1.c
	@echo "Compiling parse_utils_1.c"
	@$(CC) $(CFLAGS) -c src/parse/parse_utils_1.c -o src/parse/parse_utils_1.o
	
src/parse/parse_utils_2.o: src/parse/parse_utils_2.c
	@echo "Compiling parse_utils_2.c"
	@$(CC) $(CFLAGS) -c src/parse/parse_utils_2.c -o src/parse/parse_utils_2.o

# Objetivos
all: $(NAME) $(MLX42) $(LIBFT)

# Limpiar archivos objeto
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RMDIR) $(BUILD_DIR)
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RMDIR) $(BUILD_DIR)
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re
