/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-11 17:29:54 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-11-11 17:29:54 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->s_index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

int	del_stack(t_stack *stack)
{
	t_node	*first;
	int		data;

	if (!stack->head)
		exit(1);
	first = stack->head;
	data = first->data;
	stack->head = first->next;
	free(first);
	first = NULL;
	stack->size--;
	return (data);
}
