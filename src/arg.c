/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:06:07 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/05 22:43:15 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_natural(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (0);
	if (ft_atoi(str) < 0 || ft_atoi(str) > INT_MAX)
		return (0);
	return (1);
}

void	arg_check_cont(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1)
	{
		printf("wrong input: at least one philosopher\n");
		exit (-1);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("wrong input: max eat cant be zero\n");
		exit (-1);
	}
}

void	arg_check(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("wrong input: %i argment(s)\n", argc);
		exit (-1);
	}
	i = 1;
	while (argv[i])
	{
		if (!is_natural(argv[i]))
		{
			printf("wrong input: %s not natural\n", argv[i]);
			exit (-1);
		}
		i++;
	}
	arg_check_cont(argc, argv);
}
