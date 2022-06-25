#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "global.h"


int main()
{
    int choice;
    EntryType e,newValue,s;

    TreeType t;
    createTree(&t);

    printf("1.To add  pairs to the collection.\n2.To remove pairs from the collection.\n");
    printf("3.To Modify the values of existing pairs.\n4.To lookup to the value associated with a particular key.\n5.exit\n\n.");

    printf("Enter your choice\n");
    scanf("%d",&choice);



    while(choice){
        switch(choice){

             case 1: //insert
                printf("Enter key\n");
                scanf("%d",&e.key);

                printf("Enter number of values\n");
                scanf("%d",&e.sizeValue);
                printf("Enter values\n");
                for(int i=0 ;i<e.sizeValue;i++){
                    scanf("%d",&e.value[i]);
                }
                if(insert(&t,&e)!=0){
                    printf("key ALREADY exists!\n");
                }

                break;

             case 2://delete
                printf("Enter key\n");
                scanf("%d",&e.key);
                if(deleteKey(&t, &e)){
                    printf("deleted successfully\n");
                }else{
                    printf("key does not exist!\n");
                }

                break;
             case 3:
                printf("Enter key\n");
                scanf(" %d",&s.key);
                printf("Enter number of values\n");
                scanf("%d",&newValue.sizeValue);
                printf("Enter the new value\n");
                for(int i=0 ;i<newValue.sizeValue;i++){
                    scanf("%d",&newValue.value[i]);
                }
                modifyValue(&t,&s,&newValue);
                break;

             case 4: //search
               printf("Enter key\n");
               scanf("%d",&e.key);
               if(search(&t,&e)){
                    for(int i=0;i< e.sizeValue;i++){
                     printf("%d \n",e.value[i]);
                    }
               }
               else {
                 printf("The key does not exist!\n");
               }
                break;

             case 5:
                exit(0);
        }
        printf("\n\n");
        printf("1.To add  pairs to the collection.\n2.To remove pairs from the collection.\n");
        printf("3.To Modify the values of existing pairs.\n4.To lookup to the value associated with a particular key.\n5.exit\n\n.");
        printf("Enter your choice\n");
        scanf("%d",&choice);
    }



    return 0;
}
