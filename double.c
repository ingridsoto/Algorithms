#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct person
{
	char * firstName;
	char * lastName;
	int mm,dd,yy;
};
/*
struct node
{
	struct node * prev;
	struct node * next;
	void * data;
};*/
struct node
{
	struct node * prev;
	struct node * next;
	struct person * Person;
};

struct person * createPerson (char * firstName, char * lastName, int mm, int dd, int yy)
{
	struct person * s;
	s=(struct person*)malloc(sizeof(struct person));
	char *f = malloc((strlen(firstName)+1)*sizeof(char));
	char *l = malloc((strlen(lastName)+1)*sizeof(char));

	strncpy(f,firstName,strlen(firstName)+1);
	strncpy(l,lastName,strlen(lastName)+1);

	s->firstName = f;
	s->lastName = l;
	s->mm = mm;
	s->dd = dd;
	s->yy = yy;

	return s;
}

struct node * insert (struct node *front,void * data)
{
	struct node *p, *q= NULL, *nnew;
	p=front;
	nnew=data;
	while (p!=NULL)
    {
		q=p;
		p=p->next;
	}
	q->next=nnew;
	nnew->prev = q;
	nnew->next = p;
}

struct node * createNode (void * data)
{
	struct node * n;
	n=(struct node*)malloc(sizeof(struct node));
	n->Person = data;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

struct node * insertNode (struct node * front, void * data)
{
    struct node *p, *q= NULL, *nnew;
    nnew=(struct node*)malloc(sizeof(struct node));
    nnew->Person = data;
    if (!front)
    {
        nnew->prev = NULL;
        nnew->next = NULL;
        front = nnew;
    }
    else
    {
    p=front;
    while (p!=NULL)
    {
        q=p;
        p=p->next;
    }
        q->next=nnew;
        nnew->prev=q;
        nnew->next=p;
    }
    return (front);
}



void showList(struct node *front)
{
    struct node *aux;
    system("cls");
    if(!front)
        printf("It's empty");
    else
    {
        aux=front;
        do
        {
            printf("\n%s",aux->Person->firstName);
            printf("\n%s",aux->Person->lastName);
            printf("\n%d/%d/%d",aux->Person->dd, aux->Person->mm, aux->Person->yy);
            aux=aux->next;
        }
        while(aux!= NULL);
    }
    getch();
}

void capturaCadena(char arreglo[],char min, char max, int size,int minSize)
{
    int i=0,flag=0;
    char ascii;

    do
    {
        ascii=getch();

        if(i>size-1 && ascii!=8)
            if(ascii!=13)
                ascii=49;

        if(ascii==8)
        {
            if(i>0)
            {
                i--;
                printf("%c",8);
            }
        }

        if ((ascii>=min && ascii<=max) || ascii==13 || (ascii>=(min-32) && ascii<=(max-32)) || ascii==32 )
        {

            if(ascii==13)
            {
                if(i<minSize)
                {
                    printf("\nNo son suficientes caracteres\n");
                    getch();
                    i=0;
                }
                else
                    flag=1;
                arreglo[i]='\0';
            }
            else
            {
                arreglo[i]=ascii;
                i++;
            }
        }
        else
        {
            ascii=8;
            printf("%c",0);
        }
        printf("%c",ascii);
    }
    while(flag!=1);
}



void main ()
{
	int option;
	struct node * front=NULL;
	char firstName[128];
	char lastName [128];
	int dd,mm,yy;
	do
    {
        system("cls");
        printf(" 1. Add node\n");
        printf(" 2. Delete node\n");
        printf(" 3. Show list\n");
        printf(" 4. Exit\n");
        printf("Option: [ ]\b\b");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        	{
        		system("cls");
        		printf("First Name:\n");
    			capturaCadena(firstName,'a','z',MAX,1);
    			printf("\n");
		        printf("Last Name:\n");
		        capturaCadena(lastName,'a','z',MAX,1);
		        printf("\n");
		        printf("MM DD YY:\n");
		        scanf("%d",&mm);
		        scanf("%d",&dd);
		        scanf("%d",&yy);
        		/*if (!front)
        		{	
            		front=createNode(createPerson(firstName,lastName,dd,mm,yy));
				}
                else
				front=insert(front,createPerson(firstName,lastName,dd,mm,yy));*/
				front=insertNode(front,createPerson(firstName,lastName,dd,mm,yy));
			}
            break;
            
        case 3:
        	showList(front);
            break;
        case 2:
            system("cls");
            
            break;
        case 4:
            break;
        }
    }
    while(option!=4);
}

