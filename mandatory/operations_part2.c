/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:02 by knacer            #+#    #+#             */
/*   Updated: 2024/04/29 15:32:35 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	head = *stack_a;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	head = *stack_a;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack_a;
	*stack_a = last;
}

void	rrrb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	head = *stack_b;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack_b;
	*stack_b = last;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	head = *stack_b;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrra(stack_a);
	rrrb(stack_b);
	write(1, "rrr\n", 4);
}
