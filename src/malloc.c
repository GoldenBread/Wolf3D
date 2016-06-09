/*
** malloc.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu Dec 31 21:58:08 2015 Thierry LEVISSE
** Last update Thu Jan  7 23:16:21 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	"my.h"

void	malloc_double_u_int(t_params *to_mainloop)
{
  int	i;

  to_mainloop->texture1 = bunny_malloc(sizeof(unsigned int *) * 64);
  to_mainloop->texture2 = bunny_malloc(sizeof(unsigned int *) * 64);
  to_mainloop->texture3 = bunny_malloc(sizeof(unsigned int *) * 64);
  to_mainloop->texture4 = bunny_malloc(sizeof(unsigned int *) * 64);
  i = 0;
  while (i < 64)
    {
      to_mainloop->texture1[i] = bunny_malloc(sizeof(unsigned int *) * 64);
      to_mainloop->texture2[i] = bunny_malloc(sizeof(unsigned int *) * 64);
      to_mainloop->texture3[i] = bunny_malloc(sizeof(unsigned int *) * 64);
      to_mainloop->texture4[i] = bunny_malloc(sizeof(unsigned int *) * 64);
      i++;
    }
}

void	free_mainloop(t_params *to_mainloop)
{
  bunny_free(to_mainloop->map);
  bunny_free(to_mainloop->texture1);
  bunny_free(to_mainloop->texture2);
  bunny_free(to_mainloop->texture3);
  bunny_free(to_mainloop->texture4);
}
