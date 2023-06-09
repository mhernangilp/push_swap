/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:22:46 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 20:10:56 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_program(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (a)
		while (stack_len(*a) != 0)
		{
			aux = *a;
			*a = aux -> next;
			free(aux -> value);
			free(aux -> index);
			free(aux -> arr);
			free(aux -> arr_size);
		}
	if (b)
		while (stack_len(*b) != 0)
		{
			aux = *b;
			*b = aux -> next;
			free(aux -> value);
			free(aux -> index);
			free(aux -> arr);
			free(aux -> arr_size);
		}
	exit(0);
}
