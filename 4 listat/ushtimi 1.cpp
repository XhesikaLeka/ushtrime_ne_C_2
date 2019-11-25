//Te ndertohet nje funksion qe merr si parameter nje liste nje-drejtimore dhe nje numer te plote M. 
//Te kthehet lista pasi eshte shtuar vlera e dhene e pozicionin e pare dhe te fundit.


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
	return koka;
}

nyje *afisho(nyje *L)
{
	nyje *tmp=L;
	while(tmp!=NULL)
	{printf("%d ",tmp->vlere);
		tmp=tmp->pas;
	}
}
//Te ndertohet nje funksion qe merr si parameter nje liste nje-drejtimore dhe nje numer te plote M.
// Te kthehet lista pasi eshte shtuar vlera e dhene e pozicionin e pare dhe te fundit.
nyje *shto (nyje *L,int x)
{
	nyje *eliri=L,*tmp=L;
	if (L==NULL)
	{L=(nyje*)malloc(sizeof(nyje));
	eliri=(nyje*)malloc(sizeof(nyje));
	L->vlere=x;
	L->pas=eliri;
	eliri->vlere=x;
	eliri->pas=NULL;
	}
	else
	{eliri=(nyje*)malloc(sizeof(nyje));
	eliri->vlere=x;
	eliri->pas=L;
	L=eliri;
	tmp=(nyje*)malloc(sizeof(nyje));
	while(eliri->pas!=NULL)
	{eliri=eliri->pas;}
	eliri->pas=tmp;
	tmp->vlere=x;
	tmp->pas=NULL;
	}
	
	return L;
}
int main()
{
	int n,x;
	printf ("jep elementin qe do shtosh\n");
	scanf ("%d",&x);
	printf("Jep numrin e elementeve te listes: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes: ");
	nyje *L=krijo_liste(n);
	L=shto(L,x);
	afisho(L);
	
	getch();
	return 0;
}
