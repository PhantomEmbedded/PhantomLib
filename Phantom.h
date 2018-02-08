#ifndef PHANTOM_H
#define PHANTOM_H

#include <stdlib.h>

void *operator new(size_t size);
void *operator new[](size_t size);
void operator delete(void * ptr);
void operator delete[](void * ptr);

#endif /* END PHANTOM_H */