/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:47:18 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 12:05:16 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_ptr(va_list lst, int *len)
{
	uintptr_t	ptr;
	static char	base16[16] = "0123456789abcdef";

	ptr = (uintptr_t) va_arg(lst, void *);
	if (!ptr)
		return (ft_putstr("(nil)", len));
	ft_putstr("0x", len);
	ft_putnbr_ptr((uintptr_t) ptr, base16, 16, len);
}
