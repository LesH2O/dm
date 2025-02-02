#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
	if(tables(n)==(1,1)){return 0;}
	else{return 1;}
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
int premiercommepremier(int* tab, int taille){
	if(taille < 1){exit(1);}
	int premier = tab[0] ;
	for(int i= 1 ; i < taille ; i +=1){
		if(tab[i] == premier && i+1<taille){return i+1 ;}
	}
	return -1 ;
}


int main53(){
	int t1[3] = {1,2,3} ;
	int t2[3] = {1,1,2} ;
	int t3[3] = {1,2,1} ;
	int t4[1] = {1}; 
	if(premiercommepremier(t1, 3)==-1 &&
premiercommepremier(t2, 3)==2 &&
premiercommepremier(t3, 3)==-1 &&
premiercommepremier(t4, 1)==-1){return 0 ;}
	return 1 ;
}

int* premiercommeavant(int* tab , int taille){
	if(taille < 1){exit(1);}
	int* r = malloc(2*sizeof(int));
	r[0] = -1 ;
	r[1] = -1 ;
	for(int i= 1 ; i < taille ; i +=1){
		if(tab[i] == tab[i-1]){r[0] = i ; r[1] = i-1 ; return r;}
	}
	return r;
}
int main54(){
	int t1[3] = {1,2,3} ;
	int t2[3] = {1,1,2} ;
	int t3[3] = {1,2,1} ;
	int* tt1 = premiercommeavant(t1,3) ;
	int* tt2 = premiercommeavant(t2,3) ;
	int* tt3 = premiercommeavant(t3,3) ;
	if(tt1[0]== -1 && tt1[1] == -1)
	{ printf("never\n") ; 
		if(tt2[0]== 1  && tt2[1] == 0)
	{ printf("gonna\n") ;
		if(tt3[0]== -1 && tt3[1] == -1){printf("give you up \n"); free(tt1) ; free(tt2);free(tt3); return 0 ;}}}
	printf("never gonna let you down \n");
	return 1 ;
}
bool equilibre(int* t, int taille){
	int max = t[0];
	int min = t[0];
	for (int i = 0; i<taille; i+=1)
	{
		if (t[i]<min) min = t[i];
		if (t[i]>max) max = t[i];
	}
	int* occur = malloc((max-min+1)*sizeof(int));
	for (int i=0; i<(max-min+1); i+=1){ occur[i]=0; }
	for (int i=0; i<taille; i+=1){ occur[t[i]-min]+=1;}
	bool verif = true;
	int value = occur[0];
	for (int i=0; i<(max-min+1); i+=1)
	{
		if ((occur[i]!=value)&&(occur[i]!=0)){ verif = false;};
	}
	free(occur);
	return verif;
}


int main55(){
	int tab[2] = {1,3};
	if(equilibre(tab,2)){ return 0 ;}
	else{return 1 ;}
}




int premierabsent(int* t, int n)
{
    int k = -1;
    bool present = true;
    while (present)
    {
        k+=1;
        present = false;
        for (int i = 0; i<n; i+=1)
        {
            if (t[i]==k) {present=true;};
        }
    }
    return k;
}

int main56(){
    int tab[5] = {1,2,0,4,5};
	printf("%d", premierabsent(tab, 5));
	if (premierabsent(tab,5)==3) {return 0;};
}



int rpz(char s[]){
	int taille = strlen(s);
	int t[5] = {0, 0, 0, 0, 0};
	for (int i = 0; i<taille; i+=1)
	{
		if (s[i]=='m') t[0]+=1.;
		if (s[i]=='o') t[1]+=1;
		if (s[i]=='s') t[2]+=1;
		if (s[i]=='e') t[3]+=1;
		if (s[i]=='l') t[4]+=1;
	} 
	float min = t[0];
	for (int i = 0; i<3; i+=1)
	{
		if (t[i]<min) min=t[i];
	}
	for (int i = 3; i<5; i+=1)
	{
	    if (((int)(t[i]/2))<min) min=(int)(t[i]/2);
	}
	return min;
}


int main57(){
	if (rpz("moselle")==1) {return 0;}
	else {return 1;}
}


int* decomp(int x){
   int p=2;
   int* t = malloc((x/2)*sizeof(int));
   int i =0;
   while (x>=p){
       if (x%p==0){
           t[i]=p;
           x=x/p;
           i=i+1;}
       else {p=p+1;}
       
   }
   int* res= malloc((i)*sizeof(int));
   for (int j=0; j<=i; j+=1){res[j]=t[j];}
   free(t);
   return res;
}

int main58(){
	int t[]={2, 3, 7};
	if((decomp(42)[0]==2)&&(decomp(42)[1]==3)&&(decomp(42)[2]==7)){return 1;}
    else {return 1;}
}



struct Carte { char val[6]; char coul[8];};
typedef struct Carte carte;

int evaluationHL(carte* hand){
	int points =0;
	int* nb_coul = malloc(4*sizeof(int));
	for (int i=0; i<4; i+=1)
	{
		nb_coul[i]=0;
	}
	for (int i=0; i<13; i+=1)
	{
		if (strcmp(hand[i].coul, "coeur")==0){nb_coul[0]+=1;}
		if (strcmp(hand[i].coul, "carreau")==0){nb_coul[1]+=1;}
		if (strcmp(hand[i].coul, "trefle")==0){nb_coul[2]+=1;}
		if (strcmp(hand[i].coul, "pique")==0){nb_coul[3]+=1;}
		if (strcmp(hand[i].val, "As")==0){points+=4;}
		if (strcmp(hand[i].val, "Roi")==0){points+=3;}
		if (strcmp(hand[i].val, "Reine")==0){points+=2;}
		if (strcmp(hand[i].val, "Valet")==0){points+=1;}
	}
	for (int i=0; i<4; i+=1)
	{
		if (nb_coul[i]>4){points+=nb_coul[i]-4;}
	}
	free(nb_coul);
	return points;
}


int main59()
{
    carte roi_pique = { .val = "Roi" , .coul = "pique" };
    carte as_carreau = { .val = "As" , .coul = "carreau" };
    carte huit_carreau = { .val = "huit" , .coul = "carreau" };
    carte reine_coeur = { .val = "Reine" , .coul = "coeur" };
    carte valet_trefle = { .val = "Valet" , .coul = "trefle" };
    carte neuf_coeur = { .val = "neuf" , .coul = "coeur" };
    carte deux_coeur = { .val = "deux" , .coul = "coeur" };
    carte valet_coeur = { .val = "Valet" , .coul = "coeur" };
    carte neuf_trefle = { .val = "neuf" , .coul = "trefle" };
    carte deux_pique = { .val = "deux" , .coul = "pique" };
    carte sept_coeur = { .val = "sept" , .coul = "coeur" };
    carte six_coeur = { .val = "six" , .coul = "coeur" };
    carte trois_pique = { .val = "trois" , .coul = "pique" };
    
    
    carte hand[13]= { roi_pique , as_carreau , huit_carreau , reine_coeur , valet_trefle , neuf_coeur , deux_coeur , valet_coeur , neuf_trefle , deux_pique , sept_coeur , six_coeur , trois_pique };
    if (evaluationHL(hand)==13){return 0;}
	else { return 1;}
}





void main(){
    int r = main50();

	exit(r);
}

