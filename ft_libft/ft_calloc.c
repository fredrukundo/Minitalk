/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:33:50 by frukundo          #+#    #+#             */
/*   Updated: 2023/12/12 22:56:08 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t size)
{
	void	*array;
	size_t	fred;

	fred = num_elements * size;
	if (fred != 0 && fred / num_elements != size)
	{
		write(1, "error", 5);
		return (NULL);
	}
	array = (void *)malloc(num_elements * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (num_elements * size));
	return (array);
}
