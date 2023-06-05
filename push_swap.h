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
	struct s_stack	*next;
}	t_stack;

void	exit_program(t_stack *a, t_stack *b);
int		check_args(char **argv, int argc);
void initialize_stacks(t_stack **a, t_stack **b, char **argv, int argc);
int	ft_atoi(const char *str);

//Movement functions
void	swap(t_stack **stack);
void	push(t_stack **dest, t_stack **orig);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);

//Basic functions
t_stack	*new_node(char *value);
int	stack_len(t_stack *stack);
int	is_ordered(t_stack *stack);

//Extra functions
void	print_stack(char name, t_stack *stack);

#endif
