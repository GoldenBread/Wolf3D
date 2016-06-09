/*
** my_strcpy.c for my_strcpy in /home/leviss_t/rendu/Piscine_C_J06/ex_02
** 
** Made by Thierry LEVISSE
** Login   <leviss_t@epitech.net>
** 
** Started on  Mon Oct  5 09:05:10 2015 Thierry LEVISSE
** Last update Sun Jan  3 09:55:25 2016 Thierry LEVISSE
*/

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
}
