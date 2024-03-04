/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:46:19 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 15:52:46 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_til_prctg(const char *format, int *printed_len)
{
	int	i;

	i = 0;
	while (format[i] && (format[i] != '%'))
		i++;
	write(1, format, i);
	*printed_len += i;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_func	function;
	int		i;
	int		printed_len;

	if (format == NULL)
		return (0);
	i = 0;
	printed_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 2;
			function = find_func(format[i - 1]);
			if (!function)
				return (va_end(args), -1);
			function(args, &printed_len);
		}
		else
			i += write_til_prctg(format + i, &printed_len);
	}
	va_end(args);
	return (printed_len);
}
