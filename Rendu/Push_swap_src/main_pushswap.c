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
	ft_printf("\nSize B : %d\n", stack[B][0]);
}

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





