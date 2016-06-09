/*
** ini.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jan  3 11:27:19 2016 Thierry LEVISSE
** Last update Fri Jan  8 01:16:45 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	<unistd.h>
#include	"wall1.xpm"
#include	"wall2.xpm"
#include	"floor.xpm"
#include	"white.xpm"
#include	"menu1.xpm"
#include	"menu2.xpm"
#include	"my.h"

int	check_map_borders(t_params *to_mainloop)
{
  int	i;
  int	size[2];
  char	**map;

  map = to_mainloop->map;
  size[0] = to_mainloop->size[0];
  size[1] = to_mainloop->size[1];
  i = 0;
  while (i < size[1])
    {
      if (map[i][0] == 0 || map[i][size[0] - 1] == 0)
	return (-1);
      i++;
    }
  i = 0;
  while (i < size[0])
    {
      if (map[0][i] == 0 || map[size[1] - 1][i] == 0)
	return (-1);
      i++;
    }
  return (0);
}

int	ini_to_map(t_params *to_mainloop)
{
  int	i;
  int	j;
  int	k;
  char	tmp;

  i = 0;
  j = 0;
  k = 0;
  to_mainloop->map[9][9] = 1;
  while (i < to_mainloop->size[1])
    {
      j = 0;
      while (j < to_mainloop->size[0])
	{
	  tmp = atoi(bunny_ini_get_field(to_mainloop->ini, "level1", "data", k));
	  to_mainloop->map[i][j] = tmp;
	  j++;
	  k++;
	}
      i++;
    }
  bunny_delete_ini(to_mainloop->ini);
  if (map_borders(to_mainloop) == -1)
    return (-1);
  return (0);
}

int	check_ini_map(char *str, t_params *to_ml)
{
  int	size[2];
  float	coord[2];
  char	*sp;

  sp = bunny_malloc(15);
  my_strcpy(sp, "start_position");
  to_ml->ini = bunny_load_ini(str);
  if (to_ml->ini == NULL)
    {
      write(2, "maps.ini is needed\n", 19);
      return (-1);
    }
  size[0] = atoi(bunny_ini_get_field(to_ml->ini, "level1", "width", 0));
  size[1] = atoi(bunny_ini_get_field(to_ml->ini, "level1", "height", 0));
  coord[0] = atof(bunny_ini_get_field(to_ml->ini, "level1", sp, 0));
  coord[1] = atof(bunny_ini_get_field(to_ml->ini, "level1", sp, 1));
  to_ml->size[0] = size[0];
  to_ml->size[1] = size[1];
  to_ml->x = coord[0];
  to_ml->y = coord[1];
  to_ml->start[0] = coord[0];
  to_ml->start[1] = coord[1];
  to_ml->angle = atof(bunny_ini_get_field(to_ml->ini, "level1", sp, 2)) * RAD;
  bunny_free(sp);
  return (0);
}

void	init_params(t_params *to_mainloop, t_bunny_window *win, char **argv)
{
  int	i;
  int	size_tmp;

  size_tmp = to_mainloop->size[1];
  to_mainloop->win = win;
  to_mainloop->argv = argv;
  to_mainloop->map = bunny_malloc(sizeof(char *) * (to_mainloop->size[0]));
  i = 0;
  while (i < to_mainloop->size[0])
    {
      to_mainloop->map[i] = bunny_malloc(sizeof(char *) * size_tmp);
      i++;
    }
}

void	load_image(t_params *to_mainloop)
{
  malloc_double_u_int(to_mainloop);
  xpm_to_array(to_mainloop->texture1, wall1_xpm);
  xpm_to_array(to_mainloop->texture2, wall2_xpm);
  xpm_to_array(to_mainloop->texture3, floor_xpm);
  xpm_to_array(to_mainloop->texture4, white_xpm);
  to_mainloop->menu1 = bunny_new_pixelarray(800, 600);
  to_mainloop->menu2 = bunny_new_pixelarray(800, 600);
  xpm_to_pix(to_mainloop->menu1, menu1_xpm);
  xpm_to_pix(to_mainloop->menu2, menu2_xpm);
  to_mainloop->menu = 1;
}
