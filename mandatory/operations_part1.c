/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:17:40 by knacer            #+#    #+#             */
/*   Updated: 2024/04/29 15:46:15 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = stack_a->nbr;
	stack_a->nbr = stack_a->next->nbr;
	stack_a->next->nbr = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	tmp = stack_b->nbr;
	stack_b->nbr = stack_b->next->nbr;
	stack_b->next->nbr = tmp;
	write(1, "sb\n", 3);
}

void	ssa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = stack_a->nbr;
	stack_a->nbr = stack_a->next->nbr;
	stack_a->next->nbr = tmp;
}

void	ssb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	tmp = stack_b->nbr;
	stack_b->nbr = stack_b->next->nbr;
	stack_b->next->nbr = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ssa(stack_a);
	ssb(stack_b);
	write(1, "ss\n", 3);
}
