
#include "../push_swap.h"

void	print_stack(char name, t_stack *stack)
{
	t_stack	*aux;

	printf("-- Name: %c --\n", name);
	aux = stack;
	while (aux != NULL)
	{
		printf("%d   (%d)\n", *aux -> value, *aux -> index);
		aux = aux -> next;
	}
}
