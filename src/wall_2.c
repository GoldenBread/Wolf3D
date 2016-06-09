/*
** wall_2.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jan  3 11:11:42 2016 Thierry LEVISSE
** Last update Sun Jan  3 11:11:43 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	<math.h>
#include	"wall.h"

void		process_wall5(t_process_wall *in,
			      t_bunny_pixelarray *pix,
			      void *to_mainloop)
{
  in->i = 0;
  while (in->i < pix->clipable.clip_width)
    {
      in->percent = (1.2 / in->ray_length[in->i]) * 100;
      tekwallline(pix, to_mainloop, in);
      in->i++;
    }
}

void		process_wall4_2(t_process_wall *in)
{
  in->rayon.ray_pos_surface[in->i] = in->y_scan[0];
  in->rayon.which_wall = 'h';
  in->ray_length[in->i] = in->ray_hori * cos(in->true_angle);
  in->rayon.length[in->i] = in->ray_length[in->i];
  in->rayon.angle[in->i] = in->pol.angle;
  in->rayon.x_hit[in->i] = in->y_scan[0];
  in->rayon.y_hit[in->i] = in->y_scan[1];
  in->color[in->i] = 2;
}

void		process_wall4(t_process_wall *in)
{
  float	vert_pow;
  float	hori_pow;

  vert_pow = pow(in->x_scan[1] - in->car.y, 2);
  hori_pow = pow(in->y_scan[1] - in->car.y, 2);
  in->ray_vert = sqrt(pow(in->x_scan[0] - in->car.x, 2) + vert_pow);
  in->ray_hori = sqrt(pow(in->y_scan[0] - in->car.x, 2) + hori_pow);
  if (in->ray_vert < in->ray_hori)
    {
      in->rayon.ray_pos_surface[in->i] = in->x_scan[1];
      in->rayon.which_wall = 'v';
      in->ray_length[in->i] = in->ray_vert * cos(in->true_angle);
      in->rayon.angle[in->i] = in->pol.angle;
      in->rayon.x_hit[in->i] = in->x_scan[0];
      in->rayon.y_hit[in->i] = in->x_scan[1];
      in->color[in->i] = 1;
    }
  else
    process_wall4_2(in);
}

void		process_wall3_2(t_process_wall *in)
{
  float		ag;

  ag = in->pol.angle;
  if ((ag < 360 * RAD && ag > 180 * RAD) || ag < 0 * RAD)
    {
      in->y_dir_scan[1] = 1;
      in->y_scan[1] = ceil(in->car.y);
      in->y_scan[0] = ((in->y_scan[1] - in->car.y) * (1)) * in->y_dir_scan[0];
      in->y_scan[0] += in->car.x;
    }
  if (in->pol.angle == 180 * RAD)
    {
      in->y_dir_scan[1] = 0;
      in->y_scan[1] = 0;
      in->y_scan[0] = ceil(in->car.y);
    }
  if (in->pol.angle == 0 * RAD || in->pol.angle == 360 * RAD)
    {
      in->y_dir_scan[1] = 0;
      in->y_scan[1] = 0;
      in->y_scan[0] = floor(in->car.y);
    }
  in->scan_tmp[0] = in->y_scan[0];
  in->scan_tmp[1] = in->y_scan[1];
  in->k = 0;
}
