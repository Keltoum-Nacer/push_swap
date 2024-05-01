/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:03:57 by knacer            #+#    #+#             */
/*   Updated: 2024/04/29 15:33:42 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	head;

	head = stack_a->nbr;
	while (stack_a->next)
	{
		stack_a->nbr = stack_a->next->nbr;
		stack_a = (stack_a)->next;
	}
	(stack_a)->nbr = head;
	head = stack_b->nbr;
	while (stack_b->next)
	{
		stack_b->nbr = stack_b->next->nbr;
		stack_b = stack_b->next;
	}
	stack_b->nbr = head;
	write(1, "rr\n", 3);
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
	write(1, "pb\n", 3);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (stack_b == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_b);
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	write(1, "pa\n", 3);
}
