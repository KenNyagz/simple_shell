#include "shell.h"

/**
  *h_sigint - handles interruption from keyboard
  *
  *@sig: integer corresponding to signal to be sent
  *
  */

void h_sigint(int sig)
{
	/*
	*char *action;
	*
	*action = "Interrupted. Exit or press enter to continue";
	*/
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
}

/**
  *h_sigterm - handles termination signal
  *
  *@sig: integer corresponding to signal to be sent
  *
  */

void h_sigterm(int sig)
{
	char *action;

	action = "Terminated\n";
	if (sig == SIGTERM)
		write(STDOUT_FILENO, action, 12);
}

/**
  *h_sigsegv - handles invalid memory reference
  *
  *@sig: integer corresponding to signal to be sent
  *
  */

void h_sigsegv(int sig)
{
	char *action;

	action = "Segmentation fault\n";
	if (sig == SIGSEGV)
	{
		write(STDOUT_FILENO, action, 20);
		return;
	}
}

/**
  *h_sigtstp - handles bad memory access
  *
  *@sig: integer corresponding to signal to be sent
  *
  */

void h_sigtstp(int sig)
{
	char *action;

	action = "\n";
	if (sig == SIGTSTP)
	{
		write(STDOUT_FILENO, action, 2);
	}
}

/**
  *handlers_init - sets up the signal handling functions
  *
  */

void handlers_init(void)
{
	struct sigaction sig_action;
	struct sigaction sig_action_2;
	struct sigaction sig_action_3;
	struct sigaction sig_action_4;

	sig_action.sa_handler = h_sigint;
	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sig_action, NULL) == -1)
	{
		perror("Sigint action failed");
		exit(1);
	}
	sig_action_2.sa_handler = h_sigterm;
	sigemptyset(&sig_action_2.sa_mask);
	sig_action_2.sa_flags = 0;
	if (sigaction(SIGTERM, &sig_action_2, NULL) == -1)
	{
		perror("Sigterm action failed");
		exit(1);
	}
	sig_action_3.sa_handler = h_sigsegv;
	sigemptyset(&sig_action_3.sa_mask);
	sig_action_3.sa_flags = 0;
	if (sigaction(SIGSEGV, &sig_action_3, NULL) == -1)
	{
		perror("Sigsegv action failed");
		exit(1);
	}
	sig_action_4.sa_handler = h_sigtstp;
	sigemptyset(&sig_action_4.sa_mask);
	sig_action_4.sa_flags = 0;
	if (sigaction(SIGTSTP, &sig_action_4, NULL) == -1)
	{
		perror("Sicont action failed");
		exit(1);
	}
}
