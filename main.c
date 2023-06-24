#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "StackQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualSpace vs;
	StackList stack;
	Queue queue;
	Product prod;
	String menuOptions[11] = {"Visualize", "Initialize", "Push", "Pop", "Peek", "Display", "Initialize", "Enqueue", "Dequeue", "Front", "Display"};
	bool checker;	
	int i, choice;
	
	ProdString name;
	int id, qty, date, month, year;
	char* newline;
	double price;
		
	printf("----- W E L C O M E -----\n\n");
	system("pause");
	system("cls");
	
	printf("----- INITIALIZING VIRTUAL HEAP -----\n\n");
	system("pause");
	system("cls");
	initVSpace(&vs);
	printf("----- VIRTUAL HEAP INITIALIZED -----\n\n");
	system("pause");
	
	do{
		system("cls");
		printf("----- MAIN MENU -----\n\n");
		for(i = 0; i < 11; i++){
			if(i == 0){
				printf("< Virtual Heap >\n");
			} else if(i == 1){
				printf("< Stack Structure >\n");
			} else if(i == 6){
				printf("< Queue Structure >\n");
			}	
			
			printf("[%d] %s\n", i+1, menuOptions[i]);
			
			if(i == 0 || i == 5 || i == 10) printf("\n\n");
		}
		
		printf("Enter your choice <0 to EXIT>: ");
		scanf("%d", &choice);
		
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		
		switch(choice){
			case 0:
				system("cls");
				printf("----- EXITING SYSTEM -----\n\n");
				system("pause");
				system("cls");
				
				printf("----- GOOD BYE!! -----\n\n");
				
				system("pause");
				
				break;
				
			case 1:
				system("cls");
				printf("----- VISUALIZING VIRTUAL HEAP -----\n\n");
				system("pause");
				printf("\n\n");
				
				visualize(vs);
				
				system("pause");
				
				break;
				
			case 2:
				system("cls");
				printf("----- INITIALIZING STACK -----\n\n");
				system("pause");
				
				initStack(&stack);
				printf("\n\n----- STACK INITIALIZED -----\n\n");
				system("pause");
				
				break;
				
			case 3:
				system("cls");
				printf("----- PUSH STACK -----\n\n");
				
				printf("Enter product name: ");
				fgets(name, 20, stdin);
				
				newline = strchr(name, '\n'); 
				if (newline) {  
				    *newline = '\0'; 
				}
				
				printf("\nEnter desired ID number: ");
				scanf("%d", &id);
				printf("\n");
				
				printf("Enter quantity:  ");
				scanf("%d", &qty);
				printf("\n");
				
				printf("Enter price: ");
				scanf("%lf", &price);
				printf("\n\n");
				
				printf("--- EXPIRY DATE ---\n\n");
				printf("Enter month: ");
				scanf("%d", &month);
				printf("\n");
				
				printf("Enter date: ");
				scanf("%d", &date);
				printf("\n");
				
				printf("Enter year: ");
				scanf("%d", &year);
				
				printf("\n\n");
				
				checker = push(&vs, &stack, addProduct(id, name, qty, price, addDate(date, month, year)));
				checker ? printf("Stack has been updated\n\n") : printf("Stack is full\n\n");
				
				system("pause");
				
				break;
				
			case 4:
				system("cls");
				printf("----- POPPING STACK -----\n\n");
				
				checker = pop(&vs, &stack);
				
				system("pause");
				
				printf("\n\n");
				checker ? printf("Stack has been popped and updated\n\n") : printf("Stack is empty\n\n");
				
				system("pause");
				
				break;
			
			case 5:
				system("cls");
				printf("----- TAKING A PEEK OF THE STACK -----\n\n");
				system("pause");
				
				prod = peek(vs, stack);
				printf("\n\nProduct ID%24s-----%5s%d\n", " ", " ", prod.prodID);
				printf("Product Name%22s-----%5s%s\n", " ", " ", prod.prodName);
				printf("Product Available Quantity%8s-----%5s%d\n", " ", " ", prod.prodQty);
				printf("Product Price%21s-----%5sPhp. %.2lf\n", " ", " ", prod.prodPrice);
				printf("Product Expiration Date%11s-----%5s%d %s %d\n\n", " ", " ", prod.prodExp.date, convertMonth(prod.prodExp.month), prod.prodExp.year);
				
				system("pause");
				
				break;
			
			case 6:
				system("cls");
				printf("----- DISPLAYING STACK -----\n\n");
				system("pause");
				printf("\n\n");
				
				displayStack(&vs, &stack);
				
				system("pause");
				
				break;
				
			case 7:
				system("cls");
				printf("----- INITIALIZING QUEUE -----\n\n");
				system("pause");
				printf("\n\n");
				
				initQueue(&queue);
				printf("----- QUEUE INITIALIZED -----\n\n");
				
				system("pause");
				
				break;
				
			case 8:
				system("cls");
				printf("----- ENQUEUE QUEUE -----\n\n");
				
				printf("Enter product name: ");
				fgets(name, 20, stdin);
				
				newline = strchr(name, '\n'); 
				if (newline) {  
				    *newline = '\0'; 
				}
				
				printf("\nEnter desired ID number: ");
				scanf("%d", &id);
				printf("\n");
				
				printf("Enter quantity:  ");
				scanf("%d", &qty);
				printf("\n");
				
				printf("Enter price: ");
				scanf("%lf", &price);
				printf("\n\n");
				
				printf("--- EXPIRY DATE ---\n\n");
				printf("Enter month: ");
				scanf("%d", &month);
				printf("\n");
				
				printf("Enter date: ");
				scanf("%d", &date);
				printf("\n");
				
				printf("Enter year: ");
				scanf("%d", &year);
				
				printf("\n\n");
				
				checker = enqueue(&vs, &queue, addProduct(id, name, qty, price, addDate(date, month, year)));
				checker ? printf("Queue has been updated\n\n") : printf("Queue is full\n\n");
				
				system("pause");
				
				break;
				
			case 9:
				system("cls");
				printf("----- DEQUEUEING QUEUE -----\n\n");
				
				checker = dequeue(&vs, &queue);
				
				system("pause");
				
				printf("\n\n");
				checker ? printf("Queue has been dequeued and updated\n\n") : printf("Queue is empty\n\n");
				
				system("pause");
				
				break;
				
			case 10:
				system("cls");
				printf("----- DISPLAYING THE FRONT OF THE QUEUE -----\n\n");
				system("pause");
				
				prod = front(vs, queue);
				printf("\n\nProduct ID%24s-----%5s%d\n", " ", " ", prod.prodID);
				printf("Product Name%22s-----%5s%s\n", " ", " ", prod.prodName);
				printf("Product Available Quantity%8s-----%5s%d\n", " ", " ", prod.prodQty);
				printf("Product Price%21s-----%5sPhp. %.2lf\n", " ", " ", prod.prodPrice);
				printf("Product Expiration Date%11s-----%5s%d %s %d\n\n", " ", " ", prod.prodExp.date, convertMonth(prod.prodExp.month), prod.prodExp.year);
				
				system("pause");
				
				break;
				
			case 11:
				system("cls");
				printf("----- DISPLAYING QUEUE -----\n\n");
				system("pause");
				printf("\n\n");
				
				displayQueue(vs, queue);
				
				system("pause");
				
				
				break;
			
			default: 
				system("cls");
				printf("INVALID CHOICE\n\n");
				system("pause");
		}
	}while(choice != 0);

// Don't mind it's my notes
//	initVSpace(&vs);
//	visualize(vs);
//
//	initStack(&stack);
//	checker = push(&vs, &stack, addProduct(101, "Milo", 20, 9.50, addDate(1, 1, 2025)));
//	checker = push(&vs, &stack, addProduct(101, "Milo", 1, 8.00, addDate(05, 12, 2024)));
//	checker = push(&vs, &stack, addProduct(101, "Milo", 1, 8.00, addDate(31, 12, 2024)));
//	checker ? printf("Memory inserted\n") : printf("Memory full\n");
//	displayStack(&vs, &stack);
//	visualize(vs);
//	
//	initQueue(&queue);
//	checker = enqueue(&vs, &queue, addProduct(102, "Bear Brand", 2, 9.50, addDate(31, 6, 2024)));
//	checker = enqueue(&vs, &queue, addProduct(102, "Bear Brand", 2, 9.50, addDate(31, 6, 2024)));
//	checker = enqueue(&vs, &queue, addProduct(102, "Bear Brand", 2, 9.50, addDate(31, 6, 2024)));
//	checker ? printf("Memory inserted\n") : printf("Memory full\n");
//	displayQueue(vs, queue);
//	visualize(vs);
	
	return 0;
}
