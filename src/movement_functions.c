/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:43:05 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/14 14:43:06 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, char name)
{
	t_stack	*aux;

	if (stack_len(*stack) < 2)
		return ;
	aux = (*stack) -> next;
	(*stack)-> next = aux -> next;
	aux -> next = (*stack);
	*stack = aux;
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	push(t_stack **dest, t_stack **orig, char name)
{
	t_stack	*aux;

	if (stack_len(*orig) == 0)
		return ;
	aux = *orig;
	*orig = (*orig) -> next;
	aux -> next = (*dest);
	*dest = aux;
	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack **stack, char name)
{
	t_stack	*end;
	t_stack	*aux;

	if (stack_len(*stack) < 2)
		return ;
	end = *stack;
	aux = *stack;
	while (end -> next != NULL)
		end = end -> next;
	*stack = (*stack) -> next;
	aux -> next = NULL;
	end -> next = aux;
	write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	reverse(t_stack **stack, char name)
{
	t_stack	*end;

	if (stack_len(*stack) < 2)
		return ;
	end = *stack;
	while (end -> next -> next != NULL)
		end = end -> next;
	end -> next -> next = *stack;
	*stack = end -> next;
	end -> next = NULL;
	write(1, "rr", 2);
	write(1, &name, 1);
	write(1, "\n", 1);
}
