/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editeur.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:21:37 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 17:22:02 by nrivoire    ###    #+. /#+    ###.fr     */
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
# include "../../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include "../../frameworks/SDL2_net.framework/Headers/SDL_net.h"

# define WIDTH 1200
# define HEIGHT 900
# define RADIUS 10
# define CASES 30

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

// typedef struct		s_lst
// {
// 	int				center_x;
// 	int				center_y;
// 	int				over;
// 	int				etat;
// 	int				select;
// 	int				seg;
// 	struct s_lst	*next;
// }					t_lst;

typedef struct		s_map
{
	int				case_x;
	int				case_y;
}					t_map;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		e;
	SDL_Texture		*back;
	t_draw_circle	center;
	//t_lst			*point;
	t_map			**tab;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

/*
** --events--
*/
void			mouse_button_event(SDL_Event event, t_env *v);
void			mouse_motion_event(SDL_Event event, t_env *v);
int				key_event(const Uint8 *keyboard_state, t_env *v);

/*
** --draw--
*/
void			pixel_put(t_env *v, int x, int y, t_rgb color);
t_point			make_point(int x, int y);
t_rgb			make_rgb(int r, int g, int b, int a);
void			drawline(t_point m1, t_point m2, t_rgb color, t_env *v);
void			draw_void_circle(t_env *v, int x, int y, t_rgb color);
void			draw_full_circle(t_env *v, int x, int y, t_rgb color);

/*
** --main--
*/
//void			new_elem_lst(t_lst **elem, int x, int y);
void			display(t_env *v);

#endif
