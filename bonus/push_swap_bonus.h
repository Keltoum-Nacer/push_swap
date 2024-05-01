/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:00:27 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 14:46:39 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				pos;
	int				nbr_of_moves;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_malloc
{
	void			*data;
	struct s_malloc	*next;
}					t_malloc;

void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int					ft_atoi(const char *str);
int					ft_lstsize(t_stack *stack);
t_stack				*ft_lstlast(t_stack *stack);
void				ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_lstnew(int nbr);
int					is_sorted(t_stack *stack);
char				**ft_split(char const *s, char c);
void				check_charac(char **av);
void				check_spaces(char *av);
void				print_msg(void);
int					check_dup(t_stack *stack_a, int nbr);
void				*ft_malloc(size_t size);

#endif
