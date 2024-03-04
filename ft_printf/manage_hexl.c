/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:46:49 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 11:52:29 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_hexl(va_list lst, int *len)
{
	unsigned int	n;
	char			*base16;

	base16 = "0123456789abcdef";
	n = (unsigned int) va_arg(lst, unsigned int);
	ft_putnbr_base_unsigned(n, base16, 16, len);
}
