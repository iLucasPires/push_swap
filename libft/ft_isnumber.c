/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:50:34 by lpires-n          #+#    #+#             */
/*   Updated: 2022/11/10 04:01:31 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *s)
{
	int	verify;

	verify = 0;
	if (((*s == '-') || (*s == '+')) && !ft_isdigit(*(s + 1)))
		return (0);
	if (s[ft_strlen(s) - 1] == '.')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '.')
		return (0);
	while (*s)
	{
		if (*s == '.')
			verify++;
		if (verify > 1)
			return (0);
		if (!ft_isdigit(*s) && *s != '.' && *s)
			return (0);
		s++;
	}
	return (1);
}
