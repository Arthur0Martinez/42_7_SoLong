/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:08:14 by artmarti          #+#    #+#             */
/*   Updated: 2023/09/14 11:08:15 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_exit(int keysym, t_id *data)
{
	if (keysym == XK_E)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	size_line(char **map)
{
	int	size_line;

	size_line = 0;
	while (map[0][size_line] != '\0')
		size_line++;
	return (size_line);
}

int	close_all(t_id *d)
{
	free_map(d->mapp.map);
	mlx_destroy_image(d->mlx, d->play.mi);
	mlx_destroy_image(d->mlx, d->exit.mi);
	mlx_destroy_image(d->mlx, d->coll.mi);
	mlx_destroy_image(d->mlx, d->wall.mi);
	mlx_destroy_image(d->mlx, d->grnd.mi);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit (0);
	return (0);
}

void	check_exit_pose(t_obj *exit, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == EXIT)
			{
				exit->x = i;
				exit->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	add_collect(char **map, char l)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == l)
			{
				map[i][j] = '0';
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
