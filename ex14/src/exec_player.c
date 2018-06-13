#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>
#include "vm_filler.h"
#include <signal.h>

#define READ_SIDE   (0)
#define WRITE_SIDE  (1)

// redirect the input (STDIN to the pipe)
int      exec_filler(char *filepath, int read, int write)
{
  dup2(read, 0);
  dup2(write, 1);
  execlp(filepath, filepath, NULL);
}

int        exec_player(vmcore_t *vm, player_t *p)
{
  pid_t    cpid;
  int pipe_req[2];
  int pipe_ans[2];

  pipe(pipe_req);
  pipe(pipe_ans);
  cpid = fork();

  if(cpid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (cpid == 0)
  {

    close(pipe_req[WRITE_SIDE]);
    close(pipe_ans[READ_SIDE]);
    dprintf(vm->log_fd, "------------- Child process: %s\n", p->filepath);
    exec_filler(p->filepath, pipe_req[READ_SIDE], pipe_ans[WRITE_SIDE]);
  } else {
    p->player_id = cpid;
    p->in = pipe_ans[READ_SIDE];
    p->out = pipe_req[WRITE_SIDE];
    close(pipe_req[READ_SIDE]);
    close(pipe_ans[WRITE_SIDE]);
    return(0);
  }
}

int     exec_players_pool(vmcore_t *vm)
{
  for (int i = 0; i < vm->nbplayers; i++)
  {
    dprintf(vm->log_fd, "exec_player[%d]\n", i);
    exec_player(vm, vm->players[i]);
  }
}


int kill_players_pool(vmcore_t *vm)
{
  for (int i = 0; i < vm->nbplayers; i++)
  {
    kill(vm->players[i]->player_id, SIGKILL);
  }

}
