/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 01:08:23 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:04:16 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

int		get_gradian(int ind, int max, int col1, int col2)
{
	double	per;
	int		r;
	int		g;
	int		b;

	per = (double)ind / max;
	r = (col1 >> 16) & 0xff;
	g = (col1 >> 8) & 0xff;
	b = col1 & 0xff;
	r = r + (int)(((col2 >> 16) & 0xff) - r) * per;
	g = g + (int)(((col2 >> 8) & 0xff) - g) * per;
	b = b + (int)((col2 & 0xff) - b) * per;
	return ((r << 16) | (g << 8) | b);
}

void	create_gradian(int *tab, int col1, int col2, int col3)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		tab[i] = get_gradian(i, 20, col1, col2);
		i++;
	}
	while (i < 50)
	{
		tab[i] = get_gradian(i - 20, 30, col2, col3);
		i++;
	}
}

void	set_color(t_ge *ge)
{
	create_gradian(ge->col1, 0, 0xf59300, 0);
	create_gradian(ge->col2, 0, 0xffffff, 0);
	create_gradian(ge->col3, 0x690069, 0xffff00, 0x690069);
	create_gradian(ge->col4, 0xdd1801, 0xfee400, 0xdd1801);
	create_gradian(ge->col5, 0x17202a, 0x00fcfc, 0x17202a);
	create_gradian(ge->col6, 0x1D8348, 0xE5E7E9, 0x1D8348);
	create_gradian(ge->col7, 0x004445, 0xffd800, 0x2c7873);
	create_gradian(ge->col8, 0xfb5b5a, 0xf5f0e3, 0xff502f);
	create_gradian(ge->col9, 0xff502f, 0x32dbc6, 0xebefd0);
	create_gradian(ge->col10, 0x0357AF, 0xAED6F1, 0xffffff);
}
