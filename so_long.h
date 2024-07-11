/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:32:59 by artmarti          #+#    #+#             */
/*   Updated: 2023/07/18 10:33:00 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WHITE_PIXEL 0xFFFFFF
# define WW 128
# define WH 128
# define PLAYER_NAME 'P'
# define GROUND '0'
# define WALL '1'
# define COLLECT 'C'
# define EXIT 'E'
# define XK_W 
# define XK_S
# define XK_A
# define XK_D

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_imgg
{
	void	*mi;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_imgg;

typedef struct s_obj
{
	int	x;
	int	y;
	int	nbr;
	int	move;
}	t_obj;

typedef struct s_map
{
	char	**map;
	int		size;
	int		check;
	t_obj	player;
	t_obj	collect;
	t_obj	exit;
}	t_map;

typedef struct s_id
{
	void	*mlx;
	void	*win;
	int		nbr_y;
	int		nbr_x;
	t_imgg	play;
	t_imgg	coll;
	t_imgg	exit;
	t_imgg	wall;
	t_imgg	grnd;
	t_map	mapp;
}	t_id;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

void	check_exit_pose(t_obj *exit, char **map);
void	free_map(char **map);
void	printmap(t_map *data);
void	printmap_check(t_map *data, char **map);
void	change_map2(t_map *d, int a);
void	change_map(t_map *d, int a);
void	check_player_pose(t_obj *player, char **map);
char	*transf_lastn(char *map);
char	**get_map(char *map_name, int size);
char	**get_map2(char *map_name, int size);
int		add_collect(char **map, char l);
int		check_correct_char_map(char **map);
int		check_wall(char **map, int sl);
int		check_rect_and_wall(char **map);
int		c_err(char **map);
int		c_bas_err(t_map *data, char **map);
int		handle_exit(int keysym, t_id *data);
int		size_line(char **map);
int		close_all(t_id *data);
int		c_do(t_map *dmap, int x, int y, char **map);
int		size_map(char *map_name);
int		render(t_id *d);
int		ext_main2(char **map1, char **map2);
int		main2(t_map *dmap, char **map2, char **argv);

#endif