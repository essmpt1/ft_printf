/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:08:44 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 19:14:56 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(*args, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(*args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit((long)(va_arg(*args, int)), 10, 0);
	else if (specifier == 'u')
		count += ft_print_digit((long)(va_arg(*args, unsigned int)), 10, 0);
	else if (specifier == 'x')
		count += ft_print_digit((long)(va_arg(*args, unsigned int)), 16, 0);
	else if (specifier == 'X')
		count += ft_print_digit((long)(va_arg(*args, unsigned int)), 16, 1);
	else
		count += ft_print_char(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format || format == 0)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_printf_format(format[++i], &args);
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*
int main()
{
	int count;

	char *s = NULL;
	int number = 2000;

	count = ft_printf("Sou o maior da %s e %s. %d%%\n", "", "arredores", -42);
	ft_printf("FT: %d\n", count);
	count = printf("Sou o maior da %s e %s. %d%%\n", "", "arredores", -42);
	printf("FI: %d\n", count);
	count = ft_printf("%p\n", (void *)s);
	ft_printf("FT count: %d\n", count);
	count = printf("%p\n", (void *)s);
	printf("FI count: %d\n", count);
	count = ft_printf("FT: %s\n", s);
	ft_printf("FT: %d\n", count);
	count = printf("FI: %s\n", s);
	printf("FI: %d\n", count);
	count = ft_printf(NULL);
	ft_printf("FT: %d\n", count);
	count = printf(NULL);
	printf("FI: %d\n", count);

	ft_printf("FTT: %%%%%%\n");
	printf("FII: %%%%%%\n");	

	count = printf("FI Pointer: %p\n", s);
	printf("%d\n", count);
	count = ft_printf("FT pointer: %p\n", s);
	ft_printf("%d\n", count);

	count = ft_printf("Print HEXA FT: %x\n", number);
	ft_printf("%d\n", count);
	count = printf("Print HEXA FI: %x\n", number);
	printf("%d\n", count);
	return (0);
}
*/
