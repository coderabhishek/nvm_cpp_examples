/*********************************************

shas19@shaspc:~/build/bin$ ./nvm -fname=main $HOME/nvm_cpp_examples/file2.cpp
DEBUG:Will only analyze/replaces sources in: 
DEBUG:target_func: main @file: file2.cpp
vector<float> [dummy] vardecl_modified <main>:file2.cpp:38:2
DEBUG:Will only analyze/replaces sources in: 
DEBUG:target_func: test_func @file: file2.cpp
vector<int> [list_of_ints] vardecl_modified <test_func>:file2.cpp:33:2
vector<class p> [list_of_persons] vardecl_modified <test_func>:file2.cpp:34:2
======================== FINISHED ============================
Explored Function count = 2
Max explored depth = 1
Total exec time: 0:0:1

**********************************************/




#include<vector>
#include<stdio.h>
using namespace std;

class p{
int i;
};


void test_func(vector<float> dummy)
{
	//just to check whether nvm detects types or not
	vector<int> list_of_ints;
	vector<p> list_of_persons;
} 
int main()
{
	vector<float> dummy;
	test_func(dummy);	//to make nvm's BFS go into test_func  
	return 0;
}
