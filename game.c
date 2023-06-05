/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:23:50 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/05 15:42:15 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void coll_ballon(t_l *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < l->tv)
	{
		while (j < l->th)
		{
			if (l->map[i][j] == 'C')
				mlx_put_image_to_window(l->mp, l->wp, l->gB, j * 32, i * 32);
			if (l->map[i][j] == '1' && i != 0 && j != l->th - 1 
				&& i != l->tv - 1 && j != 0)
				mlx_put_image_to_window(l->mp, l->wp, l->eu, j * 32, i * 32);
			if (l->map[i][j] == 'E')
				mlx_put_image_to_window(l->mp, l->wp, l->po, j * 32, i * 32);
			j++;
		}
		i++;
		j = 0;
	}
}
void perso(t_l *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < l->tv)
	{
		j = 0;
		while (j < l->th)
		{
			if (l->map[i][j] == 'P')
			{
				mlx_put_image_to_window(l->mp, l->wp, l->jd, j * 32, i * 32);
				l->z = i;
				l->y = j;
			}
			j++;
		}
		i++;
	}
}
int keys(int keycode, t_l *l)
{
	if (keycode == 119)
		haut_perso(l);
	else if (keycode == 115)
		bas_perso(l);
	else if (keycode == 97)
		gauche_perso(l);
	else if (keycode == 100)
		droite_perso(l);
	return (0);
}

