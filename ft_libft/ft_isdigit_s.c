/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:15:39 by frukundo          #+#    #+#             */
/*   Updated: 2023/12/13 08:20:08 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_s(char *string)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (string[i])
	{
		if (ft_isdigit(string[i]) == 1)
			result = 1;
		else
			return (0);
		i++;
	}
	return (result);
}
