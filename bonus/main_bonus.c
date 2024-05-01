/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:58:07 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 15:34:01 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	init_stack_a(t_stack **stack_a, char **buffer)
{
	int		i;
	int		nbr;
	t_stack	*node;

	i = 0;
	while (buffer[i])
	{
		nbr = ft_atoi(buffer[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			print_msg();
		if (check_dup(*stack_a, nbr) == 1)
			print_msg();
		node = ft_lstnew(nbr);
		ft_lstadd_back(stack_a, node);
		i++;
	}
}

void	check_instructions(t_stack **stack_a, t_stack **stack_b, char *oper)
{
	if (!ft_strcmp(oper, "sa\n"))
		sa(*stack_a);
	else if (!ft_strcmp(oper, "sb\n"))
		sb(*stack_b);
	else if (!ft_strcmp(oper, "ss\n"))
		ss(*stack_a, *stack_b);
	else if (!ft_strcmp(oper, "ra\n"))
		ra(*stack_a);
	else if (!ft_strcmp(oper, "rb\n"))
		rb(*stack_b);
	else if (!ft_strcmp(oper, "rr\n"))
		rr(*stack_a, *stack_b);
	else if (!ft_strcmp(oper, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(oper, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(oper, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(oper, "pa\n"))
		pa(stack_b, stack_a);
	else if (!ft_strcmp(oper, "pb\n"))
		pb(stack_a, stack_b);
	else
		print_msg();
}

void	check_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*oper;

	oper = get_next_line(0);
	while (oper)
	{
		check_instructions(stack_a, stack_b, oper);
		free(oper);
		oper = get_next_line(0);
	}
	if (!is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	**buffer;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && !av[1][0])
		print_msg();
	else if (ac >= 2)
	{
		i = 1;
		while (av[i])
		{
			check_spaces(av[i]);
			buffer = ft_split(av[i], ' ');
			init_stack_a(&stack_a, buffer);
			check_charac(buffer);
			i++;
		}
		check_operations(&stack_a, &stack_b);
	}
}
