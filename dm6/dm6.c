#include <stdlib.h>


int tables(int n){
	if(n<6){exit(0);}
	int a = n/4 ;
	int r = n-(4*(a)) ;
	while(r % 3 != 0){
		a -= 1 ;
		r += 4 ;
	}
	int b = r /3 ;
	return (a,b);
}

int main50(){
	int n = 7 ;
	if(tables(n)==(1,1)){return 1;}
	else{return 0;}
}



void main(){
	int r = main50() ;
	exit(r);
}
