/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:35:03 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:01:27 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void			set_fractal(t_ge *ge)
{
	if (ge->fracn == 1 && ge->mand.ex == 0)
		set_mandelbrot(&ge->mand, ge->col1);
	if (ge->fracn == 2 && ge->juli.ex == 0)
		set_julia(&ge->juli, ge->col1);
	if (ge->fracn == 3 && ge->tric.ex == 0)
		set_tricorn(&ge->tric, ge->col1);
	if (ge->fracn == 4 && ge->burn.ex == 0)
		set_burning_ship(&ge->burn, ge->col1);
	if (ge->fracn == 5 && ge->burn_j.ex == 0)
		set_burning_julia(&ge->burn_j, ge->col1);
	if (ge->fracn == 6 && ge->feig.ex == 0)
		set_feigenbaum_point(&ge->feig, ge->col1);
	if (ge->fracn == 7 && ge->real.ex == 0)
		set_reality_point(&ge->real, ge->col1);
	if (ge->fracn == 8 && ge->imag.ex == 0)
		set_imagine_point(&ge->imag, ge->col1);
	if (ge->fracn == 9 && ge->tear.ex == 0)
		set_teardrop(&ge->tear, ge->col1);
}

void			find_fractal(t_ge *ge, t_dr dr)
{
	if (ge->fracn == 1)
		mandelbrot_draw(ge, dr);
	if (ge->fracn == 2)
		julia_draw(ge, dr);
	if (ge->fracn == 3)
		tricorn_draw(ge, dr);
	if (ge->fracn == 4)
		burning_ship_draw(ge, dr);
	if (ge->fracn == 5)
		burning_julia_draw(ge, dr);
	if (ge->fracn == 6)
		feigenbaum_point_draw(ge, dr);
	if (ge->fracn == 7)
		reality_point_draw(ge, dr);
	if (ge->fracn == 8)
		imagine_point_draw(ge, dr);
	if (ge->fracn == 9)
		teardrop_draw(ge, dr);
}

t_fr			*detect_fractal(t_ge *ge)
{
	if (ge->fracn == 1)
		return (&ge->mand);
	if (ge->fracn == 2)
		return (&ge->juli);
	if (ge->fracn == 3)
		return (&ge->tric);
	if (ge->fracn == 4)
		return (&ge->burn);
	if (ge->fracn == 5)
		return (&ge->burn_j);
	if (ge->fracn == 6)
		return (&ge->feig);
	if (ge->fracn == 7)
		return (&ge->real);
	if (ge->fracn == 8)
		return (&ge->imag);
	if (ge->fracn == 9)
		return (&ge->tear);
	return (NULL);
}

long double		map(long double v, long double ox,\
		long double nn, long double nx)
{
	return ((v / ox) * (nx - nn) + nn);
}

char			*ft_itoa(int va, t_ge *ge)
{
	char	*buf;
	int		len;
	int		res;

	res = va;
	len = 0;
	while (res > 0)
	{
		res = res / 10;
		len++;
	}
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		environment_set_error(ge);
	res = len;
	while (va > 0)
	{
		len--;
		buf[len] = va % 10 + '0';
		va = va / 10;
	}
	buf[res] = '\0';
	return (buf);
}
