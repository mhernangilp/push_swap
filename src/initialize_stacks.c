/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:03:04 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 20:33:10 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void initialize_stacks(t_stack **a, t_stack **b, char **argv)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	*b -> value = -1;
	*a -> value = 1;
}
