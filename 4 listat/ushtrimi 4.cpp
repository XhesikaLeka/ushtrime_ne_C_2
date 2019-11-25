
/*	4.	Te ndertohet nje funksion qe merr si parameter nje liste dy-drejtimore
		dhe nje numer te plote M, fshin nga lista te gjithe elementet e 
		barabarte me M dhe kthen listen e re. */

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
nyje *fshij(nyje *L ,int M)
{nyje *tmp=L;
if(L==NULL)
	return NULL;
//else if (L->pas==NULL&&L->para==NULL&&L->vlere==M)
//	return NULL;
else 
	while (tmp!=NULL)
	{if (tmp->vlere==M)
			{tmp->para->pas=tmp->pas;
			tmp->pas->para=tmp->para;
			}
			tmp=tmp->pas;
	}
return L;
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


int main()
{
	int n,M;
	printf("Jep numrin e elementeve te listes: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes: ");
	nyje *L=krijo_liste(n);
	printf("Jep elementin qe do te fshish: ");
	scanf("%d",&M);
	L=fshij(L,M);
	afisho(L);
	getch();
	return 0;
}
