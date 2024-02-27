/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:08:17 by nbidal            #+#    #+#             */
/*   Updated: 2024/02/27 17:32:17 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h> // to remove and actually code them
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
int print_char(int c);
int print_str(char *s);
int print_nbr(int n);
int print_ptr(void *p);
#endif