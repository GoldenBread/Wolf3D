/*
** xpm.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu Dec 31 21:36:17 2015 Thierry LEVISSE
** Last update Thu Jan  7 21:30:48 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	"my.h"

void		xpm_to_pix_2(t_bunny_pixelarray *pix, t_xpm_read data, char **xpm)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	k;
  unsigned int	l;

  i = data.header_size;
  j = 0;
  k = 0;
  while (i < data.header_size + data.height)
    {
      j = 0;
      while (j < data.width)
	{
	  l = 0;
	  while ((unsigned int)*(*(xpm + i) + j) != data.palette[l][0])
	    l++;
	  ((unsigned int *) (pix->pixels)) [k] = data.palette[l][1];
	  j++;
	  k++;
	}
      i++;
    }
}

void		xpm_to_pix(t_bunny_pixelarray *pix, char **xpm)
{
  t_xpm_read	data;
  unsigned int	i;
  unsigned int	j;
  char		isolate[7];

  data.width = atoi(*(xpm + 0));
  data.height = atoi(*(xpm + 1));
  data.palette_size = atoi(*(xpm + 2));
  data.header_size = data.palette_size + 4;
  data.palette = bunny_malloc(sizeof(unsigned int *) * data.palette_size);
  i = 0;
  while (i < data.palette_size)
    {
      data.palette[i] = bunny_malloc(sizeof(unsigned int *) * 2);
      data.palette[i][0] = *(*(xpm + i + 4) + 0);
      j = 0;
      while (j < 6)
	{
	  isolate[j] = *(*(xpm + i + 4) + j + 5);
	  j++;
	}
      data.palette[i][1] = dec_to_hex_lapin(isolate);
      i++;
    }
  xpm_to_pix_2(pix, data, xpm);
}

void		xpm_to_array_2(unsigned int **dest, t_xpm_read data, char **xpm)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	l;

  i = data.header_size;
  j = 0;
  while (i < data.header_size + data.height)
    {
      j = 0;
      while (j < data.width)
	{
	  l = 0;
	  while ((unsigned int)*(*(xpm + i) + j) != data.palette[l][0])
	    l++;
	  dest[i - data.header_size][j] = data.palette[l][1];
	  j++;
	}
      i++;
    }
}

void		xpm_to_array(unsigned int **dest, char **xpm)
{
  t_xpm_read	data;
  unsigned int	i;
  unsigned int	j;
  char		isolate[7];

  data.width = atoi(*(xpm + 0));
  data.height = atoi(*(xpm + 1));
  data.palette_size = atoi(*(xpm + 2));
  data.header_size = data.palette_size + 4;
  data.palette = bunny_malloc(sizeof(unsigned int *) * data.palette_size);
  i = 0;
  while (i < data.palette_size)
    {
      data.palette[i] = bunny_malloc(sizeof(unsigned int *) * 2);
      data.palette[i][0] = *(*(xpm + i + 4) + 0);
      j = 0;
      while (j < 6)
	{
	  isolate[j] = *(*(xpm + i + 4) + j + 5);
	  j++;
	}
      data.palette[i][1] = dec_to_hex_lapin(isolate);
      i++;
    }
  xpm_to_array_2(dest, data, xpm);
}
