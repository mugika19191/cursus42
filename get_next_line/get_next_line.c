/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:52:58 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/19 14:21:05 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_clean(char **rem)
{
	int	i;
	int	len;
	char	*str;
	
	i = 0;
	len = 0;
	while (*(*rem + len) != '\n' && *(*rem + len))
		len++;
	str = malloc(len + 2);
	if (!str || (len == 0 && *(*rem + len) != '\n'))
	{
		free(str);
		return (0);
	}
	while (*(*rem + i) != '\n' && *(*rem + i))
	{
		str[i] = *(*rem + i);
		i++;
	}
	if (*(*rem + i))
		str[i] = '\n';
	str[i + 1] = '\0';
	*rem = *rem + i + 1;
	return (str);
}

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == (unsigned char)c)
			return ((char *)string);
		string++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

char *get_next_line(int fd)
{
	static char *rem;
	char *buffer;
	int bytes;
	
	buffer = malloc(BUFFER_SIZE);
	if (fd == -1 || !BUFFER_SIZE || !buffer )
	{
		free(buffer);
		return (0);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes)
	{
		rem = ft_strjoin(rem, buffer, bytes);
		while (!ft_strchr(rem, '\n') && bytes && bytes == BUFFER_SIZE)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes)
				rem = ft_strjoin(rem, buffer, bytes);
		}
	}
	free(buffer);
	return (ft_clean(&rem));
}
