/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:41:51 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/09 23:17:20 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (checking_stop(philo) == 0)
	{
		printing(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (checking_stop(philo) == 0)
		{
			printing(philo, "has taken a fork");
			if (checking_stop(philo) == 0)
			{
				printing(philo, "is eating");
				pthread_mutex_lock(&philo->base->time);
				philo->last_eat_time = get_abs_time();
				pthread_mutex_unlock(&philo->base->time);
				usleep(philo->base->time_to_eat * 1000);
				counting(philo);
			}
		}
		pthread_mutex_unlock(philo->left_fork);
	}
	pthread_mutex_unlock(philo->right_fork);
}

void	eating_left(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (checking_stop(philo) == 0)
	{
		printing(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		if (checking_stop(philo) == 0)
		{		
			printing(philo, "has taken a fork");
			if (checking_stop(philo) == 0)
			{
				printing(philo, "is eating");
				pthread_mutex_lock(&philo->base->time);
				philo->last_eat_time = get_abs_time();
				pthread_mutex_unlock(&philo->base->time);
				usleep(philo->base->time_to_eat * 1000);
				counting(philo);
			}
		}
		pthread_mutex_unlock(philo->right_fork);
	}
	pthread_mutex_unlock(philo->left_fork);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 != 0)
		eating_right(philo);
	else
		eating_left(philo);
}

void	thinking(t_philo *philo)
{
	printing(philo, "is thinking");
	usleep(500);
}

void	sleeping(t_philo *philo)
{
	printing(philo, "is sleeping");
	usleep(philo->base->time_to_sleep * 1000);
}
