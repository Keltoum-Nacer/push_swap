/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:56:07 by knacer            #+#    #+#             */
/*   Updated: 2024/04/05 01:50:40 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
int is_sorted(t_stack *stack)
{
    if(!stack)
        return(1);
    while(stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return(1);
        stack = stack->next;
    }
    return(0);
}

void    sort_3(t_stack **stack)
{
    t_stack *head;
    
    head = *stack;
   
        if (head->nbr > head->next->nbr && head->nbr < head->next->next->nbr)
            sa(head);
        else if (head->nbr > head->next->nbr && head->next->nbr > head->next->next->nbr)
        {
            sa(head);
            rra(stack);
        }
        else if(head->nbr > head->next->nbr && head->nbr > head->next->next->nbr)
            ra(head);
        else if (head->nbr < head->next->nbr && head->nbr < head->next->next->nbr)
        {
            sa(head);
            ra(head);
        }
        else if(head->nbr > head->next->next->nbr && head->nbr < head->next->nbr)
            rra(stack);

}

// int find_cheapest(t_stack *stack_a, t_stack *stack_b)
// {
//     while(stack_a)
//     {
        
//     }   
// }

int find_max(t_stack *stack)
{
    int max;
    
    max = stack->nbr;
    stack->pos = 0;
    while(stack->next)
    {
        if (max < stack->next->nbr)
        {
            max = stack->next->nbr;
            stack->pos++;
        }
        stack = stack->next;
    }
    return(max);
}

int find_target(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *node;
    int max;

    node = stack_a;
    node->target = INT_MIN; 
    max = find_max(stack_b);
    while(stack_b)
    {
        if(node->nbr > stack_b->nbr  && stack_b->nbr > node->target)
            node->target = stack_b->nbr;
        stack_b = stack_b->next;
    }
    if (node->target == INT_MIN)
        node->target = max;
  
    return(node->target);   
}

void    algo(t_stack **stack_a, t_stack **stack_b)
{
    int size_a;

    size_a = ft_lstsize(*stack_a);
    if (size_a-- > 3 && is_sorted(*stack_a))
    {
        pb(stack_a, stack_b);
    }
    if (size_a-- > 3 && is_sorted(*stack_a))
    {
        pb(stack_a, stack_b);
    }
    while (size_a  > 3 && is_sorted(*stack_a))
    {
        while(*stack_a)
        {
            int target = find_target(*stack_a, *stack_b);
            printf("target of node is: %d\n", target);
            *stack_a = (*stack_a)->next; 
        }
        size_a--;
    }

    //     max = find_max(stack_b);
    //     if(stack_a->nbr > max)
    //     {
    //         if(stack_b->pos == 1)
    //             rb(stack_b);
    //         pb(&stack_a, &stack_b);
    //     }
    // }
}
