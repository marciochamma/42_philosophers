/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:06:58 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/09 23:21:31 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	counting(t_philo *philo)
{
	pthread_mutex_lock(&philo->base->count);
	philo->eat_count++;
	philo->base->eat_count_all++;
	pthread_mutex_unlock(&philo->base->count);
}

void	printing(t_philo *philo, char *msg)
{
	int	time;

	pthread_mutex_lock(&philo->base->print);
	time = get_time(philo->base->start_time);
	printf("%i %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->base->print);
}
