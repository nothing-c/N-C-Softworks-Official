#!/bin/sh

#add file with tags to tagfile
#usage: addtag.sh [filename]
tagfile=""
#could add in a pwd here to have the absolute path...
i=`head -n 1 $1 | sed s/^#//`; k=$1":"$i; echo $k >> $tagfile
