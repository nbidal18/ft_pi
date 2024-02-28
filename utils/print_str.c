/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:03:42 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/28 09:53:01 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		count += write(1, "(null)", 6);
	while (s != NULL && *s)
		count += print_char(*s++);
	return (count);
}
