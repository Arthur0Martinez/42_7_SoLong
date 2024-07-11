# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 08:06:32 by artmarti          #+#    #+#              #
#    Updated: 2023/07/24 11:33:30 by artmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALLFILES = so_long.c get_map.c error.c map.c utils.c so_long2.c

GNLSRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJECTS = $(ALLFILES:.c=.o)

GNLOBJS = $(GNLSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

all : doprintf $(NAME)
	
$(NAME) : $(OBJECTS) $(GNLOBJS)
	gcc $(CFLAGS) $(ALLFILES) $(GNLSRC) mlx/libmlx.a ft_printf/printf.a -o so_long -lX11 -lXext -no-pie

clean :
	rm -rf $(OBJECTS)
	@make clean -C ft_printf

fclean : clean
	rm -rf $(NAME)
	@make -C ft_printf fclean

re : fclean all

doprintf : 
	@make -C ft_printf all

dognl :
	@make -C get_next_line all

dominilibx :
	@make -C mlx all