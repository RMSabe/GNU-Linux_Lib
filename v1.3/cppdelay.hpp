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

#ifndef CPPDELAY_HPP
#define CPPDELAY_HPP

#include "globldef.h"

extern void cppdelay_ms(unsigned long time_ms);
extern void cppdelay_us(unsigned long time_us);

#endif /*CPPDELAY_HPP*/

