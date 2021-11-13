#!/bin/sh

cc lvlup.h xpfarmer.c -o xpfarmer && echo "Compilation Successful";
mv xpfarmer /usr/local/bin && echo "Movement successful, type 'xpfarmer' to play!";
