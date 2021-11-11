/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:40:22 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/11 21:40:24 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<stdlib.h>
#include<unistd.h>

#include<stdio.h>
#include<string.h>
#include<fcntl.h>

char    *get_next_line(int fd);
void	*ft_memcpy(void *dest,	const void *src,	size_t size);
size_t	ft_strlen(char const	*str);
char	*ft_strjoin(char const *s1,	char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
#endif
