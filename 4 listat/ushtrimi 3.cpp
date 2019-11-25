//Te ndertohet nje funksion qe merr si parameter dy lista nje-drejtimore rrethore, shton listen e pare pas listes se dyte dhe klthen listen e re.

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
//Te ndertohet nje funksion qe merr si parameter dy lista nje-drejtimore rrethore, shton listen e pare pas listes se dyte dhe klthen listen e re.
nyje *bashko(nyje *L1, nyje *L2)
{nyje *tmp=L2;
if(L1==NULL&&L2==NULL)
	{return NULL;}
else if(L1==NULL)
	{return L2;}
else if(L2==NULL)
	{return L1; }
else
	{while (tmp->pas!=L2)
			{tmp=tmp->pas;
			}
tmp->pas=L1;
tmp=L1->pas;
	{while (tmp->pas!=L1)
			{tmp=tmp->pas;
			}
		tmp->pas=L2	;
			
	}	

}
return L2;

}
 int main ()
{
	int n;
	printf("Jep numrin e elementeve te listes se pare: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes se pare: ");
	nyje *L1=krijo_liste(n);
		int m;
	printf("Jep numrin e elementeve te listes se dyte: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes se dyte: ");
	nyje *L2=krijo_liste(n);
	nyje *L=bashko(L1,L2);
	afisho(L);
	getch();
	return 0;
}
