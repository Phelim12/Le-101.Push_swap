/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_push_swap.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 16:39:50 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/18 16:39:50 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(int **stack)
{
	int x;

	x = 0;
	ft_printf("Pile A:\n");
	while (stack[A] && ++x < stack[A][0])
		ft_printf("%d  ", stack[A][x]);
	x = 0;
	ft_printf("\nPile B:\n");
	while (++x < stack[B][0])
		ft_printf("%d  ", stack[B][x]);
	printf("\n");
	ft_printf("\nSize A : %d\n", stack[A][0]);
	ft_printf("\nSize B : %d\n", stack[B][0]);
}

int		ft_usage_ps(int **stack)
{
	ft_putendl_fd("checker: need two or more arguments", 2);
	ft_putendl_fd("usage1: ./checker \"nb1 nb2 nb3 ...\"", 2);
	ft_putendl_fd("usage2: ./checker nb1 nb2 nb3 ...", 2);
	free(stack);
	return (0);
}

/*
t_ps	ft_params_push_swap(int **stack)
{
	int 	*list;
	t_ps	ret;
	int		cur;

	cur = 0;
	list = (int *)malloc(sizeof(int) * (stack[A][0]));
	while (++cur < stack[A][0])
		list[cur - 1] = stack[A][cur];
	ft_sort_list(list, stack[A][0]);
	ret.mid = list[(stack[A][0] - 1) / 2];
	return (ret);
}

int		ft_push_swap(int **stk, t_ps ps)
{
	int top;

	top = (stk[A][0] - 1);
	printf("end : %d mid : %d start : %d\n", stk[A][top], ps.mid, stk[A][1]);
	if (stk[A][top] < ps.mid && stk[A][top] < stk[A][1])
		return (2);
	if (stk[A][1] < ps.mid && stk[A][1] < stk[A][top])
		return (7);
	if (stk[A][1] > ps.mid && stk[A][top] > ps.mid && stk[A][1] > stk[A][top])
		return (3);
	return (2);
	exit(0);
}
*/

void	ft_modif_stack(int **stack, int opt)
{
	if (opt == 1 && stack[B][0] > 1)
		ft_push_a(stack);
	if (opt == 2 && stack[A][0] > 1)
		ft_push_b(stack);
	if ((opt == 3 || opt == 9) && stack[A][0] > 2)
		ft_swap_a(stack);
	if ((opt == 4 || opt == 9) && stack[B][0] > 2)
		ft_swap_b(stack);
	if ((opt == 5 || opt == 10) && stack[A][0] > 2)
		ft_rot_a(stack);
	if ((opt == 6 || opt == 10) && stack[B][0] > 2)
		ft_rot_b(stack);
	if ((opt == 7 || opt == 11) && stack[A][0] > 1)
		ft_revrot_a(stack);
	if ((opt == 8 || opt == 11) && stack[B][0] > 1)
		ft_revrot_b(stack);
}

int		ft_check_good(int **stack)
{
	int y;

	y = 0;
	if (stack[B][0] > 1)
		return (1);
	while ((++y + 1) < stack[A][0])
		if (stack[A][y] <= stack[A][y + 1])
			return (1);
	return (0);
}

int		**ft_dup_stack(int **stack)
{
	int **ret;
	int y;

	ret = (int **)malloc(sizeof(int *) * (2));
	ret[A] = (int *)malloc(sizeof(int) * (stack[A][0] + 2));
	ret[B] = (int *)malloc(sizeof(int) * (stack[A][0] + 2));
	y = -1;
	while (++y < stack[A][0])
		ret[A][y] = stack[A][y];
	y = -1;
	while (++y < stack[B][0])
		ret[B][y] = stack[B][y];
	return (ret);
}

void	ft_cpy_stack(int **stack, int **stack_cpy)
{
	int y;

	y = -1;
	while (++y < stack[A][0])
		stack_cpy[A][y] = stack[A][y];
	y = -1;
	while (++y < stack[B][0])
		stack_cpy[B][y] = stack[B][y];
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

int		ft_check_grps(int *grps, int nb)
{
	int x;

	x = 0;
	while (++x < (grps[0] + 1))
		if (grps[x] == nb)
			return (1);
	return (0);
}

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

int		ft_backtracking(int **swap_stack, int **new_stack, int *ret, int turn)
{
	int	y;
	int x;

	y = 2;
	ft_cpy_stack(new_stack, swap_stack);
	if (ft_check_good(new_stack) == 0)
		return (1);
	if (turn < 0)
		return (0);
	while (++y < 12)
	{
		x = -1;
		if (ft_check_good(new_stack) == 0)
		ft_modif_stack(new_stack, y);
		if (ft_backtracking(swap_stack, new_stack, ret, (turn - 1)))
		{
			printf("TURN = %d Y = %d\n", turn, y);
			ret[turn] = y;
			return (1);
		}
		else
			ft_cpy_stack(swap_stack, new_stack);
	}
	return (0);
}

int		*ft_main_backtracking(int **stack, int turn)
{	
	int 	**swap_stack;
	int		**new_stack;
	int		*ret;
	int		cur;

	cur = 0;
	new_stack = ft_dup_stack(stack);
	swap_stack = ft_dup_stack(stack);
	ret = (int *)malloc(sizeof(int) * (turn + 5));
	while (cur < (turn + 2))
		ret[cur++] = -1;
	ft_backtracking(swap_stack, new_stack, ret, turn);
	ft_print_stack(new_stack);
	return (ret);
}

int		ft_push_swap(int **stk, t_ps ps)
{
	int end;
	int endb;

	end = (stk[A][0] - 1);
	endb = (stk[B][0] - 1);
	if (ft_check_grps(ps.grps[A], stk[A][end]) && stk[A][end] < stk[A][1])
		return (2);
	if (ft_check_grps(ps.grps[A], stk[A][1]))
		return (7);
	if (ft_check_grps(ps.grps[D], stk[A][end]))
		return (5);
	if (ft_check_grps(ps.grps[C], stk[A][end]) && !(ft_check_grps(ps.grps[C], stk[A][end - 1])))
		return (3);
	if (ft_check_grps(ps.grps[B], stk[A][end]) && stk[A][end] < stk[A][1])
		return (2);
	if (ft_check_grps(ps.grps[B], stk[A][1]))
		return (7);
	printf("grps D\n");
	if (ft_check_grps(ps.grps[D], stk[A][1]))
		return (7);
	if (ft_check_grps(ps.grps[C], stk[A][end]))
		return (5);
	return 0;
}

int		main(int argc, char *argv[])
{
	t_ps	push_swap;
	int		**stack;

	stack = (int **)malloc(sizeof(int *) * (2));
	if (argc == 1)
		return (ft_usage_ps(stack));
	if (ft_fill_ps(argc, argv, &stack))
		return (0);
	push_swap = ft_params_push_swap(stack);
	ft_main_backtracking(stack, 6);
	/*while (ft_check_place(stack, push_swap.grps))
	{
		if (ft_push_swap(stack, push_swap) == 0)
			break ;
		ft_modif_stack(stack, ft_push_swap(stack, push_swap));
		ft_print_stack(stack);
		sleep(5);
	}*/
	//printf("%d\n", stack[A][1]);
	return (0);
}





