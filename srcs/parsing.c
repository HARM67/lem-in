/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:21:08 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:21:12 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		skip_space(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}

void		remove_comment(char *str)
{
	while (*str != '\0')
	{
		if (*str == '#')
		{
			if (ft_strncmp(str, "##start", 7) == 0)
				str += 6;
			else if (ft_strncmp(str, "##end", 5) == 0)
				str += 4;
			else
			{
				*str = '\0';
				return ;
			}
		}
		str++;
	}
}

int			check_comment_line(char **str)
{
	char	*tmp;

	tmp = *str;
	skip_space(&tmp);
	if (*tmp == '#' && ft_strncmp(tmp, "##start", 7) &&
			ft_strncmp(tmp, "##end", 5))
	{
		free(*str);
		return (1);
	}
	return (0);
}

void		read_ant(t_app *app, char *line)
{
	skip_space(&line);
	app->nbr_ant = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line != '\0')
	{
		if (*line != ' ' && *line != '\t')
			put_error("Nombre de fourmille absent ou mal formate");
		line++;
	}
	if (app->nbr_ant == 0)
		put_error("Le nombre de fourmille est egale a zero");
	app->read_mode = 0;
}

void		read_file(t_app *app)
{
	char			*line;

	while (get_next_line(0, &line) >= 0)
	{
		if (line == 0)
			break ;
		ft_putendl(line);
		if (check_comment_line(&line))
			continue ;
		remove_comment(line);
		if (app->read_mode == 9)
			read_ant(app, line);
		else if (app->read_mode <= 2)
			read_case(app, line);
		if (app->read_mode == 3)
			prepare_data(app);
		if (app->read_mode == 4)
			read_tube(app, line);
		if (app->read_mode == 5)
			break ;
		free(line);
		line = 0;
	}
	if (line)
		free(line);
}
