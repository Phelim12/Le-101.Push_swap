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

int		ft_usage_ps(int **stack)
{
	ft_putendl_fd("checker: need two or more arguments", 2);
	ft_putendl_fd("usage1: ./checker \"nb1 nb2 nb3 ...\"", 2);
	ft_putendl_fd("usage2: ./checker nb1 nb2 nb3 ...", 2);
	free(stack);
	return (0);
}

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
	ft_printf("\nSize B : %d\n\n\n", stack[B][0]);
}

void	ft_modif_stack(int **stack, int opt)
{
	int static test = 0;
	printf("test = %d\n", test++);
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

t_sa	ft_search_not_rank(int *stack, int *ptr, int choice)
{
	t_sa	ret;
	int		cur1;
	int 	cur2;
	int		*tab;

	cur1 = 2;
	cur2 = 0;
	while (cur1 < stack[0] && stack[cur1 - 1] == (stack[cur1] + 1))
		cur1++;
	if (choice == B || stack[cur1 - 1] != 0)
		cur1 = 1;
	tab = (int *)malloc(sizeof(int) * (stack[0] + 2));
	while (cur1 < stack[0])
		tab[cur2++] = stack[cur1++];
	ft_sort_list(tab, cur2 + 1);
	ret.min = tab[0];
	ret.mid = tab[cur2 / 2];
	if (choice == A && *ptr > ret.min)
		ret.mid = *ptr;
	ret.max = tab[cur2 - 1];
	if (choice == A)
		(*ptr) = ret.mid;
	free(tab);
	return (ret);
}

int		ft_check_end_split(int *stack, t_sa info, int choice)
{
	int cur;

	cur = 0;
	while (++cur < stack[0])
	{
		if (choice == A && stack[cur] >= info.min && stack[cur] < info.mid)
			return (1);
		if (choice == B && stack[cur] > info.mid)
			return (1);
	}
	return (0);
}

void	ft_split_sa(int **stack, int *mid)
{
	t_sa	info;
	int		cur;

	cur = 1;
	info = ft_search_not_rank(stack[A], mid, A);
	/*printf("MID = %d\n", info.mid);
	printf("MIN = %d\n", info.min);
	sleep(2);*/
	while (ft_check_end_split(stack[A], info, A))
	{
		if (SA[ENDA] >= info.min && SA[ENDA] < info.mid)
			ft_modif_stack(stack, 2);
		else
			ft_modif_stack(stack, 5);
		if (SB[0] > 3 && SB[ENDB] < SB[ENDB - 1] && SB[ENDB] > SB[ENDB - 2])
			ft_modif_stack(stack, 4);
		if (SB[0] > 2 && SB[ENDB] < SB[1] && SA[ENDA] >= info.mid)
			ft_modif_stack(stack, 10);
		//sleep(2);
	}
}

int		ft_opti_test(int **stack)
{
	int cur;

	cur = 1;
	//ft_print_stack(stack);
	//sleep(5);
	while (++cur < SB[0])
	{
		if (SB[cur - 1] != (SB[cur] + 1))
			return (0);
	}
	return (1);
}

void	ft_split_sb(int **stack)
{
	t_sa	info;
	int		cur;

	cur = 1;
	info = ft_search_not_rank(stack[B], NULL, B);
	if (info.min > 0)
		while (SA[1] != (info.min - 1))
			ft_modif_stack(stack, 7);
	while (ft_check_end_split(stack[B], info, B))
	{
		if (SB[1] > info.mid && SB[1] > SB[ENDB] && SB[1] > SB[ENDB - 1])
			ft_modif_stack(stack, 8);
		if (SB[ENDB] > info.mid && SB[ENDB - 1] > SB[ENDB])
			ft_modif_stack(stack, 4);
		if (SB[ENDB] > info.mid)
			ft_modif_stack(stack, 1);
		else
			ft_modif_stack(stack, 6);
	}
	if (ft_opti_test(stack))
		cur = 0;
	if (SB[0] > 4)
		ft_split_sb(stack);
}

int		ft_check_end(int **stack)
{
	int cur;

	cur = 1;
	if (SB[0] > 1)
		return (1);
	while (cur++ < SA[0])
	{
		if (SA[cur - 1] != (SA[cur] + 1))
			break;
	}
	if (cur == SA[0])
		return (0);
	return (1);
}

void	ft_tidy(int **stack)
{
	if (SB[ENDB - 2] < SB[ENDB] && SB[ENDB - 2] > SB[ENDB - 1])
		ft_modif_stack(stack, 8);
	if (SB[ENDB] < SB[ENDB - 1])
		ft_modif_stack(stack, 4);
	if (SB[ENDB - 2] > SB[ENDB])
		ft_modif_stack(stack, 8);
	if (SB[ENDB] < SB[ENDB - 1])
		ft_modif_stack(stack, 4);
}

void	ft_range_stack(int **stack)
{
	if (SB[0] == 4)
		ft_tidy(stack);
	else if (SB[ENDB] < SB[ENDB - 1])
		ft_modif_stack(stack, 4);
	while (SB[0] != 1)
		ft_modif_stack(stack, 1);
	while ((ft_check_end(stack) && SA[ENDA] == 0) || SA[1] == (SA[ENDA] - 1) ||
			SA[1] == (SA[ENDA - 1] - 1) || SA[1] == (SA[ENDA - 2] - 1))
	{
		if (SA[1] == (SA[ENDA - 2] - 1))
			ft_modif_stack(stack, 2);
		if (SA[1] == (SA[ENDA - 1] - 1))
			ft_modif_stack(stack, 3);
		ft_modif_stack(stack, 5);
	}
}

int		main(int argc, char *argv[])
{
	int		**stack;
	int		mid;

	mid = 0;
	stack = (int **)malloc(sizeof(int *) * (2));
	if (argc == 1)
		return (ft_usage_ps(stack));
	if (ft_fill_ps(argc, argv, &stack))
		return (0);
	stack = ft_params_push_swap(stack);
	while (ft_check_end(stack))
	{
		ft_split_sa(stack, &mid);
		ft_split_sb(stack);
		ft_range_stack(stack);
		ft_print_stack(stack);
		/*printf("ft_split_sa\n");
		sleep(2);
		printf("ft_split_sb\n");
		sleep(2);
		printf("ft_range_stack\n");
		ft_print_stack(stack);
		sleep(2);*/
	}
	ft_print_stack(stack);
	return (0);
}











