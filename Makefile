##
## Makefile for Wol3d in /media/thierry/leviss_t/rendu/FDF2
##
## Made by Thierry LEVISSE
## Login   <thierry@epitech.net>
##
## Started on Thu Dec 17 01:38:42 2015 Thierry LEVISSE
## Last update Thu Jan  7 10:49:10 2016 Thierry LEVISSE
##


NAME1	=	wolf3d

LIB	=	-L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm

CFLAGS	=	-Wall -W -Werror -pedantic \
		-I/home/${USER}/.froot/include/ \
		-I./src/include \
		-I./ressources

SRC1	=	src/wolf3d.c \
		src/malloc.c \
		src/wall_1.c \
		src/wall_2.c \
		src/wall_3.c \
		src/misc.c \
		src/checking.c \
		src/basic_tools/ini.c \
		src/basic_tools/xpm.c \
		src/basic_tools/hexa_2octets.c \
		src/basic_tools/key.c \
		src/basic_tools/my_strcpy.c \
		src/drawing_tools/tekpixel.c

OBJ1	=	$(SRC1:.c=.o)

CC	=	gcc

RM	=	rm -f

all:		$(NAME1)
$(NAME1):	$(OBJ1)
		$(CC) $(OBJ1) $(LIB) -o $(NAME1)

clean:
		$(RM) $(OBJ1)

fclean:		clean
		$(RM) $(NAME1)

re:		fclean all
