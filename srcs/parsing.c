#include "lem_in.h"

void		read_ant(t_app *app, char *line)
{
	app->nbr_ant = ft_atoi(line);
	app->read_mode = 0;
	while (*line != 0)
	{
		if (!ft_isdigit(*line))
			exit(1);
		line++;
	}
}

void		read_file(t_app *app)
{
	char			*line;
	unsigned int	i;

	i = 0;
	app->read_mode = 9;
	while (get_next_line(0, &line) >= 0 )
	{
		if (line == 0)
			break ;
		if (app->read_mode == 9)
			read_ant(app, line);
		else if (app->read_mode <= 2)
			read_case(app, line, &i);
		if (app->read_mode == 3)
			prepare_data(app);
		if (app->read_mode == 4)
			read_tube(app, line);
		if (app->read_mode == 5)
			break ;
		ft_putendl(line);
		free(line);
		line = 0;
	}
}
