#include "../push_swap.h"

void	print_stack(char name, t_stack *stack)
{
	t_stack	*aux;
	int		i;

	printf("-- Name: %c --\n", name);
	aux = stack;
	while (aux != NULL)
	{
		printf("%d   (%d) [", *aux -> value, *aux -> index);
		i = -1;
		while (++i < *aux -> arr_size - 1)
			printf("%d, ", aux -> arr[i]);
		printf("%d", aux -> arr[i]);
		printf("]  -%d-\n", *aux -> arr_size);
		aux = aux -> next;
	}
}
