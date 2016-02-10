#include "lem_in.h"

static int	check_all(t_app *app, t_path *path, unsigned int iteration)
{
	t_path			**tmp;
	unsigned int	i;

	i = 0;
	tmp = app->path_selected_temp;
	while (i < iteration + 1)
	{
		if (and_test(path->content, tmp[i]->content,app->nbr_long))
			return (0);
		i++;
	}
	return (1);
}

static void	reg_best(t_app *app, unsigned int iteration)
{
	unsigned int	i;

	i = 0;
	while (i < iteration)
	{
		app->path_selected[i] = app->path_selected_temp[i];
		i++;
	}
	while (i < app->nbr_full)
	{
		app->path_selected[i] = 0;
		i++;
	}
}

static void	check_better(t_app *app, unsigned int iteration)
{
	unsigned int	best_tmp;

	best_tmp = 0;
	app->selected_size = iteration + 1;
	best_tmp = calc_f_nums(app);
	if (best_tmp < app->best_comb)
	{
		app->best_size = iteration + 1;
		reg_best(app, iteration + 1);
		app->best_comb = best_tmp;
	}
}

void		choose_rec(t_app *app, t_path *path, unsigned int iteration)
{
	unsigned int	i;
	unsigned int	j;
	t_path			*tmp;

	app->path_selected_temp[iteration] = path;
	check_better(app, iteration);
	if (iteration == app->nbr_full - 1)
		return ;
	i = 0;
	j = 0;
	tmp = app->full_first;
	while (tmp && i < app->nbr_full)
	{
		if (check_all(app, tmp, iteration))
			choose_rec(app, tmp, iteration + 1);
		tmp = tmp->next;
		i++;
	}
	app->path_selected_temp[iteration] = 0;
}
