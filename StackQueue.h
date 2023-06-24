#ifndef CB_ST_QU_H
#define CB_ST_QU_H

#define MAX 20

typedef char String[50];
typedef char ProdString[20];

typedef struct {
	int date; 
	int month; // Must be translated to months (use Array)
	int year; 
} Date;

typedef struct {
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
} Product;

typedef struct {
	Product items;
	int link;
} Stype;

typedef struct {
	Stype data[MAX];
	int avail;
} VirtualSpace;

typedef int StackList;

typedef struct {
	int front;
	int rear;
} Queue;

// -- VIRTUAL HEAP FUNCTIONS ---
void initVSpace(VirtualSpace *vs);
int allocSpace(VirtualSpace *vs); // Include check isFull here for efficiency
void deallocSpace(VirtualSpace *vs, int node);
void visualize(VirtualSpace vs);

// --- PRODUCT FUNCTIONS ---
char* convertMonth(int month);
Date addDate(int date, int month, int year);
Product addProduct(int id, String name, int qty, double price, Date expry);

// STACK FUNCTIONS
void initStack(StackList *stack);
bool push(VirtualSpace *vs, StackList *stack, Product newProd);
bool pop(VirtualSpace *vs, StackList *stack);
Product peek(VirtualSpace vs, StackList stack);
void displayStack(VirtualSpace *vs, StackList *stack);

// --- QUEUE FUNCTIONS ---
void initQueue(Queue *q);
bool enqueue(VirtualSpace *vs, Queue *q, Product newProd);
bool dequeue(VirtualSpace *vs, Queue *q);
Product front(VirtualSpace vs, Queue q); 
void displayQueue(VirtualSpace vs, Queue q);

//Extra Functions
bool dequeueFirstOccurrence(Queue *q, int prodName, VirtualSpace *vs);

#endif
