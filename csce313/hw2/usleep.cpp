// Graham Leslie
// usleep() in C style snippit

// wait thread
pthread_mutex_lock(&m);
while (timer > 0)
	pthread_cond_wait(&c, &m);
pthread_mutex_unlock(&m);

// timer thread
pthread_mutex_lock(&m);
while (timer > 0)
	timer --;
pthread_cond_signal(&c);
pthread_mutex_unlock(&m);