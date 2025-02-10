#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

int pgcd(int a,int b){
	int r = a%b;
	if(r==0){return b;}
	else{return pgcd(b,r);}
}

int mcnuggets(int a, int b){
	if(pgcd(a,b)>1){exit(1);}
	bool* t = malloc(a*b*sizeof(bool));
	for(int i = 0 ; i < a*b ; i +=1){t[i] = false;}
	t[0] = true ; 
	for(int i = 0 ; i < a*b ; i +=1){
		if(t[i]){
			if(i+a < a*b){t[i+a] = true;}
			if(i+b < a*b){t[i+b] = true;}
		}
	}
	int j = (a*b)-1 ;
	while(t[j]){j-=1;}
	free(t);
	return j ;
}


int main60(){
	int r = mcnuggets(3,4);
	if(r == 5){return 0 ;}
	return 1;
}

bool existesomme(int* tab, int l){
	for(int i=0 ; i < l ; i +=1){
		for(int j=0 ; j<m-1 ; j+=1){
			for(int k=j+1 ; k<m ; k+=1){
				if(i != j && k!=i){
					if(tab[i] == tab[j]+tab[k]){return true;}
				}
			}
		}
	}
	return false;
}

int main61(){}
void main(){
		int r = main60();
		printf("%d",r);
		exit(r);
}
	
