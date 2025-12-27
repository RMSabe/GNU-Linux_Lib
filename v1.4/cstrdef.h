/*
 * Some functions and definitions to ease development on GNU-Linux systems.
 * Version 1.4
 *
 * config.h is the macro settings file. Used to define behavior and variables.
 * globldef.h is the global definition file. It should be the first file included in all other source files.
 *
 * Author: Rafael Sabe
 * Email: rafaelmsabe@gmail.com
 *
 * GitHub Repository: https://github.com/RMSabe/GNU-Linux_Lib
 */

#ifndef CSTRDEF_H
#define CSTRDEF_H

#include "globldef.h"

/*
 * cstr_getlength()
 * returns the length of a null-terminated C string, or -1 if error.
 */

extern ssize_t cstr_getlength(const char *str);

/*
 * cstr_locatechar()
 * search for a specific char (c) in a null-terminated C string.
 *
 * returns the index of the first matching character found,
 * returns -1 if character is not in the string or error.
 */

extern ssize_t cstr_locatechar(const char *str, char c);

/*
 * cstr_compare()
 * compares 2 null-terminated C strings.
 *
 * returns true if they're equal.
 * returns false if they're not equal or error
 */

extern bool cstr_compare(const char *str1, const char *str2);

/*
 * cstr_compare_upto_len()
 * compares 2 null-terminated C strings up to a specified length (stop_index).
 *
 * fail_if_nolen sets the outcome if both strings are shorter than stop_index:
 * if both strings are shorter than stop_index and fail_if_nolen is set to true, then function will return false, even if strings are equal.
 * if both strings are shorter than stop_index and fail_if_nolen is set to false, then function will perform normal cstr_compare between input strings.
 *
 * returns true if both strings are equal up to stop_index.
 * returns false if not equal or error.
 */

extern bool cstr_compare_upto_len(const char *str1, const char *str2, size_t stop_index, bool fail_if_nolen);

/*
 * cstr_compare_upto_char()
 * compares 2 null-terminated C strings until it reaches a specified character (stop_char) in either string.
 *
 * fail_if_nochar sets the outcome if neither strings have the stop_char:
 * if neither strings have stop_char and fail_if_nochar is set to true, then function will return false, even if strings are equal.
 * if neither strings have stop_char and fail_if_nochar is set to false, then function will perform normal cstr_compare between input strings.
 */

extern bool cstr_compare_upto_char(const char *str1, const char *str2, char stop_char, bool fail_if_nochar);

/*
 * cstr_copy()
 * copies the content of an input null-terminated C string, to an output string. Appends null-terminator character to output string.
 *
 * if input string length is longer than output buffer length - 1, all remaining input characters past buffer length - 1 will be truncated from output string.
 *
 * returns true if successful, false if error.
 */

extern bool cstr_copy(const char *input_str, char *output_str, size_t bufferout_length);

/*
 * cstr_copy_upto_len()
 * copy the content of an input null-terminated C string to an output string up to a specified length (stop_index).
 *
 * if input string is shorter than given stop_index, then function will copy the whole input string.
 * if input string is longer than output buffer length - 1, then all remaining input characters past that index will be truncated in output string.
 *
 * if append_nullchar is true, function will append a null-terminator character to the copied content in output buffer.
 * function will always write a null-terminator character at the very end of output buffer, even if append_nullchar is false, for safety.
 *
 * returns true if successful, false if error.
 */

extern bool cstr_copy_upto_len(const char *input_str, char *output_str, size_t bufferout_length, size_t stop_index, bool append_nullchar);

/*
 * cstr_copy_upto_char()
 * copy the content of an input null-terminated C string to an output string up to a specified character (stop_char).
 *
 * if input string does not have stop_char, then function will copy the whole input string.
 * if input string is longer than output buffer length - 1, then all remaining input characters past that index will be truncated in output string.
 *
 * if append_nullchar is true, function will append a null-terminator character to the copied content in output buffer.
 * function will always write a null-terminator character at the very end of output buffer, even if append_nullchar is false, for safety.
 *
 * returns true if successful, false if error.
 */

extern bool cstr_copy_upto_char(const char *input_str, char *output_str, size_t bufferout_length, char stop_char, bool append_nullchar);

/*
 * cstr_tolower() & cstr_toupper()
 *
 * converts all letters in a null-terminated C string to lower-case or upper-case.
 *
 * returns true if successful, false if error.
 */

extern bool cstr_tolower(char *str, size_t buffer_length);
extern bool cstr_toupper(char *str, size_t buffer_length);

#endif /*CSTRDEF_H*/

