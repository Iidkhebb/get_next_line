/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:40:40 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/11 21:40:41 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return(0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s1;
	char	*s2;
	char	*dest;

	dest = (char *)malloc((sizeof(char)) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (0);
	s1 = (char *)s;
	s2 = dest;
	while (*s1)
	{
		*s2 = *s1;
		s1++;
		s2++;
	}
	*s2 = '\0';
	return (dest);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*ptr_dst;
	char		*ptr_dest2;
	const char	*ptr_src;
	const char	*ptr_src2;

	ptr_dst = str1;
	ptr_src = str2;
	if (!(str1) && !(str2))
		return (0);
	if (ptr_dst < ptr_src)
	{
		while (n--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_src2 = ptr_src + (n - 1);
		ptr_dest2 = ptr_dst + (n - 1);
		while (n--)
			*ptr_dest2-- = *ptr_src2--;
	}
	return (str1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	index;
	char	*out;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s) || !(out))
		return (0);
	index = start;
	i = 0;
	while (i < len && index < ft_strlen(s))
		out[i++] = ((char *)s)[index++];
	out[i] = '\0';
	free((char *)s);
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if ((!s1 && !s2) || !s)
		return (0);
	ft_memmove(s, s1, ft_strlen(s1));
	ft_memmove(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((char *)s1);
	return (s);
}

