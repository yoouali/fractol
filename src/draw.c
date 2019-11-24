/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:14:58 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:03:37 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	*draw1(void *param)
{
	t_ge	*ge;
	t_dr	dr;

	ge = (t_ge *)param;
	dr.y = -1;
	while (++dr.y < IMG_HEI / 2)
	{
		dr.x = -1;
		while (++dr.x < IMG_WID / 2)
		{
			find_fractal(ge, dr);
			dr.x += ge->sonic;
		}
		dr.y += ge->sonic;
	}
	return (NULL);
}

void	*draw2(void *param)
{
	t_ge	*ge;
	t_dr	dr;

	ge = (t_ge *)param;
	dr.y = -1;
	while (++dr.y < IMG_HEI / 2)
	{
		dr.x = IMG_WID / 2 - 1;
		while (++dr.x < IMG_WID)
		{
			find_fractal(ge, dr);
			dr.x += ge->sonic;
		}
		dr.y += ge->sonic;
	}
	return (NULL);
}

void	*draw3(void *param)
{
	t_ge	*ge;
	t_dr	dr;

	ge = (t_ge *)param;
	dr.y = IMG_HEI / 2 - 1;
	while (++dr.y < IMG_HEI)
	{
		dr.x = -1;
		while (++dr.x < IMG_WID / 2)
		{
			find_fractal(ge, dr);
			dr.x += ge->sonic;
		}
		dr.y += ge->sonic;
	}
	return (NULL);
}

void	*draw4(void *param)
{
	t_ge	*ge;
	t_dr	dr;

	ge = (t_ge *)param;
	dr.y = IMG_HEI / 2 - 1;
	while (++dr.y < IMG_HEI)
	{
		dr.x = IMG_WID / 2 - 1;
		while (++dr.x < IMG_WID)
		{
			find_fractal(ge, dr);
			dr.x += ge->sonic;
		}
		dr.y += ge->sonic;
	}
	return (NULL);
}

void	draw_fractal(t_ge *ge)
{
	if ((pthread_create(&ge->thread[0], NULL, draw1, (void *)ge)) ||\
		(pthread_create(&ge->thread[1], NULL, draw2, (void *)ge)) ||\
		(pthread_create(&ge->thread[2], NULL, draw3, (void *)ge)) ||\
		(pthread_create(&ge->thread[3], NULL, draw4, (void *)ge)))
		environment_set_error(ge);
	pthread_join(ge->thread[0], NULL);
	pthread_join(ge->thread[1], NULL);
	pthread_join(ge->thread[2], NULL);
	pthread_join(ge->thread[3], NULL);
}
