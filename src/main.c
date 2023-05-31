/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:14:17 by mhernang          #+#    #+#             */
/*   Updated: 2023/05/31 20:33:07 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !check_args(argv))
		exit_program(NULL, NULL);
	else
	{
		initialize_stacks(&a, &b, argv);
	}
	printf("%d\n", a -> value);
	return (0);
}
