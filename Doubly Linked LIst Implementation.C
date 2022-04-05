#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
typedef struct node * List;
typedef struct node * Position;
List L;
List NewNode;
void CreateList()
{
    int n;
    struct node *newNode;
    struct node *temp;
    L = (struct node *)malloc(sizeof(struct node));
    printf("Enter the total number of nodes [Excluding header]: ");
    scanf("%d",&n);
    L->next=NULL;
    temp=L;
    for(int i=1; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp = temp->next;
    }
}
void TraverseList(List l)
{
    struct node *temp;
    if(l == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = l;
    temp = temp->next; 
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); 
        temp = temp->next;              
    }
}
int IsEmpty(List l)
{
    if(l->next==NULL)
       return 1;
    else
       return 0;
}
int IsLast(Position P)
{
    if(P->next == NULL)
        return 1;
    else
        return 0;
}
Position Find(int x,List l)
{  
    Position Temp;
    Temp=l;
    while(Temp!=NULL)
    {
    if(Temp->data==x)
        return Temp;
    Temp=Temp->next;
    }
    return Temp;
}
Position FindPrev(int x,List l)
{
     Position P;
     P=l;
     while(P->next !=NULL && P->next->data!=x)
     P=P->next;
   return P;
}
Position FindNext(int x,List l)
{
    Position P;
    P = Find(x,l);
    return P->next;
}
void InsertBeg(int e,List l)
{
    NewNode =(struct node*)malloc(sizeof(struct node));
    NewNode->data = e;
    if(IsEmpty(l))
        NewNode->next = NULL;
    else
        {
            NewNode->next = l->next;
            NewNode->next->prev=NewNode;
        }
    NewNode->prev=l;    
    l->next = NewNode;
}
void InsertMid(int p, int e,List l)
{
    NewNode =(struct node *) malloc(sizeof(struct node));
    Position P;
    P = Find(p,l);
    NewNode->data = e;
    NewNode->next = P->next;
    P->next->prev=NewNode;
    P->next = NewNode;
    NewNode->prev=P;
}
void InsertEnd(int e,List l)
{
    NewNode =(struct node *) malloc(sizeof(struct node));
    Position P;
    NewNode->data = e;
    NewNode->next = NULL;
    if(IsEmpty(l))
    {
        l->next = NewNode;
        NewNode->prev=l;
    }    
    else
    {
        P = l;
        while(P->next != NULL)
            P = P->next;
        P->next = NewNode;
        NewNode->prev=P;
    }
}
void DeleteBeg(List l)
{
    if(!IsEmpty(l))
    {
        Position TempNode;
        TempNode = l->next;
        l->next = TempNode->next;
        if(l->next!=NULL)
        TempNode->next->prev=l;
        printf("The deleted item is %d\n", TempNode->data);
        free(TempNode);
    }
    else
        printf("List is empty...!\n");
}
void DeleteEnd(List l)
{
    if(!IsEmpty(l))
    {
        Position P,TempNode;
        P = l;
        while(P->next != NULL)
        P = P->next;
        TempNode = P;
        P->prev->next = NULL;
    printf("The deleted item is %d\n", TempNode->data);
    free(TempNode);
    }
    else
        printf("List is empty...!\n");
}
void DeleteMid(int e,List l)
{
    if(!IsEmpty(l))
    {
        Position P,TempNode;
        P = Find(e,l);
        if(!IsLast(P))
        {
            TempNode = P;
            P->prev->next = P->next;
            P->next->prev=P->prev;
            printf("The deleted item is %d\n", TempNode->data);
            free(TempNode);
        }
    }
    else
        printf("List is empty...!\n");
}

int main() {
    int n;
    CreateList();
    printf("Enter the operation\n1-Traverse\n2-Is Empty\n3-Find\n4-Find Previous\n5-Find Next\n");
    printf("6-Insert Beginning\n7-Insert Middle\n8-Insert End\n9-Delete Beginning\n");
    printf("10-Delete Middle\n11-Delete End\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            TraverseList(L);
            break;
        }
        case 2:
        {
            if(IsEmpty(L))
                printf("List is empty\n");
            else
                printf("List is not empty\n");
            break;    
        }
        case 3:
        {
            int x;
            printf("Enter the element");
            scanf("%d",&x);
            if(Find(x,L)!=NULL)
            {
                printf("Element is present at %d",Find(x,L));
            }
            else
               printf("Element is not found");
            break;   
        }
        case 4:
        {
            int x;
            printf("Enter the element");
            scanf("%d",&x);
            if(FindPrev(x,L)!=NULL)
            {
                printf("Previous element is present at %d\n",FindPrev(x,L));
            }
            else
               printf("Previous element is not found\n");
            break;   
        }
        case 5:
        {
            int x;
            printf("Enter the element");
            scanf("%d",&x);
            if(FindNext(x,L)!=NULL)
            {
                printf("Next element is present at %d\n",FindNext(x,L));
            }
            else
               printf("Next element is not found\n");
            break;
        }
        case 6:
        {
            int x;
            printf("Enter element to be added\n");
            scanf("%d",&x);
            InsertBeg(x,L);
            printf("The modified list is\n");
            TraverseList(L);
            break;
        }
        case 7:
        {
            int p,x;
            printf("Enter the element before the data to be added and element to be added\n");
            scanf("%d%d",&p,&x);
            InsertMid(p,x,L);
            printf("The modified list is\n");
            TraverseList(L);
            break;
            
        }
        case 8:
        {
            int x;
            printf("Enter element to be added\n");
            scanf("%d",&x);
            InsertEnd(x,L);
            printf("The modified list is\n");
            TraverseList(L);
            break;
        }
        case 9:
        {
            DeleteBeg(L);
            break;
        }
        case 10:
        {
            int x;
            printf("Enter element to be deleted\n");
            scanf("%d",&x);
            DeleteMid(x,L);
            break;
        }
        case 11:
        {
            DeleteEnd(L);
            break;
        }
        default:
           printf("Invalid Operation\n");
    }
    return 0;
}
