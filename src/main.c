/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:47:10 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/03 15:03:10 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map       *init_map(void)
{
    t_map = *map;

    map = (t_env)malloc(sizeof(t_env));
    map->len;
    map->width;
    map->grid;
    return (map);
}

t_env       *init_env(void)
{
    t_env *env;

    env =(t_env*)malloc(sizeof(t_env));
    env->map = init_map();
    return (env);
}

int         main(int ac, char **av)
{
    char *str;
    t_env *env;

    if (ac != 2)
    {
        ft_printf(""\033[31mINVALID NUMBER OF ARGUMENTS!\033[0m"");
        return (0);
    }
    env = init_env();
    fd = open(av[1], O_RDONLY);
    store_map(env, fd);

}