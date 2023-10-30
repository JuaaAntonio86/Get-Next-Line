/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:00:08 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/26 15:19:36 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (int) 5

# endif

char	*ft_read_return_line(char *buffer, int fd);
char	*ft_newline(char *buffer);
void	*ft_free(char	**str);
char	*ft_newline(char *buffer);
char	*ft_cleanbuffer(char *buffer, char *newline);
char	*ft_strjoin(char *storage, char *buffer);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*get_next_line(int fd);

#endif
