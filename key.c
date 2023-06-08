/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:34:31 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/08 11:29:52 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fermer_esc(int keyboard, t_l *l)
{
	if (keyboard == 65307)
	{
		free(l);
		exit(0);
	}
	return (0);
}

int	fermer_croix(void)
{
	exit(0);
	return (0);
}
