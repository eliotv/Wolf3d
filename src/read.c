/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:48:17 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/10 14:15:58 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void       read_map(t_env *env, int fd)
{
    char *str;
    int  num[4];
    int i;

    i = 0;
    str = (char*)malloc(sizeof(char) * UINT_MAX);
    get_next_line(fd, &str);
    while (*str)
    {
        if (*str == ' ')
            str++;
        else
        {
            num[i] = ft_atoi(str);
            while (*str >= '0' && *str <= '9')
                str++;
            i++;
        }
    }
    env->map.width = num[0];
    env->map.len = num[1];
    env->player.pos_x = (num[2] * SCALE) + (SCALE / 2);
    env->player.pos_y = (num[3] * SCALE) + (SCALE / 2);
}

void    store_map(t_env *env, int fd)
{
    char **str;
    char **line;
    int chk;
    int i;
    int j;

    i = 0;
    line = (char**)malloc(sizeof(char*) * env->map.len);   
    env->map.grid = (int**)malloc(sizeof(char*) * env->map.len);
    while ((chk = get_next_line(fd, &line[i])))
    {
        if (chk == -1)
        {
            ft_printf("\033[31mREAD FAILED!\033[0m\n");
            return ;
        }
        j = 0;
        env->map.grid[i] = (int*)malloc(sizeof(int) * env->map.width);
        while (j < env->map.width)
        {
            str = ft_strsplit(line[i], ' ');
            env->map.grid[i][j] = ft_atoi(str[j]);
            j++;
        }
        i++;
    }
}

void        print_map(t_env *env)
{
    int i;
    int j;
    
    i = 0;
    while (i < env->map.len)
    {
        j = 0;
        while (j < env->map.width)
        {
            ft_printf("%d ", env->map.grid[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}