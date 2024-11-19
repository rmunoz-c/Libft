/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 16:03:05 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-11-13 16:03:05 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b, int mid)
{
	while (stack_a->size > 3)
	{
		if (stack_a->head->s_index <= mid)
		{
			push(stack_a, stack_b, 'b', TRUE);
		}
		else
		{
			rotate(stack_a, 'a', TRUE);
		}
	}
}

void	max_index_sort(t_stack *stack_a)
{
	int	max;

	max = find_max(stack_a);
	if (stack_a->head->s_index == max)
		rotate(stack_a, 'a', TRUE);
	else if (stack_a->head->next->s_index == max)
		swap(stack_a, 'a', TRUE);
	if (stack_a->head->s_index > stack_a->head->next->s_index)
		swap(stack_a, 'a', TRUE);
}

void	back_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	while (stack_b->size > 0)
	{
		max = find_max(stack_b);
		move_to_top(stack_b, max);
		push (stack_a, stack_b, 'a', TRUE);
	}
}

void	turkish(t_stack *stack_a, t_stack *stack_b)
{
	int	total;
	int	mid;

	total = stack_a->size;
	mid = (total + 1) / 2;
	push_b(stack_a, stack_b, mid);
	max_index_sort(stack_a);
	back_a(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *c, int lenght)
{
	if (is_already_sorted(stack_a) == 0)
	{
		free(c);
		free_stack(stack_a);
		ft_error("Ya esta ordenado", TRUE);
	}
	else if (stack_a->size > 1)
	{
		turkish(stack_a, stack_b);
		free(c);
	}
	else
	{
		free(c);
		free_stack(stack_a);
		ft_error("Error\n", TRUE);
	}
}
