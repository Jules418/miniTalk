/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:47:28 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 11:52:50 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_uns(va_list lst, int *len)
{
	unsigned int	n;
	char			*base10;

	n = (unsigned int) va_arg(lst, unsigned int);
	base10 = "0123456789";
	ft_putnbr_base_unsigned(n, base10, 10, len);
}
