/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:06:38 by artmarti          #+#    #+#             */
/*   Updated: 2023/09/14 11:06:39 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	printmap(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
}

void	printmap_check(t_map *data, char **map)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	change_map2(t_map *d, int a)
{
	if (a == 119)
	{
		if (d->map[d->player.x - 1][d->player.y] == COLLECT)
			d->collect.nbr--;
		d->map[d->player.x][d->player.y] = GROUND;
		d->player.x--;
		d->map[d->player.x][d->player.y] = PLAYER_NAME;
	}
	else if (a == 115)
	{
		if (d->map[d->player.x + 1][d->player.y] == COLLECT)
			d->collect.nbr--;
		d->map[d->player.x][d->player.y] = GROUND;
		d->player.x++;
		d->map[d->player.x][d->player.y] = PLAYER_NAME;
	}
	else if (a == 97)
	{
		if (d->map[d->player.x][d->player.y - 1] == COLLECT)
			d->collect.nbr--;
		d->map[d->player.x][d->player.y] = GROUND;
		d->player.y--;
		d->map[d->player.x][d->player.y] = PLAYER_NAME;
	}
}

void	change_map(t_map *d, int a)
{
	int	do_ext;

	do_ext = 0;
	if ((d->player.x == d->exit.x) && (d->player.y == d->exit.y))
		do_ext = 1;
	if (a == 119 || a == 115 || a == 97)
		change_map2(d, a);
	else if (a == 100)
	{
		if (d->map[d->player.x][d->player.y + 1] == COLLECT)
			d->collect.nbr--;
		d->map[d->player.x][d->player.y] = GROUND;
		d->player.y++;
		d->map[d->player.x][d->player.y] = PLAYER_NAME;
	}
	if (do_ext == 1)
		d->map[d->exit.x][d->exit.y] = EXIT;
	d->player.move++;
	ft_printf("\nPosition : %i, %i\n", d->player.x, d->player.y);
	ft_printf("Moves : %i\n", d->player.move);
	ft_printf("Collectibles left : %i\n\n", d->collect.nbr);
}
