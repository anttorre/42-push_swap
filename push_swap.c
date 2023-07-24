/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:47:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/24 17:03:53 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc > 2)
	{
		if (check_args(argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		if (check_args1(argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
