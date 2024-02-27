/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:06:01 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/27 17:52:28 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_ptr(void *p)
{
	if (p == NULL)
        return write(1, "0x0", 3);
	uintptr_t ptr_value = (uintptr_t)p;
	return print_nbr(ptr_value, 16);
}