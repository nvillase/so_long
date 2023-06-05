/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:44:25 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/05 17:32:40 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void brain(t_l *l)
{
	full_img(l);
	calcul(l);
	print_angle(l);
	print_ligne(l);
	print_vertical(l);
	coll_ballon(l);
	perso(l);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	t_l	l;

	l.mp = mlx_init();
	create_map(&l, av[1]);
	if (!secu_1(&l))
		return (0);
	if (!secu_v(&l))
		return (0);
	if (!secu_rec(&l))
		return (0);
	if (secu_all(&l))
		return (0);
	l.wp = mlx_new_window(l.mp, l.th * 32, l.tv * 32, "Rugby");
	brain(&l);
	mlx_key_hook(l.wp, keys, &l);
	mlx_hook(l.wp, 2, 1L<<0, &fermer_esc, NULL);
	mlx_hook(l.wp, 17, 1L<<0, &fermer_croix, NULL);
	mlx_loop(l.mp);
	return (0);
}
