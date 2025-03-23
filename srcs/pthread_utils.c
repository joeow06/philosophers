/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:53:49 by jow               #+#    #+#             */
/*   Updated: 2025/03/21 18:14:00 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex(pthread_mutex_t *mutex, t_mtx_type type);
void	ft_thread(pthread_t *thread, void *(*func)(void *), void *arg, \
		t_thread_type type);

void	ft_mutex(pthread_mutex_t *mutex, t_mtx_type type)
{
	if (type == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			print_error_exit("Mutex init failed");
	}
	else if (type == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			print_error_exit("Mutex destroy failed");
	}
	else if (type == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			print_error_exit("Mutex lock failed");
	}
	else if (type == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			print_error_exit("Mutex unlock failed");
	}
}

/**
 * ft_thread - Wrapper function to manage threads
 * @thread: Pointer to pthread_t (the thread identifier)
 * @func: Pointer to the function that the thread will execute
 * @arg: Pointer to the argument passed to the function
 * 		(typically a t_philo struct)
 * @type: Type of thread operation (INIT, JOIN, DETACH)
 */
void	ft_thread(pthread_t *thread, void *(*func)(void *), void *arg, \
	t_thread_type type)
{
	if (type == INIT)
	{
		if (pthread_create(thread, NULL, func, arg) != 0)
			print_error_exit("Thread init failed");
	}
	else if (type == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			print_error_exit("Thread join failed");
	}
	else if (type == DETACH)
	{
		if (pthread_detach(*thread) != 0)
			print_error_exit("Thread detach failed");
	}
}
