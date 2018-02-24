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

# define MAXI 2147483647
# define MINI -2147483648
# define OP1 "pa"
# define OP2 "pb"
# define OP3 "sa"
# define OP4 "sb"
# define OP5 "ra"
# define OP6 "rb"
# define OP7 "rra"
# define OP8 "rrb"
# define OPA "ss"
# define OPB "rr"
# define OPC "rrr"
# define A 0
# define B 1
# define C 2
# define D 3

# include "../Libft/Includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_ps
{
	int		**grps;
	int		mid;
}				t_ps;

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

#endif