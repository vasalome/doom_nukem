/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 16:45:42 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 16:46:32 by vasalome    ###    #+. /#+    ###.fr     */
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
	float			p0x;
	float			p0y;
	float			p1x;
	float			p1y;
	float			p2x;
	float			p2y;
	float			p3x;
	float			p3y;
	float			x;
	float			y;
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
	float			x_ray_position;
	float			y_ray_position;
	float			x_ray_direction;
	float			y_ray_direction;
	float			x_side_distance;
	float			y_side_distance;
	float			x_delta_distance;
	float			y_delta_distance;
	float			intersectDist1;
	float			intersectDist2;
}					t_ray;

typedef struct		s_player
{
	float			x_camera;
	float			height;
	float			x_pos;
	float			y_pos;
	float			x_old_position;
	float			y_old_position;
	float			x_dir;
	float			y_dir;
	float			x_plane;
	float			y_plane;
	float			x_old_direction;
	float			x_old_plane;
	float			move_speed;
	float			fov;
	int				tp[9999];
	int				tp_index;
	int				life;
	int				backup;
	int				hit;
	int				can_trap;

	// test animation head
	int				head;
	
	//test collision
	float			x_bef;
	float			y_bef;
	float			x_save;
	float			y_save;
	float			x_lim;
	float			y_lim;
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
	float			wall_h;
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
	float			x_spawn;
	float			y_spawn;
	float			xOffset;
	float			yOffset;
	char			*name;
	t_form			**map;
	int				**door_state;
	float			**door_offset;
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
	float			wall_distance;
	float			floor_distance;
	int				x;
	float			wall_x;
	float			floor_x;
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
	int				hp;
	int				info_hp;
	int				kick;
}					t_item;

typedef	struct			s_floor
{
	float			dist;
	float			weight;
	float			currentFloorX;
	float			currentFloorY;
	int				floorTexX;
	int				floorTexY;
	float			floorXWall;
	float			floorYWall;
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

typedef struct		s_pillar
{
	float			p1x;
	float			p1y;
	float			p2x;
	float			p2y;
	float			scx;
	float			scy;
	float			rayon;
}					t_pillar;

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
	float			delta_time;
	int				button;	
	int				game;	
	float			xOffsetMenu;
	float			yOffsetMenu;
	float			xrel;
	float			yrel;
	float			zoom;
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
	//SDL_Surface		*wall_tex[8];
	//SDL_Surface		*floor_tex[2];
	SDL_Surface		*sky[4];
	uint32_t		fps_now;

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
void				keys_mouvements(t_info *info, const Uint8 *keyboard_state);
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
** checker
*/

/*
** ft_init_texture.c
*/
void				init_textures(t_info *info);

/*
** ft_init.c
*/
void				init_window(t_info *info);
void				load_textures(t_info *info);
void				init_map(t_info *info);
void				init_player(t_info *info);
void				init_doors(t_info *info);

/*
** ft_draw_wall.c
*/
void				draw_wall(int x, int draw_start, int draw_end,
							t_info *info);
void				draw_wall_plus(int x, int draw_start,
							t_info *info, int tex_y);

/*
** make_pillar.c
*/
void				make_pillar(t_info *info);

/*
** make_flat_wall.c
*/
void				make_flat_wall_7(t_info *info);
void				make_flat_wall_8(t_info *info);

/*
** ----------------------------------------------------------------------
*/

/*
** srcs:			ft_ray.c
*/
void				its_a_trap(t_info *info);
int					threadAnim(void* data);
int					threadAnim2(void* data);
void				hud(t_info *info);
int					ray_casting(t_info *info);
void				ray_casting_init(t_info *info, int x);

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
** srcs:			ft_wall.c
*/

void				wall_detection(t_info *info);
void				wall_detection_plus(t_info *info);
void				wall_detection_init_x(t_info *info);
void				wall_detection_init_y(t_info *info);
//void				create_img(t_info *info);

/*
** srcs:			ft_spawn.c
*/
int					get_spawn(t_info *info);

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

void    put_weapon(t_info *info);
void    change_item(t_info *info);
void    omg_he_got_a_gun(t_info *i);
void    kick(t_info *i);

#endif
