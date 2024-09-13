# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 23:17:14 by jvivas-g          #+#    #+#              #
#    Updated: 2024/09/13 04:16:56 by jvivas-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Colores
COLOR_RESET = "\033[0m"
COLOR_VERDE = "\033[32m"

# Lista de archivos fuente y objetos
SOURCES = 	src/main.c \
			src/errors/errors.c \
			src/parser/parse.c

OBJECTS =	src/main.o \
			src/errors/errors.o \
			src/parser/parse.o

# Librería
LIBFT = lib/libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Regla principal
$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -L lib -lft -o $(NAME)
	@echo $(COLOR_VERDE) "Created $(NAME)" $(COLOR_RESET)

# Reglas de compilación para cada archivo objeto
src/main.o: src/main.c
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) -c src/main.c -o src/main.o
	
src/errors/errors.o: src/errors/errors.c
	@echo "Compiling errors.c"
	@$(CC) $(CFLAGS) -c src/errors/errors.c -o src/errors/errors.o

src/parser/parser.o: src/parser/parser.c
	@echo "Compiling errors.c"
	@$(CC) $(CFLAGS) -c src/parser/parser.c -o src/parser/parser.o

all: $(NAME)

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
