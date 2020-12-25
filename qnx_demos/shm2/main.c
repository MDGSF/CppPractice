#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char** argv) {
  int fd;
  unsigned* addr;

  /*
   * In case the unlink code isn't executed at the end
   */
  if (argc != 1) {
    shm_unlink("/bolts");
    return EXIT_SUCCESS;
  }

  /* Create a new memory object */
  fd = shm_open("/bolts", O_RDWR | O_CREAT, 0777);
  if (fd == -1) {
    fprintf(stderr, "Open failed:%s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  /* Set the memory object's size */
  if (ftruncate(fd, sizeof(*addr)) == -1) {
    fprintf(stderr, "ftruncate: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  /* Map the memory object */
  addr = mmap(0, sizeof(*addr), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    fprintf(stderr, "mmap failed: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  printf("Map addr is 0x%08x\n", addr);

  /* Write to shared memory */
  *addr = 1;

  /*
   * The memory object remains in
   * the system after the close
   */
  close(fd);

  /*
   * To remove a memory object
   * you must unlink it like a file.
   *
   * This may be done by another process.
   */
  shm_unlink("/bolts");

  return EXIT_SUCCESS;
}
