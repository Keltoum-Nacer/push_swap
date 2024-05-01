/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:33:26 by knacer            #+#    #+#             */
/*   Updated: 2024/04/28 21:32:15 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	find_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_a;
	t_stack	*target_b;
	int		best_target;

	while (stack_b)
	{
		best_target = INT_MAX;
		node_a = stack_a;
		while (node_a)
		{
			if (stack_b->nbr < node_a->nbr && node_a->nbr < best_target)
			{
				best_target = node_a->nbr;
				target_b = node_a;
			}
			node_a = node_a->next;
		}
		if (best_target == INT_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target_b;
		stack_b = stack_b->next;
	}
}

void	rotate_a(int ia, t_stack **stack_a)
{
	while (ia > 0)
	{
		ra(*stack_a);
		ia--;
	}
}

void	rrotate_a(int ia, t_stack **stack_a)
{
	while (ia < ft_lstsize(*stack_a))
	{
		rra(stack_a);
		ia++;
	}
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if ((*stack_b)->target->pos <= size_a / 2)
	{
		rotate_a((*stack_b)->target->pos, stack_a);
	}
	else
		rrotate_a((*stack_b)->target->pos, stack_a);
	pa(stack_b, stack_a);
}
