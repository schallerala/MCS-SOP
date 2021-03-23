#------------------------------------------
# Makefile for the scope/lifetime programs
#
#------------------------------------------

all :  local  global
clean_all:
	rm  local  global


#scope programs
#--------------
local : local.c
	gcc local.c  -o local -Wall

global : global1.c  global2.c
	gcc  global1.c  global2.c  -o global -Wall
