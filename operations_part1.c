/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:17:40 by knacer            #+#    #+#             */
/*   Updated: 2024/04/05 01:35:42 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    if (stack_a == NULL || stack_a->next == NULL)
        return;
    int tmp;

    tmp = stack_a->nbr;
    stack_a->nbr = stack_a->next->nbr;
    stack_a->next->nbr = tmp;
}

void    sb(t_stack *stack_b)
{
    if (stack_b == NULL || stack_b->next == NULL)
        return;
    int tmp;

    tmp = stack_b->nbr;
    stack_b->nbr = stack_b->next->nbr;
    stack_b->next->nbr = tmp;
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL)
        return;
    t_stack *tmp;
    
    tmp = *stack_b;
    *stack_b = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_b)->next = tmp;
}

void    pa(t_stack **stack_b, t_stack **stack_a)
{
    if (stack_b == NULL)
        return;
    t_stack *tmp;

    tmp = *stack_a;
    *stack_a = (*stack_b);
    *stack_b = (*stack_b)->next;
    (*stack_a)->next = tmp;
}

