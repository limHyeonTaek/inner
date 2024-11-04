/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:03:12 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 11:37:51 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
}					t_stack;

typedef struct s_var
{
	int				max_size;
	int				*pivot_arr;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				*list;
	int				list_size;
	int				a_size;
	int				b_size;
}					t_var;

int					main(int ac, char **av);
void				ps_error(t_var *stacks, char **tmp);
void				free_stacks(t_var *stacks);
void				check_sort(t_var *stacks);
int					find_list_max(t_var *stacks);
void				indexing(t_var *stacks);
void				stacking(t_var *stacks);
char				*ps_all_join(int ac, char **av);
void				validate_args(int ac, char **av, t_var *stacks);
void				init_stack(t_var *var);
void				push_top(t_stack *stack, t_node *new_node);
void				push_bottom(t_stack *stack, t_node *new_node);
t_node				*pop_top(t_stack *stack);
t_node				*pop_bottom(t_stack *stack);
t_node				*get_new_node(int num);
void				sa(t_var *stacks);
void				sb(t_var *stacks);
void				ss(t_var *stacks);
void				pa(t_var *stacks);
void				pb(t_var *stacks);
void				ra(t_var *stacks);
void				rb(t_var *stacks);
void				rr(t_var *stacks);
void				rra(t_var *stacks);
void				rrb(t_var *stacks);
void				rrr(t_var *stacks);
void				operating(t_var *stacks);
void				sort_args(t_var *stacks);
void				sort_big_last(t_var *stacks);
void				sort_three_args(t_var *stacks);
void				get_min_rotate(t_var *stacks, int *a, int *b);
void				rotate_a(t_var *stacks, int a);
void				rotate_b(t_var *stacks, int b);
void				rotate_same(t_var *stacks, int *a, int *b);
void				divide_pivot(t_var *stacks);
int					get_bigger(int a, int b, int a_loc, int b_loc);
int					get_stack_min(t_var *stacks);
int					get_stack_max(t_var *stacks);
int					find_a_location(int num, t_var *stacks);
int					find_a_min(t_var *stacks);
int					find_a_max(t_var *stacks);
int					find_a_mid(int num, t_var *stacks);

#endif