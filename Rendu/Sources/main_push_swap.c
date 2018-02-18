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

int		ft_tablen(char **tab)
{
	int	ret;
	
	ret = 0;
	while (tab[ret])
		ret++;
	return (ret);
}

int		ft_str_is_numeric(char *str)
{
	int x;

	x = -1;
	while (str[++x])
		if (!(ft_isdigit(str[x])))
			return (0);
	return (1);
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

int		ft_tab_is_numeric(char **tab)
{
	int x;
	int	y;
	
	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (!(ft_isdigit(tab[y][x])))
				if ((tab[y][0] != '-' && tab[y][0] != '+') || x != 0)
					return (0);
		}
	}
	return (1);
}

int		ft_error_dup(int *stack, int stop)
{
	int	x;
	
	x = 0;
	while (++x < stop)
		if (stack[x] == stack[stop])
			return (1);
	return (0);
}

int		*ft_atoi_tab(int argc, char **argv)
{
	int			*stack;
	intmax_t	max;
	int			y;
	
	y = -1;
	stack = (int *)malloc(sizeof(int) * (argc + 2));
	while (argv[++y])
	{
		max = ft_atoimax(argv[y]);
		stack[y + 1] = ft_atoi(argv[y]);
		if ((max > MAXI|| max < MINI) || ft_error_dup(stack, (y + 1)))
		{
			free(stack);
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
	}
	stack[0] = (argc + 1);
	return (stack);
}

void		ft_rev_stack(int **stack)
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

int		ft_error_ps(int argc, char **argv, int ***stack)
{
	char	**cmd;

	if (argc == 2)
	{
		cmd = ft_strsplit(argv[1], 32);
		if (!(ft_tab_is_numeric(cmd)))
		{
			ft_free_tab(&cmd);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		(*stack)[A] = ft_atoi_tab(ft_tablen(cmd), cmd);
		ft_free_tab(&cmd);
	}
	else if (argc > 2 && !(ft_tab_is_numeric(argv + 1)))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (argc > 2)
		(*stack)[A] = ft_atoi_tab(ft_tablen(argv + 1), argv + 1);
	if ((*stack)[A] == NULL)
		return (1);
	ft_rev_stack(*stack);
	return (0);
}

int		ft_usage_ps(void)
{
	ft_putendl_fd("checker: need two or more arguments", 2);
	ft_putendl_fd("usage1: ./checker \"nb1 nb2 nb3 ...\"", 2);
	ft_putendl_fd("usage2: ./checker nb1 nb2 nb3 ...", 2);
	return (0);
}

void	ft_push_a(int **stack)
{
	int	end;

	stack[B][0] -= 1;	
	end = stack[B][0];
	stack[A][stack[A][0]] = stack[B][end];
	stack[A][0] += 1;
}

void	ft_push_b(int **stack)
{
	int	end;

	stack[A][0] -= 1;
	end = stack[A][0];
	stack[B][stack[B][0]] = stack[A][end];
	stack[B][0] += 1;
}


void	ft_swap_a(int **stack)
{
	int swap;
	int	end;

	end = (stack[A][0] - 1);
	swap = stack[A][end];
	stack[A][end] = stack[A][end - 1];
	stack[A][end - 1] = swap;
}

void	ft_swap_b(int **stack)
{
	int swap;
	int	end;

	end = (stack[B][0] - 1);
	swap = stack[B][end];
	stack[B][end] = stack[B][end - 1];
	stack[B][end - 1] = swap;
}

void	ft_rot_a(int **stack)
{
	int swap1;
	int swap2;
	int x;
	
	x = 1;
	swap1 = stack[A][x];
	swap2 = stack[A][x + 1];
	while (++x < stack[A][0])
	{
		stack[A][x] = swap1;
		swap1 = swap2;
		swap2 = stack[A][x + 1];
	}
	stack[A][1] = swap1;
}

void	ft_rot_b(int **stack)
{
	int swap1;
	int swap2;
	int x;
	
	x = 1;
	swap1 = stack[B][x];
	swap2 = stack[B][x + 1];
	while (++x < stack[B][0])
	{
		stack[B][x] = swap1;
		swap1 = swap2;
		swap2 = stack[B][x + 1];
	}
	stack[B][1] = swap1;	
}

void	ft_revrot_a(int **stack)
{
	int swap1;
	int swap2;
	int x;
	
	x = (stack[A][0] - 1);
	swap1 = stack[A][x];
	swap2 = stack[A][x - 1];
	stack[A][x] = stack[A][1];
	while (--x > 1)
	{
		stack[A][x] = swap1;
		swap1 = swap2;
		swap2 = stack[A][x - 1];
	}
	stack[A][1] = swap1;
}

void	ft_revrot_b(int **stack)
{
	int swap1;
	int swap2;
	int x;
	
	x = (stack[B][0] - 1);
	swap1 = stack[B][x];
	swap2 = stack[B][x - 1];
	stack[B][x] = stack[B][1];
	while (--x > 1)
	{
		stack[B][x] = swap1;
		swap1 = swap2;
		swap2 = stack[B][x - 1];
	}
	stack[B][1] = swap1;
}

void		ft_print_stack(int **stack)
{
	int x;

	x = 0;
	ft_printf("Pile A:\n");
	while (++x < stack[A][0])
		ft_printf("%d  ", stack[A][x]);
	x = 0;
	ft_printf("\nSize A : %d\n", stack[A][0]);
	ft_printf("Pile B:\n");
	while (++x < stack[B][0])
		ft_printf("%d  ", stack[B][x]);
	ft_printf("\nSize B : %d\n", stack[B][0]);
}
void	ft_checker(int **stack, char *ln)
{
	if (!(ft_strcmp(ln, "print")))
		ft_print_stack(stack);
	if (!(ft_strcmp(ln, OP1)) && stack[B][0] > 1)
		ft_push_a(stack);
	if (!(ft_strcmp(ln, OP2)) && stack[A][0] > 1)
		ft_push_b(stack);
	if ((!(ft_strcmp(ln, OP3)) || !(ft_strcmp(ln, OPA))) && stack[A][0] > 2)
		ft_swap_a(stack);
	if ((!(ft_strcmp(ln, OP4)) || !(ft_strcmp(ln, OPA))) && stack[B][0] > 2)
		ft_swap_b(stack);
	if ((!(ft_strcmp(ln, OP5)) || !(ft_strcmp(ln, OPB))) && stack[A][0] > 2)
		ft_rot_a(stack);
	if ((!(ft_strcmp(ln, OP6)) || !(ft_strcmp(ln, OPB))) && stack[B][0] > 2)
		ft_rot_b(stack);
	if ((!(ft_strcmp(ln, OP7)) || !(ft_strcmp(ln, OPC))) && stack[A][0] > 1)
		ft_revrot_a(stack);
	if ((!(ft_strcmp(ln, OP8)) || !(ft_strcmp(ln, OPC))) && stack[B][0] > 1)
		ft_revrot_b(stack);
}

int		main(int argc, char **argv)
{
	int		**stack;
	char	*line;
	
	stack = (int **)malloc(sizeof(int *) * (2));
	if (argc == 1)
		return (ft_usage_ps());
	if (ft_error_ps(argc, argv, &stack))
		return (0);
	stack[B] = (int *)malloc(sizeof(int) * (stack[A][0]));
	stack[B][0] = 1; 
	while (1)
	{
		get_next_line(1, &line);
		if (!(ft_strcmp(line, "stop")))
			break;
		ft_checker(stack, line);
		free(line);
	}
	return (0);
}









