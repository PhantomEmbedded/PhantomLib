#ifndef PHANTOM_H
#define PHANTOM_H

#include <stdlib.h>

void *operator new(size_t size) {
  return malloc(size);
}

void *operator new[](size_t size) {
  return malloc(size);
}

#endif /* END PHANTOM_H */