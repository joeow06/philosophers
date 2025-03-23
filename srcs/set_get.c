/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:16:14 by jow               #+#    #+#             */
/*   Updated: 2025/03/23 23:37:07 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	set_long(pthread_mutex_t *mutex, long *value, long new_value)
{
	ft_mutex(mutex, LOCK);
	*value = new_value;
	ft_mutex(mutex, UNLOCK);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	ret;

	ft_mutex(mutex, LOCK);
	ret = *value;
	ft_mutex(mutex, UNLOCK);
	return (ret);
}
