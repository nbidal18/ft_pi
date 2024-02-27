/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:52:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/27 12:54:03 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// specifiers : xX

int print_char(int c)
{
	return (write (1, &c, 1));
}

int print_str(char *s)
{
	int	count;
	
	count = 0;
	while (*s)
		count += print_char(*s++);
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
		return (write (1, "0", 1));
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	while (n > 0) //ERROR HERE
	{
		print_nbr(n / 10);
		digit = n % 10;
		write(1, &digit, 1);
		count++;
	}
	return (count);
}

int print_ptr(void *p)
{
	if (p == NULL)
		return (write(1, "(null)", 6));
	uintptr_t ptr_value = (uintptr_t)p;
	return print_nbr(ptr_value);
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

int main()
{
	int count1 = 0;
	int count2 = 0;
	count1 = printf("(printf) Hello %s, today is %d.\n", "Nizar", 27);
	printf("(printf) Count: %d\n", count1);
	count2 = ft_printf("(ft_printf) Hello %s, today is %d.\n", "Nizar", 27);
	ft_printf("(ft_printf) Count: %d\n", count2);
}