/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:09:16 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 15:35:07 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	check_dup(t_stack *stack_a, int nbr)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a)
	{
		if (stack_a->nbr == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
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

void	check_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_3(&stack_a);
		else
			algo(&stack_a, &stack_b);
	}
	else
		exit(0);
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
			check_charac(buffer);
			init_stack_a(&stack_a, buffer);
			i++;
		}
		check_stack_a(stack_a, stack_b);
	}
}
