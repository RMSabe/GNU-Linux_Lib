//Test cppthread wait

#include "globldef.h"
#include "delay.h"
#include "cstrdef.h"
#include "cthread.h"

#include "cppdelay.hpp"
#include "strdef.hpp"
#include "cppthread.hpp"

#include <iostream>

#define __USE_CPPDELAY

std::thread test_thread;

extern void routine_proc(void);
extern void routine_loop(void);

extern void hold(unsigned long time_ms);

int main(void)
{
	routine_proc();

	std::cout << "Exit Successful\n";
	return 0;
}

void routine_proc(void)
{
	test_thread = std::thread(&routine_loop);

	if(!cppthread_wait(&test_thread))
	{
		std::cout << "Something went wrong\n";
		return;
	}

	cppthread_stop(&test_thread);
	return;
}

void routine_loop(void)
{
	std::uint8_t byte = 0u;

	while(byte < 32u)
	{
		std::cout << std::to_string(byte) << std::endl;
		hold(256ul);
		byte++;
	}

	return;
}

void hold(unsigned long time_ms)
{
#ifdef __USE_CPPDELAY
	cppdelay_ms(time_ms);
#else
	delay_ms((clock_t) time_ms);
#endif

	return;
}

