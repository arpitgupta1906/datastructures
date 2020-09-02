#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList *node;


node create(int data){
    node new_node=(node)malloc(sizeof(struct LinkedList));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}


node insert_tail(node head1,int num){
    node temp=head1,new_node;
     new_node=create(num);
    if(temp==NULL){ 
        head1=new_node;
    }
    else
    {
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    return head1;
}


void display(node head){
    node temp=head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}


node insert_head(node head,int num){
    node new_node;
    new_node=create(num);
    if(head==NULL){
        head=new_node;
    }
    else{
        new_node->next=head;
        head=new_node;
    }
    return head;
}


node insert_position(node head,int num,int position){
    node temp=head,new_node;
    new_node=create(num);
    int i=1;
    while(temp->next!=NULL && i<position){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return head;
}


void search(node head,int value){
    node temp=head;
    int flag=0,index,i=0;
    while(temp!=NULL){
        if(temp->data==value){
            flag=1;
            index=i;
            break;
        }
        i++;
        temp=temp->next;
    }
    if(flag){
        printf("Element found at index: %d",index);
    }
    else{
        printf("Element not found");
    }
}

void copy(node input,node target){
    node tempinp=input;
    while(tempinp!=NULL){
        target=insert_tail(target,tempinp->data);
        tempinp=tempinp->next;
    }
}


node reverse(node head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    else{
        node temp=reverse(head->next);
        temp->next=head;
        head->next=NULL;
        return head;
        
    }
}


node delete_index(node head,int index){
        if(index==0){
            return head->next;
        }
        else
        {   
           head->next=delete_index(head->next,index-1);
           return head;
        }
        
    
}


int pop(node head){
    node temp=head;
    if(temp==NULL){
        return 0;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    int popvalue=temp->data;
    temp=NULL;
    return popvalue;
}


void sort(node head){
    node i=head,j;
    int a;
    while(i!=NULL){
        j=i->next;
        while(j!=NULL){
            if((i->data)>(j->data)){
                a=i->data;
                i->data=j->data;
                j->data=a;
            }
            j=j->next;
        }
        i=i->next;
    }
}


int main(){
    node head;
    head=NULL;
    int n,topnum;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        head=insert_tail(head,num);
    }
    display(head);
    printf("\nenter to insert at top: ");
    scanf("%d",&topnum);
    head=insert_head(head,topnum);
    display(head);
    printf("\n Enter value and position to insert: ");
    int value,index;
    scanf("%d %d",&value,&index);
    head=insert_position(head,value,index);
    display(head);
    return 0;
}
