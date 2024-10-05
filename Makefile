# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 23:17:14 by jvivas-g          #+#    #+#              #
#    Updated: 2024/10/05 02:05:12 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Lista de archivos fuente y objetos
SOURCES = 	src/main.c \
			src/errors/errors.c \
			src/free/free.c \
			src/init/init.c \
			src/keys/keys.c \
			src/parser/parse.c \
			src/parser/utils_1.c \
			src/parser/utils_2.c \
			src/parser/utils_3.c \

OBJECTS =	src/main.o \
			src/errors/errors.o \
			src/free/free.o \
			src/init/init.o \
			src/keys/keys.o \
			src/parser/parse.o \
			src/parser/utils_1.o \
			src/parser/utils_2.o \
			src/parser/utils_3.o \

# Ruta a la libft
LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a

# Ruta a la MLX42
MLX42_DIR = MLX42
BUILD_DIR = $(MLX42_DIR)/build
MLX42 = $(BUILD_DIR)/libmlx42.a

# Flags de compilacion
CC := gcc
CFLAGS := -Wall -Wextra -Werror
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
	
src/errors/errors.o: src/errors/errors.c
	@echo "Compiling errors.c"
	@$(CC) $(CFLAGS) -c src/errors/errors.c -o src/errors/errors.o

src/free/free.o: src/free/free.c
	@echo "Compiling free.c"
	@$(CC) $(CFLAGS) -c src/free/free.c -o src/free/free.o

src/init/init.o: src/init/init.c
	@echo "Compiling init.c"
	@$(CC) $(CFLAGS) -c src/init/init.c -o src/init/init.o

src/keys/keys.o: src/keys/keys.c
	@echo "Compiling keys.c"
	@$(CC) $(CFLAGS) -c src/keys/keys.c -o src/keys/keys.o

src/parser/parse.o: src/parser/parse.c
	@echo "Compiling parse.c"
	@$(CC) $(CFLAGS) -c src/parser/parse.c -o src/parser/parse.o

src/parser/utils_1.o: src/parser/utils_1.c
	@echo "Compiling utils_1.c"
	@$(CC) $(CFLAGS) -c src/parser/utils_1.c -o src/parser/utils_1.o
	
src/parser/utils_2.o: src/parser/utils_2.c
	@echo "Compiling utils_2.c"
	@$(CC) $(CFLAGS) -c src/parser/utils_2.c -o src/parser/utils_2.o

src/parser/utils_3.o: src/parser/utils_3.c
	@echo "Compiling utils_3.c"
	@$(CC) $(CFLAGS) -c src/parser/utils_3.c -o src/parser/utils_3.o

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
