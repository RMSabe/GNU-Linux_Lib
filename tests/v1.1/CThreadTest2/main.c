//Test cthread stop

#include "globldef.h"
#include "delay.h"
#include "cstrdef.h"
#include "cthread.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_t test_thread;

extern void routine_proc(void);
extern void *routine_loop(void *args);

int main(void)
{
	routine_proc();

	printf("Exit Successful\n");
	return 0;
}

void routine_proc(void)
{
	pthread_create(&test_thread, NULL, &routine_loop, NULL);

	delay_ms(4096);
	cthread_stop(test_thread);
	return;
}

void *routine_loop(void *args)
{
	uint8_t byte = 0u;

	while(true)
	{
		printf("%u\n", byte);
		delay_ms(256);
		byte++;
	}

	return NULL;
}

