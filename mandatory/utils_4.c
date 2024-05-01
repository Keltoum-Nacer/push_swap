/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:32 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 15:17:30 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_charac(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') && (av[i][j + 1] == '-'
					|| av[i][j + 1] == '+'))
				print_msg();
			if ((av[i][j] == '+' && av[i][j + 1] == '+') || (av[i][j] == '-'
					&& av[i][j + 1] == '-') || (av[i][j] == '+'
					&& av[i][j] == '-') || (av[i][j] == '-' && av[i][j] == '+'))
				print_msg();
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-'
				&& av[i][j] != '+')
				print_msg();
			j++;
		}
		i++;
	}
}

void	check_spaces(char *av)
{
	int	j;

	j = 0;
	while (av[j] == ' ')
	{
		j++;
	}
	if (j == ft_strlen(av))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	ft_lstadd_back_m(t_malloc **lst, t_malloc *new)
{
	t_malloc	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_malloc	*ft_lstnew_m(void *data)
{
	t_malloc	*ptr;

	ptr = malloc(sizeof(t_malloc));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
	ptr->next = NULL;
	return (ptr);
}

void	*ft_malloc(size_t size)
{
	void			*ptr;
	static t_malloc	*head;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_lstadd_back_m(&head, ft_lstnew_m(ptr));
	return (ptr);
}
