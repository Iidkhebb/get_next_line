/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:39:58 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/13 03:50:59 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	buffer_len(char *str_static)
{
	int	i;

	if (!str_static)
		return (-1);
	i = 0;
	while (str_static[i] != '\0' && str_static[i] != '\n')
		i++;
	if (str_static[i] == '\0')
		return (-1);
	return (i);
}

char	*line_cutter(char *str_static)
{
	char	*new_str;
	int		pos;

	if (!str_static)
		return (NULL);
	pos = buffer_len(str_static);
	if (pos == -1)
		return (ft_strdup(str_static));
	new_str = (char *)malloc((pos + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, str_static, pos);
	new_str[pos] = '\n';
	new_str[pos + 1] = '\0';
	return (new_str);
}

char	*buffer_old_line_rm(char *str_static)
{
	int	remaining_len;
	int	pos;

	if (!str_static)
		return (NULL);
	remaining_len = (int)ft_strlen(str_static);
	pos = buffer_len(str_static);
	if (pos == -1 || ((remaining_len - pos) == 1))
		return (free(str_static), NULL);
	str_static = ft_substr(str_static, (pos + 1), (remaining_len - pos - 1));
	return (str_static);
}

char	*get_next_line(int fd)
{
	char		*str_tmp;
	static char	*str_static[1024];
	int			rtr;
	char		*new_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_tmp = malloc(BUFFER_SIZE + 1);
	if (!str_tmp)
		return (NULL);
	while (buffer_len(str_static[fd]) == -1)
	{
		rtr = read(fd, str_tmp, BUFFER_SIZE);
		if (rtr <= 0)
			break ;
		str_tmp[rtr] = '\0';
		str_static[fd] = ft_strjoin(str_static[fd], str_tmp);
	}
	free(str_tmp);
	new_str = line_cutter(str_static[fd]);
	str_static[fd] = buffer_old_line_rm(str_static[fd]);
	return (new_str);
}
/*
int main()
{
    int fd;
    char *line;
    int i;
    i =0;
    fd = open("test.txt", O_RDWR | O_CREAT);
    //printf("the FD is : %d\n",fd);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s",line);
    }
    return (0);
}
*/
