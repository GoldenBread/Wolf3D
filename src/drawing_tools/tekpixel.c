/*
** tekpixel.c for tekpixel in /home/thierry/rendu/FDF2/to_push/tcore
**
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
**
** Started on Sat Dec 19 15:21:56 2015 Thierry LEVISSE
** Last update Sun Jan  3 21:22:18 2016 Thierry LEVISSE
*/

#include	<lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	i;

  i = pix->clipable.clip_width * pos->y + pos->x;
  if (pos->y >= 0 && pos->x >= 0 && pos->y <= pix->clipable.clip_height)
    {
      if (pos->x <= pix->clipable.clip_width)
	{
	  if (i >= 0)
	    {
	      if (i <= pix->clipable.clip_width * pix->clipable.clip_height)
		((unsigned int *) (pix->pixels)) [i] = color->full;
	    }
	}
    }
}

void	tekpixel_old(t_bunny_pixelarray *pix,
		     t_bunny_position *pos,
		     unsigned int color)
{
  int	i;

  i = pix->clipable.clip_width * pos->y + pos->x;
  if (pos->y >= 0 && pos->x >= 0 && pos->y <= pix->clipable.clip_height)
    {
      if (pos->x <= pix->clipable.clip_width)
	{
	  if (i >= 0)
	    {
	      if (i <= pix->clipable.clip_width * pix->clipable.clip_height)
		((unsigned int *) (pix->pixels)) [i] = color;
	    }
	}
    }
}
