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
	if (app->read_mode == 2)
		app->in = nbr;
	else if (app->read_mode == 3)
		app->out = nbr;
	if (app->read_mode == 2 || app->read_mode == 3)
		app->read_mode = 0;
	return (1);
}

static int	read_other(t_app *app, char *array, unsigned int n)
{
	unsigned int	temoin;

	temoin = 1;
	if (ft_strncmp(array, "##Start", 7) == 0 && !app->read_mode)
		app->read_mode = 2;
	else if (ft_strncmp(array, "##end", 5) == 0 && !app->read_mode)
		app->read_mode = 3;
	else if (array[0] == '#' || array[0] == 'L')
		;
	else
	{
		app->read_mode = 1;
		temoin = 0;
	}
	return (temoin);
}

static int	read_case(t_app *app, char **array, unsigned int count,
				unsigned int *n)
{
	unsigned int	rt;
	unsigned int	i;

	i = 0;
	rt = 0;
	if (count == 3 && !(app->read_mode == 1))
	{
		rt = read_block(app, array, *n);
		*n += rt;
	}
	else if (count == 1)
		rt = read_other(app, array[0], *n);
	while (i < count)
		free(array[i++]);
	free(array);
	return (rt);
}

static void	list_to_array(t_app *app)
{
	t_block			*tmp;
	unsigned int	i;

	i = 0;
	tmp = app->first_block;
	app->block_array = (t_block**)ft_memalloc(sizeof(t_block*) * app->size);
	while (tmp && i < app->size)
	{
		app->block_array[i] = tmp;
		tmp = tmp->next;
		i++;
	}
}

static int	read_tube(t_app *app, char *line)
{
	char			**tube;
	unsigned int	count;
	int				a;
	int				b;

	count = ft_strcount(line, '-');
	if (count != 2)
		return (-1);
	tube = ft_strsplit(line, '-');
	a = what_nbr(app, tube[0]);
	b = what_nbr(app, tube[1]);
	if (a == -1 || b == -1)
		return (-1);
	//ft_printf("%s %s\n", app->block_array[a]->name, app->block_array[b]->name);
	make_or(&app->mtrx.data[a], &app->identity.data[b], app->nbr_long);
	make_or(&app->mtrx.data[b], &app->identity.data[a], app->nbr_long);
	return (0);
}

void		read_file(t_app *app)
{
	char			*line;
	unsigned int	i;

	i = 0;
	while (app->read_mode != 1 && get_next_line(0, &line) > 0 )
	{
		read_case(app, ft_strsplit(line, ' '), ft_strcount(line, ' '), &i);
		if (app->read_mode != 1)
			free(line);
	}
	list_to_array(app);
	init_mtrx(&app->mtrx, app->size);
	app->nbr_long = app->mtrx.nbr_long;
	init_mtrx(&app->identity, app->size);
	init_mtrx_identity(&app->identity);
	if (line)
	{
		read_tube(app, line);
		free(line);
		line = 0;
	}
	while (get_next_line(0, &line) > 0)
	{
		read_tube(app, line);
		free(line);
		line = 0;
	}
	if (line)
	{
		read_tube(app, line);
		free(line);
		line = 0;
	}
}
