/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:08:16 by knacer            #+#    #+#             */
/*   Updated: 2024/04/29 15:18:41 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*node_b;
	t_stack	*target_a;
	int		best_target;

	while (stack_a)
	{
		best_target = INT_MIN;
		node_b = stack_b;
		while (node_b)
		{
			if (stack_a->nbr > node_b->nbr && node_b->nbr > best_target)
			{
				best_target = node_b->nbr;
				target_a = node_b;
			}
			node_b = node_b->next;
		}
		if (best_target == INT_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target_a;
		stack_a = stack_a->next;
	}
}

void	check_moves(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		if (stack_a->pos <= size_a / 2 && stack_a->target->pos <= size_b / 2)
			stack_a->nbr_of_moves = max(stack_a->pos, stack_a->target->pos);
		if (stack_a->pos > size_a / 2 && stack_a->target->pos > size_b / 2)
			stack_a->nbr_of_moves = max(size_a - stack_a->pos, size_b
					- stack_a->target->pos);
		if (stack_a->pos > size_a / 2 && stack_a->target->pos <= size_b / 2)
			stack_a->nbr_of_moves = max(size_a - stack_a->pos,
					stack_a->target->pos);
		if (stack_a->pos <= size_a / 2 && stack_a->target->pos > size_b / 2)
			stack_a->nbr_of_moves = max(stack_a->pos, size_b
					- stack_a->target->pos);
		stack_a = stack_a->next;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	int		min;
	t_stack	*cheapest;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->nbr_of_moves < min)
		{
			min = stack->nbr_of_moves;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

void	before_push_a(t_stack *stack_a, t_stack *stack_b)
{
	find_index(stack_a);
	find_index(stack_b);
	find_target_a(stack_a, stack_b);
	check_moves(stack_a, stack_b);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	int		size_a;
	int		size_b;

	cheapest = get_cheapest(*stack_a);
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (cheapest->pos <= size_a / 2 && cheapest->target->pos <= size_b / 2)
		rr_ra_rb(cheapest->pos, cheapest->target->pos, stack_a, stack_b);
	if (cheapest->pos > size_a / 2 && cheapest->target->pos > size_b / 2)
		rrr_rra_rrb(cheapest->pos, cheapest->target->pos, stack_a, stack_b);
	if (cheapest->pos > size_a / 2 && cheapest->target->pos <= size_b / 2)
		rra_rb(cheapest->pos, cheapest->target->pos, stack_a, stack_b);
	if (cheapest->pos <= size_a / 2 && cheapest->target->pos > size_b / 2)
		ra_rrb(cheapest->pos, cheapest->target->pos, stack_a, stack_b);
	pb(stack_a, stack_b);
}
