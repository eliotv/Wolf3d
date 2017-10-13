/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:29:11 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/12 17:25:40 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     key_press(int key, t_env *env)
{

    int move_y;
    int move_x;

    if (key == KEY_ESC)
        exit(0);
    if (key == KEY_W || key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_LAR || key == KEY_RAR)
    {
        move_x = cos(env->player.angle) * MOVESPEED;
        move_y = sin(env->player.angle) * MOVESPEED;
        if (key == KEY_W)
        {
            // if (env->player.angle >= 0 && env->player.angle <= M_PI / 2)
            // {
                // env->player.pos_x += cos(env->player.angle) * MOVESPEED;
                // env->player.pos_y -= sin(env->player.angle) * MOVESPEED;
            // // }
            // else if (env->player.angle <= M_PI)
            // {
            //     env->player.pos_x += cos(env->player.angle) * MOVESPEED;
            //     env->player.pos_y -= sin(env->player.angle) * MOVESPEED;
            // }
            // else if (env->player.angle <= 3 * M_PI / 2)
            // {
            //     env->player.pos_x += cos(env->player.angle) * MOVESPEED;
            //     env->player.pos_y += sin(env->player.angle) * MOVESPEED;
            // }
            // else
            // {
            //   env->player.pos_x -= cos(env->player.angle) * MOVESPEED;
            //   env->player.pos_y += sin(env->player.angle) * MOVESPEED;
            // }
        }
        if (key == KEY_A)
            env->key.a = 1;
        if (key == KEY_D)
            env->key.d = 1;
        if (key == KEY_S)
            env->key.s = 1;
        if (key == KEY_LAR)
            turn_x_y(key, env);
        if (key == KEY_RAR)
            turn_x_y(key, env);
        ray_casting(env);
    } 
    return (0);
}

void turn_x_y(int key, t_env *env)
{
    if (key == KEY_LAR)
        env->player.angle += TURNSPEED;
    if (key == KEY_RAR)
        env->player.angle -= TURNSPEED;
    while (env->player.angle < 0)
        env->player.angle += 2 * M_PI;
    while (env->player.angle > 2 * M_PI)
        env->player.angle -= 2 * M_PI;
}

int     exit_key(int key, t_env *env)
{
    (void)key;
    (void)env;
    exit(0);
}