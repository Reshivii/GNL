/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:12:28 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/20 12:26:23 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}

	return (0);
}