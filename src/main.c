#include <assert.h>
#include <kv.h>
#include <stdio.h>

int main() {
  kv_t *db = kv_init(16);
  printf("%p\n", db);
  printf("%ld\n", db->capacity);

  assert(db != NULL);
  assert(db->capacity == 16);
  assert(db->count == 0);
  kv_free(db);
}
