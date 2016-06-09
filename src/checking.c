/*
** checkng.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jan  3 11:27:08 2016 Thierry LEVISSE
** Last update Thu Jan  7 21:26:49 2016 Thierry LEVISSE
*/

#include	<math.h>
#include	"wall.h"

void	check_every_angle_3(void *data,
			    t_cartesian car,
			    t_cartesian ray,
			    t_check_every_angle p)
{
  if (p.choosed_angle == 270)
    {
      ray.x = car.x;
      ray.y = car.y + 0.05;
    }
  ((t_params *)data)->x = ray.x;
  ((t_params *)data)->y = ray.y;
}


void	check_every_angle_2(void *data,
			    t_cartesian car,
			    t_cartesian ray,
			    t_check_every_angle p)
{
  while (p.i < 5)
    {
      if (p.angle[p.i] != -1 && p.short_angle[p.i] < p.small_angle)
	{
	  p.small_angle = p.short_angle[p.i];
	  p.choosed_angle = p.angle[p.i];
	}
      p.i++;
    }
  if (p.choosed_angle == 0 || p.choosed_angle == 360)
    {
      ray.x = car.x + 0.05;
      ray.y = car.y;
    }
  if (p.choosed_angle == 90)
    {
      ray.x = car.x;
      ray.y = car.y - 0.05;
    }
  if (p.choosed_angle == 180)
    {
      ray.x = car.x - 0.05;
      ray.y = car.y;
    }
  check_every_angle_3(data, car, ray, p);
}

void	check_every_angle_intermediare(void *data,
				       t_cartesian car,
				       t_cartesian ray,
				       t_check_every_angle params)
{
  params.i = 0;
  params.small_angle = (float)360;
  params.short_angle[0] = fabs((((t_params *)data)->angle * DEG) - 0);
  params.short_angle[1] = fabs((((t_params *)data)->angle * DEG) - 90);
  params.short_angle[2] = fabs((((t_params *)data)->angle * DEG) - 180);
  params.short_angle[3] = fabs((((t_params *)data)->angle * DEG) - 270);
  params.short_angle[4] = fabs((((t_params *)data)->angle * DEG) - 360);
  check_every_angle_2(data, car, ray, params);
}

void			check_every_angle(void *data,
					  t_cartesian car,
					  t_cartesian ray)
{
  t_check_every_angle	params;

  params.angle[0] = (float)-1;
  params.angle[1] = (float)-1;
  params.angle[2] = (float)-1;
  params.angle[3] = (float)-1;
  params.angle[4] = (float)-1;
  if (((t_params *)data)->map[(int)car.y][(int)(car.x + 0.3)] == 0)
    params.angle[0] = 0;
  if (((t_params *)data)->map[(int)(car.y + 0.3)][(int)car.x] == 0)
    params.angle[1] = 90;
  if (((t_params *)data)->map[(int)car.y][(int)(car.x - 0.3)] == 0)
    params.angle[2] = 180;
  if (((t_params *)data)->map[(int)(car.y + 0.3)][(int)car.x] == 0)
    params.angle[3] = 270;
  if (((t_params *)data)->map[(int)car.y][(int)(car.x + 0.3)] == 0)
    params.angle[4] = 360;
  check_every_angle_intermediare(data, car, ray, params);
}

int	too_close(void *data, t_polar pol, t_cartesian car)
{
  if (((t_params *)data)->map[(int)car.y][(int)(car.x + 0.3)] == 1)
    if (pol.angle < 90 || pol.angle > 270)
      return (1);
  if (((t_params *)data)->map[(int)(car.y + 0.3)][(int)car.x] == 1)
    if ((pol.angle > 0 && pol.angle < 180) || pol.angle > 360)
      return (1);
  if (((t_params *)data)->map[(int)car.y][(int)(car.x - 0.3)] == 1)
    if (pol.angle > 90 && pol.angle < 270)
      return (1);
  if (((t_params *)data)->map[(int)(car.y + 0.3)][(int)car.x] == 1)
    if ((pol.angle > 180 && pol.angle < 360) || pol.angle < 0)
      return (1);
  return (0);
}
