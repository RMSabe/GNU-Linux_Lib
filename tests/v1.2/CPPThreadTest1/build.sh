#!/bin/bash

g++ main.cpp globldef.c delay.c cstrdef.c cthread.c cppdelay.cpp strdef.cpp cppthread.cpp -lpthread -o run.elf

