#include "../push_swap.h"

t_stack	*new_node(char *value)
{
	t_stack	*node;
	int		*temp_value;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	temp_value = malloc(sizeof(int));
	if (!temp_value)
		return (NULL);
	*temp_value = ft_atoi(value);
	node -> value = temp_value;
	node -> next = NULL;
	return (node);
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

int	is_sorted(t_stack *stack)
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

//Mode 0: values, mode 1: indexes
int	get_biggest_num(t_stack *stack, int mode)
{
	int	i;

	i = -2147483648;
	if (mode == 0)
	{
		while (stack != NULL)
		{
			if (*stack -> value > i)
				i = *stack -> value;
			stack = stack -> next;
		}
	}
	else
	{
		while (stack != NULL)
		{
			if (*stack -> index > i)
				i = *stack -> index;
			stack = stack -> next;
		}
	}
	return (i);
}

//Mode 0: values, mode 1: indexes
int	get_smallest_num(t_stack *stack, int mode)
{
	int	i;

	i = 2147483647;
	if (mode == 0)
	{
		while (stack != NULL)
		{
			if (*stack -> value < i)
				i = *stack -> value;
			stack = stack -> next;
		}
	}
	else
	{
		while (stack != NULL)
		{
			if (*stack -> index < i)
				i = *stack -> index;
			stack = stack -> next;
		}
	}
	return (i);
}
