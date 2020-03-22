#include <stdlib.h>
#include <libnetmap.h>

#include "netflow-table.h"

static struct netflow_table* netflow_table_init (void) {
   struct netflow_table *table = malloc (sizeof (struct netflow_table));
   table->placeholder = 0;
   D("Placeholder got to netflow table init\n");
   return table;
}


/* NOTE: This function isn't threadsafe !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
static void
netflow_table_insert(struct netflow_table *table, const char *_p, int len, struct netmap_ring *ring, int cur) {
   /* Placeholder code */
   table->placeholder += sizeof (table) + sizeof(_p) + sizeof(len) + sizeof (ring) + cur;
   D("table placeholder = %d\n", table->placeholder);
}
