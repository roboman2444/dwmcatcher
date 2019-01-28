#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



pid_t topid = 0;


void reset_handler(int id){
	switch(id){
		case SIGUSR1: {
			pid_t temp = topid;
			topid = 0;
			kill(temp, SIGTERM);
		} break;
		case SIGUSR2: {
			topid = 0;
		} break;
		//todo more of em
	}
	return;
}


int main(const int argc, char * const *argv){
	pid_t thepid = 0;
	int lastret = 0;
	if(argc < 2){
		//hacky way of doing this
		char *c[] = {"killall", "dwmcatcher", "-q", "-USR1", (char*) NULL};
		int ret = execvp(*c, c);
    printf("%d\n", ret);
    perror("execvp failed with error: ");
		return 0;
	}
	if(
		signal(SIGUSR1, reset_handler) == SIG_ERR ||
		signal(SIGUSR2, reset_handler) == SIG_ERR
	){
		printf("Cant get signal handler\n");
		return 1;
	}
	do {
		thepid = fork();
		if(thepid){ // parent
			topid = thepid;
		} else {// child
			execvp(argv[1], argv+1);
			return 0;
		}
		waitpid(thepid, &lastret, 0);
	} while(topid != thepid);
	return lastret;
}
