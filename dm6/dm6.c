#include <stdlib.h>
#include <stdio.h>

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

double q1 (double* tab, int taille){
	double* res = malloc(taille/4*sizeof(double));
	int n = taille/4;
	int s = 0;
	if(n==0){exit(1);}
	else{res[0] = tab[0];}
	for(int i=1 ; i < taille ; i++)
	{
		if(s<n-1)
		{
			int j = s ;
			s +=1 ;
			res[j] = tab[i];
    		while (j > 0 && res[j] < res[j-1])
			{
   				double buff = res[j];
	   			res[j] = res[j-1];
   				res[j-1] = buff;
   				j -= 1;
	    	}	
		}
		else if(tab[i]<res[s])
		{
			int j = s ;
			res[j] = tab[i];
    		while (j > 0 && res[j] < res[j-1])
			{
   				double buff = res[j];
	   			res[j] = res[j-1];
   				res[j-1] = buff;
   				j -= 1;
	    	}	
		}
	}
	double r = res[s] ;
	free(res);
	return r;
}

int main51(){
	double tab[5] = {5.2,4.3, 2.9,1.8, 2.6};
	double r = q1(tab,5) ;
	if(r == 1.8){return(0) ;}
	else{return(1);}
}


void main(){
	int r = main51() ;
	exit(r);
}
