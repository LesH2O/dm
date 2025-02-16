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
	





int niederschaffolshein(char s, int n){
    int count=0;
    int max = 0;
    for (int i=0; i<n; i+=1){
        if (s[i]==" "){if (count>max){max=count;}
                       count=0;}
        else{count+=1;}
    }
    return max;
} 





int knekes(char s, int n){
    char* res=malloc(7*n*sizeof(char));
    int point=0;
    for (int i=0 ; i<n ; i+=1){
        if (s[i]==" "){res[point]=" ";
                       point+=1;
                       res[point]="h";
                       point+=1;
                       res[point]="o";
                       point+=1;
                       res[point]="p";
                       point+=1;
                       res[point]="l";
                       point+=1;
                       res[point]="a";
                       point+=1;}
        else{res[point]=s[i];
             point+=1;}
    }
    char* r=malloc(point*sizeof(char));
    for (int i=0; i<point; i+=1){
        r[i]=res[i];
    }
    free(res);
    return r;
    
}