/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:47:00 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 14:56:20 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*node;

	node = ft_malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (stack && new)
	{
		temp = *stack;
		if (*stack == NULL)
			*stack = new;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}

t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	if (!stack)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	ft_lstsize(t_stack *stack)
{
	int	cpt;

	cpt = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		cpt++;
		stack = stack->next;
	}
	return (cpt);
}
