/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:44:36 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/03 14:47:25 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/libftmega.h"
# include "../libmlx/mlx.h"
# include <sys/fcntl.h>
# include <math.h>

typedef struct  s_map
{
    int         len;
    int         width;
    int         **grid;
}               t_map


typedef struct  s_env
{
    t_map       *map;
}               t_env;


/*
** -------------------- main.c -----------------------
*/
void		convert_points(t_env *env, char *line, int y);
void    store_map(t_env *env, int fd);
int main(int ac, char **av);
t_env       *init_env(void)