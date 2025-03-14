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

/*
 * Basic math operations with complex numbers. (32bit floating point)
 *
 * Functions return true if successful, false otherwise. divide() will also return false if divider equals 0.
 */

#ifndef COMPLEX32_H
#define COMPLEX32_H

#include "globldef.h"

struct _complex32 {
	float r;
	float i;
};

typedef struct _complex32 complex32_t;

bool complex32_get_conjugate(const complex32_t *p_input, complex32_t *p_output);
bool complex32_add(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output);
bool complex32_subtract(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output);
bool complex32_multiply(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output);
bool complex32_divide(const complex32_t *p_input1, const complex32_t *p_input2, complex32_t *p_output);

#endif /*COMPLEX32_H*/

