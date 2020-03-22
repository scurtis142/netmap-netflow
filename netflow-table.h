#ifndef NETFLOW_TABLE_H
#define NETFLOW_TABLE_H

struct netflow_table {
   uint32_t n_entries;
   hashBucket_t *array; 
};

typedef struct netflow_table_key {
    uint8_t proto;
    uint32_t ip_src;                                /**< saved in network order */
    uint32_t ip_dst;                                /**< saved in network order */
    uint16_t port_src;                              /**< saved in network order */
    uint16_t port_dst;                              /**< saved in network order */
} key_t;

typedef struct netflow_hashBucket {
    uint8_t vlanId;
    uint8_t proto;

    uint32_t ip_src;                                /**< saved in network order */
    uint32_t ip_dst;                                /**< saved in network order */
    uint16_t port_src;                              /**< saved in network order */
    uint16_t port_dst;                              /**< saved in network order */
   
    uint64_t bytesSent, pktSent;                    /**< saved in host order */
    uint64_t bytesRcvd, pktRcvd;                    /**< saved in host order */
    
    struct netflow_hashBucket *next;
} hashBucket_t;


/* Functions */
struct netflow_table* netflow_table_init (void);
void netflow_table_insert (struct netflow_table *table, const char *_p, int len, struct netmap_ring *ring, int cur);
void netflow_table_free (struct netflow_table *table);
void netflow_table_print (struct netflow_table *table);
void netflow_table_print_stats (struct netflow_table *table);

#endif
