/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hold_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:42:13 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:07:20 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	move_fractal(int key, t_ge *ge)
{
	t_fr *fr;

	fr = detect_fractal(ge);
	if (key == 123)
		fr->xof += 10;
	if (key == 124)
		fr->xof -= 10;
	if (key == 126)
		fr->yof += 10;
	if (key == 125)
		fr->yof -= 10;
}

void	change_itr(int key, t_ge *ge)
{
	t_fr	*fr;

	fr = detect_fractal(ge);
	if (key == 69)
		fr->itr += 10;
	if (key == 78)
		fr->itr -= 10;
	if (fr->itr < 0)
		fr->itr = 0;
	if (fr->itr > MAX_ITR)
		fr->itr = MAX_ITR;
}

void	change_color_key(int key, t_ge *ge)
{
	t_fr	*fr;

	fr = detect_fractal(ge);
	if (key == 43)
		fr->col = fr->col > 0 ? fr->col - 1 : 9;
	if (key == 47)
		fr->col = fr->col < 9 ? fr->col + 1 : 0;
	if (fr->col == 0)
		fr->colt = ge->col1;
	if (fr->col == 1)
		fr->colt = ge->col2;
	if (fr->col == 2)
		fr->colt = ge->col3;
	if (fr->col == 3)
		fr->colt = ge->col4;
	if (fr->col == 4)
		fr->colt = ge->col5;
	if (fr->col == 5)
		fr->colt = ge->col6;
	if (fr->col == 6)
		fr->colt = ge->col7;
	if (fr->col == 7)
		fr->colt = ge->col8;
	if (fr->col == 8 || fr->col == 9)
		fr->colt = fr->col == 8 ? ge->col9 : ge->col10;
}

int		key_hold_event(int key, t_ge *ge)
{
	if ((key >= 123 && key <= 126) || key == 78 || key == 69 ||\
			key == 43 || key == 47)
	{
		reset_graphic_environment(ge);
		if (key >= 123 && key <= 126)
			move_fractal(key, ge);
		if (key == 69 || key == 78)
			change_itr(key, ge);
		if (key == 43 || key == 47)
			change_color_key(key, ge);
		run_graphic_environment(ge);
	}
	return (0);
}
