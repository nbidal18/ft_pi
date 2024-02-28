/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:52:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/28 16:42:24 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
				count += ft_putptr(va_arg(args, void *));
			else if (*format == 'd' || *format == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				count += ft_putnbr_u(va_arg(args, unsigned int));
			else if (*format == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
			else if (*format == 'X')
				count += ft_puthex_up(va_arg(args, unsigned int));
			else if (*format == '%')
				count += ft_putchar('%');
			format++;
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	ft_printf("\n");
	count1 = printf("1 • %d\n", 2147483647);
	printf("1 • %d\n", count1);
	count2 = ft_printf("2 • %d\n", 2147483647);
	ft_printf("2 • %d\n", count2);
	ft_printf("\n");
}*/