#!/bin/sh

#find taglist for given file
#usage: findtag.sh [filename]

tagfile=""
grep $1 $tagfile | sed s/.*:// | awk '{split($0,a,","); for (i in a) { print a[i];}}'
