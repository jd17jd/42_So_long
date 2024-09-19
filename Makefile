# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 23:17:14 by jvivas-g          #+#    #+#              #
#    Updated: 2024/09/19 20:58:43 by jvivas-g         ###   ########.fr        #
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
			src/parser/parse.c \
			src/parser/utils_2.c \
			src/parser/utils.c

OBJECTS =	src/main.o \
			src/errors/errors.o \
			src/free/free.o \
			src/init/init.o \
			src/parser/parse.o \
			src/parser/utils_2.o \
			src/parser/utils.o

# Librería
LIBFT = lib/libft.a

# Ruta a la MLX42
MLX42_DIR = MLX42/build
MLX42 = $(MLX42_DIR)/libmlx42.a
GLFW = -lglfw
MLX42_INC = -I ./include
LIBS = $(MLX42) -ldl -lglfw -lm

CC := gcc
CFLAGS := -Wall -Wextra -Werror $(MLX42_INC)
RM := rm -f

# Regla principal
$(NAME): $(OBJECTS) $(LIBFT) $(MLX42)
	@$(CC) $(CFLAGS) $(OBJECTS) -L lib -lft $(LIBS) -o $(NAME)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

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

src/parser/parse.o: src/parser/parse.c
	@echo "Compiling parse.c"
	@$(CC) $(CFLAGS) -c src/parser/parse.c -o src/parser/parse.o
	
src/parser/utils_2.o: src/parser/utils_2.c
	@echo "Compiling utils_2.c"
	@$(CC) $(CFLAGS) -c src/parser/utils_2.c -o src/parser/utils_2.o

src/parser/utils.o: src/parser/utils.c
	@echo "Compiling utils.c"
	@$(CC) $(CFLAGS) -c src/parser/utils.c -o src/parser/utils.o

all: libmlx $(NAME)

libmlx:
	@cmake $(MLX42_DIR) -B $(LIBMLX) && make -C $(LIBMLX) -j4

# Limpiar archivos objeto
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C lib clean
	@echo $(COLOR_VERDE) "All objects cleaned" $(COLOR_RESET)

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C lib fclean
	@echo $(COLOR_VERDE) "All executable cleaned" $(COLOR_RESET)

# Recompilar todo
re: fclean all

# Compilar la librería
$(LIBFT):
	@$(MAKE) -C lib

.PHONY: all clean fclean re
