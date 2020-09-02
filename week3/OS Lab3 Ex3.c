#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct linked_list {
	struct node *head;
};

struct linked_list ll;

void print_list() {
	struct node*p = ll.head;
	if(p == NULL) {
		printf("The list is empty!\n");
		return;
	}
	while(p != NULL) {
		printf("%d ",p->value);
		p = p->next;
	}
	printf("\n");
}
void insert_node(int elem) {
	struct node*p = ll.head;
	if(p==NULL) {
		struct node* temp = malloc(sizeof(struct node));
		temp->value = elem;
		temp->next = NULL;
		ll.head = temp;
		return;
	}
	while(p->next != NULL)
		p = p->next;
	struct node* temp = malloc(sizeof(struct node));
	temp->value = elem;
	temp->next = NULL;
	p->next = temp;
}
void delete_node(int pos) {
	struct node*p = ll.head;
	int i = 0;
	if(ll.head == NULL) {
		printf("The list is empty!");		
		return;
	} else {
		if(pos ==0) {
			ll.head = ll.head->next;
			free(p);
			return;
		}
		while(p->next != NULL && i < pos-1) {
			p = p->next;
			i++;
		}
		if(i < pos-1) {
			printf("Postition exceeds length of the list");
			return;
		} else {
			struct node* temp = p->next;
			p->next = p->next->next;
			free(temp);
		}
	}
}

int main() {
	ll.head = NULL;
	print_list(ll);
	insert_node(10);
	insert_node(11);
	insert_node(12);
	print_list(ll);
	delete_node(1);
	print_list(ll);
	insert_node(13);
	print_list(ll);
	delete_node(2);
	print_list(ll);
	delete_node(0);
	print_list(ll);
	delete_node(0);
	print_list(ll);
	return 0;
}

