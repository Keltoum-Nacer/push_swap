/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_before_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:16:22 by knacer            #+#    #+#             */
/*   Updated: 2024/04/30 23:19:16 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_ra_rb(int ia, int ib, t_stack **stack_a, t_stack **stack_b)
{
	while (ia > 0 && ib > 0)
	{
		rr(*stack_a, *stack_b);
		ia--;
		ib--;
	}
	while (ia > 0)
	{
		ra(*stack_a);
		ia--;
	}
	while (ib > 0)
	{
		rb(*stack_b);
		ib--;
	}
}

void	rrr_rra_rrb(int i_a, int i_b, t_stack **stack_a, t_stack **stack_b)
{
	while (i_a < ft_lstsize(*stack_a) && i_b < ft_lstsize(*stack_b))
	{
		rrr(stack_a, stack_b);
		i_a++;
		i_b++;
	}
	while (i_a < ft_lstsize(*stack_a))
	{
		rra(stack_a);
		i_a++;
	}
	while (i_b < ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		i_b++;
	}
}

void	rra_rb(int ia, int ib, t_stack **stack_a, t_stack **stack_b)
{
	while (ia < ft_lstsize(*stack_a))
	{
		rra(stack_a);
		ia++;
	}
	while (ib > 0)
	{
		rb(*stack_b);
		ib--;
	}
}

void	ra_rrb(int ia, int ib, t_stack **stack_a, t_stack **stack_b)
{
	while (ia > 0)
	{
		ra(*stack_a);
		ia--;
	}
	while (ib < ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		ib++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
