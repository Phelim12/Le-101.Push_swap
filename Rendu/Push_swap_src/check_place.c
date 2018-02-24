/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_place.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 21:39:21 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 21:39:21 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_place_d(int **stack, int **grps)
{
	int cur1;
	int cur2;

	cur2 = 1;
	cur1 = grps[D][0];
	while (cur1 > 0 && cur2 < stack[A][0])
	{
		if (!(ft_check_grps(grps[D], stack[A][cur2++])))
			return (0);
		cur1--;
	}
	return (1);
}

int		ft_check_place_c(int **stack, int **grps)
{
	int cur1;
	int cur2;

	cur1 = grps[C][0];
	cur2 = (stack[A][0] - 1);
	while (cur1 > 0 && cur2 > 0)
	{
		if (!(ft_check_grps(grps[C], stack[A][cur2--])))
			return (0);
		cur1--;
	}
	return (1);
}

int		ft_check_place_b(int **stack, int **grps)
{
	int cur1;
	int cur2;

	cur1 = grps[B][0];
	cur2 = (stack[B][0] - 1);
	if (cur2 == 0)
		return (0);
	while (cur1 > 0 && cur2 > 0)
	{
		if (!(ft_check_grps(grps[B], stack[B][cur2--])))
			return (0);
		cur1--;
	}
	return (1);
}

int		ft_check_place_a(int **stack, int **grps)
{
	int cur1;
	int cur2;

	cur2 = 1;
	cur1 = grps[A][0];
	if (cur2 == 0)
		return (0);
	while (cur1 > 0 && cur2 < stack[B][0])
	{
		if (!(ft_check_grps(grps[A], stack[B][cur2++])))
			return (0);
		cur1--;
	}
	return (1);
}

int		ft_check_place(int **stack, int **grps)
{
	if (ft_check_place_a(stack, grps) && ft_check_place_b(stack, grps) &&
		ft_check_place_c(stack, grps) && ft_check_place_d(stack, grps))
		return (0);
	return (1);
}