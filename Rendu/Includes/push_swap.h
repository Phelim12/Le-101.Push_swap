/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 17:17:41 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 17:17:41 by clcreuso    ###    #+. /#+    ###.fr     */
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

# include "../Libft/Includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>



/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             main_push_swap.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_str_is_numeric(char *str);
int		ft_tab_is_numeric(char **tab);

#endif
