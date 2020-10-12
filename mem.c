#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int sleep_time = 60;

  int slice_size = atoi(argv[1]);
  int slices = atoi(argv[2]);

  int *ptr[slices];

  printf("[INFO] Will allocate %lu bytes...\n", slices * slice_size * sizeof(int));

  for (int i = 0; i < slices; i++) {
    printf("[INFO] allocating slice %d (%lu bytes)\n", i, slice_size * sizeof(int) * i);
    ptr[i] = (int*)malloc(slice_size * sizeof(int));
    if ( ptr[i]==NULL ) {
      printf("[ERROR] Memory not allocated!");
      exit(1);
    }
    printf("[INFO] Filling memory...\n");
    for (int j = 0; j < slice_size; j++){
      ptr[i][j] = 1;
    }

    printf("[INFO] Memory filled.\n");
  }

  printf("[INFO] Sleeping %d seconds......\n", sleep_time);

  sleep(sleep_time);

  printf("[INFO] Freeing up memory.\n");
  for (int i = 1; i <= slices; i++) {
    free(ptr[i]);
  }

  return 0;
}
