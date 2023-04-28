/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:40:33 by nvillase          #+#    #+#             */
/*   Updated: 2023/04/27 14:50:53 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_map(t_l *l)
{
	int		i;
	int		fd;
	char	*buffer;

	fd = open ("./map/map.ber", O_RDONLY);
	if (fd < 0)
		return ;
	buffer = (char *)malloc(sizeof(char) * 10000);
	if (!buffer)
		return ;
	i = read(fd, buffer, 10000);
	buffer[i] = '\0';
	l->map = ft_split(buffer, '\n');
	free(buffer);
	l->th = ft_strlen(l->map[0]);
	l->tv = 0;
	while (l->map[l->tv])
		l->tv++;
}
void full_img(t_l *l)
{
	int a;

	a = 32;
	l->BD = mlx_xpm_file_to_image(l->mp, "./m/BD.xpm", &a, &a);
	l->BG = mlx_xpm_file_to_image(l->mp, "./m/BG.xpm", &a, &a);
	l->HD = mlx_xpm_file_to_image(l->mp, "./m/HD.xpm", &a, &a);
	l->HG = mlx_xpm_file_to_image(l->mp, "./m/HG.xpm", &a, &a);
	l->g = mlx_xpm_file_to_image(l->mp, "./m/g.xpm", &a, &a);
	l->LH = mlx_xpm_file_to_image(l->mp, "./m/LH.xpm", &a, &a);
	l->LV = mlx_xpm_file_to_image(l->mp, "./m/LV.xpm", &a, &a);
	l->LVPt = mlx_xpm_file_to_image(l->mp, "./m/LVPt.xpm", &a, &a);
	l->TB = mlx_xpm_file_to_image(l->mp, "./m/TB.xpm", &a, &a);
	l->TH = mlx_xpm_file_to_image(l->mp, "./m/TH.xpm", &a, &a);
	return ;
}
void print_angle(t_l *l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < l->tv)
	{
		while (j < l->th)
		{
			if (i == 0 && j == 0)
				mlx_put_image_to_window(l->mp, l->wp, l->HG, j * 32, i * 32);
			if (i == 0 && j == l->th - 1)
				mlx_put_image_to_window(l->mp, l->wp, l->HD, j * 32, i * 32);
			if (i == l->tv - 1 && j == 0)
				mlx_put_image_to_window(l->mp, l->wp, l->BG, j * 32, i * 32);
			if (i == l->tv - 1 && j == l->th - 1)
				mlx_put_image_to_window(l->mp, l->wp, l->BD, j * 32, i * 32);
			if (l->map[i][j] == '0' && j != l->m && 
				j != l->x - 1 && j != l->th - l->x)
				mlx_put_image_to_window(l->mp, l->wp, l->g, j * 32, i * 32);
			j++;
		}
		i++;
		j = 0;
	}
}
void print_ligne(t_l *l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < l->tv)
	{
		while (j < l->th)
		{
			if (i == 0 && j != 0 && j != l->th - 1 && j != l->m)
				mlx_put_image_to_window(l->mp, l->wp, l->LH, j * 32, i * 32);
			if (i == l->tv - 1 && j != 0 && j != l->th - 1 && j != l->m)
				mlx_put_image_to_window(l->mp, l->wp, l->LH, j * 32, i * 32);
			if (i == 0 && j == l->m)
				mlx_put_image_to_window(l->mp, l->wp, l->TH, j * 32, i * 32);
			if (i == l-> tv - 1 && j == l->m)
				mlx_put_image_to_window(l->mp, l->wp, l->TB, j * 32, i * 32);
			if (i != 0 && i != l->tv - 1 && 
				(j == l->x - 1 || j == l->th - l->x))
				mlx_put_image_to_window(l->mp, l->wp, l->LV, j * 32, i * 32);
			j++;
		}
		i++;
		j = 0;
	}
}
void print_vertical(t_l *l)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < l->tv)
	{
		while (j < l->th)
		{
			if (i != 0 && j == 0 && i != l->tv - 1)
				mlx_put_image_to_window(l->mp, l->wp, l->LV, j * 32, i * 32);
			if (i != 0 && i != l->tv - 1 && j == l->th - 1)
				mlx_put_image_to_window(l->mp, l->wp, l->LV, j * 32, i * 32);
			if (i != 0 && i != l->tv - 1 && j == l->m)
				mlx_put_image_to_window(l->mp, l->wp, l->LV, j * 32, i * 32);
			if (i == 0 && (j == l->x - 1 || j == l->th - l->x))
				mlx_put_image_to_window(l->mp, l->wp, l->TH, j * 32, i * 32);
			if (i == l->tv - 1 && (j == l->x - 1 || j == l->th - l->x))
				mlx_put_image_to_window(l->mp, l->wp, l->TB, j * 32, i * 32);
			j++;
		}
		i++;
		j = 0;
	}
}
