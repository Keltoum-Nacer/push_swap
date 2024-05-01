/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:21:26 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 15:34:16 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (stack_b == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_b);
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	check_charac(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') && (av[i][j + 1] == '-'
					|| av[i][j + 1] == '+'))
				print_msg();
			if ((av[i][j] == '+' && av[i][j + 1] == '+') || (av[i][j] == '-'
					&& av[i][j + 1] == '-') || (av[i][j] == '+'
					&& av[i][j] == '-') || (av[i][j] == '-' && av[i][j] == '+'))
				print_msg();
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-'
				&& av[i][j] != '+')
				print_msg();
			j++;
		}
		i++;
	}
}

void	check_spaces(char *av)
{
	int	j;

	j = 0;
	while (av[j] == ' ')
	{
		j++;
	}
	if (j == ft_strlen(av))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	check_dup(t_stack *stack_a, int nbr)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a)
	{
		if (stack_a->nbr == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
