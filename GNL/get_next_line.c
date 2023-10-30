/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:37:10 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/25 17:55:01 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (buffer == NULL)
	{
	buffer = malloc(1 * sizeof(char));
		if (buffer == NULL)
			return (NULL);
	buffer[0] = '\0';
	}
	buffer = ft_read_return_line(buffer, fd);
	if (buffer == NULL || buffer[0] == 0)
		return (ft_free(&buffer));
	line = ft_newline(buffer);
	if (line == NULL)
		return (ft_free(&buffer));
	buffer = ft_cleanbuffer(buffer, line);
	if (buffer == NULL || line[0] == 0)
		return (ft_free(&buffer));
	return (line);
}

char	*ft_read_return_line(char *buffer, int fd)
{
	int		read_check;
	char	*read_str;

	read_check = 1;
	read_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_str == NULL)
		return (ft_free(&buffer));
	while (read_check > 0 && ft_strchr(buffer, '\n') == 0)
	{	
		read_check = read(fd, read_str, BUFFER_SIZE);
		if (read_check < 0)
		{
			free(buffer);
			return (ft_free(&read_str));
		}
		read_str[read_check] = '\0';
		buffer = ft_strjoin(buffer, read_str);
		if (buffer == NULL)
			return (ft_free(&read_str));
	}
	free(read_str);
	return (buffer);
}

char	*ft_newline(char *buffer)
{
	int		i;
	char	*newline;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	newline = malloc((i + 1) * sizeof(char));
	if (newline == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		newline[i] = buffer[i];
	i++;
	}
	if (buffer[i] == '\n')
		newline[i++] = '\n';
	newline[i] = 0;
	return (newline);
}

void	*ft_free(char	**str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_cleanbuffer(char *buffer, char *newline)
{
	char	*nbuffer;
	int		i;
	int		j;

	j = 0;
	if (ft_strlen(newline) > ft_strlen(buffer))
		i = ft_strlen(newline) - ft_strlen(buffer);
	else
		i = ft_strlen(buffer) - ft_strlen(newline);
	nbuffer = malloc((i + 1) * sizeof(char));
	if (nbuffer == NULL)
	{
		free(buffer);
		return (ft_free(&newline));
	}
	i = ft_strlen(newline);
	while (buffer[i] != 0)
	{
		nbuffer[j++] = buffer[i++];
	}
	nbuffer[j] = 0;
	free(buffer);
	return (nbuffer);
}

/*/////////////////////////////////////MAIN////////////////////////
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
	int		fd;
	char	*theline;
//	int		bytes;
	int		i = 0;

	theline = NULL;
	fd = open("42_with_nl", O_RDONLY);
	printf("file descriptor = %d\n", fd);
	theline = malloc(999);
//	bytes = read(fd, theline, 999);
//	printf("CONTENT:\n%s\nbytes read: %d", theline, bytes);
	while (theline != NULL)
	{
		printf("----next line:----\n");
		theline = get_next_line(fd);
		printf("%s", theline);
		i++;
	}
	return (0);
}*/
