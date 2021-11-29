/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:40:40 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/13 03:52:19 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int i = 0;

	s2 = (char *)malloc((sizeof(char)) * (ft_strlen(s) + 1));
	if (!s2)
		return (0);
	while (s[i])
	{
		s2[i] = ((char *)s)[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	unsigned int i = 0;
	unsigned int len1 = ft_strlen(s1);
	unsigned int len2 = ft_strlen(s2);
	s = (char *)malloc((len1 + len2) + 1);
	if (!s)
		return (0);
	while (i  < len1)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i  < len2)
	{
		s[i + len1] = s2[i];
		i++;
	}
	s[len1 + len2] = '\0';
	free((char *)s1);
	return (s);
}
