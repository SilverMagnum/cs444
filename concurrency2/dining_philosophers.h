#ifndef DINING_PHILOSOPHERS_H
#define DINING_PHILOSOPHERS_H
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define NUM_PHILOSOPHERS 5
#define NUM_FORKS NUM_PHILOSOPHERS

struct philosopher {
    char *name;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
};

extern struct philosopher Philosophers[NUM_PHILOSOPHERS];
extern pthread_t Workers[NUM_PHILOSOPHERS];
extern pthread_mutex_t Locks[NUM_PHILOSOPHERS];
extern char *PhilosopherNames[NUM_PHILOSOPHERS];

void think();
void eat();
void get_chopsticks();
void put_chopsticks();
void cleanup(int exit_val);
void *loop(void *input);

#endif
