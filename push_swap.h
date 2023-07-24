/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:50:06 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/24 17:11:54 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/ft_printf.h"
# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

int					check_args(char **argv);
int					check_args1(char **argv);

#endif