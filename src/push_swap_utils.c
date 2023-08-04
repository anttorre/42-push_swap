/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:43:44 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/04 14:43:27 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_content(void *content)
{
	content = NULL;
}

long long int	ft_atol(const char *str)
{
	long long int	num;
	unsigned int	i;
	long long int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

int	int_cmp(t_data *data, long long n)
{
	t_list	*aux;

	aux = data->stack_a;
	if (n < MIN_INT || n > MAX_INT)
		return (EXIT_FAILURE);
	while (aux != NULL)
	{
		if ((long long)aux->content == n)
			return (EXIT_FAILURE);
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}

int	init_stack_a(t_data *data)
{
	t_list		*new;
	long long	n;

	data->i = -1;
	while (data->arr[++data->i] != NULL)
	{
		n = ft_atol(data->arr[data->i]);
		if (int_cmp(data, n) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		new = ft_lstnew((void *)(intptr_t)n);
		ft_lstadd_back(&data->stack_a, new);
	}
	return (EXIT_SUCCESS);
}
