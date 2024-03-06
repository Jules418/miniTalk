/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:22:08 by jbanacze          #+#    #+#             */
/*   Updated: 2024/03/07 00:45:29 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARR_H
# define DYNARR_H

# include <stdlib.h>

typedef struct s_dynarr
{
	char	*arr;
	size_t	len;
	size_t	capacity;
}	*t_dynarr;

t_dynarr	new_dynarr(void);
void		free_dynarr(t_dynarr da);
void		add_dynarr(t_dynarr da, char c);

#endif