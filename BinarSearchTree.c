
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void insert()
{
    struct node *temp,*parent;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        parent=root;
        while(parent!=NULL)
        {
            if(temp->data>parent->data)
            {
                if(parent->right==NULL)
                {
                    parent->right=temp;
                    return;
                }
                else
                {
                    parent=parent->right;
                }
            }
            else
            {
                if(parent->left==NULL)
                {
                    parent->left=temp;
                    return;
                }
                else
                {
                    parent=parent->left;
                }
            }
        }
    }
}
void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}
void search()
{
    struct node *temp;
    int data;
    printf("Enter the data to be searched:");
    scanf("%d",&data);
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            printf("Data found\n");
            return;
        }
        else if(temp->data<data)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
    printf("Data not found\n");
}
void delete()
{
    struct node *temp,*parent,*suc,*psuc,*ptr;
    int data;
    printf("Enter the data to be deleted:");
    scanf("%d",&data);
    temp=root;
    parent=NULL;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            break;
        }
        parent=temp;
        if(temp->data<data)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
    if(temp==NULL)
    {
        printf("Data not found\n");
        return;
    }
    if(temp->left==NULL)
    {
        ptr=temp->right;
    }
    else if(temp->right==NULL)
    {
        ptr=temp->left;
    }
    else
    {
        psuc=temp;
        suc=temp->right;
        while(suc->left!=NULL)
        {
            psuc=suc;
            suc=suc->left;
        }
        if(temp==psuc)
        {
            suc->left=temp->left;
        }
        else
        {
            suc->left=temp->left;
            psuc->left=suc->right;
            suc->right=temp->right;
        }
        ptr=suc;
    }
    if(parent==NULL)
    {
        root=ptr;
    }
    else if(parent->left==temp)
    {
        parent->left=ptr;
    }
    else
    {
        parent->right=ptr;
    }
    free(temp);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Search\n6.Delete\n7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                   break;
            case 2:inorder(root);
                   break;
            case 3:preorder(root);
                   break;
            case 4:postorder(root);
                   break;
            case 5:search();
                   break;
            case 6:delete();
                   break;
            case 7:exit(0);
            default:printf("Wrong Choice\n");
        }
    }
    return 0;
}
