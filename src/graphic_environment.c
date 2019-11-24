/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_environment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:20:42 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 01:55:32 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	environment_set_error(t_ge *ge)
{
	int		i;

	i = 0;
	if (ge->png)
		mlx_destroy_image(ge->ptr, ge->png);
	if (ge->img)
		mlx_destroy_image(ge->ptr, ge->img);
	if (ge->win)
		mlx_destroy_window(ge->ptr, ge->win);
	ft_putendl("⏒⏒ sorry fractol stop ⏒⏒");
	exit(1);
}

void	reset_graphic_environment(t_ge *ge)
{
	int		d1;
	int		d2;
	int		d3;

	mlx_clear_window(ge->ptr, ge->win);
	mlx_destroy_image(ge->ptr, ge->img);
	ge->img = NULL;
	if (!(ge->img = mlx_new_image(ge->ptr, IMG_WID, IMG_HEI)) ||\
		!(ge->data = (int *)mlx_get_data_addr(ge->img, &d1, &d2, &d3)))
		environment_set_error(ge);
}

void	run_graphic_environment(t_ge *ge)
{
	t_fr	*fr;
	char	*buf;

	fr = detect_fractal(ge);
	draw_fractal(ge);
	mlx_put_image_to_window(ge->ptr, ge->win, ge->png, 0, 0);
	mlx_put_image_to_window(ge->ptr, ge->win, ge->img, IMG_X, IMG_Y);
	mlx_string_put(ge->ptr, ge->win, IMG_X + 5, IMG_Y + 20, 0xffffff, "ITR :");
	buf = ft_itoa(fr->itr, ge);
	mlx_string_put(ge->ptr, ge->win, IMG_X + 40, IMG_Y + 20, 0xffffff, buf);
	free(buf);
}

void	set_up_environment(t_ge *ge)
{
	int		d1;
	int		d2;
	int		d3;

	ft_putendl("⛩ fractol start");
	if (!(ge->ptr = mlx_init()) ||\
		!(ge->win = mlx_new_window(ge->ptr, WIN_WID, WIN_HEI, "fractol")) ||\
		!(ge->png = mlx_png_file_to_image(ge->ptr, "src/ui.png", &d1, &d2))\
		|| !(ge->img = mlx_new_image(ge->ptr, IMG_WID, IMG_HEI)) ||\
		!(ge->data = (int *)mlx_get_data_addr(ge->img, &d1, &d2, &d3)))
		environment_set_error(ge);
}

void	set_zero(t_ge *ge)
{
	ge->frez = 0;
	ge->ptr = NULL;
	ge->win = NULL;
	ge->png = NULL;
	ge->img = NULL;
	ge->data = NULL;
	ge->sonic = 0;
	ge->mand.ex = 0;
	ge->juli.ex = 0;
	ge->tric.ex = 0;
	ge->burn.ex = 0;
	ge->burn_j.ex = 0;
	ge->feig.ex = 0;
	ge->real.ex = 0;
	ge->imag.ex = 0;
	ge->tear.ex = 0;
}
