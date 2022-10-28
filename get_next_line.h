/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:08:01 by aburnott          #+#    #+#             */
/*   Updated: 2022/10/28 12:34:56 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*free_all(char *save, char *buf);
int		search_n(char *save);
int		ft_strlen(char *s);
char	*ft_strjoin(char *save, char *buf);
char	*get_next_line(int fd);

#endif