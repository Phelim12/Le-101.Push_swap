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

#include "checker.h"

int		ft_usage_ps(int **stack)
{
	ft_putendl_fd("checker: need two or more arguments", 2);
	ft_putendl_fd("usage1: ./checker \"nb1 nb2 nb3 ...\"", 2);
	ft_putendl_fd("usage2: ./checker nb1 nb2 nb3 ...", 2);
	free(stack);
	return (0);
}

void		ft_print_stack(int **stack)
{
	int x;

	x = 0;
	ft_printf("Pile A:\n");
	while (stack[A] && ++x < stack[A][0])
		ft_printf("%d  ", stack[A][x]);
	x = 0;
	ft_printf("\nSize A : %d\n", stack[A][0]);
	ft_printf("Pile B:\n");
	while (++x < stack[B][0])
		ft_printf("%d  ", stack[B][x]);
	ft_printf("\nSize B : %d\n", stack[B][0]);
}

int		main(int argc, char **argv)
{
	int		**stack;

	stack = (int **)malloc(sizeof(int *) * (2));
	if (argc == 1)
		return (ft_usage_ps(stack));
	if (ft_fill_ps(argc, argv, &stack))
		return (0);
	ft_print_stack(stack);
	return (0);
}
