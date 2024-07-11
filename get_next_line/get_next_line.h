/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:33:31 by artmarti          #+#    #+#             */
/*   Updated: 2023/04/18 10:33:36 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_freestr(char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		modify_strlen(char *container, int i);
char	*get_actual_line(char *container);
char	*replace_good_pos(char *container);
char	*get_next_line(int fd);
int		ft_return_if(int read_result, char *containfile);
int		ft_free_if(char *container, int i);

#endif
