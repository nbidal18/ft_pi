/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:52:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/28 08:56:54 by nbidal           ###   ########.fr       */
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
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_str(va_arg(args, char *));
			else if (*format == 'p')
				count += print_ptr(va_arg(args, void *));
			else if (*format == 'd' || *format == 'i')
				count += print_nbr(va_arg(args, int), 10);
			else if (*format == 'u')
				count += print_nbr(va_arg(args, unsigned int), 10);
			else if (*format == 'x')
				count += print_nbr(va_arg(args, unsigned int), 16);
			else if (*format == '%')
				count += print_char('%');
			format++;
		}
		else
			count += print_char(*format++);
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	ft_printf("\n");
	count1 = printf("%p\n", NULL);
	printf("1 Count: %d\n", count1);
	count2 = ft_printf("%p\n", NULL);
	ft_printf("2 Count: %d\n", count2);
	ft_printf("\n");
}