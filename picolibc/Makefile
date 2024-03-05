TARGET = picolibc

SRC = main.c

include ../build.mk

FLAGS = -Os -specs=picolibc.specs -march=rv32imac -mabi=ilp32 -DPICOLIBC_INTEGER_PRINTF_SCANF -TLink.ld
