/*
** misc.c for wold3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jan  3 11:25:02 2016 Thierry LEVISSE
** Last update Sun Jan  3 12:48:49 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	<unistd.h>
#include	"my.h"

void		fill_sky(t_bunny_pixelarray *pixelarray)
{
  int           i;
  int           total;

  total = (pixelarray->clipable.clip_width * pixelarray->clipable.clip_height);
  total /= 2;
  i = 0;
  while (i < total)
    {
      ((unsigned int *) (pixelarray->pixels)) [i] = 16760576;
      i++;
    }
}

void		fill_floor(t_bunny_pixelarray *pixelarray)
{
  int           i;
  int           total;

  total = (pixelarray->clipable.clip_width * pixelarray->clipable.clip_height);
  i = (pixelarray->clipable.clip_width * pixelarray->clipable.clip_height) / 2;
  while (i < total)
    {
      ((unsigned int *) (pixelarray->pixels)) [i] = 6908265;
      i++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	map_borders(t_params *to_mainloop)
{
  if (check_map_borders(to_mainloop) == -1)
    {
      write(2, "Error : missing border map\n", 27);
      return (-1);
    }
  return (0);
}

int		hit_or_not(void *to_mainloop, double scan_x, double scan_y)
{
  char		**map;

  map = ((t_params *)to_mainloop)->map;
  if (scan_x < 0)
    return (1);
  if (scan_x > ((t_params *)to_mainloop)->size[0])
    return (1);
  if (scan_y < 0)
    return (1);
  if (scan_y > ((t_params *)to_mainloop)->size[1])
    return (1);
  if (map[(int)(scan_y - PRE)][(int)(scan_x - PRE)] != 0)
    return (map[(int)(scan_y - PRE)][(int)(scan_x - PRE)]);
  if (map[(int)(scan_y)][(int)(scan_x)] != 0)
    return (map[(int)(scan_y)][(int)(scan_x)]);
  return (0);
}
