#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nyje {
	int vlere;
	struct nyje *pas;
} nyje;

nyje *krijo_nyje(int vlere)
{
	nyje *n;
	n=(nyje*)malloc(sizeof(nyje));
	n->vlere=vlere;
	n->pas=NULL;
	return n;
}

nyje *krijo_liste(int n)
{
	if(n==0)
	return NULL;
	nyje *koka=NULL;
	int vlere;
	scanf("%d",&vlere);
	koka=krijo_nyje(vlere);
	nyje *eliri=koka;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&vlere);
		eliri->pas=krijo_nyje(vlere);
		eliri=eliri->pas;
	}
	eliri->pas=koka;
	return koka;
}

void afisho(nyje *L)
{
	nyje *tmp=L;
	while(tmp->pas!=L)
	{printf("%d ",tmp->vlere);
		tmp=tmp->pas;
	}
	printf("%d ",tmp->vlere);
}
//Te ndertohet nje funksion qe merr si parameter nje liste nje-drejtimore rrethore dhe shton ne fund te listes nje nyje te re te barabarte me nyjen e fundit.
nyje *shto (nyje *L)
{nyje *tmp=L, *eliri=L;
if(L==NULL)
return NULL;
else
{
	eliri=(nyje*)malloc(sizeof(nyje));
	while(tmp->pas!=L)
			{tmp=tmp->pas;
			}
	eliri->vlere=tmp->vlere;
	tmp->pas=eliri;
	eliri->pas=L;
	return L;
}
}
 int main ()
{
	int n;
	printf("Jep numrin e elementeve te listes: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes: ");
	nyje *L=krijo_liste(n);
	L=shto(L);
	afisho(L);
	getch();
	return 0;
}
