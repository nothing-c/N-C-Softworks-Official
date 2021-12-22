#!/usr/bin/perl

#Merry Christmas from all at NC Softworks! :)

$maxlen = 22;

for $i (0..$maxlen){
	if ($i == 0){
		print ' ' x $maxlen;#($maxlen/2);
		print "*\n";
	} else {
		print ' ' x ($maxlen - $i);#(($maxlen/2) - (2*$i));
		print 'x' x (2*$i);
		print "\n";
	}
}
print ' ' x $maxlen;
print "=\n";
