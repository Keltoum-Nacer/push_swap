/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:10:23 by knacer            #+#    #+#             */
/*   Updated: 2024/04/04 16:37:27 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	count_nbsub(char const *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			cpt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cpt);
}

int	count_char(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**affect_str(char **arr, int nbsub, char const *s, char c)
{
	int	len;
	int	j;
	int	i;
	int	k;

	j = 0;
	i = 0;
	while (nbsub--)
	{
		while (s[i] == c)
			i++;
		len = count_char(s + i, c);
		arr[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[j])
		{
			free_arr(arr);
			return (NULL);
		}
		k = 0;
		while (k < len)
			arr[j][k++] = s[i++];
		arr[j++][k] = '\0';
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		nbsub;

	nbsub = count_nbsub(s, c);
	arr = (char **)malloc(sizeof(char *) * (nbsub + 1));
	if (!arr)
		return (NULL);
	if (affect_str(arr, nbsub, s, c) == NULL)
		return (NULL);
	return (arr);
}

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> nbr = nbr;
	node -> next = NULL;
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
			while (temp -> next)
				temp = temp -> next;
			temp -> next = new;
		}
	}
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		new -> next = *stack;
		*stack = new;
	}
}

t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	if (!stack)
		return (NULL);
	while (node -> next)
		node = node -> next;
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
		stack = stack -> next;
	}
	return (cpt);
}

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	i;
	int	s;

	x = 0;
	s = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		x = x * 10 + (str[i] - '0');
		i++;
	}
	return (s * x);
}
