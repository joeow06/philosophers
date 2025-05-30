/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:16:14 by jow               #+#    #+#             */
/*   Updated: 2025/04/02 00:05:06 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_time(pthread_mutex_t *mutex, time_t *value, time_t new_value);
time_t	get_time(pthread_mutex_t *mutex, time_t *value);

void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value)
{
	ft_mutex(mutex, LOCK);
	*value = new_value;
	ft_mutex(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	ret;

	ft_mutex(mutex, LOCK);
	ret = *value;
	ft_mutex(mutex, UNLOCK);
	return (ret);
}

void	set_time(pthread_mutex_t *mutex, time_t *value, time_t new_value)
{
	ft_mutex(mutex, LOCK);
	*value = new_value;
	ft_mutex(mutex, UNLOCK);
}

time_t	get_time(pthread_mutex_t *mutex, time_t *value)
{
	time_t	ret;

	ft_mutex(mutex, LOCK);
	ret = *value;
	ft_mutex(mutex, UNLOCK);
	return (ret);
}
