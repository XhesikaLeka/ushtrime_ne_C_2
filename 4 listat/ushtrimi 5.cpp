//Te ndertohet nje funksion qe merr si parameter nje liste dy-drejtimore dhe nje numer te plote M, shton numrin M 
//pas elementin te M-te, nqs lista ka me pak se M elemente te shtohet ne fund.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nyje {
	int vlere;
	struct nyje *para;
	struct nyje *pas;
} nyje;

nyje *krijo_nyje(int vlere)
{
	nyje *n;
	n=(nyje*)malloc(sizeof(nyje));
	n->vlere=vlere;
	n->para=NULL;
	n->pas=NULL;
	return n;
}

nyje *krijo_liste(int n)
{
	if(n==0)
	return NULL;
	nyje *koka;
	int vlere;
	scanf("%d",&vlere);
	koka=krijo_nyje(vlere);
	nyje *eliri=koka;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&vlere);
		eliri->pas=krijo_nyje(vlere);
		eliri->pas->para=eliri;
		eliri=eliri->pas;
	}
	return koka;
}

void afisho(nyje *L)
{
	nyje *tmp=L;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->vlere);
		tmp=tmp->pas;
	}
}
nyje *shto (nyje *L, int M)
{nyje *tmp=L,*eliri;
int c=0;
eliri=(nyje*)malloc(sizeof(nyje));
eliri->vlere=M;
if(L==NULL)
L->vlere=M;
L->para==NULL;
L->pas==NULL;
 	while (tmp!=NULL)
		{tmp=tmp->pas;
		c++;
		}
tmp=L;		
 	if(c<M)
		{
			while (tmp->pas!=NULL)
				{tmp=tmp->pas;
				}
	  	tmp->pas=eliri;
	 	eliri->para=tmp;
	 	eliri->pas=NULL;
		}
		
else {for(int i=1;i<M;i++)
		{tmp=tmp->pas;}
		eliri->para=tmp;
		eliri->pas=tmp->pas;
		tmp->pas=eliri;
		tmp->pas->para=eliri;
		
	}	
return L;
		
		
}


int main()
{
	int n,M;
	printf("Jep numrin e elementeve te listes: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes: ");
	nyje *L=krijo_liste(n);
	printf("Jep elementin qe do te shtosh: ");
	scanf("%d",&M);
	L=shto(L,M);
	afisho(L);
	getch();
	return 0;
}
