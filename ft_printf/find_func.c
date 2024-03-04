/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:46:14 by jbanacze          #+#    #+#             */
/*   Updated: 2024/01/05 11:52:17 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_funarr(t_func func_arr[])
{
	func_arr[0] = manage_char;
	func_arr[1] = manage_str;
	func_arr[2] = manage_ptr;
	func_arr[3] = manage_i_d;
	func_arr[4] = manage_i_d;
	func_arr[5] = manage_uns;
	func_arr[6] = manage_hexl;
	func_arr[7] = manage_hexu;
	func_arr[8] = manage_percent;
}

t_func	find_func(char c)
{
	t_func	func_arr[9];
	char	*signs;
	int		i;

	signs = "cspdiuxX%";
	initialize_funarr(func_arr);
	i = 0;
	while (signs[i])
	{
		if (signs[i] == c)
			return (func_arr[i]);
		i++;
	}
	return (NULL);
}
