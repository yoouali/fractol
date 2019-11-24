/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 02:04:53 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:05:00 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	fractal_exit(t_ge *ge)
{
	mlx_destroy_image(ge->ptr, ge->png);
	mlx_destroy_image(ge->ptr, ge->img);
	mlx_destroy_window(ge->ptr, ge->win);
	ft_putendl("fractal end⛩ ");
	exit(0);
}

void	change_pow(int key, t_ge *ge)
{
	t_fr	*fr;

	fr = detect_fractal(ge);
	if (key == 84)
		fr->pow = 0;
	if (key == 85)
		fr->pow = 1;
	if (key == 86)
		fr->pow = 2;
	if (key == 87)
		fr->pow = 3;
	if (key == 88)
		fr->pow = 4;
}

void	reset_fractal(t_ge *ge)
{
	t_fr	*fr;

	fr = detect_fractal(ge);
	fr->ex = 0;
	set_fractal(ge);
}

int		key_event(int key, t_ge *ge)
{
	if (key == 53 || (key >= 84 && key <= 88) ||\
			key == 3 || key == 1 || key == 15)
	{
		reset_graphic_environment(ge);
		if (key == 53)
			fractal_exit(ge);
		if (key >= 84 && key <= 88)
			change_pow(key, ge);
		if (key == 1)
			ge->sonic = ge->sonic == 0 ? 1 : 0;
		if (key == 3)
			ge->frez = ge->frez == 0 ? 1 : 0;
		if (key == 15)
			reset_fractal(ge);
		run_graphic_environment(ge);
	}
	return (0);
}
