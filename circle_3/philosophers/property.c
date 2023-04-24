/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:48:44 by dayun             #+#    #+#             */
/*   Updated: 2023/04/12 14:59:44 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_is_dead(t_info *info)
{
	pthread_mutex_lock(&(info->mutex_dead));
	if (info->is_dead_any)
	{
		pthread_mutex_unlock(&(info->mutex_dead));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(info->mutex_dead));
		return (0);
	}
}

void	set_is_dead(t_info *info)
{
	pthread_mutex_lock(&(info->mutex_dead));
	info->is_dead_any = DEAD;
	pthread_mutex_unlock(&(info->mutex_dead));
}

int	get_meals_count_finish(t_info *info)
{
	int	count;

	pthread_mutex_lock(&(info->mutex_all_eaten));
	count = info->finished_eat_how_many;
	pthread_mutex_unlock(&(info->mutex_all_eaten));
	return (count);
}

void	set_meals_count_finish(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->mutex_all_eaten));
	if (info->eat_times != 0 && philo->meals_count == info->eat_times)
		info->finished_eat_how_many++;
	pthread_mutex_unlock(&(info->mutex_all_eaten));
}

long long	get_last_meal_time(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&(philo->mutex_philo));
	time = philo->last_meal_time;
	pthread_mutex_unlock(&(philo->mutex_philo));
	return (time);
}
