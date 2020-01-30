/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editeur.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:21:37 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:02:34 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITEUR_H
# define EDITEUR_H

# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include "../../frameworks/SDL2.framework/Versions/A/Headers/SDL.h"
# include "../../frameworks/SDL2.framework/Versions/A/Headers/SDL_surface.h"
# include "../../frameworks/SDL2.framework/Versions/A/Headers/SDL_video.h"
# include "../../frameworks/SDL2.framework/Versions/A/Headers/SDL_render.h"
# include "../../frameworks/SDL2.framework/Versions/A/Headers/SDL_pixels.h"
# include "../../frameworks/SDL2.framework/Versions/A/Headers/SDL_events.h"
# include "../../frameworks/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"
# include "../../frameworks/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
# include "tga_parser.h"

/*
** -----------------------------EDITEUR---------------------------------
*/

typedef struct		s_draw_circle
{
	int				x;
	int				y;
}					t_draw_circle;

/*-----------------------------DRAWLINE-------------------------------*/

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_bressen
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bressen;


/*
** -----------------------------ENVIRONNEMENT----------------------------
*/

typedef struct		s_tex
{
	int				est;
	int				sud;
	int				nord;
	int				ouest;
	int				flat_wall;
	int				pillar;
}					t_tex;

typedef struct		s_map
{
	int				case_x;
	int				case_y;
	int				form;
	t_tex			texture;
}					t_map;

typedef struct		s_start
{
	int				x;
	int				y;
}					t_start;

typedef struct		s_between
{
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
}					t_between;

typedef struct		s_stretch
{
	int				x;
	int				y;
	int				dir_x;
	int				dir_y;
}					t_stretch;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*sur;
	SDL_Texture		*tex;
	t_draw_circle	center;
	t_map			**tab;
	t_stretch		s;
	t_tex			chosen_tex;
	int				form;
	int				cases;
	int				spawn_count;
	Uint32			*pixels;
	int				h;
	int				w;
	int				window;
	int				nb_wall;
	int				motion;
	int				button;
	int				valid;
	int				plus;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

/*
** --draw_tools--
*/
Uint32			get_pixel(SDL_Surface *surface, int x, int y);
void			pixel_put(t_env *v, int x, int y, t_rgb color);
t_point			make_point(int x, int y);
void			drawline(t_point m1, t_point m2, t_rgb color, t_env *v);

/*
** --background--
*/
void			background_map(t_env *v);
void			background_menu(t_env *v);

/*
** --events--
*/
int				button_is_between(SDL_Event e, t_between b);
void		    init_button(t_env *v, SDL_Event e);
void			mouse_button_event(SDL_Event event, t_env *v);
void			mouse_motion_event(SDL_Event event, t_env *v);
int				key_event(const Uint8 *keyboard_state);

/*
** --draw_form--
*/
void			draw_void_circle(t_env *v, int x, int y, int radius);
void			draw_full_circle(t_env *v, int x, int y, int radius);
void			draw_form_cube(t_env *v, t_start start, int size, t_rgb color);
void			draw_diagonal_d(t_env *v, int x, int y, int size);
void			draw_diagonal_g(t_env *v, int x, int y, int size);
void			draw_horizontal_wall(t_env *v, int x, int y, int size);
void			draw_vertical_wall(t_env *v, int x, int y, int size);
void            put_picture(t_env *v, t_start start, int size, char *picture);
void			make_picture_tga(t_env *v, t_start start, int size, char *pic);

/*
** --display_pro_frame--
*/
void			make_grid_pattern(t_env *v, SDL_Event event);
void			menu_text(t_env *v);
void			menu_button(t_env *v);
void			draw_in_grid_pattern(t_env *v);
void			open_window(t_env *v);

/*
** --write--
*/
SDL_Surface		*write_text(char *text, int size_font);
void			put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y);

/*
** --make_map--
*/
void			free_tab(t_env *v, t_map **tab);
void			make_map(t_env *v);

/*
** --main--
*/
void			display(t_env *v);

#endif
