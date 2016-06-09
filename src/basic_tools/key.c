/*
** key.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jan  1 23:06:57 2016 Thierry LEVISSE
** Last update Thu Jan  7 20:26:00 2016 Thierry LEVISSE
*/

#include		<lapin.h>
#include		"my.h"
#include		"key.h"

void			key_move(void *data)
{
  t_keystate            params;
  const bool		*bks_key;

  bks_key = bunny_get_keyboard();
  if (bks_key[BKS_Z] == 1)
    {
      params.car.x = ((t_params *)data)->x;
      params.car.y = ((t_params *)data)->y;
      params.pol.angle = ((t_params *)data)->angle;
      if (bks_key[57] == 0)
	params.pol.radius = 0.05;
      else
	params.pol.radius = 0.1;
      pol_to_car(params.pol, &params.ray, params.car);
      if (hit_or_not(data, params.ray.x, params.ray.y) == 0)
	{
	  ((t_params *)data)->x = params.ray.x;
	  ((t_params *)data)->y = params.ray.y;
	}
      else
        check_every_angle(data, params.car, params.ray);
    }
  key_move_2(data, params, bks_key);
}

void			key_move_2(void *data,
				   t_keystate params,
				   const bool *bks_key)
{
  if (bks_key[BKS_S] == 1)
    {
      params.car.x = ((t_params *)data)->x;
      params.car.y = ((t_params *)data)->y;
      params.pol.angle = ((t_params *)data)->angle;
      if (bks_key[57] == 0)
	params.pol.radius = -0.05;
      else
	params.pol.radius = -0.1;
      pol_to_car(params.pol, &params.ray, params.car);
      if (hit_or_not(data, params.ray.x, params.ray.y) != 1)
	{
	  ((t_params *)data)->x = params.ray.x;
	  ((t_params *)data)->y = params.ray.y;
	}
    }
  key_move_3(data, params, bks_key);
}

void			key_move_3(void *data,
				   t_keystate params,
				   const bool *bks_key)
{
  if (bks_key[BKS_Q] == 1)
    {
      params.car.x = ((t_params *)data)->x;
      params.car.y = ((t_params *)data)->y;
      params.pol.angle = ((t_params *)data)->angle - (90 * RAD);
      if (bks_key[57] == 0)
	params.pol.radius = -0.05;
      else
	params.pol.radius = -0.1;
      pol_to_car(params.pol, &params.ray, params.car);
      if (hit_or_not(data, params.ray.x, params.ray.y) != 1)
	{
	  ((t_params *)data)->x = params.ray.x;
	  ((t_params *)data)->y = params.ray.y;
	}
    }
  key_move_4(data, params, bks_key);
}

void			key_move_4(void *data,
				   t_keystate params,
				   const bool *bks_key)
{
  if (bks_key[BKS_D] == 1)
    {
      params.car.x = ((t_params *)data)->x;
      params.car.y = ((t_params *)data)->y;
      params.pol.angle = ((t_params *)data)->angle - (90 * RAD);
      if (bks_key[57] == 0)
	params.pol.radius = 0.05;
      else
	params.pol.radius = 0.1;
      pol_to_car(params.pol, &params.ray, params.car);
      if (hit_or_not(data, params.ray.x, params.ray.y) != 1)
	{
	  ((t_params *)data)->x = params.ray.x;
	  ((t_params *)data)->y = params.ray.y;
	}
    }
  key_move_5(data, bks_key);
}

void			key_move_5(void *data,
				   const bool *bks_key)
{
  if (bks_key[BKS_A] == 1)
    {
      if (((t_params *)data)->angle * DEG >= 360)
	((t_params *)data)->angle = 0.5 * RAD;
      else
	((t_params *)data)->angle += 2.5 * RAD;
	}
  if (bks_key[BKS_E] == 1)
    {
      if (((t_params *)data)->angle * DEG <= 0)
	((t_params *)data)->angle = 359.5 * RAD;
      else
	((t_params *)data)->angle -= 2.5 * RAD;
    }
}
