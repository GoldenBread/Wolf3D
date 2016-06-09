/*
** wall_3.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jan  3 11:12:16 2016 Thierry LEVISSE
** Last update Thu Jan  7 23:17:14 2016 Thierry LEVISSE
*/

#include		<lapin.h>
#include		<math.h>
#include		"wall.h"

void			tekfloorcast(t_bunny_pixelarray *pix,
				     t_generate_wall *wall,
				     void *to_mainloop,
				     t_process_wall *in)
{
  t_floor_cast		p;
  int			i;

  p.car.x = ((t_params *)to_mainloop)->x;
  p.car.y = ((t_params *)to_mainloop)->y;
  p.pos.x = in->i;
  p.pol.angle = in->rayon.angle[in->i];
  p.increment = p.dist / 50;
  i = 0;
  while (i < wall->y_start)
    {
      p.pol.radius = ((1.2 * 300) / (300 - (wall->y_start - i)));
      p.pol.radius /= cos((0.075 * in->i - 30) * RAD);
      pol_to_car(p.pol, &p.t_p, p.car);
      p.t_p.x = (int)(p.t_p.x * 64) % 64;
      p.t_p.y = (int)(p.t_p.y * 64) % 64;
      p.pos.y = i + wall->y_start + wall->y_size;
      tekpixel_old(pix, &p.pos, wall->texture[(int)p.t_p.x][(int)p.t_p.y]);
      p.dist -= p.increment;
      i++;
    }
}

void			tekwallline_2(t_generate_wall *wall,
				      double percent,
				      t_bunny_pixelarray *pix,
				      t_process_wall *in)
{
  wall->y_size = (pix->clipable.clip_height / 100) * percent;
  wall->y_start = (pix->clipable.clip_height - wall->y_size) / 2;
  wall->pos.y = wall->y_start;
  wall->i_texture_array = (float)64 / wall->y_size;
  wall->i = 0;
  wall->j = (int)(in->rayon.ray_pos_surface[in->i] * 64) % 64;
  while (wall->pos.y < wall->y_start + wall->y_size)
    {
      tekpixel_old(pix, &wall->pos, wall->texture[(int)wall->i][(int)wall->j]);
      wall->pos.y++;
      wall->i += wall->i_texture_array;
    }
}

void			tekwallline(t_bunny_pixelarray *pix,
				    void *to_mainloop,
				    t_process_wall *in)
{
  t_generate_wall	wall;

  wall.pos.x = in->i;
  wall.hit_x = (double)in->rayon.x_hit[in->i];
  wall.hit_y = (double)in->rayon.y_hit[in->i];
  if (in->color[in->i] == 1)
    wall.texture = ((t_params *)to_mainloop)->texture1;
  else if (in->color[in->i] == 2)
    wall.texture = ((t_params *)to_mainloop)->texture2;
  if (hit_or_not(to_mainloop, wall.hit_x, wall.hit_y) == 2)
    wall.texture = ((t_params *)to_mainloop)->texture4;
  if (in->percent < 1000)
    tekwallline_2(&wall, in->percent, pix, in);
  else
    {
      wall.pos.y = 0;
      while (wall.pos.y < pix->clipable.clip_height)
	{
	  tekpixel_old(pix, &wall.pos, wall.texture[10][10]);
      	  wall.pos.y++;
      	}
    }
  wall.texture = ((t_params *)to_mainloop)->texture3;
  tekfloorcast(pix, &wall, to_mainloop, in);
}
