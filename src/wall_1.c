/*
** wall_1.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jan  3 11:11:17 2016 Thierry LEVISSE
** Last update Sun Jan  3 11:21:08 2016 Thierry LEVISSE
*/

#include		<lapin.h>
#include		<math.h>
#include		"wall.h"

void			process_wall3(t_process_wall *in)
{
  double		p_angle;

  p_angle = in->pol.angle;
  if (in->ray.y - in->car.y != 0)
    {
      in->y_dir_scan[0] = (in->ray.x - in->car.x) / (in->ray.y - in->car.y);
      if (in->y_dir_scan[0] > 50)
	in->y_dir_scan[0] = 50;
      if (in->y_dir_scan[0] < -50)
	in->y_dir_scan[0] = -50;
    }
  else
    in->y_dir_scan[0] = 50;
  if ((p_angle > 0 * RAD && p_angle < 180 * RAD) || p_angle > 360 * RAD)
    {
      in->y_dir_scan[1] = -1;
      in->y_dir_scan[0] *= -1;
      in->y_scan[1] = floor(in->car.y);
      in->y_scan[0] = ((in->y_scan[1] - in->car.y) * (-1)) * in->y_dir_scan[0];
      in->y_scan[0] += in->car.x;
    }
  process_wall3_2(in);
}

void			process_wall2_2(t_process_wall *in)
{
  if (in->pol.angle < 90 * RAD || in->pol.angle > 270 * RAD)
    {
      in->x_dir_scan[0] = 1;
      in->x_scan[0] = ceil(in->car.x);
      in->x_scan[1] = ((in->x_scan[0] - in->car.x) * (1)) * in->x_dir_scan[1];
      in->x_scan[1] += in->car.y;
    }
  if (in->pol.angle == 90 * RAD)
    {
      in->x_dir_scan[0] = 0;
      in->x_scan[0] = 0;
      in->x_scan[1] = ceil(in->car.x);
    }
  if (in->pol.angle == 270 * RAD)
    {
      in->x_dir_scan[0] = 0;
      in->x_scan[0] = 0;
      in->x_scan[1] = floor(in->car.x);
    }
  in->scan_tmp[0] = in->x_scan[0];
  in->scan_tmp[1] = in->x_scan[1];
  in->k = 0;
}

void			process_wall2(t_process_wall *in)
{
  in->pol.radius = 0.05;
  pol_to_car(in->pol, &in->ray, in->car);
  if (in->ray.x - in->car.x != 0)
    {
      in->x_dir_scan[1] = (in->ray.y - in->car.y) / (in->ray.x - in->car.x);
      if (in->x_dir_scan[1] > 50)
	in->x_dir_scan[1] = 50;
    }
  else
    in->x_dir_scan[1] = 50;
  if (in->pol.angle > 90 * RAD && in->pol.angle < 270 * RAD)
    {
      in->x_dir_scan[0] = -1;
      in->x_dir_scan[1] *= -1;
      in->x_scan[0] = floor(in->car.x);
      in->x_scan[1] = ((in->x_scan[0] - in->car.x) * (-1)) * in->x_dir_scan[1];
      in->x_scan[1] += in->car.y;
    }
  process_wall2_2(in);
}

void			process_wall_init(t_process_wall *in,
					  void *to_mainloop)
{
  in->car.x = ((t_params *)to_mainloop)->x;
  in->car.y = ((t_params *)to_mainloop)->y;

  in->pol.radius = 0;
  in->pol.angle = ((t_params *)to_mainloop)->angle + (30 * RAD);
  pol_to_car(in->pol, &in->ray, in->car);
  in->i = 0;
  in->true_angle = 30 * RAD;
}

void			process_wall(void *to_mainloop, t_bunny_pixelarray *pix)
{
  t_process_wall	in;

  process_wall_init(&in, to_mainloop);
  while (in.i < pix->clipable.clip_width)
    {
      process_wall2(&in);
      while (hit_or_not(to_mainloop, in.x_scan[0], in.x_scan[1]) == 0)
	{
	  in.x_scan[0] = (in.scan_tmp[0] + in.k * in.x_dir_scan[0]);
	  in.x_scan[1] = (in.scan_tmp[1] + in.k * in.x_dir_scan[1]);
	  in.k++;
	}
      process_wall3(&in);
      while (hit_or_not(to_mainloop, in.y_scan[0], in.y_scan[1]) == 0)
	{
	  in.y_scan[0] = in.scan_tmp[0] + in.k * in.y_dir_scan[0];
	  in.y_scan[1] = in.scan_tmp[1] + in.k * in.y_dir_scan[1];
	  in.k++;
	}
      process_wall4(&in);
      in.i++;
      in.pol.angle -= ((double)60 / pix->clipable.clip_width) * RAD;
      in.true_angle -= ((double)60 / pix->clipable.clip_width) * RAD;
    }
  process_wall5(&in, pix, to_mainloop);
}
