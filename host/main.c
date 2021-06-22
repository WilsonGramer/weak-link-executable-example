#include "../lib/lib.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

const char *path =
    "/Users/wilson/Desktop/plugin-test/Plugin/.build/debug/libPlugin.dylib";

int main(int argc, const char **argv) {
  if (argc != 2) {
    printf("Usage: %s path/to/plugin.dylib\n", argv[0]);
    exit(1);
  }

  char *error;

  void *lib = dlopen(argv[1], RTLD_LAZY | RTLD_LOCAL);
  if ((error = dlerror())) {
    printf("Error: %s\n", error);
    exit(1);
  }

  void (*plugin)(void) = dlsym(lib, "plugin");
  if ((error = dlerror())) {
    printf("Error: %s\n", error);
    exit(1);
  }

  plugin();

  dlclose(lib);
}
