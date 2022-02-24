# philosophers

## Production period.
- (21.08.03 ~ 21.09.22)

### Keywords
- Unix logic
### Skills
- Unix
- Rigor
- Imperative programming

## Overview
### What you should understand to succeed this project:
- One or more philosophers are sitting at a round table either eating, either thinking,
either sleeping. While they are eating, they do not think or sleep; while thinking
they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.
- The philosophers sit at a circular table with a large bowl of spaghetti in the center.
- There are some forks on the table. Serving and eating spaghetti with a single fork
is very inconvenient, so the philosophers will eat with two forks, one for each hand.
- Each time a philosopher finishes eating, they will drop their forks and start sleeping.
Once they have finished sleeping, they will start thinking. The simulation stops
when a philosopher dies.
- Every philosopher needs to eat and they should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know when another philosopher is about to die.
- No need to say that philosophers should avoid dying!

## Mandatory
### Program name 
- philo
### Turn in files 
- philo/
### Makefile
- Yes
### Arguments
- number_of_philosophers
- time_to_die
- time_to_eat
- time_to_sleep 
- [number_of_times_each_philosopher_must_eat]
### Libft authorized 
- No
### Description
- philosopher with threads and mutex

### The specific rules
- Each philosopher should be a thread.
- One fork between each philosopher, therefore if they are multiple philosophers, there
will be a fork at the right and the left of each philosopher.
- To avoid philosophers duplicating forks, you should protect the forks state with a
mutex for each of them.

## Score
[![sjin's 42Project Score](https://badge42.herokuapp.com/api/project/sjin/Philosophers)]
