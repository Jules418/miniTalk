/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:24:48 by jbanacze          #+#    #+#             */
/*   Updated: 2024/03/06 13:48:39 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynarr.h"

t_dynarr new_dynarr(void)
{
	t_dynarr	res;

	res = malloc(sizeof(struct s_dynarr));
	if (!res)
		return (NULL);
	res->arr = NULL;
	res->capacity = 0;
	res->len = 0;
	return (res);
}

void	free_dynarr(t_dynarr da)
{
	if (!da)
		return ;
	if (da->arr)
		free(da->arr);
	free(da);
}

void	resize_dynarr(t_dynarr da, size_t size)
{
	char	*narr;
	size_t	i;

	i = 0;
	narr = malloc(sizeof(char) * size);
	if (narr)
	{
		while (i < da->len)
		{
			narr[i] = da->arr[i];
			i++;
		}
	}
	else
		narr = NULL;
	free(da->arr);
	da->arr = narr;
	da->capacity = size * (narr != NULL);
	da->len = da->len * (da->capacity > 0);
}

void	add_dynarr(t_dynarr da, char c)
{
	if (!da)
		return ;
	if (da->len >= da->capacity)
		resize_dynarr(da, da->capacity * 2 + 1);
	if (da->arr)
	{
		da->arr[da->len] = c;
		da->len++;
	}
}