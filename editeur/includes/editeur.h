/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editeur.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:21:37 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:18:03 by nrivoire    ###    #+. /#+    ###.fr     */
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

# define WIDTH 1200
# define HEIGHT 900

/*
** -----------------------------EDITEUR---------------------------------
*/

typedef struct	s_draw_circle
{
	int			x;
	int			y;
}				t_draw_circle;

/*-----------------------------DRAWLINE-------------------------------*/

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_rgb;

typedef struct	s_bressen
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_bressen;


/*
** -----------------------------ENVIRONNEMENT----------------------------
*/

typedef struct		s_map
{
	int				case_x;
	int				case_y;
	int				form;
}					t_map;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*sur;
	SDL_Event		e;
	SDL_Texture		*back;
	SDL_Texture		*back_menu;
	SDL_Texture		*text;
	SDL_Texture		*spawn;
	SDL_Texture		*door;
	t_draw_circle	center;
	t_map			**tab;
	int				form;
	int				cases;
	int				spawn_count;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

/*
** --events--
*/
void			background_map(t_env *v);
void			background_menu(t_env *v);

void			mouse_button_event(SDL_Event event, t_env *v);
void			mouse_motion_event(SDL_Event event, t_env *v);
int				key_event(const Uint8 *keyboard_state);

/*
** --draw_form--
*/
void			draw_void_circle(t_env *v, int x, int y, int radius);
void			draw_full_circle(t_env *v, int x, int y, int radius);
void			draw_form_cube(t_env *v, int start_x, int start_y, int size);
void            put_picture(t_env *v, int start_x, int start_y, int size, char *picture);
void			draw_diagonal_d(t_env *v, int x, int y, int size);
void			draw_diagonal_g(t_env *v, int x, int y, int size);
void			draw_horizontal_wall(t_env *v, int x, int y, int size);
void			draw_vertical_wall(t_env *v, int x, int y, int size);

/*
** --draw--
*/
void			pixel_put(t_env *v, int x, int y, t_rgb color);
t_point			make_point(int x, int y);
t_rgb			make_rgb(int r, int g, int b, int a);
void			drawline(t_point m1, t_point m2, t_rgb color, t_env *v);
void			make_form_cube(t_env *v, int start_x, int start_y, int square);

/*
** --main--
*/
void			free_tab(t_env *v, t_map **tab);
void			make_map(t_env *v);
void			display(t_env *v);

#endif
