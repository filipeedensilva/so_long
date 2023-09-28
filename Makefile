# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 17:00:53 by feden-pe          #+#    #+#              #
#    Updated: 2023/09/28 16:57:36 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -gdwarf-4

SRC = so_long.c \
      controls.c \
      map.c \
      map_check.c \
      map_copy.c  \
      movements.c \
      moves_bonus.c \
      exit_errors.c \
      init.c \
      image.c

NAME = so_long
OBJ = ${addprefix ./obj/,${SRC:%.c=%.o}}

INCLUDES = -I so_long.h $(LIBFT_HEADER) $(MLX_HEADER) $(GNL_HEADER)

LIBFT = libft/libft.a
LIBFT_HEADER = libft/libft.h

FT_PRINTF = libft/ft_printf/libftprintf.a

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:%.c=%.o)
GNL_HEADER = get_next_line/get_next_line.h

MLX = mlx_linux/libmlx.a
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_HEADER = mlx_linux/mlx.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL_OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./mlx_linux

./obj/%.o: ./sources/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./mlx_linux
	$(RM) $(OBJ) $(GNL_OBJ)

fclean: clean
	make fclean -C ./libft
	make clean -C ./mlx_linux
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
