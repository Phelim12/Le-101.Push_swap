/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   groups_algo.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 21:41:33 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 21:41:33 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list(int *list, int size)
{
	int	save;
	int b;
	int a;

	a = -1;
	while (++a < (size - 1))
	{
		b = a;
		save = list[a];
		while (b > 0 && list[b - 1] > save)
		{
			list[b] = list[b - 1];
			b--;
		}
		list[b] = save;
	}
}

int		*ft_new_stack(int **stack, int *list)
{
	int *ret;
	int cur1;
	int cur2;

	cur1 = 0;
	ret = (int *)malloc(sizeof(int) * (SA[0]));
	while (++cur1 < SA[0])
	{
		cur2 = 0;
		while (list[cur2] != SA[cur1])
			cur2++;
		ret[cur1] = cur2;
	}
	ret[0] = SA[0];
	return (ret);
}

int 	**ft_params_push_swap(int **stack)
{
	int		*list;
	int		cur;

	cur = 0;
	SB = (int *)malloc(sizeof(int) * (stack[A][0]));
	list = (int *)malloc(sizeof(int) * (stack[A][0]));
	while (++cur < stack[A][0])
		list[cur - 1] = stack[A][cur];
	ft_sort_list(list, stack[A][0]);
	SA = ft_new_stack(stack, list);
	SB[0] = 1;
	return (stack);
}
