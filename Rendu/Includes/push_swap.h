/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:04:44 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 16:04:44 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MINI -2147483648
# define MAXI 2147483647
# define ENDA (stack[A][0] - 1)
# define ENDB (stack[B][0] - 1)
# define SA (stack[A])
# define SB (stack[B])
# define A 0
# define B 1

# include "../Libft/Includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct 	s_sa
{
	int min;
	int	mid;
	int	max;
}				t_sa;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              main_checker.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              fill_checker.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			ft_tab_is_numeric(char **tab);
int			ft_error_dup(int *stack, int stop);
int			*ft_atoi_tab(int argc, char **argv);
char		**ft_fill_all_options(char **cmd, char *line);
int			ft_fill_ps(int argc, char **argv, int ***stack);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              tools_checker.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int			ft_tablen(char **tab);
int			ft_print_error_ps(void);
void		ft_free_tab(char ***tab);
void		ft_rev_stack(int **stack);
void		ft_free_stack(int **stack);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            operation1_checker.c                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		ft_push_a(int **stack);
void		ft_push_b(int **stack);
void		ft_swap_a(int **stack);
void		ft_swap_b(int **stack);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            operation2_checker.c                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		ft_rot_a(int **stack);
void		ft_rot_b(int **stack);
void		ft_revrot_a(int **stack);
void		ft_revrot_b(int **stack);

int		**ft_dup_stack(int **stack);
void	ft_cpy_stack(int **stack, int **stack_cpy);
int		ft_check_group(int *group, int nb);
void	ft_sort_list(int *list, int size);
int		**ft_good_cur(int size, int size_cur);
int		**ft_fill_grps(int **stack, int *list);
int		**ft_params_push_swap(int **stack);
int		ft_check_order(int **stack);
int		ft_check_num(int **stack);
void	ft_split_sa(int **stack, int *mid);
int		ft_check_end(int **stack);
int		ft_check_end_split(int *stack, t_sa info, int choice);
void	ft_modif_stack(int **stack, int opt);
void	ft_resolve(int **stack);
t_sa	ft_search_not_rank(int *stack, int *ptr, int choice);
void	ft_clean_sb(int **stack);
void	ft_split_sb(int **stack);
void	ft_print_stack(int **stack);
void	ft_clean_stack(int **stack, int mid);

#endif