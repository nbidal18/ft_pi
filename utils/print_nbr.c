/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:06 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/28 08:56:14 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_nbr(int n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n < base)
		count += write(1, &symbols[n], 1);
	else if (n >= base)
	{
		count += print_nbr(n / base, base);
		count += write(1, &symbols[n % base], 1);
	}
	return (count);
}
