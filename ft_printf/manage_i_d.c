/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_i_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:47:03 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 11:52:42 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_i_d(va_list lst, int *len)
{
	int		n;
	char	*base10;

	n = (int) va_arg(lst, int);
	base10 = "0123456789";
	ft_putnbr_base(n, base10, 10, len);
}
