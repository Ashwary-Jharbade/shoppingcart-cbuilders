#include<stdio.h>
#include<stdlib.h>

struct category{
    int catid;
    char catnam[10];
};

struct addcart{
    int pqty;
    int acid;
};

struct showprod{
    int spid;
    int scatid;
    char snam[10];
    char brand[10];
    char model[10];
    float scos;
    int stock;
    int like;
    int dislike;
};
struct showprod *sp=NULL;
struct category cat[5]={{0,"Personal"},{1,"Electronic"},{2,"Fashion"},{3,"Fitness"},{4,"Sports"}};
struct addcart acart[10];
int frq;
int count;
int id;

void addproduct()
{
    system("cls");
    if(sp==NULL)
    {
        sp=(struct showprod *)malloc(sizeof(struct showprod));
        sp[0].spid=0;
    }
    else
    {
        sp=(struct showprod *)realloc(sp,sizeof(struct showprod)*(count+1));
    }
    printf("Enter Product Type:\n");
    scanf("%s",sp[count].snam);
    printf("Enter Product Brand:\n");
    scanf("%s",sp[count].brand);
    printf("Enter Product Model:\n");
    scanf("%s",sp[count].model);
    printf("Enter Product Category id:\n");
    int i;
    printf("Catid       Category\n");
    for(i=0;i<5;i++)
    {
        printf("%d          %s\n",i,cat[i].catnam);
    }
    scanf("%d",&sp[count].scatid);
    printf("Enter cost of product:\n");
    scanf("%f",&sp[count].scos);
    sp[count].spid=count+1;
    sp[count].stock=500;
    count++;
    printf("______________----------______________\n");
}

int showproduct()
{
    int i;
    system("cls");
    printf("Product List....\n");
    for(i=0;i<count;i++)
    {
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Product Category:%d\n",sp[i].scatid);
        int x=sp[i].scatid;
        printf("Category Name:%s\n",cat[x].catnam);
        printf("Product Name:%s\n",sp[i].snam);
        printf("Product Id:%d\n",sp[i].spid);
        printf("Brand:%s\n",sp[i].brand);
        printf("Model:%s\n",sp[i].model);
        printf("Price:%f\n",sp[i].scos);
        printf("Stock:%u\n",sp[i].stock/2);
        printf("Likes:%u\n",sp[i].like);
        printf("Dislikes:%u\n",sp[i].dislike/300);

    }
    printf("______________---------_______________\n");
    int x;
    printf("Enter id of product to add it on cart or press 0 to go back:\n");
    scanf("%d",&x);
    return x;
}

void cart(int id)
{
     system("cls");
     if(sp[id-1].stock==0)
     {
        printf("Product is out of stock.\n");
        return;
     }
     printf("Enter QTY of product:\n");
     scanf("%d",&acart[frq].pqty);
     if(frq<1){
     acart[frq].acid=id;
      frq++;
     }
     else{
        printf("Cart is full\n");
        int x;
        printf("please remove unwanted product from cart\n");
        printf("Press 1 to continue\n");
        scanf("%d",&x);

     }
}

float viewcart()
{
    float total=0;
    int i;
    int id;
    for(i=0;i<frq;i++)
    {
        id=acart[i].acid;
        printf("++++++++++++++++++++++++++++++++++++++\n");
        total=total+(acart[i].pqty,sp[id-1].scos*acart[i].pqty);
        printf("Product id:%d       Product type:%s         Brand:%s        Model:%s       Product qty:%d         Amount:%f\n",acart[i].acid,sp[id-1].snam,sp[id-1].brand,sp[id-1].model,acart[i].pqty,sp[id-1].scos*acart[i].pqty);
    }
    printf("Total:%f\n",total);
    int x;
    printf("\nEnter 1 to continue:\n");
    scanf("%d",&x);
    return total;
}
void stockifier(){
    int id;
    int i;
    for(i=0;i<frq;i++)
    {
        id=acart[i].acid;
        sp[id-1].stock--;
    }
}
void showcart()
{
    int i;
    float total=0;
        for(i=0;i<frq;i++)
    {
        id=acart[i].acid;
        printf("________________________________________________\n");
        total=total+(acart[i].pqty,sp[id-1].scos*acart[i].pqty);
        printf("Product id:%d       Product type:%s         Brand:%s        Model:%s       Product qty:%d         Amount:%f\n",acart[i].acid,sp[id-1].snam,sp[id-1].brand,sp[id-1].model,acart[i].pqty,sp[id-1].scos*acart[i].pqty);
    }
}

void clearcart()
{
    frq=0;
}

void bill(float t)
{
    system("cls");
    int i;
    printf("User:XXXXXXXXXXXXX\n");
    printf("Email:XXXXXXXXXXXXX\n");
    printf("Mob No:XXXXXXXXXX\n");
    printf("Address:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    showcart();
    printf("Mode of Payment:XXXXXXXXXXXXXXX\n");
    printf("Payable Amount:%f\n",t);
    int x;
    printf("enter 1 to continue and 0 to go back:\n");
    scanf("%d",&x);
    if(x==1){
        printf("Payment done\n");
        stockifier();
        clearcart();
    }

}

int main()
{
   int choice=1;
   int id;
   float total;
    while(choice)
    {
        system("cls");
        printf("1)Add Product\n2)View Product\n3)View Cart Items\n4)Clear Cart\n5)Generate BILL\nEnter any of the above choices or 0 for exit:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addproduct();
            break;
        case 2:
            id=showproduct();
            if(id)
             cart(id);
            break;
        case 3:
            system("cls");
            total=viewcart();
            break;
        case 4:
            clearcart();
            break;
        case 5:
            bill(total);
            break;
        default:
            if(choice==0)
                printf("Program terminated\n");
            else{
                printf("Wrong Option\n");
            }
        }
    }

}

