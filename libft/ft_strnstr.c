/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:15:59 by lpires-n          #+#    #+#             */
/*   Updated: 2022/06/04 06:46:19 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	res;

	len = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (*s1 && (n-- >= len))
	{
		res = ft_strncmp(s1, s2, len);
		if (res == 0 && *s1 == *s2)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
