#include "lem_in.h"

void	insert_out(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->best_size)
	{
		make_or(app->path_selected[i]->content, &app->identity.data[app->out],
			app->nbr_long);
		i++;
	}
}

void	calc_stroke(t_app *app)
{
	unsigned int	i;
	t_path			*tmp;

	i = 0;
	while (i < app->best_size)
	{
		tmp = app->path_selected[i];
		tmp->stroke = tmp->size + tmp->ant_use - 1;
		if (tmp->stroke > app->max_stroke)
			app->max_stroke = tmp->stroke;
		i++;
	}
}
