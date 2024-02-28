/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:19:46 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/28 16:07:20 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex_up(unsigned int n)
{
	int					count;
	char				*symbols;
	unsigned int		base;

	count = 0;
	symbols = "0123456789ABCDEF";
	base = 16;
	if (n < 0)
		n = -n;
	if (n < base)
		count += ft_putchar(symbols[n]);
	if (n >= base)
	{
		count += ft_puthex_up(n / base);
		count += ft_putchar(symbols[n % base]);
	}
	return (count);
}