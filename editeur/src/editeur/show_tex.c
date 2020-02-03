/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show_tex.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 13:37:42 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 14:02:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/editeur.h"

static char		*img(int ori)
{
	char		*str;

	str = ft_strjoin(ft_strjoin("./src/tex/wall", ft_itoa(ori)), ".xpm");
	return (str);
}

static void		show_tex_cube(t_env *v, t_start s, int t, int g)
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

static void		show_flat_wall_tex(t_env *v, t_start s, int t, int g)
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

void			show_tex(t_env *v, SDL_Event e)
{
	int			t;
	int			g;

	t = -1;
	while (++t < v->h / v->cases)
	{
		g = -1;
		while (++g < (v->w - v->cases * 7) / v->cases)
			if (e.motion.x / v->cases == g && e.motion.y / v->cases == t &&
					v->tab[t][g].form != 0)
			{
				if (v->tab[t][g].form == 1)
					show_tex_cube(v, (t_start){v->w - (v->w - 30 * (g + 1)),
							v->h - (v->h - 30 * (t + 1))}, t, g);
				if (v->tab[t][g].form > 1 && v->tab[t][g].form < 7)
					show_flat_wall_tex(v, (t_start){v->w - (v->w - 30 *
							(g + 1)), v->h - (v->h - 30 * (t + 1))}, t, g);
			}
	}
}
