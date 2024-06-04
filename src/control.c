/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:39:57 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/10 16:09:40 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checking_delay(t_philo *philo)
{
	int	average;
	int	result;

	while (42)
	{
		result = 0;
		pthread_mutex_lock(&philo->base->count);
		average = philo->base->eat_count_all / philo->base->nbr_of_philo;
		if (philo->eat_count > average)
			result = 1;
		pthread_mutex_unlock(&philo->base->count);
		if (result)
			usleep(200);
		else
			break ;
	}
}

int	checking_all_eat(t_philo *philo)
{
	t_data	*base;
	int		result;
	int		i;

	base = philo[0].base;
	if (base->nbr_times_eat < 1)
		return (0);
	result = 1;
	i = 0;
	while (i < base->nbr_of_philo)
	{		
		pthread_mutex_lock(&philo->base->count);
		if (philo[i].eat_count < philo[i].base->nbr_times_eat)
			result = 0;
		pthread_mutex_unlock(&philo->base->count);
		i++;
	}
	return (result);
}

int	checking_death(t_philo *philo)
{
	t_data	*base;
	int		result;
	int		i;

	base = philo[0].base;
	result = 0;
	i = 0;
	while (i < base->nbr_of_philo)
	{		
		pthread_mutex_lock(&philo->base->time);
		if (get_time(philo[i].last_eat_time) > base->time_to_die)
		{
			philo[i].base->death = 1;
			result = 1;
			printing(&philo[i], "died");
		}
		pthread_mutex_unlock(&philo->base->time);
		if (result)
			break ;
		i++;
	}
	return (result);
}

int	checking_stop(t_philo *philo)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->base->count);
	if (philo->eat_count == philo->base->nbr_times_eat)
		result = 1;
	pthread_mutex_unlock(&philo->base->count);
	pthread_mutex_lock(&philo->base->time);
	if (philo->base->death == 1)
		result = 1;
	pthread_mutex_unlock(&philo->base->time);
	return (result);
}
