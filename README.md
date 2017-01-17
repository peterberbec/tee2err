tee2err - v0.1 - January 2017 - Peter Berbec - peter@berb.ec

Small C program that takes stdin and outputs it to both stdin and stderr.

Usage: tee2err

Copy standard input to stderr and also to standard output.
Useful with pipes in scripting when you want the output to go both places.

Any command line options will bring up the help screen.

Example:

#!/bin/bash
rsync_func()
{
echo \"Starting Rsync\" | tee2err
rsync -ha $1 /backup
echo \"Finished Rsync\" | tee2err
} >> $log 2>> $err
