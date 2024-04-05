/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:09:39 by knacer            #+#    #+#             */
/*   Updated: 2024/04/05 01:21:01 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


typedef struct s_stack
{
    int nbr;
    int pos;
    int target;
    struct s_stack *next;
    struct s_stack *prev;
}t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	**ft_split(char const *s, char c);
t_stack	*ft_lstnew(int nbr);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_b, t_stack **stack_a);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack **stack_a);
int	ft_lstsize(t_stack *stack);
t_stack	*ft_lstlast(t_stack *stack);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
int is_sorted(t_stack *stack);
int	ft_atoi(const char *str);
void    sort_3(t_stack **stack);
void    algo(t_stack **stack_a, t_stack **stack_b);
int	ft_isdigit(int a);

#endif
