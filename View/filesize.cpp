#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

//test.txt è un file di testo nella stessa cartella


int main(){

	/*
	FILE* p_file = NULL;
	p_file = fopen("test.txt", "rb");
	fseek(p_file, 0, SEEK_END);
	int size = ftell(p_file);
	fclose(p_file);
	*/

	ifstream in("test.txt", ifstream::ate | ifstream::binary);
	ifstream::pos_type size = in.tellg();

	cout << size << endl;

	return 0;
}
