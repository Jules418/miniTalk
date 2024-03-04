/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:47:24 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 11:58:56 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_str(va_list lst, int *len)
{
	char	*str;

	str = (char *) va_arg(lst, char *);
	if (!str)
		return (ft_putstr("(null)", len));
	ft_putstr(str, len);
}
