/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editeur.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:21:37 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:41:24 by nrivoire    ###    #+. /#+    ###.fr     */
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

/*
** -----------------------------TGA_PARSER----------------------------
*/

typedef struct		s_header
{
	char			idlength;
	char			colourmaptype;
	char			datatypecode;
	short int		colourmaporigin;
	short int		colourmaplength;
	char			colourmapdepth;
	short int		x_origin;
	short int		y_origin;
	unsigned int	width;
	unsigned int	height;
	char			bitsperpixel;
	char			imagedescriptor;
}					t_header;

typedef struct		s_px
{
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8			a;
}					t_px;

typedef struct		s_tga
{
	t_header		h;
	t_px			*px;
}					t_tga;

char				*get_chunk(char chunk);
t_px				*save_tga_rgba(int fd, t_px *px, t_header h, int byte_s);
t_px				*invert_order_px(t_tga *tga);
void				swap_rgba(t_px *left, t_px *right);
void				mirror(t_tga *tga, int w, int h);

t_tga				*tga_parser(char *img);

/*
** -----------------------------EDITEUR---------------------------------
*/

typedef struct		s_draw_circle
{
	int				x;
	int				y;
}					t_draw_circle;

/*
** -----------------------------DRAWLINE---------------------------------
*/

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
	int				tmp;
	SDL_Surface		*wall[8];
	SDL_Surface		*floor[2];
	SDL_Surface		*img[6];
	t_tga			*tga[2];
}					t_env;

/*
** ----------------------------------------------------------------------
*/

/*
** --draw_tools--
*/
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				pixel_put(t_env *v, int x, int y, t_rgb color);
void				drawline(t_point m1, t_point m2, t_rgb color, t_env *v);

/*
** --background--
*/
void				background_map(t_env *v);
void				background_menu(t_env *v);

/*
** --events--
*/
void				choose_the_size_of_your_map(t_env *v, SDL_Event e);
void				button_down(SDL_Event e, t_env *v);
void				button_window(SDL_Event e, t_env *v);
int					button_is_between(SDL_Event e, t_between b);
void				init_button(t_env *v, SDL_Event e);
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
int					key_event(const Uint8 *keyboard_state);

/*
** --draw_form--
*/
void				draw_void_circle(t_env *v, int x, int y, int radius);
void				draw_full_circle(t_env *v, int x, int y, int radius);
void				draw_form_cube(t_env *v, t_start start, int size,
		t_rgb color);
void				draw_diagonal_d(t_env *v, int x, int y, int size);
void				draw_diagonal_g(t_env *v, int x, int y, int size);
void				draw_horizontal_wall(t_env *v, int x, int y, int size);
void				draw_vertical_wall(t_env *v, int x, int y, int size);
void				put_picture(t_env *v, t_start start, int size,
		SDL_Surface *sur);
void				make_picture_tga(t_env *v, t_start start, int size,
		t_tga *tga);

/*
** --display_pro_frame--
*/
void				make_grid_pattern(t_env *v, SDL_Event event);
void				menu_text(t_env *v);
void				menu_button(t_env *v);
void				draw_in_grid_pattern(t_env *v);
void				show_tex(t_env *v, SDL_Event e);
void				choose_one_tex(t_env *v, int chosen);
void				choosing_cube_tex_2(t_env *v);
void				choosing_cube_tex(t_env *v);
void				open_window(t_env *v);

/*
** --write--
*/
SDL_Surface			*write_text(char *text, int size_font);
void				put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y);

/*
** --make_map--
*/
void				make_map(t_env *v);

/*
** --main--
*/
void				free_env(t_env *v);
void				free_tab(t_env *v, t_map **tab);
void				display(t_env *v);

#endif
