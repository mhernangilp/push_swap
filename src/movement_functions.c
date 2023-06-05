
#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*aux;

	aux = (*stack) -> next;
	if (stack_len(*stack) < 2)
		return ;
	(*stack) -> next = aux -> next;
	aux -> next = (*stack);
	*stack = aux;
}

void	push(t_stack **dest, t_stack **orig)
{
	t_stack	*aux;

	aux = *orig;
	if (stack_len(*orig) == 0)
		return ;
	*orig = (*orig) -> next;
	aux -> next = (*dest);
	*dest = aux;
}

void	rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*aux;

	end = *stack;
	aux = *stack;
	if (stack_len(*stack) < 2)
		return ;
	while (end -> next != NULL)
		end = end -> next;
	*stack = (*stack) -> next;
	aux -> next = NULL;
	end -> next = aux;
}

void	reverse(t_stack **stack)
{
	t_stack	*end;

	end = *stack;
	if (stack_len(*stack) < 2)
		return ;
	while (end -> next -> next != NULL)
		end = end -> next;
	end -> next -> next = *stack;
	*stack = end -> next;
	end -> next = NULL;
}
