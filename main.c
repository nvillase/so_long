/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:44:25 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/09 10:43:33 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	brain(t_l *l)
{
	full_img(l);
	calcul(l);
	n_c(l);
	print_angle(l);
	print_ligne(l);
	print_vertical(l);
	coll_ballon(l);
	perso(l);
}

void	secu_brain(t_l *l)
{
	if (!secu_1(l))
		exit(0);
	if (!secu_v(l))
		exit(0);
	if (!secu_rec(l))
		exit(0);
	if (secu_all(l))
		exit(0);
}

int	main(int ac, char **av)
{
	t_l	l;

	if (ac != 2)
		return (1);
	l.mp = mlx_init();
	create_map(&l, av[1]);
	secu_brain(&l);
	l.wp = mlx_new_window(l.mp, l.th * 32, l.tv * 32, "Rugby");
	brain(&l);
	mlx_key_hook(l.wp, keys, &l);
	mlx_hook (l.wp, 2, 1L << 0, &fermer_esc, NULL);
	mlx_hook(l.wp, 17, 1L << 0, &fermer_croix, NULL);
	mlx_loop(l.mp);
	return (0);
}
