/*********************************************

output of nvm

shas19@shaspc:~/build/bin$ ./nvm -fname="print_existing_records" $HOME/nvm_cpp_examples/file.cpp
DEBUG:Will only analyze/replaces sources in: 
DEBUG:target_func: print_existing_records @file: file.cpp
FILE * [fp] vardecl_modified <print_existing_records>:file.cpp:40:5
class person 
DEBUG:Will only analyze/replaces sources in: 
======================== FINISHED ============================
Explored Function count = 2
Max explored depth = 1
Total exec time: 0:0:0

**********************************************/




#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define filename "mydata.out"

class person{
public:
  int id;
  char name[100];
};

typedef struct {
    int dummy;
} dummy_struct;

void print_existing_records() {
    /* Read and interpret file from storage. */
    FILE *fp = fopen(filename, "r+");
    char* buf = (char*) malloc(sizeof(person));
    person* p;
    /* Read a person off storage and print it. */
    while (fread(buf, 1, sizeof(person), fp) == sizeof(person)) {
	p = (person*) buf;
	printf("%d %s\n", p->id, p->name);
    }
    free(buf);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 4) {
	printf("Usage: prog read OR prog write id name\n");
	exit(1);
    }
  
    if (!strcmp(argv[1], "read")) {
	print_existing_records();
    }
    else if (!strcmp(argv[1], "write")) {
	assert(argc == 4);
	/* Write to storage. */
	person p;
	p.id = atoi(argv[2]);
	strcpy(p.name, argv[3]);
	char* buf = (char*) malloc(sizeof(person));
	memcpy(buf, &p, sizeof(p));
	FILE *fp = fopen(filename, "a");
	fwrite(buf, sizeof(p), 1, fp);
	free(buf);
	fclose(fp);
    } else {
	printf("Unknown argument.\n");
	exit(1);
    }
    return 0;
}
