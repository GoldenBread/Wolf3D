/*
** my.h for fdf2 in /home/thierry/rendu/FDF2/to_push/include
**
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
**
** Started on Sun Dec 20 13:07:59 2015 Thierry LEVISSE
** Last update Sun Jan  3 10:59:16 2016 Thierry LEVISSE
*/

#include	<lapin.h>

#ifndef KEY_H_
# define KEY_H_

t_bunny_response	key_event(t_bunny_event_state state,
				  t_bunny_keysym key,
				  void *data);

void	key_move(void *data);

void	key_move_2(void *data,
		   t_keystate params,
		   const bool *bks_key);

void	key_move_3(void *data,
		   t_keystate params,
		   const bool *bks_key);

void	key_move_4(void *data,
		   t_keystate params,
		   const bool *bks_key);

void	key_move_5(void *data,
		   const bool *bks_key);

#endif
