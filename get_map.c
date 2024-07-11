/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:36:05 by artmarti          #+#    #+#             */
/*   Updated: 2023/08/25 10:36:06 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_correct_char_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != PLAYER_NAME && map[i][j] != COLLECT &&
				map[i][j] != EXIT && map[i][j] != WALL &&
				map[i][j] != GROUND)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	c_do(t_map *dmap, int x, int y, char **map)
{
	if (map[x][y] != WALL && map[x][y] != 'o')
	{
		if (map[x][y] == EXIT)
			dmap->check--;
		if (map[x][y] == COLLECT)
			dmap->check--;
		map[x][y] = 'o';
		if (dmap->check == 0)
			return (dmap->check);
		c_do(dmap, x - 1, y, map);
		c_do(dmap, x + 1, y, map);
		c_do(dmap, x, y - 1, map);
		c_do(dmap, x, y + 1, map);
	}
	return (dmap->check);
}

int	size_map(char *map_name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (i);
}

char	*transf_lastn(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			map[i] = '\0';
		i++;
	}
	return (map);
}

char	**get_map(char *map_name, int size)
{
	int		fd;
	int		i;
	int		size2;
	char	**map;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	size2 = size_map(map_name);
	map = malloc(sizeof(char *) * (size + 1));
	while (i <= size2 - 1)
	{
		map[i] = get_next_line(fd);
		map[i] = transf_lastn(map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
