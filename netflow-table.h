#ifndef NETFLOW_TABLE_H
#define NETFLOW_TABLE_H
struct netflow_table {
   int placeholder;
};

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
#endif
