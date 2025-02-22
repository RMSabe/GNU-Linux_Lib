#!/bin/bash

gcc main.c -c -o main.o
gcc globldef.c -c -o globldef.o
gcc delay.c -c -o delay.o
gcc cstrdef.c -c -o cstrdef.o
gcc cthread.c -c -o cthread.o

gcc main.o globldef.o delay.o cstrdef.o cthread.o -o run.elf

rm main.o
rm globldef.o
rm delay.o
rm cstrdef.o
rm cthread.o

