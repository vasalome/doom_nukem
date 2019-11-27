/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_wall.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:22:18 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 16:51:43 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
   	int bpp = surface->format->BytesPerPixel;
    /*Here p is the address to the pixel we want to retrieve */
  	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp)
	{
		case 1:
			return *p;
			break;

		case 2:
			return *(Uint16 *)p;
			break;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;
				break;

			case 4:
				return *(Uint32 *)p;
				break;

			default:
				return 0;       /* shouldn't happen, but avoids warnings */
    }
}

int		threadAnim(void*	data)
{
	t_info *info = data;

	return (0);
}

//calc sol plafond
void	calc_floor_ceil(t_info *info, int idtext)
{
	info->floor.weight = info->floor.dist / info->wall.wall_distance2;
	
	info->floor.currentFloorX = info->floor.weight * info->floor.floorXWall + (1.0 - info->floor.weight) * info->player.x_pos;
	info->floor.currentFloorY = info->floor.weight * info->floor.floorYWall + (1.0 - info->floor.weight) * info->player.y_pos;
	
	info->floor.floorTexX = (int)(info->floor.currentFloorX * info->wt[idtext].img->w) % info->wt[idtext].img->w;
	info->floor.floorTexY = (int)(info->floor.currentFloorY * info->wt[idtext].img->h) % info->wt[idtext].img->h;

	//int test = ((int)(info->floor.currentFloorX) + (int)(info->floor.currentFloorY)) % 2;
	//printf("floorx = %d\n floory = %d\n\n", (int)(info->floor.currentFloorX), (int)(info->floor.currentFloorY));
	if (info->map.map[(int)(info->floor.currentFloorX)][(int)(info->floor.currentFloorY)] == '4')
		info->floor.texId = 16;
	else if (info->map.map[(int)(info->floor.currentFloorX)][(int)(info->floor.currentFloorY)] == '2')
		info->floor.texId = 1;
	else if (info->map.map[(int)(info->floor.currentFloorX)][(int)(info->floor.currentFloorY)] == '7')
		info->floor.texId = 16;
	else
		info->floor.texId = 17;
	//printf("%f\n", info->wall.wall_distance2);
}

void	draw_wall_plus(int x, int draw_start, t_info *info, int tex_y)
{

	Uint32 data = getpixel(info->wt[info->w_j].img, info->wt[info->w_j].tex_x , tex_y);
	SDL_GetRGB(data, info->wt[info->w_j].img->format, &info->rgb.r, &info->rgb.g, &info->rgb.b);
	//printf("%d  %d  %d\n", info->rgb.r, info->rgb.g, info->rgb.b);
	info->fps.pixels[draw_start * WIDTH + x] = SDL_MapRGBA(info->fps.format, info->rgb.r, info->rgb.g, info->rgb.b, 255);//(Uint32 *)info->wt[info->w_j].img->pixels[tex_y * info->wt[info->w_j].img->pitch + x * sizeof(Uint32 *)]; //info->wt[info->w_j].pixels[tex_y * info->wt[info->w_j].texture->w + info->wt[info->w_j].tex_x];
	//printf("test");
		//(char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 *\
		//info->wt[info->w_j].xhud * tex_y];
	//info->fps.data[x * 4 + 4 * WIDTH * draw_start + 1] =\
		//(char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 *\
		//info->wt[info->w_j].xhud * tex_y + 1];
	//info->fps.data[x * 4 + 4 * WIDTH * draw_start + 2] =\
		//(char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 *\
		//info->wt[info->w_j].xhud * tex_y + 2];
	//info->fps.data[x * 4 + 4 * WIDTH * draw_start + 3] = (char)0;
}

void	draw_wall(int x, int draw_start, int draw_end, t_info *info)
{
	int		y;
	int		d;
	int		tex_y;
	double	semiH = HEIGHT * 0.5;
	
	y = info->player.fov;
	tex_y = 0;
	info->fps.pixels = info->fps.tmp;
	//printf("%f\n", info->wall.wall_distance2);
	//orientation sol plafond
	if (info->wall.side2 == 0 && info->ray.x_ray_direction > 0)
	{
		info->floor.floorXWall = info->map.x;
		info->floor.floorYWall = info->map.y + info->wall.ux2;
	}
	else if (info->wall.side2 == 0 && info->ray.x_ray_direction < 0)
	{
		info->floor.floorXWall = info->map.x + 1;
		info->floor.floorYWall = info->map.y + info->wall.ux2;
	}
	else if (info->wall.side2 == 1 && info->ray.y_ray_direction > 0)
	{
		info->floor.floorXWall = info->map.x + info->wall.ux2;
		info->floor.floorYWall = info->map.y;
	}
	else
	{
		info->floor.floorXWall = info->map.x + info->wall.ux2;
		info->floor.floorYWall = info->map.y + 1;
	}

	if (info->floor.texId != 0)
		while (++y <= draw_start)
		{
			info->floor.dist = HEIGHT / (((semiH) - y) * 2);
			
			calc_floor_ceil(info, info->floor.texId);
			
			Uint32 data = getpixel(info->wt[info->floor.texId].img, info->floor.floorTexX, info->floor.floorTexY);
			SDL_GetRGB(data, info->wt[info->floor.texId].img->format, &info->rgb.r, &info->rgb.g, &info->rgb.b);
			
		
			info->fps.pixels[y * WIDTH + x] = SDL_MapRGBA(info->fps.format, info->rgb.r, info->rgb.g, info->rgb.b, 255);
		}
		//info->fps.pixels[y * WIDTH + x] = SDL_MapRGBA(info->fps.format, 200, 0, 0, 255);
	while (++draw_start <= draw_end)
	{
		d = draw_start * 256 - info->win.h * 128 + info->wall.line_height * 128;
		tex_y = ((d * info->wt[info->w_j].img->h) / info->wall.line_height) / 256;
		draw_wall_plus(x, draw_start, info, tex_y);
	}
	y = draw_end - 1;
	
	while (++y < HEIGHT)
	{
		info->floor.dist = HEIGHT / (2 * (y - (semiH)));
		
		calc_floor_ceil(info, 16);

		//printf("%d , %d\n", info->floor.floorTexX, info->floor.floorTexY);
		Uint32 data = getpixel(info->wt[16].img, info->floor.floorTexX, info->floor.floorTexY);
		
		SDL_GetRGB(data, info->wt[16].img->format, &info->rgb.r, &info->rgb.g, &info->rgb.b);
		info->fps.pixels[y * WIDTH + x] = SDL_MapRGBA(info->fps.format, info->rgb.r, info->rgb.g, info->rgb.b, 255);
		/*info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;*/
	}
	//SDL_UpdateTexture(info->fps.texture2, NULL, info->fps.pixels, sizeof(Uint32) * HEIGHT);
}
