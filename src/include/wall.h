/*
** my.h for fdf2 in /home/thierry/rendu/FDF2/to_push/include
**
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
**
** Started on Sun Dec 20 13:07:59 2015 Thierry LEVISSE
** Last update Sun Jan  3 09:12:50 2016 Thierry LEVISSE
*/

#include		<lapin.h>
#include		"my.h"

#ifndef WALL_H_
# define WALL_H_
# define DEG		180 / 3.14159265359
# define RAD		3.14159265359 / 180
# define PI		3.14159265359
# define PRE		0.000000001

typedef struct		s_process_wall
{
  t_polar		pol;
  t_cartesian		car;
  t_cartesian		ray;
  int			i;
  int			k;
  double		ray_length[800];
  double		scan_tmp[2];
  double		x_dir_scan[2];
  double		x_scan[2];
  double		y_dir_scan[2];
  double		y_scan[2];
  double		ray_vert;
  double		ray_hori;
  double		true_angle;
  char			color[800];
  t_ray_data		rayon;
  double		percent;
}			t_process_wall;

typedef struct		s_generate_wall
{
  t_bunny_position	pos;
  int			y_start;
  int			y_size;
  unsigned int		**texture;
  float			i_texture_array;
  float			i;
  float			j;
  double		hit_x;
  double		hit_y;
}			t_generate_wall;

typedef struct		s_floor_cast
{
  float			increment;
  float			dist;
  t_bunny_position	pos;
  t_polar		pol;
  t_cartesian		t_p;
  t_cartesian		car;
}			t_floor_cast;

void			tekfloorcast(t_bunny_pixelarray *,
				     t_generate_wall *,
				     void *,
				     t_process_wall *);

void			tekwallline_2(t_generate_wall *,
				      double ,
				      t_bunny_pixelarray *,
				      t_process_wall *);

void			tekwallline(t_bunny_pixelarray *,
				    void *,
				    t_process_wall *);

void			process_wall5(t_process_wall *,
				      t_bunny_pixelarray *,
				      void *);

void			process_wall4_2(t_process_wall *);

void			process_wall4(t_process_wall *);

void			process_wall3_2(t_process_wall *);

void			process_wall3(t_process_wall *);

void			process_wall2_2(t_process_wall *);

void			process_wall2(t_process_wall *);

void			process_wall_init(t_process_wall *,
					  void *);

void			process_wall(void *,
				     t_bunny_pixelarray *);

#endif
