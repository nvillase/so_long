/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:03:23 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/05 15:55:17 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void bas_perso(t_l *l)
{

	if (l->map[l->z + 1][l->y] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->z++;
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x || l->y == l->m || l->y == l->x - 1)
			mlx_put_image_to_window(l->mp, l->wp, l->LV, (l->y) * 32, (l->z - 1) * 32);
		if (l->map[l->z - 1][l->y] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po, (l->y) * 32, (l->z - 1) * 32);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->y][l->z] = '0';
		}
	}
	else
		return ;
}
void gauche_perso(t_l *l)
{
	if (l->map[l->z][l->y - 1] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->y--;
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x - 1 || l->y == l->m - 1 || l->y == l->x - 2)
			mlx_put_image_to_window(l->mp, l->wp, l->LV, (l->y + 1) * 32, (l->z) * 32);
		if (l->map[l->z][l->y + 1] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po, (l->y + 1) * 32, (l->z) * 32);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->y][l->z] = '0';
		}
	}
	else
		return ;
}
void droite_perso(t_l *l)
{
	if (l->map[l->z][l->y + 1] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->y++;
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x + 1 || l->y == l->m + 1 || l->y == l->x)
			mlx_put_image_to_window(l->mp, l->wp, l->LV, (l->y - 1) * 32, (l->z) * 32);
		if (l->map[l->z][l->y - 1] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po, (l->y - 1) * 32, (l->z) * 32);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->y][l->z] = '0';
		}
	}
	else
		return ;
}
void	haut_perso(t_l *l)
{
	if (l->map[l->z  - 1][l->y] != '1')
	{
		mlx_put_image_to_window(l->mp, l->wp, l->g, (l->y) * 32, (l->z) * 32);
		l->z--;
		mlx_put_image_to_window(l->mp, l->wp, l->jd, (l->y) * 32, (l->z) * 32);
		if (l->y == l->th - l->x || l->y == l->m || l->y == l->x - 1)
			mlx_put_image_to_window(l->mp, l->wp, l->LV, (l->y) * 32, (l->z + 1) * 32);
		if (l->map[l->z + 1][l->y] == 'E')
			mlx_put_image_to_window(l->mp, l->wp, l->po, (l->y) * 32, (l->z + 1) * 32);
		if (l->map[l->z][l->y] == 'C')
		{
			l->map[l->y][l->z] = '0';
		}
	}
	else
		return ;
}
