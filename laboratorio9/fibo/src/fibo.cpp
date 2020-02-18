#include <stdio.h>
#include <mpi.h>
#include <sys/time.h>
#include <stdlib.h>

int
main (int argc, char **argv){
  long n, fibn;
  int world_size, universe_size, flag;
  int myrank;
  char command[] = "fib";
  MPI_Comm children_comm;
  MPI_Status status;
  int errcodes[1];

  MPI_Init (&argc, &argv);
  MPI_Comm_size (MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank (MPI_COMM_WORLD, &myrank);

  MPI_Info local_info;
  MPI_Info_create (&local_info);

  printf ("MPI_CommSize ok\n");

  if (world_size != 1)


  MPI_Comm_get_attr (MPI_COMM_WORLD, MPI_UNIVERSE_SIZE, &universe_size,&flag);
  if (!flag){
      printf
        ("This MPI does not support UNIVERSE_SIZE. How many\n processes total?");
      scanf ("%d", &universe_size);
  }

  printf ("MPI_Comm_get_attr ok\n");
  fflush (stdout);

  if (universe_size == 1)


  printf ("P%d - argv = %s\n", myrank, argv[0]);

  // Prepare argv for spawning the recursive process
  argv += 1;
  n = atol (argv[0]);

  if (n < 2){
      printf ("fib(%ld)=%ld\n", n, n);
      exit (0);
  }else{
      printf ("<root> intercambiando proceso recursivo, n = %ld\n", n);
      sprintf (argv[0], "%ld", n);

      MPI_Comm_spawn (command, argv, 1, local_info, myrank, MPI_COMM_SELF,
                      &children_comm, errcodes);
  }

  printf ("<root> waiting receive\n");
  fflush(stdout);

  MPI_Recv (&fibn, 1, MPI_LONG, MPI_ANY_SOURCE, 1, children_comm,
            MPI_STATUS_IGNORE);

  printf ("fib(%ld)=%ld\n", n, fibn);
  fflush(stdout);

  MPI_Finalize ();
}
