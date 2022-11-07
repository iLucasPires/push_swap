/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 07:09:30 by lpires-n          #+#    #+#             */
/*   Updated: 2022/06/11 18:10:13 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	counter_number(int n)
{
	int		i;

	i = 0;
	if (n < 0 || n == 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	void	number_for_string(int number, char *number_string)
{
	int	len;
	int	aux;
	int	i;

	i = 0;
	aux = 0;
	len = counter_number(number);
	if (number < 0)
	{
		number *= -1;
		number_string[0] = '-';
		i = 1;
	}
	while (len-- - i)
	{	
		aux = number % 10;
		number = number / 10;
		number_string[len] = aux + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*number_string;
	int		len_number;

	len_number = counter_number(n);
	if (n == -2147483648)
	{
		number_string = ft_strdup("-2147483648");
		return (number_string);
	}
	number_string = malloc(sizeof(char) * (len_number + 1));
	if (number_string == NULL)
		return (NULL);
	number_for_string(n, number_string);
	number_string[len_number] = '\0';
	return (number_string);
}
