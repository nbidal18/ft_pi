/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:51 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/27 16:50:42 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//doesn't check INT_MAX and INT_MIN
/*int print_nbr(int n)
{
	int	count;
	int digit;
	char *symbols;

	count = 0;
	digit = 0;
	symbols = "0123456789abcdefABCDEF";
	if (n < 0) //count++ here is not working???
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	if (n < 10)
	{
		write (1, &symbols[n], 1);
		count++;
	}
	while (n >= 10)
	{
		digit = n % 10;
		if (n / 10 >= 1)
			print_nbr(n / 10);
		write(1, &digit, 1);
		count++;
	}
	return (count);	
}*/

int print_nbr(long n)
{
	char	str[12];
	int		count;
	char	*symbols;
	int		i;

	i = 0;
	count = 0;
	symbols = "0123456789abcdefABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	while (n < 10)
	{
		write (1, &symbols[n], 1);
		count++;
	}
	str[i + 1] = 0;
	i--;
	while (i >= 0)
	{
		write (1, &str[i--], 1);
		count++;
	}
	return (count);
}
