/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:57:05 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/11 21:03:48 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    init_key(t_env *env)
{
    env->key.w = 0;
    env->key.a = 0;
    env->key.s = 0;
    env->key.d = 0;
    env->key.lar = 0;
    env->key.rar = 0;
}

void    init_V_H(t_env *env)
{
    env->V.x = 0;
    env->V.y = 0;
    env->H.y = 0;
    env->H.x = 0;
    env->H.d = 0;
    env->V.d = 0;
}

void    init_player(t_env *env)
{
    env->player.pos_x = 0;
    env->player.pos_y = 0;
    env->player.angle = 3 * M_PI / 2;
}

void    init_map(t_env *env)
{
    env->map.len = 0;
    env->map.width = 0;
    env->map.grid = 0;
}

t_env       *init_env(void)
{
    t_env *env;

    env = (t_env*)malloc(sizeof(t_env));

    init_map(env);
    init_player(env);
    init_V_H(env);
    init_key(env);
    env->mlx = NULL;
    env->win = NULL;
    env->ww = W_W;
    env->wh = W_H;
    env->bpp = 4;
    env->sl = 0;
    env->img = 0;
    env->pixels = 0;
    env->endian = 0;
    env->name = "Wolf3d";
    env->block = 0;
    env->drawn = 1;
    return (env);
}