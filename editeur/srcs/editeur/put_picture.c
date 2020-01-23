/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_picture.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:22:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 11:47:42 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

void			put_picture(t_env *v, t_start start, int size, char *picture)
{
	SDL_Rect	pos;

	pos.x = start.x;
	pos.y = start.y;
	pos.w = size;
	pos.h = size;
	if (!(v->sur = IMG_Load(picture)))
		ft_error((char*)SDL_GetError());
	v->spawn = SDL_CreateTextureFromSurface(v->ren, v->sur);
	SDL_FreeSurface(v->sur);
	SDL_RenderCopy(v->ren, v->spawn, NULL, &pos);
	SDL_DestroyTexture(v->spawn);
}
