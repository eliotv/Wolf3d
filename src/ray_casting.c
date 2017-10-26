/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:31:24 by evanheum          #+#    #+#             */
/*   Updated: 2017/10/19 11:29:27 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	clear_pixels(t_env *env)
{
	int		i;

	i = 0;
	while (i < W_W * W_H)
	{
		env->pixels[i] = 0;
		i++;
	}
	mlx_clear_window(env->mlx, env->win);
	env->drawn = 0;
}

void	horizontal_ray(t_env *env, double angle)
{
	int		xa;

	if (angle > M_PI)
		env->h.y = (env->player.pos_y / SCALE) * (SCALE) + SCALE;
	else
		env->h.y = (env->player.pos_y / SCALE) * (SCALE) - 1;
	xa = SCALE / tan(angle);
	env->h.x = env->player.pos_x +
		((env->player.pos_y - env->h.y) / tan(angle));
	while (!check_grid(env->h.x, env->h.y, env))
	{
		if (angle > M_PI)
		{
			env->h.y += SCALE;
			env->h.x += -xa;
		}
		else
		{
			env->h.x += xa;
			env->h.y += -SCALE;
		}
	}
	env->h.d = fabs((env->player.pos_y - env->h.y) / sin(angle));
	if (env->h.d < 0)
		env->h.d = INT_MAX;
}

void	vertical_ray(t_env *env, double angle)
{
	int		ya;

	if ((angle > M_PI / 2) && (angle < 3 * M_PI / 2))
		env->v.x = (env->player.pos_x / SCALE) * (SCALE) - 1;
	else
		env->v.x = (env->player.pos_x / SCALE) * (SCALE) + SCALE;
	ya = SCALE * tan(angle);
	env->v.y = env->player.pos_y +
				((env->player.pos_x - env->v.x) * tan(angle));
	while (!check_grid(env->v.x, env->v.y, env))
	{
		if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		{
			env->v.y += ya;
			env->v.x += -SCALE;
		}
		else
		{
			env->v.x += SCALE;
			env->v.y += -ya;
		}
	}
	env->v.d = fabs((env->player.pos_x - env->v.x) / cos(angle));
	if (env->v.d < 0)
		env->v.d = INT_MAX;
}

void	ray_casting(t_env *env)
{
	double	angle;
	int		col;

	if (env->drawn == 1)
		clear_pixels(env);
	angle = env->player.angle + (FOV / 2);
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	col = 0;
	while (col < W_W)
	{
		while (angle < 0)
			angle += 2 * M_PI;
		horizontal_ray(env, angle);
		vertical_ray(env, angle);
		env->block = SCALE * 1000 /
					((env->h.d < env->v.d) ? env->h.d : env->v.d);
		wall_color(env, angle);
		draw_block(env, col);
		angle -= (FOV / W_W);
		col++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->drawn = 1;
}

void	wall_color(t_env *env, double angle)
{
	if (env->h.d < env->v.d)
	{
		if (angle > M_PI)
			env->wallcolor = 0x7c7b56;
		else
			env->wallcolor = 0x565c7c;
	}
	else
	{
		if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
			env->wallcolor = 0x77567c;
		else
			env->wallcolor = 0x7c5756;
	}
}
