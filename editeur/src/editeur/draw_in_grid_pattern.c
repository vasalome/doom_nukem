/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_in_grid_pattern.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 11:55:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 12:23:29 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static void		choose_your_form_from_1_to_9(t_env *v, int g, int t)
{
	int			x;
	int			y;
	t_start		s;

	x = g * v->cases;
	y = t * v->cases;
	s = (t_start){x + 5, y + 5};
	if (v->tab[t][g].form == 1)
		draw_form_cube(v, s, v->cases - 10, (t_rgb){0, 0, 153, 255});
	if (v->tab[t][g].form == 2)
		draw_horizontal_wall(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 3)
		draw_vertical_wall(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 4)
		draw_diagonal_d(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 5)
		draw_diagonal_g(v, x + 5, y + 5, v->cases - 10);
	if (v->tab[t][g].form == 6)
		draw_void_circle(v, x + v->cases / 2, y + v->cases / 2, v->cases / 3);
	if (v->tab[t][g].form == 7)
		put_picture(v, s, v->cases - 7, "./src/img/door.xpm");
	if (v->tab[t][g].form == 8)
		put_picture(v, s, v->cases - 7, "./src/img/stickman.xpm");
	if (v->tab[t][g].form == 9)
		v->tab[t][g].form = 0;
}

char			*img(int ori)
{
	char		*str;

	str = ft_strjoin(ft_strjoin("./src/tex/wall", ft_itoa(ori)),".xpm");
	return (str);
}

void			show_tex_cube(t_env *v, t_start s, int t, int g)
{
	int			i;
	int			j;

	j = s.y - 1;
	while (++j < s.y + 100)
	{
		i = s.x - 1;
		while (++i < s.x + 100)
			pixel_put(v, i, j, (t_rgb){179, 179, 179, 255});
	}
	put_text(v, write_text("est", 7), s.x + 21, s.y + 6);
	put_picture(v, (t_start){s.x + 14, s.y + 15}, 27,
			img(v->tab[t][g].texture.est));
	put_text(v, write_text("sud", 7), s.x + 68, s.y + 6);
	put_picture(v, (t_start){s.x + 62, s.y + 15}, 27,
			img(v->tab[t][g].texture.sud));
	put_text(v, write_text("ouest", 7), s.x + 18, s.y + 55);
	put_picture(v, (t_start){s.x + 14, s.y + 63}, 27,
			img(v->tab[t][g].texture.ouest));
	put_text(v, write_text("nord", 7), s.x + 67, s.y + 55);
	put_picture(v, (t_start){s.x + 62, s.y + 63}, 27,
			img(v->tab[t][g].texture.nord));
}

void			show_flat_wall_tex(t_env *v, t_start s, int t, int g)
{
	int			i;
	int			j;

	j = s.y - 1;
	while (++j < s.y + 50)
	{
		i = s.x - 1;
		while (++i < s.x + 50)
			pixel_put(v, i, j, (t_rgb){179, 179, 179, 255});
	}
	put_text(v, write_text("texture", 7), s.x + 10, s.y + 4);
	if (v->tab[t][g].form > 1 && v->tab[t][g].form < 6)
		put_picture(v, (t_start){s.x + 11, s.y + 15}, 29,
				img(v->tab[t][g].texture.flat_wall));
	else if (v->tab[t][g].form > 1 && v->tab[t][g].form == 6)
		put_picture(v, (t_start){s.x + 11, s.y + 15}, 29,
				img(v->tab[t][g].texture.pillar));
}

void			draw_in_grid_pattern(t_env *v, SDL_Event event)
{
	int			g;
	int			t;

	t = -1;
	while (++t < v->h / v->cases)
	{
		g = -1;
		while (++g < (v->w - v->cases * 7) / v->cases)
			if (v->tab[t][g].form != 0)
			{
				choose_your_form_from_1_to_9(v, g, t);
				if (event.motion.x / v->cases == g && event.motion.y / v->cases == t)
				{
					if (v->tab[t][g].form == 1)
						show_tex_cube(v, (t_start){v->w - (v->w - 30 * (g + 1)), v->h - (v->h - 30 * (t + 1))}, t, g);
					if (v->tab[t][g].form > 1 && v->tab[t][g].form < 7)
						show_flat_wall_tex(v, (t_start){v->w - (v->w - 30 * (g + 1)), v->h - (v->h - 30 * (t + 1))}, t, g);
				}
			}
	}
}
