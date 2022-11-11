/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  lpires-n < lpires-n@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:29:37 by  lpires-n         #+#    #+#             */
/*   Updated: 2022/11/10 21:36:43 by  lpires-n        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atolli(const char *nptr)
{
	int				signal;
	long long int	result;

	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	signal = ((ft_isdigit(*nptr) || *nptr == '+') - (*nptr == '-'));
	nptr += (*nptr == '-' || *nptr == '+');
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - '0');
	return (result * signal);
}
