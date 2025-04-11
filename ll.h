typedef struct ll_node {
    int data;
    struct ll_node *next;
} ll_node_t;

ll_node_t* init_node(int data);
ll_node_t* insert_front(int data, ll_node_t* top);
ll_node_t* insert_back(int data, ll_node_t* bottom);
ll_node_t* remove_front(ll_node_t* top);
