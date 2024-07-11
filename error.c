/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:07:52 by artmarti          #+#    #+#             */
/*   Updated: 2023/09/14 11:07:54 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall2(char **map, int j)
{
	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != WALL)
			return (1);
		j++;
	}
	return (0);
}

int	check_wall(char **map, int sl)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (map[size] != NULL)
		size++;
	i = 1;
	if (check_wall2(map, 0) == 1)
		return (1);
	while (i < size)
	{
		j = 0;
		if (map[i][0] != WALL || map[i][sl - 1] != WALL)
			return (1);
		i++;
	}
	size--;
	while (map[size][j] != '\0')
	{
		if (map[size][j] != WALL)
			return (1);
		j++;
	}
	return (0);
}

int	check_rect_and_wall(char **map)
{
	int	i;
	int	j;
	int	size_line;

	size_line = 0;
	while (map[0][size_line] != '\0')
		size_line++;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (j != size_line)
			return (1);
		i++;
	}
	if (check_wall(map, size_line) == 1)
		return (2);
	return (0);
}

int	c_err(char **map)
{
	if (check_rect_and_wall(map) == 1)
	{
		write(2, "\nError : Map is not a rectangle\n\n", 33);
		return (1);
	}
	if (check_rect_and_wall(map) == 2)
	{
		write(2, "\nError : Map is not surrounded by walls\n\n", 41);
		return (1);
	}
	return (0);
}

int	c_bas_err(t_map *data, char **map)
{
	if (check_correct_char_map(map))
	{
		write(2, "\nError : Unknown characters on map\n\n", 36);
		return (1);
	}
	data->collect.nbr = add_collect(map, COLLECT);
	data->player.nbr = add_collect(map, PLAYER_NAME);
	data->exit.nbr = add_collect(map, EXIT);
	data->check = data->collect.nbr + data->exit.nbr;
	if (data->collect.nbr < 1)
	{
		write(2, "\nError : You need to have at least 1 collectible\n\n", 50);
		return (1);
	}
	if (data->player.nbr != 1)
	{
		write(2, "\nError : You can't have more/less than 1 player\n\n", 49);
		return (1);
	}
	if (data->exit.nbr != 1)
	{
		write(2, "\nError : You can't have more/less than 1 exit\n\n", 47);
		return (1);
	}
	return (0);
}
