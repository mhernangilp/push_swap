

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
	t_stack	*aux;

	i = 0;
	aux = stack;
	while (aux != NULL)
	{
		i += 1;
		aux = aux -> next;
	}
	return (i);
}
