/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_wall.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:22:18 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 14:29:40 by vasalome    ###    #+. /#+    ###.fr     */
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

	y = -1;
	tex_y = 0;
	info->fps.pixels = info->fps.tmp;
	while (++y <= draw_start)
		info->fps.pixels[y * WIDTH + x] = SDL_MapRGBA(info->fps.format, 200, 0, 0, 255);
	while (++draw_start <= draw_end)
	{
		d = draw_start * 256 - info->win.h * 128 + info->wall.line_height * 128;
		tex_y = ((d * info->wt[info->w_j].img->h) / info->wall.line_height) / 256;
		draw_wall_plus(x, draw_start, info, tex_y);
	}
	y = draw_start - 5;
	while (++y < info->win.h)
	{
		info->fps.pixels[y * WIDTH + x] = SDL_MapRGBA(info->fps.format, 75, 75, 75, 255);
		/*info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;*/
	}

	
	//SDL_UpdateTexture(info->fps.texture2, NULL, info->fps.pixels, sizeof(Uint32) * HEIGHT);
}
