#include "lem_in.h"

static int	read_block(t_app *app, char **array, unsigned int nbr)
{
	unsigned int	i;
	t_block			*n;

	i = 0;
	if (!verif_number(array[1]) || !verif_number(array[2]))
		return (0);
	if (array[0][0] == '#' || array[0][0] == 'L')
		return (0);
	n = new_block(array[0], ft_atoi(array[1]), ft_atoi(array[2]));
	insert_block(app, n);
	if (app->read_mode == 1)
	{
		app->have_start = 1;
		app->in = nbr;
	}
	else if (app->read_mode == 2)
	{
		app->have_end = 1;
		app->out = nbr;
	}
	if (app->read_mode == 1 || app->read_mode == 2)
		app->read_mode = 0;
	return (1);
}

static int	read_other(t_app *app, char *array, unsigned int n)
{
	if (ft_strncmp(array, "##start", 7) == 0 && !app->read_mode)
		app->read_mode = 1;
	else if (ft_strncmp(array, "##end", 5) == 0 && !app->read_mode)
		app->read_mode = 2;
	else if (array[0] == '#' || array[0] == 'L')
		;
	else
		return (0);
	return (1);
}

void read_case(t_app *app, char *line, unsigned int *n)
{
	unsigned int	rt;
	unsigned int	i;
	unsigned int	count;
	char			**array;

	i = 0;
	rt = 0;
	count = ft_strcount(line, ' ');
	if (read_other(app, line, *n))
		;
	else if (count == 3)
	{
		array = ft_strsplit(line, ' ');
		rt = read_block(app, array, *n);
		while (i < count)
			free(array[i++]);
		free(array);
		*n += rt;
	}
	else
		app->read_mode = 3;
}

int	read_tube(t_app *app, char *line)
{
	char			**tube;
	unsigned int	count;
	int				a;
	int				b;

	count = ft_strcount(line, '-');
	if (count != 2 || line[0] == '#' || line[0] == 'L')
	{
		if (line[0] != '#' && line[0] != 'L')
			app->read_mode = 5;
		return (-1);
	}
	tube = ft_strsplit(line, '-');
	a = what_nbr(app, tube[0]);
	b = what_nbr(app, tube[1]);
	if (a == -1 || b == -1)
		app->read_mode = 5;
	make_or(&app->mtrx.data[a], &app->identity.data[b], app->nbr_long);
	make_or(&app->mtrx.data[b], &app->identity.data[a], app->nbr_long);
	return (0);
}
