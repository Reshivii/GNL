/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:12:28 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/28 12:37:03 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *save)
{
	char	*buf;
	int		i;
	
	i = 0;
	buf = malloc(sizeof(*buf) *(BUFFER_SIZE + 1));
	if (!buf)
		return (free_all(save, buf));
	while (!search_n(save))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			free_all(save, buf);
		if (!i)
			break ;
		buf[i] = 0;
		save = ft_strjoin(save, buf);
		if (!save)
			return(0);
	}
	free(buf);
	return (save);
}

static char	*before_n(char *save, int *count)
{
	char	*line;
	int		i;


	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(sizeof(*line) * i + 1);
	if (!line)
		return(free_all(save, 0));
	line[i] = 0;
	*count = i;
	while (i != 0)
	{
		line[i - 1] = save[i - 1];
		i--;
	}
	return (line);
}

static char	*after_n(char *save, int count)
{	
	char	*new_save;
	int		i;
	
	if (count == ft_strlen(save))
		return (free_all(save, 0));
	new_save = malloc(sizeof(*new_save) * (ft_strlen(save) - count) + 1);
	if (!new_save)
		return(free_all(save, 0));
	i = -1;
	while (save[count])
	{
		new_save[++i] = save[count];
		count++;
	}
	new_save[i] = 0;
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	int			i;
	
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	save = read_line(fd, save);
	if (!save)
		return (0);
	line = before_n(save, &i);
	if (!line)
	{
		save = 0;
		return (0);
	}
	save = after_n(save, i);
	return (line);
}