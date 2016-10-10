/*********************************************

has19@shaspc:~/build/bin$ ./nvm -fname="print_existing_records" $HOME/nvm_cpp_examples/file1.cpp
DEBUG:Will only analyze/replaces sources in: 
DEBUG:target_func: print_existing_records @file: file1.cpp
FILE * [fp] vardecl_modified <print_existing_records>:file1.cpp:41:5
person<int> * [pt] vardecl_modified <print_existing_records>:file1.cpp:42:5
person<int> 
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

template<typename T>
class person{
public:
  T id;
  char name[100];
};

typedef struct {
    int dummy;
} dummy_struct;

void print_existing_records() {
    /* Read and interpret file from storage. */
    FILE *fp = fopen(filename, "r+");
    person<int> *pt = new person<int>;
    char* buf = (char*) malloc(200);
    person<int>* p;
    /* Read a person<int> off storage and print it. */
    while (fread(buf, 1, sizeof(person<int>), fp) == sizeof(person<int>)) {
    p = (person<int>*) buf;
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
    person<int> p;
    p.id = atoi(argv[2]);
    strcpy(p.name, argv[3]);
    char* buf = (char*) malloc(sizeof(person<int>));
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
