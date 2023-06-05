
#include "../push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*aux;

	aux = (*stack) -> next;
	if (stack_len(*stack) < 2)
		return ;
	(*stack) -> next = aux -> next;
	aux -> next = (*stack);
	*stack = aux;
}
