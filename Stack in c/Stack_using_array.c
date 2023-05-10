#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array,a,j,n,val;
    printf("\nEnter size of Stack :- ");
    scanf("%d",&n);
    array=(int*)malloc(sizeof(int)*n);
    j=-1;
    do{
        printf("\nEnter \n1...To Push\n2...To Pop\n3...To Display\n0...To Exit\n");
        scanf("%d",&a);
        switch(a){
            case 1:
                if(j+1==n){
                    printf("Stack is full\n");
                }
                else{
                    printf("Enter value to push :- ");
                    scanf("%d",&val);
                    array[++j]=val;
                }    
                break;
            case 2:
                if(j==-1){
                    printf("Stack is Empty\n");
                }
                else
                    printf("%d is poped\n",array[j--]);
                break;
            case 3:
                for(int i=j;i>=0;i--){
                    printf("%d ",array[i]);
                }
                break;
            case 0:
                printf(".....THANKS FOR USING OUR PROGRAM.....\n");
                break;
            default:
                printf("Enter valid input\n");                    
        }
    }while(a);
    return 0;
}