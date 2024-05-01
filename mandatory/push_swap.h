/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:09:39 by knacer            #+#    #+#             */
/*   Updated: 2024/05/01 14:46:46 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void				ft_lstadd_back(t_stack **lst, t_stack *new);
char				**ft_split(char const *s, char c);
t_stack				*ft_lstnew(int nbr);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack **stack_a);
int					ft_lstsize(t_stack *stack);
t_stack				*ft_lstlast(t_stack *stack);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack);
int					ft_atoi(const char *str);
void				sort_3(t_stack **stack);
void				algo(t_stack **stack_a, t_stack **stack_b);
int					ft_isdigit(int a);
t_stack				*get_cheapest(t_stack *stack);
void				check_moves(t_stack *stack_a, t_stack *stack_b);
void				find_index(t_stack *stack);
t_stack				*find_min(t_stack *stack);
void				find_target_b(t_stack *stack_a, t_stack *stack_b);
void				before_push_b(t_stack *stack_a, t_stack *stack_b);
void				push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void				set_min_on_head(t_stack **stack_a);
void				rr_ra_rb(int ia, int ib, t_stack **stack_a,
						t_stack **stack_b);
void				rrr_rra_rrb(int i_a, int i_b, t_stack **stack_a,
						t_stack **stack_b);
void				rra_rb(int ia, int ib, t_stack **stack_a,
						t_stack **stack_b);
void				ra_rrb(int ia, int ib, t_stack **stack_a,
						t_stack **stack_b);
void				before_push_a(t_stack *stack_a, t_stack *stack_b);
void				push_a_to_b(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_max(t_stack *stack);
int					max(int a, int b);
int					ft_strlen(char *str);
void				check_charac(char **av);
void				check_spaces(char *av);
void				print_msg(void);
void				*ft_malloc(size_t size);

#endif
