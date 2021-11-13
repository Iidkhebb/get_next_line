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
	{
		i++;
	}
	if (str_static[i] == '\0')
		return (-1);
	return (i);
}

char	*next_line_maker(char *str_static, int pos)
{
	int		i;
	char	*new_str;
	int		line_len;

	i = 0;
	line_len = buffer_len(str_static);
	new_str = (char *)malloc((pos + 2) * sizeof(char));
	if (!new_str)
		return (0);
	ft_memmove(new_str, str_static, line_len);
	new_str[line_len] = '\n';
	new_str[line_len + 1] = '\0';
	return (new_str);
}

char	*line_cutter(char *str_static)
{
	char	*new_str;
	int		pos;

	if (ft_strlen(str_static) <= 0)
		return (0);
	pos = buffer_len(str_static);
	if (pos == -1 || pos == (int)ft_strlen(str_static) - 1)
	{
		new_str = ft_strdup(str_static);
		return (new_str);
	}
	new_str = next_line_maker(str_static, pos);
	return (new_str);
}

char	*buffer_old_line_rm(char *str_static)
{
	int	remaining_len;
	int	pos;

	if (!str_static)
		return (0);
	remaining_len = (int)ft_strlen(str_static);
	pos = buffer_len(str_static);
	if (pos == -1 || ((remaining_len - pos) == 1))
	{
		free(str_static);
		return (0);
	}
	str_static = ft_substr(str_static, (pos + 1), (remaining_len - pos - 1));
	return (str_static);
}

char	*get_next_line(int fd_track)
{
	char		*str_tmp;
	static char	*str_static[10000000];
	int			read_return_index;
	char		*new_str;

	if (fd_track < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_tmp = malloc(BUFFER_SIZE + 1);
	if (!(str_tmp))
		return (0);
	while (buffer_len(str_static[fd_track]) == -1)
	{
		read_return_index = read(fd_track, str_tmp, BUFFER_SIZE);
		if (read_return_index <= 0)
			break ;
		str_tmp[read_return_index] = '\0';
		str_static[fd_track] = ft_strjoin(str_static[fd_track], str_tmp);
	}
	free(str_tmp);
	if (read_return_index == -1)
		return (0);
	new_str = line_cutter(str_static[fd_track]);
	str_static[fd_track] = buffer_old_line_rm(str_static[fd_track]);
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
