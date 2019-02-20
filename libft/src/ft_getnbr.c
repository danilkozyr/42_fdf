/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:32:38 by dkozyr            #+#    #+#             */
/*   Updated: 2019/01/17 15:32:38 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(char *str, int *i)
{
	int min;
	int res;

	res = 0;
	min = 1;
	while (str[*i] == ' ')
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			min = -1;
		*i += 1;
	}
	while (ft_isdigit(str[*i]))
	{
		res = res * 10 + str[*i] - 48;
		*i += 1;
	}
	return (res * min);
}
