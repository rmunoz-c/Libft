/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 16:45:18 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-11-13 16:45:18 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		ft_error("Error\n", TRUE);
	current = stack->head;
	max = current->s_index;
	while (current != NULL)
	{
		if (current->s_index > max)
			max = current->s_index;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int num)
{
	t_node	*current;
	int		position;

	if (stack == NULL || stack->head == NULL)
		ft_error("Error\n", TRUE);
	current = stack->head;
	position = 0;
	while (current != NULL)
	{
		if (current->data == num)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	move_to_top(t_stack *stack, int num)
{
	t_node	*current;
	t_node	*previous;

	if (stack == NULL || stack->head == NULL)
		ft_error("Error\n", TRUE);
	current = stack->head;
	previous = NULL;
	if (current != NULL && current->data == num)
		return ;
	while (current != NULL && current->data != num)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL)
		ft_error("Error\n", TRUE);
	if (previous != NULL)
	{
		previous->next = current->next;
		current->next = stack->head;
		stack->head = current;
	}
}

int	is_already_sorted(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL || stack->head == NULL || stack->head->next == NULL)
		return (1);
	temp = stack->head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	while (stack)
		del_stack(stack);
}
