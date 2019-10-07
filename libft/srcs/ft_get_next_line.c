/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_next_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 15:50:20 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 18:45:41 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static void		ft_add_to_gnl_list(t_gnl **save, t_gnl *elem)
{
	t_gnl		*list;

	list = *save;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
}

static t_gnl	*ft_create_list(int fd)
{
	t_gnl		*list;

	if (!(list = (t_gnl*)malloc(sizeof(*list))))
		return (NULL);
	list->fd = fd;
	list->tempo = ft_strnew(0);
	list->text = NULL;
	list->next = NULL;
	return (list);
}

static t_gnl	*ft_fd(t_gnl *save, int fd)
{
	t_gnl		*tmp;
	t_gnl		*fd_list;

	tmp = NULL;
	fd_list = save;
	while (fd_list)
	{
		if (fd_list->fd == fd)
			return (fd_list);
		if (!(fd_list->next))
		{
			tmp = ft_create_list(fd);
			ft_add_to_gnl_list(&fd_list, tmp);
			return (tmp);
		}
		fd_list = fd_list->next;
	}
	return (NULL);
}

static int		ft_check(char *save, char **line)
{
	char		*end;

	if (!save)
		return (0);
	end = ft_strchr(save, '\n');
	if (end != NULL)
	{
		*end = '\0';
		if (!(*line = ft_strdup(save)))
			return (-1);
		ft_strncpy(save, &end[1], ft_strlen(&end[1]) + 1);
		return (1);
	}
	else if (ft_strlen(save) > 0)
	{
		if (!(*line = ft_strdup(save)))
			return (-1);
		*save = '\0';
		return (1);
	}
	return (0);
}

int				ft_get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*save;
	t_gnl			*tmp;
	int				ret;

	if (!(save))
		save = ft_create_list(fd);
	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_fd(save, fd);
	while (!(ft_strchr(tmp->tempo, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_check(tmp->text, line));
		buf[ret] = '\0';
		if (!(tmp->text = ft_strjoin(tmp->tempo, buf)))
			return (-1);
		free(tmp->tempo);
		tmp->tempo = tmp->text;
	}
	return (ft_check(tmp->text, line));
}
