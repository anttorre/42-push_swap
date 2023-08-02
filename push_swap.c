/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:47:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/02 17:40:55 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	imprimir_lista_enlazada(t_data *data)
{
	t_list	*nodo_actual;

	nodo_actual = data->stack_a;
	while (nodo_actual != NULL)
	{
		ft_printf("%d\n", nodo_actual->content);
		nodo_actual = nodo_actual->next;
	}
}

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}



void	initialize_data(t_data *data)
{
	data->arr = NULL;
	data->i = 0;
	data->j = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	atexit(ft_leaks);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	initialize_data(data);
	if (argc > 2)
	{
		if (check_args(argv, data, argc) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		if (check_args1(argv, data) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else
		return (free(data), EXIT_FAILURE);
	if (init_stack_a(data) == EXIT_FAILURE)
		return (ft_free_full_arr(data->arr), ft_lstclear(&data->stack_a, &del_content), free(data), ft_printf("Error\n"), EXIT_FAILURE);
	imprimir_lista_enlazada(data);
	return (ft_free_full_arr(data->arr), ft_lstclear(&data->stack_a, &del_content), free(data), EXIT_SUCCESS);
}
