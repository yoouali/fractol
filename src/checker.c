/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:18:41 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/23 21:47:23 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void		fractal_usage(void)
{
	ft_putendl("\033[1;36m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ft_putendl("┃\033[0m     usage: ./fractol fractal_name     \033[1;36m┃");
	ft_putendl("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	ft_putendl("┃\033[0m             mandelbrot                \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m               julia                   \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m              tricorn                  \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m            burning_ship               \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m            burning_julia              \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m           feigenbaum_point            \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m            reality_point              \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m            imagine_point              \033[1;36m┃");
	ft_putendl("┃            ━━━━━━━━━━━                ┃");
	ft_putendl("┃\033[0m             teardrop                  \033[1;36m┃");
	ft_putendl("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m");
	exit(1);
}

int			fractal_checker(char *name)
{
	if (is_equal("mandelbrot", name))
		return (1);
	if (is_equal("julia", name))
		return (2);
	if (is_equal("tricorn", name))
		return (3);
	if (is_equal("burning_ship", name))
		return (4);
	if (is_equal("burning_julia", name))
		return (5);
	if (is_equal("feigenbaum_point", name))
		return (6);
	if (is_equal("reality_point", name))
		return (7);
	if (is_equal("imagine_point", name))
		return (8);
	if (is_equal("teardrop", name))
		return (9);
	return (0);
}

int			is_equal(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	return (1);
}

void		ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
