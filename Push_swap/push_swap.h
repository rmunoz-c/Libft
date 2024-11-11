/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-11 16:00:52 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-11-11 16:00:52 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

void	push_stack(t_stack *stack, int index, int data);
int		del_stack(t_stack *stack);
void	swap(t_stack *stack, char x, t_bool b);
void	push(t_stack *stack1, t_stack *stack2, char x, t_bool b);
void	rotate(t_stack *stack, char x, t_bool b);
void	reverse_rotate(t_stack *stack, char x, t_bool b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	reverese_rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif