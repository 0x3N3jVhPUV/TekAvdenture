##
## Makefile for  in /home/thomas.mikhail/tekadventure/thomas
## 
## Made by Thomas Mikhail
## Login   <thomas.mikhail@epitech.net>
## 
## Started on  Wed Sep 27 16:20:47 2017 Thomas Mikhail
## Last update Sat Oct  7 10:28:34 2017 andy afene mebaley
##

CC	=	gcc -g3

RM	=	rm -f

NAME	=	tekadventure

CFLAGS	=	-I./include -Wall -Wextra -Werror

LIBS	=	 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRCS	=	./src/main.c\
		./src/display.c\
		./src/init_elements.c\
		./src/init_elements2.c\
		./src/init_base.c\
		./src/update.c\
		./src/update2.c\
		./src/update3.c\
		./src/collision.c\
		./src/update_cmd.c\
		./src/destroy.c\
		./src/destroy_bullet.c\
		./src/base_menu.c\
		./src/menu.c\
		./src/game_menu.c\
		./src/base.c\
		./src/base2.c\
		./src/debug.c\
		./src/score.c\
		./src/music.c\
		./src/str.c\
		./src/my_free.c\
		./src/getnextline.c\
		./src/push_front_list.c

OBJS	=	$(SRCS:.c=.o)

all:			$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LIBS) $(CFLAGS) 

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean all re
