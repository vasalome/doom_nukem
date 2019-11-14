/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:02:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 15:43:13 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "../libft/includes/libft.h"
# include <Tk/X11/X.h>
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
# include <SDL2_mixer/SDL_mixer.h>




# define WIDTH 1600
# define HEIGHT 900

struct SDL_Texture
{
    const void *magic;
    Uint32 format;              /**< The pixel format of the texture */
    int access;                 /**< SDL_TextureAccess */
    int w;                      /**< The width of the texture */
    int h;                      /**< The height of the texture */
    int modMode;                /**< The texture modulation mode */
    SDL_BlendMode blendMode;    /**< The texture blend mode */
    Uint8 r, g, b, a;           /**< Texture modulation values */
 
    SDL_Renderer *renderer;
 
    /* Support for formats not supported directly by the renderer */
    SDL_Texture *native;
    void *yuv; // chez moiil connait pas la struture SDL_SW_YUVTexture 
    void *pixels;
    int pitch;
    SDL_Rect locked_rect;
 
    void *driverdata;           /**< Driver specific texture representation */
 
    SDL_Texture *prev;
    SDL_Texture *next;
};

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
}					t_ray;

typedef struct		s_player
{
	double			x_camera;
	int				height;
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
	int				can_trap;
}					t_player;

typedef struct		s_win
{
	int				w;
	int				h;
	SDL_Renderer	*renderer;
	SDL_Surface		*screen;
	SDL_Window		*win;
}					t_win;

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
	char			*name;
	char			**map;
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
	int				x;
	double			ux;
	int				trap;
}					t_wall;

typedef struct		s_weapon
{
	SDL_Surface		*img;
	int				w;
	int				h;
	SDL_Rect		rect;
	SDL_Surface		*icon;/*
	int				iconx;
	int				icony;*/
}					t_weapon;

typedef struct		s_music
{
	Mix_Music		*sound;
	Mix_Chunk		*scratch;
	Mix_Chunk		*high;
	Mix_Chunk		*medium;
	Mix_Chunk		*low;
}					t_music;

/*typedef struct		s_record
{
	const int		MAX_RECORDING_DEVICES = 10;
	const int 		MAX_RECORDING_SECONDS = 5;
	const int 		RECORDING_BUFFER_SECONDS = MAX_RECORDING_SECONDS + 1;
}					t_record;*/

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
}					t_floor;

typedef struct		s_info
{
	t_tex			tex;
	t_ray			ray;
	t_player		player;
	t_win			win;
	t_map			map;
	t_wall			wall;
	t_weapon		wp[11];
	t_weapon		head[10];
	t_weapon		img;
	t_tex			fps;
	t_tex			flash;
	t_tex			wt[30];
	t_music			music;
	t_floor			floor;
	//t_record		rec;
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
	int				action;
}					t_info;

/*
** srcs:			ft_init.c
*/

void				init(t_info *info);
void				init_window(t_info *info);
void				load_textures(t_info *info);
void				init_map(t_info *info);
void				init_player(t_info *info);

/*
** srcs:			ft_init_hub.c
*/

void				icon(t_info *info);
void				icon_2(t_info *info);
void				hub_life(t_info *info);

/*
** srcs:			ft_init_texture.c
*/

void				textures_wall_1(t_info *info);
void				textures_wall_2(t_info *info);
void				textures_door_1(t_info *info);
void				textures_door_2(t_info *info);
void				textures_floor(t_info *info);

/*
** srcs:			ft_init_weapon.c
*/

void				weapons(t_info *info);

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
void				create_img(t_info *info);

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
** srcs:			ft_move.c
*/

int					move(t_info *info);
void				move_plus_1(t_info *info);
void				move_plus_2(t_info *info);
void				turn_right(t_info *info);
void				turn_left(t_info *info);

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

int					red_cross(void);
int					f_exist(t_info *info);
int					ft_usage(char *error);

void				draw_skybox(t_info *info);

#endif
