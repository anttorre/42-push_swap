/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:02:44 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/04 17:06:26 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rrr1(t_data *data)
{
	void	*content;
	t_list	*aux;
	t_list	*new;

	content = ft_lstlast(data->stack_b)->content;
	ft_lstdelone(ft_lstlast(data->stack_b), &del_content);
	aux = data->stack_b;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_front(&data->stack_b, new);
	ft_printf("rrr\n");
}

void	rrr(t_data *data)
{
	void	*content;
	t_list	*aux;
	t_list	*new;

	content = ft_lstlast(data->stack_a)->content;
	ft_lstdelone(ft_lstlast(data->stack_a), &del_content);
	aux = data->stack_a;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_front(&data->stack_a, new);
	rrr1(data);
}
