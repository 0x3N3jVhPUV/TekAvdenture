/*
** new.h for  in /home/thomas.mikhail/tekadventure
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 21:35:31 2017 Thomas Mikhail
** Last update Sat Oct  7 11:08:42 2017 Thomas Mikhail
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <SFML/Audio.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define GAME_NAME "GALAMUS"
# define BACKGROUND "data/ra.png"
# define BACKGROUND2 "data/ra2.png"
# define BACKGROUND3 "data/cloud2.png"
# define BACKGROUND4 "data/cloud2.png"
# define BACKGROUND5 "data/cloud2.png"
# define BULLET "data/plasma.png"
# define PLAYER "data/explosion.png"
# define PLAYER2 "data/rocket.png"
# define START "data/glowtube2.png"
# define EXIT "data/glowtube.png"
# define FONT "data/8bit.ttf"
# define SHIP "data/ship2.png"
# define ASTE "data/redplanet2.png"
# define EXP "data/lexplosion.flac"
# define MUS "data/rise_of_space.flac"

# define NOARG "Error : No argument\n"
# define TOOARG "Error : Too much arguments\n"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define SPEED 10

typedef struct		s_score
{
  sfFont		*font;
  sfText		*best;
  sfText		*score;
  sfVector2f		pos_best;
  sfVector2f		pos_score;
  int			nb;
}			t_score;

typedef struct		s_menu
{
  sfFont		*font;
  sfText		*start;
  sfText		*exit;
  sfText		*title;
  sfVector2f		pos_title;
  sfVector2f		pos_start;
  int			choice_start;
  int			choice_exit;
  sfVector2f		pos_exit;
}			t_menu;

typedef struct		s_bullet
{
  int			i;
  int			dead;
  size_t		compt;
  sfSprite		*sprite;
  sfTexture		*texture;
  sfVector2f		pos;
  sfVector2f		cvelocity;
  float			maxspeed;
  struct s_bullet	*next;
}			t_bullet;

typedef struct		s_mouse
{
  double		x;
  double		y;
  sfVector2i		point;
  float			angle;
  sfVector2i		m;
  sfVector2f		aim;
  sfVector2f		aimnorm;
  sfVector2i		poswind;
}			t_mouse;

typedef struct	s_ship
{
  float		x;
  float		y;
  float		stype;
  sfSprite	*sprite;
  sfTexture	*texture;
  t_bullet	*bullets;
  int		spr_count_t;
  int		spr_count_r;
  int		spr_count_s;
  int		spr;
  int		nb_bullets;
  sfVector2i	a;
  sfVector2i	b;
  int		i;
  int		dead;
  int		att_speed;
}		t_ship;

typedef struct	s_elem
{
  int		i;
  float		x;
  float		y;
  sfSprite	*sprite;
  sfTexture	*texture;
  float		type;
  float		stype;
  float		hp;
  float		dmg;
  int		dead;
  sfVector2i	a;
  sfVector2i	b;
  int		spr_count_s;
  int		spr_count_t;
  int		spr_count_q;
  int		spr_count_r;
  int		spr;
  int		fire;
  struct s_elem	*next;
}		t_elem;

typedef struct		s_disp
{
  char			*scrolling_object;
  char			*bullet;
  char			*back;
  char			*str;
  int			fd;
  int			i;
   int			spr_count_q;
  int			spr_count_r;
  int			spr_count_s;
  int			spr_count_t;
  int			rst1;
  int			fire;
  int			nbr_kill;
  int			boss;
  t_ship		*ship;
  t_elem		*elems;
  float			bmaxspeed;
  sfView		*view;
  sfMusic		*explo;
  sfMusic		*melo;
  sfVector2f		playerpos;
  sfVector2f		playerctr;
  t_mouse		*mouse;
  sfRenderWindow	*window;
  t_bullet		*bullets;
  t_score		*score;
  int			start;
  int			boom;
  int			best;
  int			j;
  sfEvent		*event;
}			t_disp;


sfVector2i	vector2i(int x, int y);
sfVector2f	vector2f(float x, float y);
sfRenderWindow	*create_window(char *name, int width, int height);
sfSprite	*cut_sprite(sfSprite *d, sfVector2i a, sfVector2i b, sfVector2i c);

sfView		*init_view(sfRenderWindow *window);

sfSprite	*init_sprite_bullet(char *path, t_bullet *elem);
sfSprite	*init_sprite_ship(char *path, t_ship *elem);
sfSprite	*init_sprite(char *path, t_elem *elem);

t_elem          *init_explosions(float x, float y, char *path, float stype);
t_elem		*init_enemies(float x, float y, char *path, float stype);
t_ship	        *init_ship(float x, float y, char *path, float stype);
t_elem	        *init_cloud(float x, float y, char *path, float stype);
t_elem	        *init_back(float x, float y, char *path, float stype);
t_disp	        *init_disp(char *name, int width, int height);

t_disp	        *init_level_one(t_disp *disp);

void		level_one_loop(t_disp *disp);

t_bullet	*update_mouse_click(t_disp *disp, t_bullet *bullet);
void	update_mouse_pos(t_disp *disp, sfRenderWindow *window);

t_bullet	*update_cmd(t_disp *d);
void	update_keys(t_ship *ship);

t_bullet	*update_all(t_disp *disp);
void	update_animation(t_elem *elems);
void	update_cloud(t_elem *cloud);
void	update_back(t_elem *back, t_disp *disp);
t_bullet	*update_enemies(t_elem *enemies, t_bullet *bullet, t_disp *disp);
void	update_bullets(t_bullet *bullets);

sfSprite	*update_sprite_ship(t_ship *ship, t_disp *disp);
sfSprite        *update_sprite_enemies_ship(t_elem *ship);
sfSprite        *update_sprite_explosion(t_elem *enemies_ship, t_disp *disp);

void	display_bullets_en(t_bullet *bullet, sfRenderWindow *window);
void	display_explosions(t_elem *en, sfRenderWindow *window);
void	display_enemies(t_elem *en, sfRenderWindow *window);
void	display_bullets(t_bullet *bullets, sfRenderWindow *window);
void	display_back(t_elem *back, sfRenderWindow *window);
void	display_cloud(t_elem *cloud, sfRenderWindow *window, float stype);
void	display_ship(t_ship *ship, sfRenderWindow *window, float stype);
void	display_all(t_disp *disp);
t_elem	*push_frt(t_elem *elem, t_elem *root);

void	spawn_enemies(t_disp *disp);
void	check_collision(t_disp *disp);
int	check_player_collision(t_disp *disp);
int	collision_player(t_disp *disp);
void	destroy_elements(t_disp *disp);
void	destroy_bullets(t_disp *disp);
void	destroy_bullets_en(t_disp *disp);
void	destroy_enemies(t_disp *disp);
void	destroy_player(t_disp *disp);

t_bullet	*delete_bullets_en(t_bullet *tmp, t_bullet *prev, t_disp *disp);
t_elem		*delete_enemies(t_elem *tmp, t_elem *prev, t_disp *disp);
t_bullet	*delete_bullets(t_bullet *tmp, t_bullet *prev, t_disp *disp);
t_bullet	*push_frtbls(t_bullet *bullet, t_bullet *root);

void	semifree_disp(t_disp *disp, t_menu *menu);
void	free_disp(t_disp *disp);
void	free_ship(t_ship *ship);
void	print_objects_debug(t_disp *disp);

void	update_anim_ship(t_disp *disp);
t_elem	*update_explosion(t_ship *ship);
void	init_dispmainmenu(t_disp *disp);
void	choice_mainmenu(t_disp *disp, t_menu *menu);
void	display_mainmenu(t_disp *disp, t_menu *menu, int choice);
t_menu	*init_mainmenu(char *start, char *exit);
void	init_titlemenu(char *str, t_menu *menu);
void	main_menu(t_disp *disp);
int	check_choice(t_disp *disp, t_menu *menu);
void	mouse_menu(t_disp *d);

int	choice_retrymenu(t_disp *disp, t_menu *menu, int end);
int     choice_gamemenu(t_disp *disp, t_menu *menu, int end);
void    menu_game(t_disp *disp);
void	menu_retry(t_disp *disp);
t_bullet	*create_bullet(t_bullet *bullet, t_elem *elem);
void		update_enemies_bullets(t_bullet *bullets);
void		update_explostion_ship(t_ship *ship);
void		update_animation_test(t_ship *ship);
void		free_bullets(t_disp *disp);
t_bullet	*create_bullet_big(t_bullet *bullets, t_elem *elem, t_disp *disp);

t_score	*init_score(t_disp *disp);
void	display_score(t_disp *disp, t_score *score);
char	*int_to_str(int nbr);
char	*my_str_cat(char *str, char *s);
void	my_putnbr(int nb, char *s, int size);
int	my_strlen(char *s);

void		play_explosion(t_disp *disp);
int             check_ini(char *str, t_disp *disp);
char            *get_next_line(const int fd);
int             my_strncmp(char *str, char *str2, int n);

#endif
