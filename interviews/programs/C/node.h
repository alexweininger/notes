typedef struct Node {
	struct Node * next;
	int data;
} Node;

Node ** makeList(void);
Node * makeNode(int data);
void insertHead(Node **, int data);
void insertTail(Node **, int data);
