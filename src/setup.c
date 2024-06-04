/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:45:50 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/09 13:23:04 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_base(t_data *base)
{
	int	i;

	if (base->fork)
	{
		i = 0;
		while (i < base->nbr_of_philo)
		{
			pthread_mutex_destroy(&base->fork[i]);
			i++;
		}
		free(base->fork);
	}
	pthread_mutex_destroy(&base->print);
	pthread_mutex_destroy(&base->count);
	pthread_mutex_destroy(&base->time);
	free(base);
}

void	setup_base(char **argv, t_data *base)
{
	int		i;

	base->nbr_of_philo = ft_atoi(argv[1]);
	base->time_to_die = ft_atoi(argv[2]);
	base->time_to_eat = ft_atoi(argv[3]);
	base->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		base->nbr_times_eat = ft_atoi(argv[5]);
	else
		base->nbr_times_eat = -1;
	base->eat_count_all = 0;
	base->start_time = get_abs_time();
	base->death = 0;
	pthread_mutex_init(&base->print, NULL);
	pthread_mutex_init(&base->count, NULL);
	pthread_mutex_init(&base->time, NULL);
	base->fork = ft_calloc(base->nbr_of_philo, sizeof(pthread_mutex_t));
	i = 0;
	while (i < base->nbr_of_philo)
		pthread_mutex_init(&base->fork[i++], NULL);
}

void	setup_philo(t_data *base, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < base->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].base = base;
		philo[i].left_fork = &base->fork[i];
		philo[i].right_fork = &base->fork[(i + 1) % base->nbr_of_philo];
		philo[i].eat_count = 0;
		philo[i].last_eat_time = base->start_time;
		i++;
	}
}
