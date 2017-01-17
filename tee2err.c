#include <stdio.h>

void show_help()
{
	printf("tee2err - v0.1 - January 2017 - Peter Berbec - peter@berb.ec\n\n");
	printf("Usage: tee2err\n\n");
	printf("Copy standard input to stderr and also to standard output.\n");
	printf("Useful with pipes in scripting when you want the output to go both places.\n\n");
	printf("Any command line options will bring up this screen.\n\n");
	printf("Example:\n\n");
	printf("#!/bin/bash\n");
	printf("rsync_func()\n");
	printf("{\n");
	printf("echo \"Starting Rsync\" | tee2err\n");
	printf("rsync -ha $1 /backup\n");
	printf("echo \"Finished Rsync\" | tee2err\n");
	printf("} >> $log 2>> $err\n");

	return;
}

int main(int argc, char **argv)
{
	if(argc>1) 
	{
		show_help();
		return 1;
	}

	int ch;
	
	while((ch=fgetc(stdin)) != EOF)	
	{
		fputc(ch, stdout);
		fputc(ch, stderr);
	}

	return 0;
}
