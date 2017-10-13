/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@s tudent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:23:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/06 16:40:27 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void clear_pixels(t_env *env)
{
    int i;

    i = 0;
    while (i < W_W * W_H)
    {
        env->pixels[i] = 0;
        i++;
    }
    mlx_clear_window(env->mlx, env->win);
    env->drawn = 0;
}


void    horizontal_ray(t_env *env, double angle)
{
    int Xa;
    
    Xa = SCALE / tan(angle);
    if (angle > M_PI)
        env->H.y = (env->player.pos_y / SCALE) * (SCALE) + SCALE;
    else
        env->H.y = (env->player.pos_y / SCALE) * (SCALE) - 1;
    env->H.x = env->player.pos_x + ((env->player.pos_y - env->H.y) / tan(angle));
    while (!check_grid(env->H.x, env->H.y, env))
    {
        if (angle > M_PI)
        {
            env->H.y += SCALE;
            env->H.x += -Xa;
        }
        else
        {
            env->H.x += Xa;
            env->H.x += -SCALE;
        }
    }
    env->H.d = fabs((env->player.pos_y - env->H.y) / sin(angle));
    if (env->H.d < 0)
        env->H.d = INT_MAX;
    // if (angle >= (31 * M_PI / 64) && angle <= (33 * M_PI / angle)) 
    //     printf("%d\n", env->H.d);
}

void    vertical_ray(t_env *env, double angle)
{
    int Ya;

    Ya = SCALE * tan(angle);
    if ((angle > M_PI / 2) && (angle < 3 * M_PI / 2))
        env->V.x = (env->player.pos_x / SCALE) * (SCALE) - 1;
    else
        env->V.x = (env->player.pos_x / SCALE) * (SCALE) + SCALE;
    env->V.y = env->player.pos_y + ((env->player.pos_x - env->V.x) * tan(angle));
    while(!check_grid(env->V.x, env->V.y, env))
    {
        if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
        {
            env->V.y += Ya;
            env->V.x += -SCALE;
        }
        else
        {
            env->V.x += SCALE;
            env->V.y += -Ya;
        }
    }
    env->V.d = fabs((env->player.pos_x - env->V.x) / cos(angle));
    // printf("%d\n", env->V.d);
    if (env->V.d < 0)
        env->V.d = INT_MAX;
    // if (angle >= (M_PI / 5) && angle <= ( M_PI / 7)) 
    //     printf("%d\n", env->V.d);
}

void    ray_casting(t_env *env)
{
    double angle;
    int col;

    if (env->drawn == 1)
    {
        clear_pixels(env);
        env->drawn = 0;
    }
    angle = env->player.angle + (FOV / 2);
    col = 0;
    while (col < W_W)
    {
        horizontal_ray(env, angle);
        vertical_ray(env, angle);
        // if (angle >= (3 * M_PI / 24) && angle <= (5 * M_PI / 24)) 
        // printf("%lf\t%d\t%d\n", angle, env->H.d, env->V.d);
        env->block = SCALE * 880 / ((env->H.d <= env->V.d) ? env->H.d : env->V.d);
        draw_block(env, col);
        angle -= (FOV / W_W);
        col++;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    env->drawn = 1;
}