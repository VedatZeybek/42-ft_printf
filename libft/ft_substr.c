/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:12:30 by vzeybek           #+#    #+#             */
/*   Updated: 2025/06/02 19:28:04 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t size)
{
	char	*result;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (start > str_len)
		return (NULL);
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
