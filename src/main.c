/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:17:09 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 01:55:10 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

int		moving_fractal(int x, int y, t_ge *ge)
{
	t_fr	*fr;
	int		xm;
	int		ym;

	if (x < IMG_X || x > IMG_X + IMG_WID || y < IMG_Y || y > IMG_Y + IMG_HEI\
			|| ge->frez == 0)
		return (0);
	xm = x - IMG_X;
	ym = y - IMG_Y;
	fr = detect_fractal(ge);
	fr->mr = map(xm, IMG_WID, fr->rnr, fr->rxr);
	fr->mi = map(ym, IMG_HEI, fr->inr, fr->ixr);
	reset_graphic_environment(ge);
	run_graphic_environment(ge);
	return (0);
}

int		main(int ac, char **av)
{
	t_ge	ge;

	if (ac != 2)
		fractal_usage();
	if (!(ge.fracn = (fractal_checker(av[1]))))
		fractal_usage();
	set_zero(&ge);
	set_up_environment(&ge);
	set_fractal(&ge);
	set_color(&ge);
	run_graphic_environment(&ge);
	mlx_hook(ge.win, 2, 0, key_hold_event, &ge);
	mlx_key_hook(ge.win, key_event, &ge);
	mlx_hook(ge.win, 4, 0, mouse_event, &ge);
	mlx_hook(ge.win, 6, 0, moving_fractal, &ge);
	mlx_loop(ge.ptr);
	return (0);
}
