#!/usr/bin/perl

#n-c shitty perl REPL
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
