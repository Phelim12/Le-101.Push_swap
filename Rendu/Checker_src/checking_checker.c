/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checking_checker.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:58:06 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:58:06 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_option(char *line)
{
	if (ft_strcmp(line, OP1) && ft_strcmp(line, OP2) && ft_strcmp(line, OP3) &&
		ft_strcmp(line, OP4) && ft_strcmp(line, OP5) && ft_strcmp(line, OP6) &&
		ft_strcmp(line, OP7) && ft_strcmp(line, OP8) && ft_strcmp(line, OPA) &&
		ft_strcmp(line, OPB) && ft_strcmp(line, OPC))
		return (1);
	else
		return (0);
}

void	ft_modif_stack(int **stack, char *ln)
{
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

char	*ft_checker(int **stack, char **cmd)
{
	int	y;

	y = -1;
	stack[B] = (int *)malloc(sizeof(int) * (stack[A][0]));
	stack[B][0] = 1;
	while (cmd && cmd[++y])
	{
		if (ft_check_option(cmd[y]))
			return ("KO");
		ft_modif_stack(stack, cmd[y]);
		ft_print_stack(stack);
	}
	if (stack[B][0] > 1)
		return ("KO");
	y = 0;
	while ((++y + 1) < stack[A][0])
		if (stack[A][y] <= stack[A][y + 1])
			return ("KO");
	return ("OK");
}
