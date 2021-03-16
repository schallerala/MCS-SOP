#!/bin/sh

echo "(1)"
make # (1)

echo
echo "(2)"
touch tellMe.c # or modify tellMe.c # (2)

echo
echo "(3)"
make tellMe.o # (3)

echo
echo "(4)"
make # (4)

echo
echo "(5)"
make # sic!, redo a make # (5)

echo
echo "(6)"
make -W tellMe.c # (6)