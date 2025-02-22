/*Test basic functions 1*/

#include "globldef.h"
#include "delay.h"
#include "cstrdef.h"
#include "cthread.h"

#include <stdio.h>

extern void test_round(void);
extern void test_floor(void);
extern void test_ceil(void);
extern void test_ispower2(void);
extern void test_getsizetmsb(void);
extern void test_getsizetmax(void);

int main(void)
{
	test_getsizetmax();
	test_getsizetmsb();
	test_ispower2();
	test_round();
	test_floor();
	test_ceil();

	return 0;
}

void test_round(void)
{
	size_t s_in = 0u;
	size_t s_out = 0u;

	printf("Test Round:\n\n");

	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x8000;
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_in += 0x3f201c;
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_max_value();
	s_in -= 0x3f201c;
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_in -= 0x3f201c;
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x3f201c;
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x25201c;
	s_out = _get_closest_power2_round(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	printf("\n");
	return;
}

void test_floor(void)
{
	size_t s_in = 0u;
	size_t s_out = 0u;

	printf("Test Floor:\n\n");

	s_out = _get_closest_power2_floor(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_out = _get_closest_power2_floor(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in += 0x3f201c;
	s_out = _get_closest_power2_floor(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_in -= 0x3f201c;
	s_out = _get_closest_power2_floor(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x8000;
	s_out = _get_closest_power2_floor(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x3f201c;
	s_out = _get_closest_power2_floor(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	printf("\n");
	return;
}

void test_ceil(void)
{
	size_t s_in = 0u;
	size_t s_out = 0u;

	printf("Test Ceil:\n\n");

	s_out = _get_closest_power2_ceil(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_out = _get_closest_power2_ceil(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in += 0x3f201c;
	s_out = _get_closest_power2_ceil(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = _get_sizet_msb_value();
	s_in -= 0x3f201c;
	s_out = _get_closest_power2_ceil(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x8000;
	s_out = _get_closest_power2_ceil(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	s_in = 0x3f201c;
	s_out = _get_closest_power2_ceil(s_in);

	printf("Input: 0x%lx | Output: 0x%lx\n", s_in, s_out);

	printf("\n");
	return;
}

void test_ispower2(void)
{
	size_t s_in = 0u;
	bool b_out = false;

	printf("Test is_power2:\n\n");

	s_in = 0u;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = 1u;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = 2u;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = 3u;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = 4u;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = 0x80000;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = 0x83fc6;
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = _get_sizet_msb_value();
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = (_get_sizet_msb_value() + 0x83fc6);
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = (_get_sizet_msb_value() >> 1);
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	s_in = (_get_sizet_msb_value() - 0x83fc6);
	b_out = _is_power2(s_in);

	printf("Input: 0x%lx | Output: %d\n", s_in, b_out);

	printf("\n");
	return;
}

void test_getsizetmsb(void)
{

	printf("Test size_t msb value:\n\n");
	printf("_get_sizet_msb_value() returned: 0x%lx\n\n", _get_sizet_msb_value());

	return;
}

void test_getsizetmax(void)
{
	printf("Test size_t max value:\n\n");
	printf("_get_sizet_max_value() returned: 0x%lx\n\n", _get_sizet_max_value());

	return;
}

