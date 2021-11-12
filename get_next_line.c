/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:39:58 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/11 21:40:00 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int buffer_len(char *str_static)
{
    int i;

    if(!str_static)
        return(-1);
    i = 0;
    while (str_static[i] != '\0' && str_static[i] != '\n')
    {
        i++;
    }
    if (str_static[i] == '\0')
        return (-1);
    return(i);
}

char *next_line_maker(char *str_static, int pos)
{
    int i;
    char *new_str;
    int line_len;

    i = 0;
    line_len = buffer_len(str_static);
    new_str = (char *)malloc((pos + 2) * sizeof(char));
    if(!new_str)
        return(0);
    ft_memcpy(new_str, str_static, line_len);
    new_str[line_len] = '\n';
    new_str[line_len + 1] = '\0';
    return(new_str);
}

char *line_cutter(char *str_static)
{
    char *new_str;
    int pos;

    if (ft_strlen(str_static) <= 0)
        return (0);
    pos = buffer_len(str_static);
    /* next code for when we need to know when the pos variable has the the -1 value 
    that indicate the end of the str_static, or if is has a value !-1 that indicate 
    the number of char till the /n */
    if (pos == -1 || pos == (int)ft_strlen(str_static) - 1)
    {
        new_str = ft_strdup(str_static);
        return(new_str);
    }
    new_str = next_line_maker(str_static, pos);
    //end of comment
    return(new_str);
}

char *buffer_old_line_rm(char *str_static)
{
    unsigned int remaining_len;
    int pos;

    if(!str_static)
        return (0);
    remaining_len = ft_strlen(str_static);
    pos = buffer_len(str_static);
    if (pos == -1 || ((remaining_len - pos) == 1))
    {
        free(str_static);
        return(0);
    }
    str_static = ft_substr(str_static, (pos + 1), (remaining_len - pos - 1));
    return (str_static);
}
char *get_next_line(int fd)
{
    char *str_tmp;
    static char *str_static;
    int read_return_index;
    char *new_str;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(0);
    str_tmp = malloc(BUFFER_SIZE + 1);
    if (!(str_tmp))
        return(0);
    while (buffer_len(str_static) == -1)
    {
        read_return_index = read(fd, str_tmp, BUFFER_SIZE);
        if (read_return_index <= 0)
            break;
        str_tmp[read_return_index] = '\0';
        // next code is for add strings when the buffer_len returns i, since str_tmp has the first line 
        // we should use  strjoin to add the str from str_tmp to teh static variable AKA : str_static
        str_static = ft_strjoin(str_static, str_tmp);
        // end of comment
    }
    free(str_tmp);
    /* next code for when the buffer reads the whole shit and should return null, 
        the buffer_len returns -1 when it hits the end of the string */
    if (read_return_index == -1)
        return (0);
    //end of comment
    /*
        here is the fun part,  when we need to allocate the the string fron str_static to a new 
        string *char,  but we need to add a null terminator /0 at new_str + i and a /n at new_str + i + 1
    */
    new_str = line_cutter(str_static);
    //end of comment
     /* next code is needed when we have already extract owr line , and if any next line remained 
    the extracted line need to be removed from the str_static.
    in other words the str_static need to be redefined */
    str_static = buffer_old_line_rm(str_static);
    // end of comment
    return(new_str);
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
    if(fd < 0)
        return(-1);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s",line);
    }
    return (0);
}
*/