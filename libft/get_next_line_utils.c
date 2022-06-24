/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:52:22 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 16:55:39 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			a;
	size_t			b;
	char			*newstr;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!newstr)
		return (NULL);
	a = -1;
	if (s1)
		while (s1[++a])
			newstr[a] = s1[a];
	b = 0;
	while (s2[b])
			newstr[a++] = s2[b++];
	newstr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (newstr);
}
