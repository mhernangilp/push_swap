

#include "../push_swap.h"

t_stack	*new_node(char *value)
{
	t_stack	*node;
	int	*temp_value;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	temp_value = malloc(sizeof(int));
	if (!temp_value)
		return  (NULL);
	*temp_value = ft_atoi(value);
	node -> value = temp_value;
	node -> next = NULL;
	return(node);
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i += 1;
		stack = stack -> next;
	}
	return (i);
}

int	is_ordered(t_stack *stack)
{
	if (stack_len(stack) < 2)
		return (1);
	while (stack -> next != NULL)
	{
		if (*stack -> value > *stack -> next -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
