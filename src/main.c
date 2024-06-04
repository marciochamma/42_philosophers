/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:50:48 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/06 21:48:13 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*base;
	t_philo	*philo;

	arg_check(argc, argv);
	base = ft_calloc(1, sizeof(t_data));
	if (!base)
		exit (-2);
	setup_base(argv, base);
	philo = ft_calloc(base->nbr_of_philo, sizeof(t_philo));
	if (!philo)
		exit (-2);
	setup_philo(base, philo);
	thread_mx(base, philo);
	free_base(base);
	free(philo);
	return (0);
}

// exit (-1): input error
// exit (-2): malloc error
// exit (-3): create thread error
// exit (-4): join thread error