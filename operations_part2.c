/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:02 by knacer            #+#    #+#             */
/*   Updated: 2024/04/02 15:25:06 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    ra(t_stack *stack_a)
{
    int head; 
    
    head = stack_a->nbr;
    while(stack_a->next)
    {
        stack_a->nbr = stack_a->next->nbr;
        stack_a = (stack_a)->next;
    }
    (stack_a)->nbr = head;
}

void    rb(t_stack *stack_b)
{
    int head;
    
    head = stack_b->nbr;
    while(stack_b->next)
    {
        stack_b->nbr = stack_b->next->nbr;
        stack_b = (stack_b)->next;
    }
    (stack_b)->nbr = head;
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void    rra(t_stack **stack_a)
{
    t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack_a) < 2)
		return;
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

void    rrb(t_stack **stack_b)
{
    t_stack *head;
    t_stack *last;
    
    head = *stack_b;
    last  = ft_lstlast(head);
    while(head)
    {
        if(head->next->next == NULL)
        {
            head->next= NULL;
            break;
        }
        head = head->next;
    }
    last->next = *stack_b;
    *stack_b = last;
}
void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);   
}
