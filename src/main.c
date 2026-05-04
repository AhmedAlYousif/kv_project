#include <assert.h>
#include <kv.h>
#include <stdio.h>
#include <string.h>

int main() {
  kv_t *db = kv_init(16);
  printf("%p\n", db);
  printf("%ld\n", db->capacity);
  kv_put(db, "test", "value");
  kv_put(db, "test", "overridden");

  for (int i = 0; i < db->capacity; i++) {
    if (db->entries[i].key) {
      printf("[%d] %s: %s\n", i, db->entries[i].key, db->entries[i].value);
    }
  }

  assert(db != NULL);
  assert(db->capacity == 16);
  assert(db->count == 1);
  kv_free(db);
}
