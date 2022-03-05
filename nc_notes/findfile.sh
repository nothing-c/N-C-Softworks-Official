#!/bin/sh

#find files associated with tag
#usage: findtag.sh [name of tag]
tagfile=""
grep $1 $tagfile | sed s/:.*//g
