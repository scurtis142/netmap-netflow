#include <stdlib.h>
#include <libnetmap.h>

#include "netflow-table.h"

#define TABLE_INITIAL_SIZE 2048

/* NOTE: NONE OF THESE ARE THREAD SAFE */

struct netflow_table* netflow_table_init (void) {
   struct netflow_table *table;
   
   D("Initialising NetFlow Table\n");
   table            = malloc (sizeof (struct netflow_table));
   table->array     = malloc (sizeof (hashBucket_t) * TABLE_INITIAL_SIZE);
   table->n_entries = TABLE_INITIAL_SIZE;

   return table;
}


void netflow_k_v_from_ring (const char *_p, int len, struct netmap_ring *ring, int cur) {

}


/* NOTE: This function isn't threadsafe !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
void netflow_table_insert (struct netflow_table *table, key_t key, value_t val) {
   uint32_t idx = 0;

   idx = hash_crc_4byte (key->proto, idx);
   idx = hash_crc_4byte (key->ip_src, idx);
   idx = hash_crc_4byte (key->ip_dst, idx);
   idx = hash_crc_4byte (key->port_src, idx);
   idx = hash_crc_4byte (key->port_dst, idx);
   idx = idx % table->n_entries;
}


void netflow_table_free (struct netflow_table *table) {

}


void netflow_table_print (struct netflow_table *table) {

}


void netflow_table_print_stats (struct netflow_table *table) {

}
