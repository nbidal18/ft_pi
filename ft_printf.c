/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:52:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/27 12:15:05 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// specifiers : xX

int print_char(int c)
{
	int	count;

	count = 0;
	write (1, &c, sizeof(int));
	count++;
	return (count);
}

int print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		print_char(*s++);
		count++;
	}
	return (count);
}

int print_ptr(int p)
{
	int	count;

	count = 0;
	write (1, &p, sizeof(void *));
	count++;
	return (count);
}

//doesn't check INT_MAX and INT_MIN
int print_nbr(int n)
{
	int	count;
	int digit;

	count = 0;
	digit = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (count++);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	while (n > 0)
	{
		print_nbr(n / 10);
		digit = n % 10;
		write(1, &digit, 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		count;
	
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(va_arg(args, int)); //to test
			else if (*format == 's')
				count += print_str(va_arg(args, char *)); //to test
			else if (*format == 'p')
				count += print_ptr(va_arg(args, void *)); //to test
			else if (*format == 'd' || *format == 'i')
				count += print_nbr(va_arg(args, int)); //to test
			else if (*format == 'u')
				count += print_nbr(va_arg(args, unsigned int));
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
