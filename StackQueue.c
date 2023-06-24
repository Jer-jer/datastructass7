#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "StackQueue.h"

/* --- VIRTUAL HEAP FUNCTIONS --- */
void initVSpace(VirtualSpace *vs){
	int lastIndex = MAX - 1;
	
	for(int i = lastIndex; i > -1; i--){
		vs->data[i].items = addProduct(0, "", 0, 0.00, addDate(0, 0, 0));
		vs->data[i].link = i - 1;
	}
	
 	vs->avail = lastIndex;
}
int allocSpace(VirtualSpace *vs){ // Include check isFull here for efficiency
	int retval = vs->avail;
	
	if(retval != -1) {
		vs->avail = vs->data[retval].link;
	}
	
	return retval;
	
}
void deallocSpace(VirtualSpace *vs, int node){ // Accepts a node that has a next of -1
	vs->data[node].items = addProduct(0, "", 0, 0.00, addDate(0, 0, 0));
	
	vs->data[node].link = vs->avail;
	vs->avail = node;
}
void visualize(VirtualSpace vs){
	printf("----- VIRTUAL HEAP -----\n\n");
	printf("%5s | %5s | %-5s | %5s | %5s | %-18s |%5s\n", "INDEX", "PRODUCT ID", "PRODUCT NAME", "AVAILABLE QUANTITY", "PRICE", "EXPIRATION DATE", "LINK");
	printf("--------------------------------------------------------------------------------------------\n");
	
	for(int i = 0; i < MAX; i++){
		printf("%5d | ", i);
		
		(vs.data[i].items.prodID) ? printf("%10d | ", vs.data[i].items.prodID) : printf("%10s | ", " ");
		
		(strlen(vs.data[i].items.prodName) != 0 ) ? printf("%-12s | ", vs.data[i].items.prodName) : printf("%-12s | ", " ");
		
		printf("%-18d | ", vs.data[i].items.prodQty);
		
		printf("%-5.2lf | ", vs.data[i].items.prodPrice);
		
		printf("%-3d %-8s %-5d | ", vs.data[i].items.prodExp.date, convertMonth(vs.data[i].items.prodExp.month), vs.data[i].items.prodExp.year);
		
		printf("%3d\n", vs.data[i].link);		
	}
	
	printf("--------------------------------------------------------------------------------------------\n");
	printf("AVAILABLE: %d\n", vs.avail);
	
	printf("\n\n");
}
char* convertMonth(int month){
	switch(month) {
        case 1:  return "January";
        case 2:  return "February";
        case 3:  return "March";
        case 4:  return "April";
        case 5:  return "May";
        case 6:  return "June";
        case 7:  return "July";
        case 8:  return "August";
        case 9:  return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "None";
    }
	
}
Date addDate(int date, int month, int year){
	Date newDate = { .date = date, .month = month, .year = year };
	
	return newDate;
}
Product addProduct(int id, String name, int qty, double price, Date expry){
	Product newProduct;
	
	newProduct.prodID = id;
	strcpy(newProduct.prodName, name);
	newProduct.prodQty = qty;
	newProduct.prodExp = expry;
	newProduct.prodPrice = price;
	
	return newProduct;
}

/* --- STACK FUNCTIONS --- */
void initStack(StackList *stack){
	*stack = -1;
}
bool push(VirtualSpace *vs, StackList *stack, Product newProd){
	int newNode = allocSpace(vs);
	
	if(newNode == -1) return false;
	
	vs->data[newNode].items = newProd;
	vs->data[newNode].link = *stack;
	*stack = newNode;
	
	return true;
}
bool pop(VirtualSpace *vs, StackList *stack){
	StackList holder = *stack;
	
	if(*stack == -1) return false;
	
	*stack = vs->data[*stack].link;
	vs->data[holder].link = -1;
	deallocSpace(vs, holder);
	
	return true;
}
Product peek(VirtualSpace vs, StackList stack){
	return vs.data[stack].items;
}

// Displays starting from the bottom of the stack though I'm not sure that's how Stack should work, just replicated what we did during discussion
void displayStack(VirtualSpace *vs, StackList *stack){
	StackList tempStack;
	Product prod;
	bool checker;
	
	initStack(&tempStack);
	
	while(*stack != -1){
		prod = peek(*vs, *stack);
		
		pop(vs, stack);
		
		push(vs, &tempStack, prod);
	}
	
	printf("----- STACK TABLE -----\n\n");
	printf("%5s | %-5s | %5s | %5s | %-18s\n", "PRODUCT ID", "PRODUCT NAME", "AVAILABLE QUANTITY", "PRICE", "EXPIRATION DATE");
	printf("----------------------------------------------------------------------------------------\n");
	while(tempStack != -1){
		prod = peek(*vs, tempStack);
		
		printf("%10d | ", prod.prodID);
		printf("%-12s | ", prod.prodName);
		printf("%-18d | ", prod.prodQty);
		
		printf("%-5.2lf | ", prod.prodPrice);
		
		printf("%-2d %s %d\n", prod.prodExp.date, convertMonth(prod.prodExp.month), prod.prodExp.year);

		
		pop(vs, &tempStack);
		
		push(vs, stack, prod);
	}
	
	printf("----------------------------------------------------------------------------------------\n\n");
}

/* --- QUEUE FUNCTIONS --- */
void initQueue(Queue *q){
	q->front = -1;
	q->rear = -1;
}
bool enqueue(VirtualSpace *vs, Queue *q, Product newProd){
	int newNode = allocSpace(vs);
	
	if(newNode == -1) return false;
	
	vs->data[newNode].items = newProd;
	
	if(q->front == -1 && q->rear == -1){
		q->front = q->rear = newNode;
	}else {
		vs->data[newNode].link = -1;
		vs->data[q->rear].link = newNode;
		q->rear = newNode;
	}
	
	return true;
}
bool dequeue(VirtualSpace *vs, Queue *q){
	int holder = q->front;
	
	if(q->front == -1) return false;
	
	if(vs->data[q->rear].link == -1) q->rear = -1; 
	
	q->front = vs->data[q->front].link;
	vs->data[holder].link = -1;
	deallocSpace(vs, holder);
	
	return true;
}
Product front(VirtualSpace vs, Queue q){
	return vs.data[q.front].items;
}
void displayQueue(VirtualSpace vs, Queue q){
	Product prod;
	bool checker;
	
	printf("----- QUEUE TABLE -----\n\n");
	printf("%5s | %-5s | %5s | %5s | %-18s\n", "PRODUCT ID", "PRODUCT NAME", "AVAILABLE QUANTITY", "PRICE", "EXPIRATION DATE");
	printf("----------------------------------------------------------------------------------------\n");
	while(q.front != -1){
		prod = front(vs, q);
		
		printf("%10d | ", prod.prodID);
		printf("%-12s | ", prod.prodName);
		printf("%-18d | ", prod.prodQty);
		
		printf("%-5.2lf | ", prod.prodPrice);
		
		printf("%-2d %s %d\n", prod.prodExp.date, convertMonth(prod.prodExp.month), prod.prodExp.year);
		
		dequeue(&vs, &q);
	}
	printf("----------------------------------------------------------------------------------------\n\n");
}
