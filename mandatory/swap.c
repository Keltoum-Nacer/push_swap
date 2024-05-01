/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:19:38 by knacer            #+#    #+#             */
/*   Updated: 2024/04/29 15:06:21 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_3(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	if (head->nbr > head->next->nbr && head->nbr < head->next->next->nbr)
		sa(head);
	else if (head->nbr > head->next->nbr
		&& head->next->nbr > head->next->next->nbr)
	{
		sa(head);
		rra(stack);
	}
	else if (head->nbr > head->next->nbr && head->nbr > head->next->next->nbr)
		ra(head);
	else if (head->nbr < head->next->nbr && head->nbr < head->next->next->nbr)
	{
		sa(head);
		ra(head);
	}
	else if (head->nbr > head->next->next->nbr && head->nbr < head->next->nbr)
		rra(stack);
}

void	before_push_b(t_stack *stack_a, t_stack *stack_b)
{
	find_index(stack_b);
	find_index(stack_a);
	find_target_b(stack_a, stack_b);
}

void	set_min_on_head(t_stack **stack_a)
{
	find_index(*stack_a);
	while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
	{
		if (find_min(*stack_a)->pos <= ft_lstsize(*stack_a) / 2)
			ra(*stack_a);
		else
			rra(stack_a);
	}
}

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	if (size_a-- > 3 && is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_a > 3 && is_sorted(*stack_a))
	{
		before_push_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
		size_a--;
	}
	if (ft_lstsize(*stack_a) == 3 && is_sorted(*stack_a))
		sort_3(stack_a);
	size_b = ft_lstsize(*stack_b);
	while (size_b > 0)
	{
		before_push_b(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
		size_b--;
	}
	set_min_on_head(stack_a);
}
