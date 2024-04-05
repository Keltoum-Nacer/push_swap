/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:09:16 by knacer            #+#    #+#             */
/*   Updated: 2024/04/05 01:50:02 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int     check_dup(t_stack *stack_a, int nbr)
{
    if (stack_a == NULL)
        return(0);
    while(stack_a)
    {
        if (stack_a->nbr == nbr)
            return(1);
        stack_a = stack_a->next;
    }
    return(0);
}

void    init_stack_a(t_stack **stack_a, char **buffer)
{
    int i;
    int nbr;
    t_stack *node;

    i = 0;
    while(buffer[i])
    {
        nbr = ft_atoi(buffer[i]);
        // if(!ft_isdigit(nbr))
        // {
        //     write(1, "error\n", 6);;
        //     exit(1);
        // }
        if (nbr > INT_MAX || nbr < INT_MIN)
        {
            write(1, "error\n", 6);
            exit(1);
        }
        if (check_dup(*stack_a, nbr) == 1)
        {
            write(1, "error\n", 6);
            exit(1);
        }
        node = ft_lstnew(nbr);
        ft_lstadd_back(stack_a, node);
        i++;
    }
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
 
    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return(1);
    else if (ac >= 2)
    {
        int i;
        char **buffer;
        i = 1;
        while(av[i])
        {
            buffer = ft_split(av[i], ' ');
            init_stack_a(&stack_a, buffer);
            i++;
        }
        if(is_sorted(stack_a))
        {
            //printf("waa3");
            if(ft_lstsize(stack_a) == 2)
                sa(stack_a);
            else if(ft_lstsize(stack_a) == 3)
                sort_3(&stack_a);
            else
                algo(&stack_a, &stack_b);
        }
        while(stack_a)
        {
            printf("%d\n", stack_a->nbr);
            stack_a = stack_a->next;
        }
        printf("-------------------\n");
        while(stack_b)
        {
            printf("%d\n", stack_b->nbr);
            stack_b = stack_b->next;
        }
    }
}
