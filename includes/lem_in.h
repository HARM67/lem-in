/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:16:29 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 08:24:29 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf.h"
# include "get_next_line.h"


typedef struct			s_block
{
	struct s_block		*next;
	struct s_block		*previous;
	char				*name;
	int					x;
	int					y;
	int					is_start;
	int					is_end;
}						t_block;

typedef struct			s_path
{
	struct s_path		*next;
	struct s_path		*previous;
	unsigned long		*content;
	unsigned int		unit;
	unsigned int		size;
	unsigned int		ant_use;
	unsigned int		stroke;
}						t_path;

typedef struct			s_end_path
{
	unsigned int		id_block;
	unsigned int		current_ant;
}						t_end_path;

typedef struct			s_mtrx
{
	unsigned long		*data;
	unsigned int		size;
	unsigned int		nbr_long;
}						t_mtrx;

typedef struct			s_app
{
	t_mtrx				mtrx;
	t_mtrx				identity;
	t_path				*first_path;
	t_path				*last_path;
	t_path				*full_first;
	t_path				*full_last;
	t_path				**path_selected;
	t_path				**path_selected_temp;
	t_end_path			**firsts_end;
	t_end_path			**lasts_end;
	t_block				*first_block;
	t_block				*last_block;
	t_block				**block_array;
	unsigned int		read_mode;
	unsigned long		*used;
	unsigned long		*solution;
	unsigned int		nbr_path;
	unsigned int		nbr_full;
	unsigned int		nbr_ant;
	unsigned int		f_num;
	unsigned int		size;
	unsigned int		nbr_long;
	unsigned int		in;
	unsigned int		out;
	unsigned int		current_iteration;
	unsigned int		selected_size;
	unsigned int		best_comb;
	unsigned int		best_size;
	unsigned int		current_ant;
	unsigned int		max_stroke;
	unsigned char		temoin;
	int					ac;
	char				**av;
	unsigned char		have_start;
	unsigned char		have_end;
}						t_app;

/*
** app.c
*/
void					init_app(t_app *app);
void					run_app(t_app *app);

/*
** mtrx.h
*/
void					init_mtrx(t_mtrx *mtrx, unsigned int size);
void					print_mtrx(t_app *app, t_mtrx *mtrx);

/*
** identity.c
*/
void					init_mtrx_identity(t_mtrx *mtrx);

/*
** find_link.c
*/
void					find_link(t_app *app, unsigned int nbr);

/*
** compare.c
*/
int						and_test(unsigned long *d1, unsigned long *d2,
		unsigned int nbr_long);
int						and_test_reverse(unsigned long *d1, unsigned long *d2,
		unsigned int nbr_long);

/*
** print_data.c
*/
void					print_data(unsigned long *data, unsigned int size);

/*
** path.c
*/
void					push_path(t_app *app, unsigned int unit);
void					travel_path(t_app *app, unsigned long *old,
							unsigned int unit);
void					remove_path(t_app *app, t_path *path);
void					print_paths(t_app *app);
void					is_solution(t_app *app, t_path *path);
void					print_full(t_app *app);

/*
** path2.c
*/
void					remove_inout(t_app *app);

/*
** operation.c
*/
void					make_or(unsigned long *d2, unsigned long *d1,
							unsigned int nbr_long);
void					make_and_reverse(unsigned long *d1, unsigned long *d2,
							unsigned int nbr_long);
void					make_and(unsigned long *d1, unsigned long *d2,
							unsigned int nbr_long);
void					make_reverse(unsigned long *d, unsigned int nbr_long);
void					make_cpy(unsigned long *d1, unsigned long *d2,
							unsigned int nbr_long);

/*
** parsing.c
*/
void					read_file(t_app *app);

/*
** parsing2.c
*/
void					prepare_data(t_app *app);
void					list_to_array(t_app *app);

/*
** parsing3.c
*/
void 					read_case(t_app *app, char *line, unsigned int *n);
int						read_tube(t_app *app, char *line);
/*
** block.c
*/
int						what_nbr(t_app *app, char *name);
t_block					*new_block(char *name, int x, int y);
void					insert_block(t_app *app, t_block *block);
void					print_block(t_app *app);

/*
** verif.c
*/
int						verif_number(char *nbr);

/*
** calc_f_num.c
*/
unsigned int			calc_f_nums(t_app *app);

/*
** choose_paths.c
*/
void					choose_rec(t_app*app, t_path *path, unsigned int iteration);

/*
** ant.c
*/
void					move_ants(t_app *app);

/*
** end_path.c
*/
void					make_end_paths_array(t_app *app);

/*
** other.c
*/
void					insert_out(t_app *app);
void					calc_stroke(t_app *app);
#endif
