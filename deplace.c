/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:03:23 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/08 11:56:21 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bas_perso(t_l *l)
{
	if (l->map[l->z + 1][l->y] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->z++;
		l->c_d++;
		ft_printf("Ton joueur a fait %d deplacements\n", l->c_d);
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x || l->y == l->m || l->y == l->x - 1)
			mlx_put_image_to_window(l->mp, l->wp, l->LV,
				(l->y) * 32, (l->z - 1) * 32);
		if (l->map[l->z - 1][l->y] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po,
				(l->y) * 32, (l->z - 1) * 32);
		if (l->cn == 0 && l->map[l->z][l->y] == 'E')
			end(l);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->z][l->y] = '0';
			l->cn--;
		}
	}
}

void	gauche_perso(t_l *l)
{
	if (l->map[l->z][l->y - 1] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->y--;
		l->c_d++;
		ft_printf("Ton joueur a fait %d deplacements\n", l->c_d);
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x - 1 || l->y == l->m - 1 || l->y == l->x - 2)
			mlx_put_image_to_window(l->mp, l->wp, l->LV,
				(l->y + 1) * 32, (l->z) * 32);
		if (l->map[l->z][l->y + 1] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po,
				(l->y + 1) * 32, (l->z) * 32);
		if (l->cn == 0 && l->map[l->z][l->y] == 'E')
			end(l);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->z][l->y] = '0';
			l->cn--;
		}
	}
	else
		return ;
}

void	droite_perso(t_l *l)
{
	if (l->map[l->z][l->y + 1] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->y++;
		l->c_d++;
		ft_printf("Ton joueur a fait %d deplacements\n", l->c_d);
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x + 1 || l->y == l->m + 1 || l->y == l->x)
			mlx_put_image_to_window(l->mp, l->wp, l->LV,
				(l->y - 1) * 32, (l->z) * 32);
		if (l->map[l->z][l->y - 1] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po,
				(l->y - 1) * 32, (l->z) * 32);
		if (l->cn == 0 && l->map[l->z][l->y] == 'E')
			end(l);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->z][l->y] = '0';
			l->cn--;
		}
	}
}

void	haut_perso(t_l *l)
{
	if (l->map[l->z - 1][l->y] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->z--;
		l->c_d++;
		ft_printf("Ton joueur a fait %d deplacements\n", l->c_d);
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x || l->y == l->m || l->y == l->x - 1)
			mlx_put_image_to_window(l->mp, l->wp, l->LV,
				(l->y) * 32, (l->z + 1) * 32);
		if (l->map[l->z + 1][l->y] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po,
				(l->y) * 32, (l->z + 1) * 32);
		if (l->cn == 0 && l->map[l->z][l->y] == 'E')
			end(l);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->z][l->y] = '0';
			l->cn--;
		}
	}
}

int	end(t_l *l)
{
	// int	i;

	// i = -1;
	// while (++i < l->tv)
	// 	free(l->map);
	// mlx_clear_window(l->mp, l->wp);
	// mlx_destroy_window(l->mp, l->wp);
	// destroy_image(l);
	// mlx_destroy_display(l->mp);
	// free(l->mp);
	ft_printf("Fini bien joue a toi mon grand\ntu as fini en %d coups\n", l->c_d);
	exit (0);
	return (0);
}
