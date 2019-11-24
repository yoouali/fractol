# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoouali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 00:47:12 by yoouali           #+#    #+#              #
#    Updated: 2019/11/24 02:18:12 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/burning_julia.c\
	  src/burning_ship.c\
	  src/checker.c\
	  src/color.c\
      src/draw.c\
      src/feigenbaum_point.c\
	  src/fractal.c\
	  src/graphic_environment.c\
	  src/imagine_point.c\
	  src/julia.c\
	  src/key_event.c\
	  src/key_hold_event.c\
	  src/main.c\
	  src/mandelbrot.c\
	  src/mandelbrot_pow.c\
	  src/mouse_event.c\
	  src/reality_point.c\
	  src/teardrop.c\
	  src/tricorn.c\
	  src/tricorn_pow.c

OBJ = $(SRC:.c=.o)

MLXL = mlx/libmlx.a

MLXF = -framework OpenGl -framework Appkit -lz

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	make -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(MLXL) $(OBJ) $(MLXF)

clean :
	make -C mlx clean
	rm -f $(OBJ)
fclean : clean
	make -C mlx fclean
	rm -f $(NAME)

re : fclean all
