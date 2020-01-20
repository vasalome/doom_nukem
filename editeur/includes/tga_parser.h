/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tga_parser.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 13:01:27 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TGA_PARSER_H
# define TGA_PARSER_H

# include "editeur.h"

/*
** -----------------------------TGA_PARSER----------------------------
*/

typedef struct		s_header
{
   char				idlength;
   char				colourmaptype;
   char				datatypecode;
   short int		colourmaporigin;
   short int		colourmaplength;
   char				colourmapdepth;
   short int		x_origin;
   short int		y_origin;
   unsigned int		width;
   unsigned int		height;
   char				bitsperpixel;
   char				imagedescriptor;
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

t_tga				*tga_parser(char *img);

#endif
