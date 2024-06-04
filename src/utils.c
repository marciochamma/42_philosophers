/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:27:35 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/05 13:11:17 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*new_str;
	size_t	i;

	if (nitems == 0 || size == 0)
		return (malloc(0));
	if ((nitems * size) / size != nitems)
		return (0);
	new_str = (void *)malloc(nitems * size);
	if (!new_str)
		return (0);
	i = 0;
	while (i < nitems * size)
	{
		((char *)new_str)[i] = 0;
		i++;
	}
	return (new_str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
