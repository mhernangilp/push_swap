/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:12:04 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 20:33:04 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#             include <stdio.h>

#include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*value;
	int		*index;
	int		*arr;
	int		*arr_size;
	struct s_stack	*next;
}	t_stack;

void	exit_program(t_stack **a, t_stack **b);
int		check_args(char **argv, int argc);
void initialize_stacks(t_stack **a, t_stack **b, char **argv, int argc);
int	ft_atoi(const char *str);

//Sort big functions
void	sort_big(t_stack **a, t_stack **b);

//Sort small functions
void	sort_small(t_stack **a, t_stack **b);

//Movement functions
void	swap(t_stack **stack, char name);
void	push(t_stack **dest, t_stack **orig, char name);
void	rotate(t_stack **stack, char name);
void	reverse(t_stack **stack, char name);

//Basic functions
t_stack	*new_node(char *value);
int	stack_len(t_stack *stack);
int	is_sorted(t_stack *stack);
int	get_biggest_num(t_stack *stack, int mode);
int	get_smallest_num(t_stack *stack, int mode);

//Extra functions
void	print_stack(char name, t_stack *stack);

#endif
