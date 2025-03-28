/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:24:05 by jow               #+#    #+#             */
/*   Updated: 2025/03/28 15:04:30 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[36m"
# define MAGEN	"\033[35m"
# define RESET	"\033[0m"

typedef struct s_table	t_table;

typedef enum e_thread_type
{
	CREATE,
	JOIN,
	DETACH
}	t_thread_type;

typedef enum e_mutex_type
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
}	t_mtx_type;

typedef enum e_status
{
	GOT_LEFT_FORK,
	GOT_RIGHT_FORK,
	THINKING,
	SLEEPING,
	EATING,
	DIED
}	t_status;

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork_mtx;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				meals;
	time_t			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	ph_mtx;
	pthread_t		ph_thread;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	int				philo_count;
	int				meals;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	bool			is_exit;
	bool			is_dead;
	int				active_philo;
	pthread_t		death_thread;
	pthread_mutex_t	read_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	t_philo			*philo;
}					t_table;

/* PARSER_C */
int		check_number(char *str);
int		check_valid_args(int ac, char **av);
void	parse_args(int ac, char **av, t_table *table);
void	parser(int ac, char **av, t_table *table);

/*	UTILS_C */
int		ft_atoi(const char *str);
time_t	get_time_in_ms(void);
void	ft_wait(time_t time, t_table *table);
void	active_philo(t_table *table);

/*	PTHREAD_UTILS_C*/
void	ft_mutex(pthread_mutex_t *mutex, t_mtx_type type);
void	ft_thread(pthread_t *thread, void *(*func)(void *), void *arg, \
		t_thread_type type);

/*	ERROR_C */
void	print_error_exit(char *str);

/*	INIT_C */
void	init(int ac, char **av, t_table *table);

/*	SIMULATION_C */
void	simulation(t_table *table);

/*	SET_GET_C */
void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_time(pthread_mutex_t *mutex, time_t *value, time_t new_value);
long	get_time(pthread_mutex_t *mutex, time_t *value);

/*	PRINT_C */
void	print_status(t_philo *philo, t_status status);

/*	MONITOR_C */
void	*monitoring(void *data);


#endif
