#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

/*struct node structure for car regno and time(data)*/
struct node {
      int data;
      char reg[20];
      struct node *prev, *next;
};

/*initialize array of pointer for 5 lanes and lane car counter for lane capacity*/
struct node *lane_head[5],*lane_tail[5];
int lane_count[5]={0};
int car_count=0;

/*createnode for every insertion*/
struct node * createNode(int data,char *reg) {
      struct node *newnode = (struct node *)malloc(sizeof (struct node));
      newnode->data = data;
      char a[20];        
      strcpy(newnode->reg,reg);
      newnode->next = newnode->prev = NULL;
      return (newnode);
}

/*initialize every head and tail pointer for insertions*/
void createSentinels(int lane) {
      lane_head[lane] = createNode(0,"");
      lane_tail[lane] = createNode(0,"");
      lane_head[lane]->next = lane_tail[lane];
      lane_tail[lane]->prev = lane_head[lane];
}

/* insertion at the front of the queue */
void enqueueAtFront(int data,char *reg,int lane) {
      struct node *newnode, *temp;
      newnode = createNode(data,reg);
      temp = lane_head[lane]->next;
      lane_head[lane]->next = newnode;
      newnode->prev = lane_head[lane];
      newnode->next = temp;
      temp->prev = newnode;
}
/*Initialize every lane for insertion and deletion*/
void initialize(){
      int i=0;
      for(i=0;i<5;i++){
            lane_head[i]=NULL;
            lane_tail[i]=NULL;
            createSentinels(i);
      }
}

/*Car insert at front*/
void add_car(int time,char reg[],int lane,int orig) {
      if((car_count<=25)) {
            if((lane_count[lane]<=5)){
                  enqueueAtFront(time,reg,lane);
		  if(orig==0)	printf("Car parked at front of Lane: %d\n",lane_count[lane]+1);
                  lane_count[lane]++;
            } else {
                  enqueueAtFront(time,reg,(lane+1)%5);
            }         
      }
      else 
            printf("!**Total Capacity Full**!\n");
}

/* deletion at a special position*/
void dequeueAtSpecial(char reg[]) {
      int lane=search(reg,2);
      if(lane>=0){
      struct node *temp;
      //printf("%d\n",lane);
      if (lane_head[lane]->next==lane_tail[lane]){
            printf("Queue is empty\n");
      } else {
          temp = lane_head[lane]->next;
          while((temp!=lane_tail[lane])) {
                if(strcmp(temp->reg,reg)==0){
                      temp->prev->next = temp->next;
                      temp->next->prev = temp->prev;
                      temp->next=NULL;
                      temp->prev=NULL;
                      free(temp);
                      car_count--;
                      lane_count[lane]--;
                      //printf("Car DEPARTED\n");
                      break;
                }
                temp = temp->next;
          }
      }
   }
}

/* check_slots elements present in the queue */
void check_slots(int lane) {
      struct node *temp;
      int count=0;
      printf("Lane_%d: ",lane+1);
      if (lane_head[lane]->next == lane_tail[lane]) {
            printf("Lane_%d is empty\n",lane);
            return;
      }
      
      temp = lane_tail[lane]->prev;
      while(temp!=lane_head[lane]) {
	    count++;
            //printf("U+1F697%s----", temp->reg);
            temp= temp->prev;
      }
      int slots_left=5-count;
      printf("%d slots are available.",slots_left);
      printf("\n");
}

/*search a car in every lane sequentialy and then return lane no*/
int search(char reg[],int orig) {
     struct node *temp;
     int i,flag=0,lane,slot=0;
     for(i=0;i<5;i++) {
           lane=i;
           if (lane_head[lane]->next == lane_tail[lane]) {
                  //printf("Lane_%d is empty\n",lane);
                  return -1;
            }
            
            temp = lane_tail[lane]->prev;
            while(temp!=lane_head[lane]) {
		  slot++;
                  if(strcmp(reg,temp->reg)==0) {
			if(orig==2){	printf("CAR: %s DEPARTED\nFrom Lane: %d ; Slot: %d which arrived at time %d \n",reg,i+1,temp->data,slot);flag=1;break;}
                        else{	printf("%s Car is in Lane %d ; Arrived at time %d \n",reg,i+1,temp->data);
                        flag=1;
                        break;
			}
                  }
                  temp= temp->prev;
            } if(flag==1) {
                  break;
            }
     } if(flag==0) {
           printf("no vehical found\n");
           return -1;
     }
     return lane;
}
/*void print1(){
    char narrow_str[] = "\xF0\x9F\x9A\x90";
                    // or "zß水🍌"
                    // or "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";
    wchar_t warr[29]; // the expected string is 28 characters plus 1 null terminator
    setlocale(LC_ALL, "en_US.utf8");
    swprintf(warr, sizeof warr/sizeof *warr,
              L"Converted from UTF-8: %s 1", narrow_str);
    wprintf(L"%ls\n", warr);
    return(0);
}*/
/*check_slots current parking lanes*/
void show_status() {
      int i=0; 

      for(i=0;i<5;i++) {
	      int lane=i;
              struct node *temp;
	      printf("Lane_%d: ",lane+1);
	      if (lane_head[lane]->next == lane_tail[lane]) {
		    printf("Lane_%d is empty\n",lane);
		    return;
	      }
	      
	      temp = lane_tail[lane]->prev;
	      while(temp!=lane_head[lane]) {
	      //print1();
    	      printf("\xF0\x9F\x9A\x90");
	      printf(" %s", temp->reg);
	      printf("\xF0\x9F\x92\xA8");
	      printf("    ");
		    temp= temp->prev;
	      }
	      printf("\n");
      }      
}

int console() {
      int choice;
      printf("\n1. Enter(Continue) Simulator\n0. Exit Simulator\n");      
      scanf("%d",&choice);
      if(choice==1) {
            printf("______________________________________________________\n");
            printf("|\t\tEnter Your Choice                    |\n");
	    printf("|\t\t-----------------                    |\n");
	    printf("|\t                                             |\n"); 
            printf("|\t0. Exit                                      |\n");
            printf("|\t1. Show current status                       |\n");
            printf("|\t2. Show parking slots available in each lane |\n");
            printf("|\t3. Add a New Car                             |\n");
            printf("|\t4. Departure of first Car                    |\n");
            printf("|\t5. Departure of specific Car                 |\n");
            printf("|____________________________________________________|\n");
            scanf("%d",&choice);      
      }      
      return choice;      
}

/*remove car first search than remove car*/
void remove_car(int lane_input) {
      if(lane_input>=0 && lane_input<=5){
      struct node *temp;
      //printf("%d\n",lane_input);
      if (lane_head[lane_input]->next==lane_tail[lane_input]){
            printf("Queue is empty\n");
      } else {
          temp = lane_head[lane_input]->next;
          while((temp!=lane_tail[lane_input])) {
                if(1){
                      temp->prev->next = temp->next;
                      temp->next->prev = temp->prev;
                      temp->next=NULL;
                      temp->prev=NULL;
                      free(temp);
                      car_count--;
                      lane_count[lane_input]--;
                      printf("FIRST Car IN LANE %d DEPARTED\n",lane_input+1);
                      break;
                }
                temp = temp->next;
          }
      }
      }
      else{
	printf("Wrong Lane entered");
	  }
}


int main() {
      FILE *fp;
      char a[20];
      char temp[20];
      char reg[20];
      int tim,time_unit=0,i;
      initialize();
      int orig=0;
//   printf("Enter name of file to read from\n");
//   scanf("%s",a);
      strcpy(a,"parking_data.txt");
      fp = fopen(a,"r");
      if(fp) {	
	    orig=1;
            do {
                  fscanf(fp,"%s",reg);
                  fscanf(fp,"%s",temp); 
                  tim=atoi(temp);           
                  if(time_unit==tim) {                  
                        time_unit=tim;
                        //printf("%s %d\n", reg,tim);
                        car_count++;
                        add_car(tim,reg,(car_count-1)%5,orig);
                  } else if(time_unit<tim) {
                        time_unit=tim;
                        //printf("%s %d\n", reg,tim);
                        car_count++;                  
                        add_car(tim,reg,(car_count-1)%5,orig);
                  }       
            }while(!feof(fp));
      }     
            int y,choice,lane_input; 
            printf("\n!!....Welcome....!!\n");
    	    while(choice = console()) {      
            switch(choice){
		  case 0:	break;
                  case 1:	show_status();
				break;
                  case 2: 	//printf("Input Lane no: \n");scanf("%d",&choice);
				
				for(y=0;y<5;y++)	check_slots(y);
				break;
                  case 3: printf("Input Registration no: \n");
                        scanf("%s",reg);
                        printf("Input time:\n");
                        scanf("%d",&tim);
			orig=0;
                        if(time_unit<=tim) {
                              time_unit=tim;
                              //printf("%s %d\n", reg,tim);
                              car_count++;
                              add_car(tim,reg,(car_count-1)%5,orig);  
                        } else {
                              printf("Incorrect time\n");
                        }
                        break;
                  case 4: printf("Enter the Lane no: \n");scanf("%d",&lane_input);remove_car(lane_input-1);break;
                  case 5: printf("Enter the regestration no: \n");scanf("%s",reg);dequeueAtSpecial(reg);break;
                  default: printf("wrong choice\n");
            }
	}

}
