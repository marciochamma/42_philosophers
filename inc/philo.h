/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:05:33 by mchamma           #+#    #+#             */
/*   Updated: 2024/05/09 23:22:06 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc
# include <sys/time.h> // gettimeofday
# include <unistd.h> // sleep, write
# include <pthread.h> // thread, mutex

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_data
{
	int					nbr_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_times_eat;
	int					eat_count_all;
	long				start_time;
	int					death;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	pthread_mutex_t		count;
	pthread_mutex_t		time;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					eat_count;
	long				last_eat_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*base;
}	t_philo;

// --------------------------------------- //

void		arg_check(int argc, char **argv);

void		thread_mx(t_data *base, t_philo *philo);

// --------------------------------------- //

void		eating(t_philo *philo);

void		thinking(t_philo *philo);

void		sleeping(t_philo *philo);

void		printing(t_philo *philo, char *msg);

void		counting(t_philo *philo);

// --------------------------------------- //

int			checking_all_eat(t_philo *philo);

int			checking_death(t_philo *philo);

int			checking_stop(t_philo *philo);

// --------------------------------------- //

void		setup_base(char **argv, t_data *base);

void		free_base(t_data *base);

void		setup_philo(t_data *base, t_philo *philo);

// --------------------------------------- //

long		get_abs_time(void);

int			get_time(long ref);

// --------------------------------------- //

void		*ft_calloc(size_t nitems, size_t size);

int			ft_atoi(const char *str);

// --------------------------------------- //

#endif