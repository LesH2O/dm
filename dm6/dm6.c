#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
	int seuils[2] = { 0, taille-1 };
	bool trie = false;
	int cro = 1;
	double buff;
	while (!trie && seuils[0] < seuils[1])
  	{
    	trie = true;
    	for (int i = seuils[(1-cro)/2] ; i != seuils[(cro+1)/2] ; i += cro)
    	{
      		if (tab[i]*cro > tab[i+cro]*cro)
      		{
        		buff = tab[i];
        		tab[i] = tab[i+cro];
		        tab[i+cro] = buff;
        		trie = false;
	      }
    	}
	    seuils[(cro+1)/2] -= cro;
    	cro *= -1;
	}
	int n = taille/4 ;
	return tab[n];
}

int main51(){
	double tab[5] = {5.2,4.3, 2.9,1.8, 2.6};
	double r = q1(tab,5) ;
	printf("%f \n",r);
	if(r == 2.6){return(0) ;}
	else{return(1);}
}


int abso(int a){
	if(a<0){return -a;} 
	else{return a;}
}

int minecart(int* tab, int taille){
	if(taille == 0){exit(1);}
	int mini = abso(tab[0]);
	for(int i = 1 ; i<taille ; i+=1)
	{
		int r = abso(abso(tab[i])-i) ;
		if(mini>r){mini = r;}
	}
	return mini ;
}
int main52(){
	int tab[3] = {1,1,3};
	if(minecart(tab,3)==0){ return 1 ;}
	else{return 0 ;}
}

void main(){
	int r = main52() ;
	exit(r) ;
}
