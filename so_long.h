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
	void	*gB;
	void	*jd;
	void	*eu;
	void	*po;
	int		keycode;
	int		z;
	int		y;
	int		cn;
	int		c_d;

}				t_l;

int		fermer_esc(int keyboard, t_l *l);
int 	fermer_croix(void);
void	create_map(t_l *l, const char *map_path);
void	full_img(t_l *l);
void	print_angle(t_l *l);
void	print_ligne(t_l *l);
void	print_vertical(t_l *l);
int		main(int ac, char **av);
void	calcul(t_l *l);
int		secu_1(t_l *l);
int		secu_v(t_l *l);
int 	secu_rec(t_l *l);
void	coll_ballon(t_l *l);
void	perso(t_l *l);
void	brain(t_l *l);
void	secu_brain(t_l *l);
void	haut_perso(t_l *l);
int 	keys(int keycode, t_l *l);
void	bas_perso(t_l *l);
void	gauche_perso(t_l *l);
void	droite_perso(t_l *l);
int		secu_all(t_l *l);
int		n_c(t_l *l);
int	end(t_l *l);
void	destroy_image(t_l *l);

#endif
