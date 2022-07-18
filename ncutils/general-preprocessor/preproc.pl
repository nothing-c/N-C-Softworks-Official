#!/usr/bin/perl

#replacements
%rep;

open($file, "<", $ARGV[0]) or die "No file!\n";
open($outfile, ">", "proc-$ARGV[0]");
while (<$file>) {
    chomp;
    if ($_ =~ /^#def\s(.*)\s(.*)/) {
	#add key to hash
	#print "$1 = $2\n";
	$rep{$1} = $2;
	$_ = '';
    } else {
	foreach $k (keys %rep) {
	    $pat = qr/$k/;
	    $_ =~ s/$pat/$rep{$k}/g;
	}
    }
    print $outfile "$_\n";
}
close($file);
close($outfile);
