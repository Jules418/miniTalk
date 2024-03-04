/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:47:38 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 12:03:50 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef unsigned int	t_ui;
typedef void (			*t_func)(va_list, int*);

void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);

void	ft_putnbr_base(int nbr, char *base, t_ui size_base, int *len);
void	ft_putnbr_base_unsigned(t_ui nbr, char *base, t_ui size_base, int *len);
void	ft_putnbr_ptr(uintptr_t nbr, char *base, uintptr_t size_base, int *len);

void	manage_char(va_list lst, int *len);
void	manage_str(va_list lst, int *len);
void	manage_ptr(va_list lst, int *len);
void	manage_i_d(va_list lst, int *len);
void	manage_uns(va_list lst, int *len);
void	manage_hexl(va_list lst, int *len);
void	manage_hexu(va_list lst, int *len);
void	manage_percent(va_list lst, int *len);

t_func	find_func(char c);

int		ft_printf(const char *format, ...);

#endif
