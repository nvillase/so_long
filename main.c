/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:44:25 by nvillase          #+#    #+#             */
/*   Updated: 2023/04/27 14:44:58 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_l	l;

	l.mp = mlx_init();
	create_map(&l);
	l.wp = mlx_new_window(l.mp, l.th * 32, l.tv * 32, "Rugby");
	full_img(&l);
	calcul(&l);
	print_angle(&l);
	print_ligne(&l);
	print_vertical(&l);
	mlx_hook(l.wp, 2, 1L<<0, &fermer_esc, NULL);
	mlx_loop(l.mp);
	exit(0);
}
