#include<stdio.h>
#include <stdlib.h>
int X[10],Y[10],k=0,arr[100];

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
	
int main(){
	char ch;
	int numbers_1,i=0,c,x,flag=0;
	FILE *fp=fopen("numbers.txt","r");
	FILE *fptr=fopen("numbers_1.txt","w");
	while(fscanf(fp,"%d%c",&numbers_1,&ch)!=EOF){
		//printf("%d\n",numbers_1);
		if(i==10){
			i=0;
			fprintf(fptr, "\n");
		}
		fprintf(fptr, "%d ",numbers_1);
		i++;
	}/*
	FILE *f;
	FILE *f1;
 	//char ch;
	char var[10000];
	int no_word=0,counter=0,choice;
		  f = fopen("numbers.txt","r");
		  f1 = fopen("numbers_1.txt","w");
		  if(f&&f1){
		     while((ch=getc(f))!=EOF){
			 	if(ch==' ' || ch=='\n') ++no_word;
				else	{
					if(ch!=',')	{fputc(ch,f1);}
					else	{	fprintf(f1," ");	counter++;}
					if(counter==10)	{fprintf(f1,"\n");	counter=0;}
					}
				}
			printf("Words : %d \n",no_word);
			fclose(f);	
			fclose(f1);
			}*/
	
	//FILE *fp=fopen("numbers.txt","r");
	//FILE *fptr=fopen("numbers_1.txt","w");
	printf("------------------------------\n");
	puts("Enter number to be searched:");
	printf("------------------------------\n\t\t");	
	scanf("%d",&x);
	printf("------------------------------\n");
	i=0,c=1;
	fseek(fptr, 0, SEEK_SET);
	fptr=fopen("numbers_1.txt","r+");
	
	while(fscanf(fptr,"%d",&numbers_1)!=EOF){
		if(i==10){
			c++,i=0;
		}
		if(numbers_1==x){
			printf("\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tV");
			printf("\n------------------------------\n");		
			puts("\tNumber found!!");
			printf("Line-> %d\t",c);
			printf("Position-> %d\n",i+1);
			printf("------------------------------\n\n\n");	
			flag=1;
	         fseek(fptr, -2, SEEK_CUR);
		   	fprintf(fptr, "%d",x+1);//increment no by 1
		   	X[k]=c;
		   	Y[k]=i+1;
		   	k++;
		}
		i++;
	}
	int flag1=0;
	if(!flag){
		flag1=1;
		printf("\n\n\n-----------------------------------------------\n");		
		puts("Number does not exists in the file");
			}

	if(flag1!=1){
	printf("\n\n\n---------------------------------------------------------------\n");
	printf("You want to delete the line that contain the number %d (1/0)\n",x);
	printf("---------------------------------------------------------------\n\t\t\t");
	scanf("%d",&c);
	printf("---------------------------------------------------------------\n");
	if(c==1){
		for(int i=0;i<k;i++){
				    int lineNo=X[i]-i;
				    FILE *fileptr1, *fileptr2;
				    char ch;
				    int temp = 1;
				    fileptr1 = fopen("numbers_1.txt", "r");
				    fileptr2 = fopen("temp.txt", "w");
				    while((ch=getc(fileptr1))!=EOF)
				    {
					if (ch=='\n')
					    temp++;
					    if(temp!=lineNo)
					    {
						putc(ch,fileptr2);
					    }
				    }
				    fclose(fileptr1);
				    fclose(fileptr2);
				    remove("numbers_1.txt");
				    rename("temp.txt", "numbers_1.txt");
		}
	printf("\n\n\n----------------------------\n");
	printf("  !!__Line Deleted__!!\n");
	printf("----------------------------\n");
	}
	else if(c==0){

	printf("\n\n\n----------------------------\n");
	printf("!!__Line not Deleted__!!\n");
	printf("----------------------------\n");			
		}
	}
	else{
		printf("\nNumber not found so line could not be deleted!!\n");
		printf("-----------------------------------------------\n");
	}
	printf("\n\n\n---------------------------------------------------------\n");
	printf("Do you want to sort the numbers (1/0):\n[It will create a seperate file named sortedNumber.txt]\n");
	printf("---------------------------------------------------------\n\t\t\t");
	scanf("%d",&c);
	printf("---------------------------------------------------------\n");
	if(c==1){
		rewind(fptr);
 	fptr=fopen("numbers_1.txt","r");

	k=0;
	while(fscanf(fptr,"%d",&arr[k++])!=EOF);
	mergeSort(arr, 0, k - 1);
	fp=fopen("sortedNumber.txt","w");
	rewind(fp);
	c=0;
	while(c<k){
		if(i==10){
			i=0;
			fprintf(fp, "\n");
		}
		fprintf(fp, "%d ",arr[c]);
		i++;
		c++;
	}
	printf("\n\n\n-----------------------------\n");
	printf("!!__File has been soted__!!\n");
	printf("-----------------------------\n");
	}
	else if(c==0){
	printf("\n\n\n-----------------------------\n");
	printf("!!__File not soted__!!\n");
	printf("-----------------------------\n");
	}

	return 0;
}






void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

 





