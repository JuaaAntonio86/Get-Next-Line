/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:40 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/26 15:30:20 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == (unsigned char)c)
			return (&a[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&a[i]);
	else
		return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!dst)
		return (NULL);
	str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(char));
	if (!str)
	{
		return (ft_free(&dst));
	}
	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		str[i] = dst[i];
		i++;
	}
	while (src[j] != '\0')
		str[i++] = src[j++];
	str[i] = '\0';
	free(dst);
	return (str);
}
