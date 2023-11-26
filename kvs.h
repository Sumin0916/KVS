#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LINE_LENGTH 201

struct node {
	char op[50];
	char key[100];
	char *value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	int items; // number of data 
};
typedef struct kvs kvs_t; 


kvs_t* open(FILE *input_file);
int close(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char *op, const char* key,const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return -1  if not found. 
void do_snapshot(kvs_t *kvs);
