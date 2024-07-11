/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:05:58 by artmarti          #+#    #+#             */
/*   Updated: 2023/03/28 11:06:01 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	modify_strlen(char *container, int i)
{
	if (!container)
		return (0);
	while (container[i] != '\0' && container[i] != '\n')
		i++;
	return (i);
}

char	*get_actual_line(char *container)
{
	char	*actual_line;
	int		i;

	i = 0;
	if (!container[0])
		return (NULL);
	actual_line = ft_calloc(sizeof(char), (modify_strlen(container, i)) + 2);
	while (container[i] != '\0' && container[i] != '\n')
	{
		actual_line[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		actual_line[i++] = '\n';
	return (actual_line);
}

char	*replace_good_pos(char *container)
{
	char	*good_pos;
	int		i;
	int		j;

	if (!container[0])
	{
		free(container);
		return (NULL);
	}
	i = modify_strlen(container, 0);
	if (container[i] == '\n')
		if (ft_free_if(container, i) == 1)
			return (NULL);
	j = i;
	while (container[j] != '\0')
		j++;
	good_pos = ft_calloc(sizeof(char), j - i + 1);
	j = 0;
	if (!container[i])
		i--;
	while (container[++i] != '\0')
		good_pos[j++] = container[i];
	good_pos[j] = '\0';
	free (container);
	return (good_pos);
}

char	*get_next_line(int fd)
{
	static char	*containfile = NULL;
	char		*buffer;
	int			read_result;

	read_result = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!containfile)
		containfile = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (read_result > 0)
	{
		if (ft_strchr(containfile, '\n'))
			break ;
		read_result = read(fd, buffer, BUFFER_SIZE);
		buffer[read_result] = '\0';
		if (read_result != 0)
			containfile = ft_strjoin(containfile, buffer);
	}
	free (buffer);
	buffer = get_actual_line(containfile);
	containfile = replace_good_pos(containfile);
	return (buffer);
}
