/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:33:50 by artmarti          #+#    #+#             */
/*   Updated: 2023/09/14 12:33:51 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render2(t_id *d, char c, int x, int y)
{
	if (c == PLAYER_NAME)
		mlx_put_image_to_window(d->mlx, d->win, d->play.mi, x, y);
	else if (c == GROUND)
		mlx_put_image_to_window(d->mlx, d->win, d->grnd.mi, x, y);
	else if (c == WALL)
		mlx_put_image_to_window(d->mlx, d->win, d->wall.mi, x, y);
	else if (c == COLLECT)
		mlx_put_image_to_window(d->mlx, d->win, d->coll.mi, x, y);
	else if (c == EXIT)
		mlx_put_image_to_window(d->mlx, d->win, d->exit.mi, x, y);
}

int	render(t_id *d)
{
	int	i;
	int	j;
	int	x;
	int	y;

	if (d->win == NULL)
		return (1);
	i = 0;
	x = 0;
	y = 0;
	while (d->mapp.map[i] != NULL)
	{
		j = 0;
		x = 0;
		while (d->mapp.map[i][j] != '\0')
		{
			render2(d, d->mapp.map[i][j], x, y);
			j++;
			x = x + 128;
		}
		i++;
		y = y + 128;
	}
	return (0);
}

void	check_player_pose(t_obj *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == PLAYER_NAME)
			{
				player->x = i;
				player->y = j;
				player->move = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ext_main2(char **map1, char **map2)
{
	if (map1 == NULL || map2 == NULL)
	{
		write(2, "\nError : Can't open map\n\n", 25);
		return (1);
	}
	return (0);
}

int	main2(t_map *dmap, char **map2, char **argv)
{
	char	**map3;

	if (c_err(map2) == 1 || c_bas_err(dmap, map2) == 1)
		return (1);
	map3 = get_map(argv[1], size_map(argv[1]));
	if (c_do(dmap, dmap->player.x, dmap->player.y, map3) != 0)
	{
		write(2, "\nError : Map is not doable or doesn't exist\n\n", 45);
		free_map(map3);
		return (1);
	}
	free_map(map3);
	return (0);
}
