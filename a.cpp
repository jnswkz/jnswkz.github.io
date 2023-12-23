#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char s[]="string";
	char p[20];
	int length = strlen(s);
	for (int i= 0;i< length; i++){
		p[i]=s[length- i];
	}
	
	int b = 10;
	int* i2 = &b;
	int a = *i2++;
	cout << a << "\n" << *i2;

}
