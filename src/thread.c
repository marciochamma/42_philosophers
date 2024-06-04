/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:22:22 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/23 13:17:19 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_control(void *thread_data)
{
	t_philo		*philo;

	philo = (t_philo *)thread_data;
	while (42)
	{
		if (checking_all_eat(philo))
			return (NULL);
		if (checking_death (philo))
			return (NULL);
		usleep(200);
	}
	return (NULL);
}

void	*one_philo_action(t_philo *philo)
{
	printing(philo, "has taken a fork");
	usleep(philo->base->time_to_die * 1000);
	return (NULL);
}

void	*thread_action(void *thread_data)
{
	t_philo		*philo;

	philo = (t_philo *)thread_data;
	while (42)
	{		
		if (philo->base->nbr_of_philo == 1)
			return (one_philo_action(philo));
		if (checking_stop(philo))
			break ;
		eating(philo);
		if (checking_stop(philo))
			break ;
		thinking(philo);
		if (checking_stop(philo))
			break ;
		sleeping(philo);
		if (philo->id % 2 == 0)
			usleep(5000);
	}
	return (NULL);
}

void	thread_mx(t_data *base, t_philo *philo)
{
	pthread_t	*t1;
	pthread_t	t2;
	int			i;

	t1 = ft_calloc(base->nbr_of_philo, sizeof(pthread_t));
	if (!t1)
		exit (-2);
	if (pthread_create(&t2, NULL, thread_control, philo) != 0)
		exit (-3);
	i = -1;
	while (++i < base->nbr_of_philo)
	{
		if (pthread_create(&t1[i], NULL, thread_action, &(philo[i])) != 0)
			exit (-3);
		usleep(200);
	}
	i = -1;
	while (++i < base->nbr_of_philo)
	{
		if (pthread_join(t1[i], NULL) != 0)
			exit (-4);
	}
	if (pthread_join(t2, NULL) != 0)
		exit (-4);
	free(t1);
}
