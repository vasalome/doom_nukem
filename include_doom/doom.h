/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:02:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:55:00 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <time.h>
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL_thread.h>
# include <SDL_timer.h>
# include <SDL2_ttf/SDL_ttf.h>

# define SKY 3.14159265
# define WIDTH 1600
# define HEIGHT 900

typedef	struct		s_intersect
{
	double			p0x;
	double			p0y;
	double			p1x;
	double			p1y;
	double			p2x;
	double			p2y;
	double			p3x;
	double			p3y;
	double			x;
	double			y;
}					t_inter;

typedef struct		s_fillmap
{
	int				fd;
	char			*line;
	int				i;
	int				x;
	int				y;
	int				j;
}					t_fillmap;

typedef struct		s_setmap
{
	int				fd;
	char			*line;
	int				h;
	int				w;
	int				tmp;
	int				tp;
}					t_setmap;

typedef struct		s_tex
{
	SDL_Texture		*texture;
	SDL_Texture		*texture2;
	SDL_Texture		*texture3;
	SDL_PixelFormat *format;
	void			*tmp;
	int				pitch;
	Uint32			*pixels;
	SDL_Surface		*img;
	//char			*data;
	//int				bpp;
	//int				sizeline;
	//int				endian;
	int				xhud;
	int				yhud;
	int				tex_x;
	int				tex_y;
	SDL_Rect		rect;
}					t_tex;

typedef struct		s_ray
{
	double			x_ray_position;
	double			y_ray_position;
	double			x_ray_direction;
	double			y_ray_direction;
	double			x_side_distance;
	double			y_side_distance;
	double			x_delta_distance;
	double			y_delta_distance;
	double			intersectDist1;
	double			intersectDist2;
}					t_ray;

typedef struct		s_player
{
	double			x_camera;
	double			height;
	double			x_pos;
	double			y_pos;
	double			x_old_position;
	double			y_old_position;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_old_direction;
	double			x_old_plane;
	double			move_speed;
	double			turn_rate;
	double			turn_rate_y;
	int				turn_right;
	int				turn_left;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	double			fov;
	int				tp[9999];
	int				tp_index;
	int				life;
	int				backup;
	int				hit;
	int				can_trap;

	// test animation head
	int				head;
	
	//test collision
	double			x_bef;
	double			y_bef;
	double			x_save;
	double			y_save;
	double			x_lim;
	double			y_lim;
}					t_player;

typedef	struct		s_form
{
	int				wall;
	int				floorTexId;
	int				ceilTexId;
	int				n_tex;
	int				e_tex;
	int				s_tex;
	int				w_tex;
	double			wall_h;
	int				tp_x;
	int				tp_y;
	int				tp;
	int				clip;
	int				sp;
}					t_form;

typedef struct		s_map
{
	int				x;
	int				y;
	int				x_step;
	int				y_step;
	int				hit;
	int				width;
	int				height;
	double			x_spawn;
	double			y_spawn;
	double			xOffset;
	double			yOffset;
	char			*name;
	t_form			**map;
	int				**door_state;
	double			**door_offset;
}					t_map;

typedef struct		s_wall
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				side;
	int				color;
	int				r;
	int				g;
	int				b;
	int				a;
	double			wall_distance;
	double			floor_distance;
	int				x;
	double			wall_x;
	double			floor_x;
	int				trap;
	int				alpha;
}					t_wall;

typedef struct		s_item
{
	SDL_Surface		*img;
	int				w;
	int				h;
	SDL_Rect		rect;
	SDL_Surface		*icon;
	SDL_Texture		*texture;/*
	int				iconx;
	int				icony;*/
	int				weapon;
	int				key;
	int				ammo;
	int				reload;
	int				hp; // healthpack
}					t_item;

typedef	struct			s_floor
{
	double			dist;
	double			weight;
	double			currentFloorX;
	double			currentFloorY;
	int				floorTexX;
	int				floorTexY;
	double			floorXWall;
	double			floorYWall;
	int				side;
	int				texId;
	int				texId2;
}					t_floor;

/*
** ----------------------------------------------------------------------
*/

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_start
{
	int				x;
	int				y;
}					t_start;

typedef struct		s_size
{
	int				x;
	int				y;
}					t_size;

typedef struct		s_win
{
	SDL_Renderer	*ren;
	SDL_Window		*win;
	int				w;
	int				h;
}					t_win;

typedef struct		s_info
{
	t_tex			tex;
	t_ray			ray;
	t_map			map;
	t_wall			wall;
	t_item			item;
	t_tex			flash;
	t_floor			floor;
	int				w_i;
	int				w_j;
	int				shot;
	int				ten;
	int				i;
	int				ii;
	int				iii;
	int				quit;
	int				frame;
	SDL_Color 		rgb;
	SDL_Color 		rgbbis;
	int				action;
	char			use;
	int				min;
	int				door;
	double			delta_time;
	int				button;	
	int				game;	
	double			xOffsetMenu;
	double			yOffsetMenu;
	double			xrel;
	double			yrel;
	double			zoom;
	int				raycast;
	int				testHeight;

	t_tex			fps;

	//
	t_win			win;
	SDL_Texture		*textu;
	// SDL_Texture		*texhud;
	Uint32			*pixels;
	SDL_Surface		*hud[20];
	SDL_Surface		*menu[3];
	t_item			wp[11];
	SDL_Surface		*pistol[3];
	t_tex			wt[31];
	SDL_Surface		*wall_tex[8];
	SDL_Surface		*floor_tex[2];
	SDL_Surface		*sky[4];
	t_player		player;
	int				tex_x;
}					t_info;

/*
** ----------------------------------------------------------------------
*/

/*
** put_text
*/
SDL_Surface			*write_text(char *text, int size_font);
SDL_Surface			*write_text_hud(char *text, int size_font);
void				put_text(t_info *v, SDL_Surface *sur, int s_x, int s_y);

/*
** ft_put_texture
*/
void				pixel_put(t_info *v, int x, int y, t_rgb color);
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				ft_error(char *str);
void				put_texture(t_info *v, t_start s, t_size size, SDL_Surface *sur);

/*
** events
*/
void				mouse_wheel_event(t_info *info, SDL_Event event);
void		    	mouse_motion_event(t_info *info, SDL_Event event);
void				mouse_button_up(t_info *info, SDL_Event event);
void				mouse_button_down(t_info *info, SDL_Event event);
void				key_up(t_info *info, const Uint8 *keyboard_state);
void				key_down(t_info *info, const Uint8 *keyboard_state);

void				display_doom(t_info *info);

/*
** ----------------------------------------------------------------------
*/

/*
** norminette ok
*/

/*
** srcs:			ft_init_texture.c
*/
void				init_textures(t_info *info);

/*
** srcs:			ft_init.c
*/
void				init_window(t_info *info);
void				load_textures(t_info *info);
void				init_map(t_info *info);
void				init_player(t_info *info);
void				init_doors(t_info *info);

/*
** ----------------------------------------------------------------------
*/

/*
** srcs:			ft_fill_map.c
*/

int					fill_map(t_info *info);
int					read_map(t_info *info, t_fillmap *fill);
void				fill_map_plus(t_fillmap *fill, t_info *info);

/*
** srcs:			ft_map.c
*/

int					create_map(t_info *info);
int					set_map_size(t_info *info);
void				count_width(t_setmap *set);

/*
** srcs:			ft_ray.c
*/

void				ray_casting_image(t_info *info);
void				its_a_trap(t_info *info);
int					threadAnim(void* data);
int					threadAnim2(void* data);
void				hud(t_info *info);
int					ray_casting(t_info *info);
void				ray_casting_init(t_info *info, int x);

/*
** srcs:			ft_wall.c
*/

void				wall_detection(t_info *info);
void				wall_detection_plus(t_info *info);
void				wall_detection_init_x(t_info *info);
void				wall_detection_init_y(t_info *info);
//void				create_img(t_info *info);

/*
** srcs:			ft_draw_wall.c
*/

void				draw_wall(int x, int draw_start, int draw_end,\
						t_info *info);
void				draw_wall_plus(int x, int draw_start,\
						t_info *info, int tex_y);

/*
** srcs:			ft_spawn.c
*/

int					get_spawn(t_info *info);

/*
** srcs:			ft_keys.c
*/

int					key_release(int key, t_info *info);
void				reset_weapon(t_info *info);
int					key_press(int keycode, t_info *info);
void				press_weapon(t_info *info);
void				press_weapon_2(t_info *info);

/*
** srcs:			ft_teleport.c
*/

void				tp_destination(t_fillmap *fill, t_info *info,\
						char *str, int *i);
void				tp_destination_2(t_info *info, char *str,\
						int *i, int x);
void				teleport(t_info *info);
void				teleport_2(t_info *info);

/*
** srcs:			ft_textures.c
*/

void				texture_calc(t_info *info);
void				choose_texture_1(t_info *info);
void				choose_texture_2(t_info *info);
//void				skybox(t_info *info);

/*
** srcs:			ft_gameover.c
*/

void				game_over(t_info *info);
//void				flash(t_info *info);
//void				create_flash(t_info *info);

/*
** srcs:			ft_usage.c
*/

int					f_exist(t_info *info);
int					ft_usage(char *error);

void				draw_skybox(t_info *info);

void				move_doors(t_info *info);
void				open_doors(t_info *info);

void				init_clip(t_info *info);

void	clip_10(t_info *info);
void	clip_12(t_info *info);

void	init_hud(t_info *info);
void	render_hud(t_info *info, SDL_Event *event);

void	info_hud(t_info *info);

void	reload(t_info *info);
void    init_items(t_info *info);
void	shot(t_info *info);

#endif
