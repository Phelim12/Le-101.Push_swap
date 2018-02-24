/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_checker.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:48:30 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:48:30 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		ft_print_error_ps(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

void	ft_free_stack(int **stack)
{
	free(stack[A]);
	free(stack[B]);
	free(stack);
}

int		ft_tablen(char **tab)
{
	int	ret;

	ret = 0;
	if (!tab)
		return (0);
	while (tab[ret])
		ret++;
	return (ret);
}

void	ft_free_tab(char ***tab)
{
	int y;

	y = -1;
	if (!(*tab))
		return ;
	while ((*tab)[++y])
		ft_strdel(&(*tab)[y]);
	if ((*tab))
		free(*tab);
}

void	ft_rev_stack(int **stack)
{
	int swap;
	int start;
	int	end;

	start = 1;
	end = stack[A][0] - 1;
	while (end > start)
	{
		swap = stack[A][end];
		stack[A][end] = stack[A][start];
		stack[A][start] = swap;
		start++;
		end--;
	}
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

