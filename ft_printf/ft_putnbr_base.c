/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:46:24 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 12:12:39 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, unsigned int size_base, int *len)
{
	unsigned int	n;

	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr *= -1;
	}
	n = nbr;
	if (n >= size_base)
		ft_putnbr_base(n / size_base, base, size_base, len);
	ft_putchar(base[n % size_base], len);
}

void	ft_putnbr_base_unsigned(t_ui nbr, char *base, t_ui size_base, int *len)
{
	if (nbr >= size_base)
		ft_putnbr_base_unsigned(nbr / size_base, base, size_base, len);
	ft_putchar(base[nbr % size_base], len);
}

void	ft_putnbr_ptr(uintptr_t nbr, char *base, uintptr_t size_base, int *len)
{
	if (nbr >= size_base)
		ft_putnbr_ptr(nbr / size_base, base, size_base, len);
	ft_putchar(base[nbr % size_base], len);
}
