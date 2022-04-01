#!/usr/bin/perl

#n-c crappy perl REPL

#Usage: perl /path/to/craprepl.pl
our @arr;
print '>> ';
main();
sub main{
    $in = <STDIN>;
    chomp($in);
    push(@arr, $in);
    $ev = join("", @arr);
    eval($ev);
    print "\n>> ";
    main();
}
