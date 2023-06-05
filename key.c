/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:34:31 by nvillase          #+#    #+#             */
/*   Updated: 2023/05/31 22:56:52 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fermer_esc(int keyboard)
{
	if (keyboard == 65307)
		exit(0);
	return (0);
}

int fermer_croix(void)
{
	exit(0);
	return (0);
}
