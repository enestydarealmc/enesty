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
void insert_node(int elem, int pos) {
	struct node*p = ll.head;
	if(p==NULL) {
		if(pos!=0){
			printf("Position exceeds length of the list!\n");
			return;
		}
		struct node* temp = malloc(sizeof(struct node));
		temp->value = elem;
		temp->next = NULL;
		ll.head = temp;
		return;
	}
	int i =0;
	while(p->next != NULL&&i<pos)
	{
		p = p->next;
		i++;
	}
	if(i<pos){
		printf("Position exceeds length of the list!\n");
		return;
	}
	struct node* temp = malloc(sizeof(struct node));
	temp->value = elem;
	temp->next = p->next;
	p->next = temp;
}
void insert_node_last(int elem) {
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
		printf("The list is empty!\n");		
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
			printf("Postition exceeds length of the list!\n");
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
	insert_node_last(10);
	insert_node_last(11);
	insert_node(12,1);
	print_list(ll);
	delete_node(1);
	print_list(ll);
	insert_node_last(13);
	print_list(ll);
	delete_node(2);
	print_list(ll);
	delete_node(0);
	print_list(ll);
	delete_node(0);
	print_list(ll);
	insert_node_last(1);
	insert_node(2,0);
	insert_node(3,0);
	print_list(ll);
	return 0;
}

