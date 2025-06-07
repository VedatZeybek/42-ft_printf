/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:15:48 by vzeybek           #+#    #+#             */
/*   Updated: 2025/06/02 21:42:40 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len - 1;
	if (len == 0 || dst == src)
		return (dst);
	if (dst > src)
	{
		while (i > 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
		if (i == 0)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
