/*
** wolf3d.c for wolf3d in /home/thierry/rendu/gfx_wolf3d
**
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
**
** Started on Mon Dec 21 15:26:34 2015 Thierry LEVISSE
** Last update Fri Jan  8 01:13:34 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	<math.h>
#include	<unistd.h>
#include	"my.h"
#include	"key.h"
#include	"wall.h"

void	pol_to_car(t_polar pol, t_cartesian *car, t_cartesian pos)
{
  car->x = (pol.radius * cos(pol.angle)) + pos.x;
  car->y = -(pol.radius * sin(pol.angle)) + pos.y;
}

t_bunny_response	key_event(t_bunny_event_state   state,
				  t_bunny_keysym        key,
				  void                  *data)
{
  UNUSED(state);
  if (key == BKS_UP && ((t_params *)data)->menu == 2)
    ((t_params *)data)->menu--;
  if (key == BKS_DOWN && ((t_params *)data)->menu == 1)
    ((t_params *)data)->menu++;
  if (key == BKS_P && ((t_params *)data)->menu == 0)
    ((t_params *)data)->menu = 1;
  if (key == BKS_R)
    {
      ((t_params *)data)->x = ((t_params *)data)->start[0];
      ((t_params *)data)->y = ((t_params *)data)->start[1];
    }
  if (key == BKS_RETURN)
    {
      if (((t_params *)data)->menu == 1)
	((t_params *)data)->menu = 0;
      if (((t_params *)data)->menu == 2)
	return (EXIT_ON_SUCCESS);
    }
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void			end_mainloop(t_bunny_window *win,
				     t_bunny_pixelarray *pix,
				     void *to_ml)
{
  t_bunny_position	pos_blit;

  pos_blit.x = 0;
  pos_blit.y = 0;
  bunny_blit(&win->buffer, &pix->clipable, &pos_blit);
  if (((t_params *)to_ml)->menu == 1)
    bunny_blit(&win->buffer, &((t_params *)to_ml)->menu1->clipable, &pos_blit);
  if (((t_params *)to_ml)->menu == 2)
    bunny_blit(&win->buffer, &((t_params *)to_ml)->menu2->clipable, &pos_blit);
  bunny_display(win);
  bunny_delete_clipable(&pix->clipable);
}

t_bunny_response	mainloop(void *to_mainloop)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;

  win = ((t_params *)to_mainloop)->win;
  pix = bunny_new_pixelarray(win->buffer.width, win->buffer.height);
  fill_sky(pix);
  fill_floor(pix);
  process_wall(to_mainloop, pix);
  bunny_set_key_response(key_event);
  key_move(to_mainloop);
  end_mainloop(win, pix, to_mainloop);
  return (GO_ON);
}

int			main(int argc, char **argv)
{
  t_bunny_window	*win;
  t_params		to_mainloop;

  if (argc == 2)
    {
      if (check_ini_map(argv[1], &to_mainloop) == -1)
	return (-1);
      win = bunny_start(800, 600, false, "Wolf3D");
      load_image(&to_mainloop);
      init_params(&to_mainloop, win, argv);
      if (ini_to_map(&to_mainloop) == -1)
	return (-1);
      bunny_set_loop_main_function(mainloop);
      bunny_loop(win, 60, &to_mainloop);
      free_mainloop(&to_mainloop);
    }
  else
    {
      write(2, "Usage : ", 8);
      write(2, argv[0], my_strlen(argv[0]));
      write(2, " maps\n", 6);
      return (-1);
    }
  return (0);
}
