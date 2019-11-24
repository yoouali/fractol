/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 08:22:10 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:10:14 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	fractal_zoom(int bot, int x, int y, t_ge *ge)
{
	t_fr		*fr;
	long double	xm;
	long double	ym;
	long double	k;

	if (x < IMG_X || x > IMG_X + IMG_WID || y < IMG_Y || y > IMG_Y + IMG_HEI)
		return ;
	reset_graphic_environment(ge);
	fr = detect_fractal(ge);
	xm = map(x - IMG_X + fr->xof, IMG_WID, fr->rnr, fr->rxr);
	ym = map(y - IMG_Y + fr->yof, IMG_HEI, fr->inr, fr->ixr);
	k = bot == 4 ? 0.9 : 1.9;
	fr->rnr = k * (fr->rnr - xm) + xm;
	fr->rxr = k * (fr->rxr - xm) + xm;
	fr->inr = k * (fr->inr - ym) + ym;
	fr->ixr = k * (fr->ixr - ym) + ym;
	run_graphic_environment(ge);
}

void	change_fractal(t_ge *ge, int x, int y)
{
	if (x >= 25 && x <= 262 && y >= 414 && y <= 479)
		ge->fracn = 1;
	else if (x >= 24 && x <= 262 && y >= 488 && y <= 554)
		ge->fracn = 2;
	else if (x >= 24 && x <= 262 && y >= 562 && y <= 627)
		ge->fracn = 3;
	else if (x >= 24 && x <= 262 && y >= 637 && y <= 702)
		ge->fracn = 4;
	else if (x >= 24 && x <= 262 && y >= 711 && y <= 776)
		ge->fracn = 5;
	else if (x >= 24 && x <= 262 && y >= 785 && y <= 850)
		ge->fracn = 6;
	else if (x >= 24 && x <= 262 && y >= 860 && y <= 925)
		ge->fracn = 7;
	else if (x >= 24 && x <= 262 && y >= 934 && y <= 999)
		ge->fracn = 8;
	else if (x >= 24 && x <= 262 && y >= 1009 && y <= 1074)
		ge->fracn = 9;
	set_fractal(ge);
}

void	change_color(t_ge *ge, int x, int y)
{
	t_fr	*fr;

	fr = detect_fractal(ge);
	if (x >= 33 && x <= 92 && y >= 88 && y <= 134)
		fr->colt = ge->col1;
	else if (x >= 113 && x <= 172 && y >= 88 && y <= 134)
		fr->colt = ge->col2;
	else if (x >= 193 && x <= 252 && y >= 88 && y <= 134)
		fr->colt = ge->col3;
	else if (x >= 33 && x <= 92 && y >= 168 && y <= 214)
		fr->colt = ge->col4;
	else if (x >= 113 && x <= 172 && y >= 168 && y <= 214)
		fr->colt = ge->col5;
	else if (x >= 193 && x <= 252 && y >= 168 && y <= 214)
		fr->colt = ge->col6;
	else if (x >= 33 && x <= 92 && y >= 244 && y <= 290)
		fr->colt = ge->col7;
	else if (x >= 113 && x <= 172 && y >= 244 && y <= 290)
		fr->colt = ge->col8;
	else if (x >= 193 && x <= 252 && y >= 244 && y <= 290)
		fr->colt = ge->col9;
	else if (x >= 113 && x <= 172 && y >= 312 && y <= 358)
		fr->colt = ge->col10;
	set_fractal(ge);
}

int		mouse_event(int bot, int x, int y, t_ge *ge)
{
	if (bot == 4 || bot == 5 || bot == 1)
	{
		reset_graphic_environment(ge);
		if (bot == 4 || bot == 5)
			fractal_zoom(bot, x, y, ge);
		if (bot == 1)
			change_fractal(ge, x, y);
		if (bot == 1)
			change_color(ge, x, y);
		run_graphic_environment(ge);
	}
	return (0);
}
