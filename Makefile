# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 12:02:51 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/07/03 16:19:00 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC	= $(addprefix src/, main.c image.c mandelbrot.c julia.c keyboard.c mouse.c burningship.c)
	

OBJ = $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#MLX_LNK	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
#MLX_LNK	= -std=gnu99 -I. -g ${OBJ} -lm -lGLEW -lglfw -lGL ./minilibx-linux/libmlx_Linux.a -o ${NAME}
#MLX_LNK	= -std=gnu99 -I. -lm -lGLEW -lglfw -lGL ./minilibx-linux/libmlx_Linux.a
MLX_LNK =	./minilibx/libmlx.a -l Xext -l X11



FT		= ./Libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./Libft
FT_LNK	= -L ./Libft -l ft

SCRDIR 	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(FT_LIB) $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		make -C $(FT)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
		rm -rf $(OBJ)
		make -C $(FT) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(FT) fclean

re: fclean all
