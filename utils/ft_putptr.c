/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:06:01 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/29 10:21:52 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *p)
{
	int					count;
	char				*symbols;
	unsigned int		base;
	uintptr_t			n;

	count = 0;
	symbols = "0123456789abcdef";
	base = 16;
	n = (uintptr_t)p;
	if (n < 0)
		n = -n;
	if (n < base)
	{
		count += ft_putstr("0x");
		count += ft_putchar(symbols[n]);
	}
	if (n >= base)
	{
		count += ft_putstr("0x");
		count += ft_puthex(n / base);
		count += ft_putchar(symbols[n % base]);
	}
	return (count);
}
