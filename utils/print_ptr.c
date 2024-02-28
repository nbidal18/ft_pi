/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:06:01 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/28 12:56:06 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_ptr(void *p)
{
	uintptr_t	ptr_value;

	if (p == NULL || p == 0)
		return (write(1, "0x0", 3));
	else
	{
		ptr_value = (uintptr_t)p;
		return (print_nbr(ptr_value, 16, 1));
	}
}
