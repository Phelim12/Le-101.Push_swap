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

int		ft_check_grps(int *grps, int nb)
{
	int x;

	x = 0;
	while (++x < (grps[0] + 1))
		if (grps[x] == nb)
			return (1);
	return (0);
}

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

int		**ft_good_cur(int size, int size_cur)
{
	int **ret;
	int rest;
	int cur;

	cur = -1;
	rest = (size - size_cur * 4);
	ret = (int **)malloc(sizeof(int *) * (4));
	while (++cur < 4)
	{
		ret[cur] = (int *)malloc(sizeof(int) * (size_cur + 2));
		ret[cur][0] = size_cur;
	}
	if (rest == 1 || rest == 2 || rest == 3)
		ret[D][0] += 1;
	if (rest == 2 || rest == 3)
		ret[C][0] += 1;
	if (rest == 3)
		ret[B][0] += 1;
	return (ret);
}

int		**ft_fill_grps(int **stack, int *list)
{
	int 	**ret;
	int		cur1;
	int		cur2;
	int		cur3;
	int 	size;

	size = 0;
	cur1 = -1;
	cur2 = -1;
	stack[B] = (int *)malloc(sizeof(int) * (stack[A][0] + 2));
	ret = ft_good_cur((stack[A][0] - 1), ((stack[A][0] - 1) / 4));
	while (++cur1 < (stack[A][0] - 1))
	{
		while (cur1 >= size || cur1 == 0)
		{
			size += ret[++cur2][0];
			cur3 = 1;
			if (cur1 == 0 && size > 0)
				break ;
		}
		ret[cur2][cur3++] = list[cur1];
	}
	stack[B][0] = 1; 
	return (ret);
}

t_ps	ft_params_push_swap(int **stack)
{
	t_ps ret;
	int		*list;
	int		cur;
	int 	cur1;

	cur = 0;
	list = (int *)malloc(sizeof(int) * (stack[A][0]));
	while (++cur < stack[A][0])
		list[cur - 1] = stack[A][cur];
	ft_sort_list(list, stack[A][0]);
	ret.grps = ft_fill_grps(stack, list);
	return (ret);
}