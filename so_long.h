#ifndef SO_LONG_H
# define SO_LONG_H

# include "./include/libft/libft.h"
# include "./include/mlx/mlx.h"
# include "./include/mlx/mlx_int.h"

typedef struct	s_l
{
	int		info_img;
	void	*mp;
	void	*wp;
	char	**map;
	int		th;
	int		tv;
	void	*BD;
	void	*BG;
	void	*HD;
	void	*HG;
	void	*g;
	void	*LH;
	void	*LV;
	void	*LVPt;
	void	*TB;
	void	*TH;
	int		m;
	int		x;
}				t_l;

int		fermer_esc(int keyboard);
void	create_map(t_l *l);
void	full_img(t_l *l);
void	print_angle(t_l *l);
void	print_ligne(t_l *l);
void	print_vertical(t_l *l);
int		main(void);
void	calcul(t_l *l);

#endif
