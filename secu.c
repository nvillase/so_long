/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:03:54 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/08 11:31:12 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	secu_1(t_l *l)
{
	int	i;

	l->c_d = 0;
	i = 0;
	while (l->map[0][i])
	{
		if (l->map[0][i] != '1')
		{
			ft_printf("Ca fonctionne pas, tete de mort, souci ligne 1\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (l->map[l->tv - 1][i])
	{
		if (l->map[l->tv - 1][i] != '1')
		{
			ft_printf("Non, tete de zboub, souci derniere ligne\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	secu_v(t_l *l)
{
	int	i;

	i = 0;
	while (l->map[i])
	{
		if (l->map[i][0] != '1')
		{
			ft_printf("Ca fonctionne pas, tete de gland, souci lv 1\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (l->map[i])
	{
		if (l->map[i][l->th - 1] != '1')
		{
			ft_printf("Ca fonctionne pas, tete de sperme, souci derniere lv\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	secu_rec(t_l *l)
{
	int	i;

	i = 0;
	while (l->map[i + 1])
	{
		if (ft_strlen(l->map[i]) != l->th)
		{
			ft_printf("la map n'est pas rectangulaire mon cochonou\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	secu_all(t_l *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (l->map[i])
	{
		while (l->map[i][j])
		{
			if (l->map[i][j] != '0' && l->map[i][j] != '1' &&
				l->map[i][j] != 'C' && l->map[i][j] != 'E' &&
					l->map[i][j] != 'P')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void destroy_image(t_l *l)
{
	mlx_destroy_image(l->mp, l->BD);
	mlx_destroy_image(l->mp, l->BG);
	mlx_destroy_image(l->mp, l->HD);
	mlx_destroy_image(l->mp, l->HG);
	mlx_destroy_image(l->mp, l->g);
	mlx_destroy_image(l->mp, l->LH);
	mlx_destroy_image(l->mp, l->LV);
	mlx_destroy_image(l->mp, l->TB);
	mlx_destroy_image(l->mp, l->TH);
	mlx_destroy_image(l->mp, l->gB);
	mlx_destroy_image(l->mp, l->jd);
	mlx_destroy_image(l->mp, l->eu);
	mlx_destroy_image(l->mp, l->po);
}
