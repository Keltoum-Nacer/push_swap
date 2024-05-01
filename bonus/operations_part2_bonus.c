/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:21:14 by knacer            #+#    #+#             */
/*   Updated: 2024/04/30 23:27:17 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	ra(t_stack *stack_a)
{
	int	head;

	head = stack_a->nbr;
	while (stack_a->next)
	{
		stack_a->nbr = stack_a->next->nbr;
		stack_a = (stack_a)->next;
	}
	(stack_a)->nbr = head;
}

void	rb(t_stack *stack_b)
{
	int	head;

	head = stack_b->nbr;
	while (stack_b->next)
	{
		stack_b->nbr = stack_b->next->nbr;
		stack_b = stack_b->next;
	}
	stack_b->nbr = head;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	*stack_a = tmp_a->next;
	*stack_b = tmp_a;
	tmp_a->next = tmp_b;
}
