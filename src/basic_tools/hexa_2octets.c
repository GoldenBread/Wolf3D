/*
** hexa_2octets.c for wolf3d in /home/thierry/Rendu/hexa
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Wed Jan  6 17:03:46 2016 Thierry LEVISSE
** Last update Thu Jan  7 11:01:55 2016 Thierry LEVISSE
*/

#include	<math.h>
#include	"my.h"

unsigned int	dec_to_hex_2(char interm[7])
{
  unsigned int	result;

  interm[6] = '\0';
  result = interm[1] * pow(16, 0);
  result += interm[0] * pow(16, 1);
  result += interm[3] * pow(16, 2);
  result += interm[2] * pow(16, 3);
  result += interm[5] * pow(16, 4);
  result += interm[4] * pow(16, 5);
  return (result);
}

unsigned int	dec_to_hex_lapin(char *str)
{
  char		base[2][17];
  int		i[2];
  char		interm[7];

  my_strcpy(base[0], "0123456789ABCDEF");
  base[0][16] = '\0';
  i[0] = 0;
  while (i[0] < 16)
    {
      base[1][i[0]] = i[0];
      i[0]++;
    }
  i[0] = 0;
  while (i[0] < 6)
    {
      i[1] = 0;
      while (i[1] < 16)
	{
	  if (str[i[0]] == base[0][i[1]])
	    interm[i[0]] = base[1][i[1]];
	  i[1]++;
	}
      i[0]++;
    }
  return (dec_to_hex_2(interm));
}
