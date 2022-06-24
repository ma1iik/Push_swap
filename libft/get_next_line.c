/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:45:47 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 16:56:02 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*first_line(int fd, char *saveline)
{
	char	*buf;
	int		byte_read;

	buf = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(saveline, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read <= -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_read] = '\0';
		saveline = ft_strjoin(saveline, buf);
	}
	free(buf);
	return (saveline);
}

char	*clean_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (s[i] == '\0')
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc((sizeof(char)) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_line(char *s)
{
	int		a;
	int		i;
	char	*line;

	a = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	line = malloc((sizeof(char)) * ((ft_strlen(s) - i) + 1));
	if (!line)
		return (NULL);
	i++;
	a = 0;
	while (s[i])
		line[a++] = s[i++];
	line[a] = '\0';
	free(s);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*save_line;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_line = first_line(fd, save_line);
	if (!save_line)
		return (NULL);
	line = clean_line(save_line);
	save_line = ft_save_line(save_line);
	return (line);
}
