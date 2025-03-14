/*
 * Some functions and definitions to ease development on GNU-Linux systems.
 * Version 1.3
 *
 * config.h is the macro settings file. Used to define behavior and variables.
 * globldef.h is the global definition file. It should be the first file included in all other source files.
 *
 * Author: Rafael Sabe
 * Email: rafaelmsabe@gmail.com
 *
 * GitHub Repository: https://github.com/RMSabe/GNU-Linux_Lib
 */

#include "complex32.h"

bool complex32_get_conjugate(const complex32_t *p_input, complex32_t *p_output)
{
	if(p_input == NULL) return false;
	if(p_output == NULL) return false;

	p_output->r = p_input->r;
	p_output->i = -p_input->i;

	return true;
}

bool complex32_add(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output)
{
	if(p_input1 == NULL) return false;
	if(p_input2 == NULL) return false;
	if(p_output == NULL) return false;

	p_output->r = p_input1->r + p_input2->r;
	p_output->i = p_input1->i + p_input2->i;

	return true;
}

bool complex32_subtract(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output)
{
	if(p_input1 == NULL) return false;
	if(p_input2 == NULL) return false;
	if(p_output == NULL) return false;

	p_output->r = p_input1->r - p_input2->r;
	p_output->i = p_input1->i - p_input2->i;

	return true;
}

bool complex32_multiply(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output)
{
	if(p_input1 == NULL) return false;
	if(p_input2 == NULL) return false;
	if(p_output == NULL) return false;

	p_output->r = p_input1->r*p_input2->r - p_input1->i*p_input2->i;
	p_output->i = p_input1->r*p_input2->i + p_input1->i*p_input2->r;

	return true;
}

bool complex32_divide(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output)
{
	complex32_t conjugate;
	complex32_t numerator;
	complex32_t divider;

	if(p_input1 == NULL) return false;
	if(p_input2 == NULL) return false;
	if(p_output == NULL) return false;

	complex32_get_conjugate(p_input2, &conjugate);
	complex32_multiply(p_input2, &conjugate, &divider);

	if(divider.r == 0.0f) return false;

	complex32_multiply(p_input1, &conjugate, &numerator);

	p_output->r = numerator.r/divider.r;
	p_output->i = numerator.i/divider.r;

	return true;
}

