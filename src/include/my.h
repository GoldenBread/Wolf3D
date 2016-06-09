/*
** my.h for fdf2 in /home/thierry/rendu/FDF2/to_push/include
**
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
**
** Started on Sun Dec 20 13:07:59 2015 Thierry LEVISSE
** Last update Fri Jan  8 01:12:38 2016 Thierry LEVISSE
*/

#include	<lapin.h>

#ifndef MY_H_
# define MY_H_
# define DEG		180 / 3.14159265359
# define RAD		3.14159265359 / 180
# define PI		3.14159265359
# define PRE		0.000000001
# define UNUSED(expr)	(void)(expr);


typedef struct		s_params
{
  t_bunny_window	*win;
  char			**argv;
  double		x;
  double		y;
  double		z;
  float			start[2];
  double		angle;
  double		radius;
  int			argc;
  char			**map;
  int			size[2];
  t_bunny_ini		*ini;
  unsigned int		**texture1;
  unsigned int		**texture2;
  unsigned int		**texture3;
  unsigned int		**texture4;
  t_bunny_pixelarray	*menu1;
  t_bunny_pixelarray	*menu2;
  int			menu;
}			t_params;

typedef struct		s_geometry
{
  int			faces_nb;
  int			faces;
  int			faces_circle;
  int			radius;
  int			void_size;
  float			z;
  double		until;
  char			shape;
  int			invert;
  int			height;
  int			length;
  int			width;
}			t_geometry;

typedef struct		s_position
{
  float 		x;
  float 		y;
}			t_position;

typedef struct		s_pos
{
  int			x;
  int			y;
  int			z;
}			t_pos;

typedef struct		s_polar
{
 double			angle;
 double			radius;
}			t_polar;

typedef struct		s_cartesian
{
  double		x;
  double		y;
}			t_cartesian;

typedef struct		s_xpm_read
{
  unsigned int		width;
  unsigned int		height;
  unsigned int		palette_size;
  unsigned int		header_size;
  unsigned int		**palette;
}			t_xpm_read;

typedef struct		s_ray_data
{
  float			ray_pos_surface[800];
  float			length[800];
  float			angle[800];
  char			which_wall;
  float			x_hit[800];
  float			y_hit[800];
}			t_ray_data;

typedef struct		s_keystate
{
  t_polar		pol;
  t_cartesian		car;
  t_cartesian		ray;
}			t_keystate;

typedef struct		s_check_every_angle
{
  int			angle[5];
  float			short_angle[5];
  float			small_angle;
  int			choosed_angle;
  int			i;
}			t_check_every_angle;

void			tekpixel(t_bunny_pixelarray *,
				 t_bunny_position *,
				 t_color *);

void			pol_to_car(t_polar ,
				   t_cartesian *,
				   t_cartesian);

void			my_strcpy(char *,
				  char *);

void			reading_test(t_params *);

int			hit_or_not(void *,
				   double ,
				   double);

void			xpm_to_pix(t_bunny_pixelarray *,
				   char **);

void			xpm_to_pix_2(t_bunny_pixelarray *,
				     t_xpm_read ,
				     char **);

void			xpm_to_array(unsigned int **,
				     char **);

void			xpm_to_array_2(unsigned int **,
				       t_xpm_read ,
				       char **);

void			malloc_double_u_int(t_params *);

void			free_mainloop(t_params *);

void			tekpixel_old(t_bunny_pixelarray *,
				     t_bunny_position *,
				     unsigned int);

void			check_every_angle(void *,
					  t_cartesian ,
					  t_cartesian );

void			check_every_angle_2(void *,
					    t_cartesian ,
					    t_cartesian ,
					    t_check_every_angle);

void			check_every_angle_3(void *,
					    t_cartesian ,
					    t_cartesian ,
					    t_check_every_angle);

int			too_close(void *,
				  t_polar ,
				  t_cartesian);

void			end_mainloop(t_bunny_window *,
				     t_bunny_pixelarray *,
				     void *);

void			init_params(t_params *,
				    t_bunny_window *,
				    char **);

int			my_strlen(char *);

int			check_map_borders(t_params *);

int			map_borders(t_params *);

int			ini_to_map(t_params *);

int			check_ini_map(char *,
				      t_params *);

void			load_image(t_params *);

void			fill_floor(t_bunny_pixelarray *);

void			fill_sky(t_bunny_pixelarray *);

unsigned int		dec_to_hex_lapin(char *);

#endif
