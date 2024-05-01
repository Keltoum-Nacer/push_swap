/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:21:02 by knacer            #+#    #+#             */
/*   Updated: 2024/04/30 23:26:49 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = stack_a->nbr;
	stack_a->nbr = stack_a->next->nbr;
	stack_a->next->nbr = tmp;
}

void	sb(t_stack *stack_b)
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
	sa(stack_a);
	sb(stack_b);
}

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
}
