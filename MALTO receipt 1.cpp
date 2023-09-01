#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define max 20
int size = 0;
int pd_size = 0;
int s_size = 0;
int r_size = 0;

typedef struct Cashiers{
    char id[max];
    char name[max];
    
}cashier;

typedef struct Products{
    char p_id[max];
    char p_description[max];
    double price;
    char p_unit[max];
    double qty;
    double amount;
}product;

typedef struct Sales{
    char date[max];
    char id[max];
    char p_id[max];
    char p_description[max];
    double price;
    double qty;
    double amount;
}sale;

typedef struct Receipts{
    char date[max];
    char id[max];
    char p_id[max];
    char p_description[max];
    double price;
    double qty;
    double amount;
    double s_trans;
}receipt;

Cashiers create_c(char id[max], char name[max]){                                       

	Cashiers C;

	strcpy(C.id, id);
	strcpy(C.name, name);


	size++;

	return C;
}

Receipts create_r(char date[max], char id[max], char p_id[max], char p_description[max], double price, double qty, double amount){

    Receipts T;

    strcpy(T.date, date);
    strcpy(T.id, id);
    strcpy(T.p_id, p_id);
    strcpy(T.p_description, p_description);
    T.price = price;
    T.qty = qty;
    T.amount = amount;

    r_size++;

    return T;
}

Products create_p(char p_id[max], char p_description[max], double price, char p_unit[max], double qty){

	Products P;

	strcpy(P.p_id, p_id);
	strcpy(P.p_description, p_description);
	P.price = price;
	strcpy(P.p_unit, p_unit);
	P.qty = qty;
	
	
	pd_size++;

	return P;
}

Sales create_s(char date[max], char id[max], char p_id[max], char p_description[max],
				 double price, double qty, double amount, double s_trans){

    Sales S;

    strcpy(S.date, date);
    strcpy(S.id, id);
    strcpy(S.p_id, p_id);
    strcpy(S.p_description, p_description);
    S.price = price;
    S.qty = qty;
    S.amount = amount;

    s_size++;

    return S;
}

int checkID(cashier E[max], char id[max]){
	for(int i=0; i<size;i++){
		if(strcmp(E[i].id, id)==0){
			return i;
		}
	}
	return -1;
}

void Display_all_cashiers(cashier C[max]){



    printf("\n\n\tID\t\tName\n");
	for (int i = 0; i < size; i++){
		printf("\n\t%s\t\t%s\n", C[i].id, C[i].name);
	}
}

int search_c(cashier CASHIER[max], char id[max]){
    int i;
    for(i = 0; i<size; i++){
        if(strcmp(CASHIER[i].id, id) == 0)
            return i;
    }
    return -1;

}

void search_cs(cashier B){

    printf("========(Display)========\n\n");
    printf("ID\t\t\tNAME\n");
	printf("%s\t\t\t%s\n", B.id, B.name);

}

int check_p_ID(product E[max], char p_id[max]){
	for(int i=0; i<size;i++){
		if(strcmp(E[i].p_id, p_id)==0){
			return i;
		}
	}
	return -1;
}

void display_prod(product F[50]){
	
	printf("\n\n\t---------- List of Products ----------\n\n");
    printf("ID\t\tNAME\t\tPRICE\t\tUNIT\n");
    for(int i=0; i<pd_size; i++){
    		if(strcmp(F[i].p_id, F[i-1].p_id)){
        printf("%s\t\t%s\t\t%.2lf\t\t%s\n", F[i].p_id, F[i].p_description, F[i].price, F[i].p_unit);
    }
}

}

int search_p(product ITEMS[max], char p_id[max]){
    int i;
    for(i = 0; i< pd_size; i++){
        if(strcmp(ITEMS[i].p_id, p_id) == 0){
            return i;
        }
    }
    return -1;

}

void search_pd(product F){

    printf("\nID: %s\n", F.p_id);
    printf("Description: %s\n", F.p_description);
    printf("Price: %.2lf\n", F.price);
    printf("Unit: %s\n", F.p_unit);
}


void print_receipt(receipt T[50], product P[50], int index, double cash, double total){
	double change=cash-total;
	double amount;

    FILE *ss;

    

    ss = fopen("Sales__.txt", "r");

    if(ss == NULL){
        getch();
        return;
    }

    ss = fopen("Sales__.txt", "a");

	for (int i = 0; i < r_size; i++){
       if(strcmp(P[i].p_id, P[i-1].p_id) != 0){
       	
		   amount = T[i].qty * T[i].price;
        total += amount;
        	
                fprintf(ss,"\n\n%s\t\t%s\t%.2lf\t%.2lf\t%.2lf\n\n", T[i].p_id, T[i].p_description, T[i].price, T[i].qty, amount);
        }
	}
	
//	double change;

/*	fprintf(ss,"\t\t\tCASH RECEIVED:                         %.2lf\n", cash);
    fprintf(ss,"\t\t\tCHANGE:                       %.2lf\n", change);
	fprintf(ss,"\t\t\tTOTAL:                %.2lf\n", total);
*/
    fclose(ss);
}

void Bill(receipt T[50], product P[50], int index, double cash, double total, double s_trans){

double change=cash-total;
double amount;

system("cls");
	printf("\n\n\n\n\n\t\t\t--------------------RECEIPT--------------------");
	printf("\n\n\nProduct ID\t\tDescription\t\tPrice\t\tQuantity\tAmount");
	

	for (int i = 0; i < r_size; i++){
			
		amount = T[i].qty * T[i].price;
        total += amount;
        
        fflush(stdin);
                printf("\n\n%s\t\t\t%s\t\t\t%.2lf\t\t%.2lf\t\t%.2lf\n\n", T[i].p_id, T[i].p_description, T[i].price, T[i].qty, amount);
       
	}
	printf("\t\t\tTOTAL:                                 %.2lf\n", total);
	printf("\t\t\tCASH RECEIVED:                         %.2lf\n", cash);
    printf("\t\t\tCHANGE:                                %.2lf\n", change);


    print_receipt(T, P, index, cash, total);

}

/*void sales( Sales S[50], int index, double cash, double total){

 FILE *ss;

    

    ss = fopen("Sales__.txt", "r");

	for (int i = 0; i < r_size; i++){
        if(strcmp(S[i].p_id, S[i-1].p_id) != 0){
        	
                fprintf(ss,"\n\n%s\t\t%s\t%.2lf\t%.2lf\t%.2lf\n\n", S[i].p_id, S[i].p_description, S[i].price, S[i].qty, S[i].amount);
        }
	}
	
//	double change;

/*	fprintf(ss,"\t\t\tCASH RECEIVED:                         %.2lf\n", cash);
    fprintf(ss,"\t\t\tCHANGE:                       %.2lf\n", change);
	fprintf(ss,"\t\t\tTOTAL:                %.2lf\n", total);
*/
    //fclose(ss);
//}



void display_sales( Sales S[50], int index, double cash, double total){
FILE *ss;
				
//	 ss = fopen("Sales__.txt", "r");
  ss = fopen("Sales__.txt", "a");
				
	
		time_t dt;
		time (&dt);
		printf("\n\n%s",ctime(&dt));
	
    printf("\n\nProduct ID\t\tDescription\t\tPrice\t\tQuantity\tAmount\t\t\n");
    
	
	for (int i = 0; i < s_size; i++){
		
		 if(strcmp(S[i].p_id, S[i-1].p_id) != 0){
		printf("\n%s\t\t\t%s\t\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t\n", S[i].p_id, S[i].p_description, S[i].price, S[i].qty, S[i].amount);
		 
	//	fprintf(ss,"%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", S[i].p_id, S[i].p_description, S[i].price, S[i].qty, S[i].amount);
			}
				    
}
	double amount = 0;
	for (int i = 0; i < s_size; i++){
			
		amount = S[i].qty * S[i].price;
                        total += amount;
                        
    	fprintf(ss,"%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", S[i].p_id, S[i].p_description, S[i].price, S[i].qty, S[i].amount);
	}
	
	printf("\n\n\t\t\t\tOverall Total:   %.2lf", total);

	
	fclose(ss);
getch();

	
//	sales(  S, index, cash,  total);
	
}

void all_sales(Sales S[max], product P[max], int index){
	
	//FILE *pr;
	
	// pr = fopen("Products__.txt", "a");
	 
	 printf("\nProduct ID\t\tDescription\t\tPrice\t\tQTY\t\tAmount\n");


	for (int i = 0; i < s_size; i++){
        if(strcmp(S[i].p_id, S[i-1].p_id) != 0){
            printf("\n\n%s\t\t\t%s\t\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", S[i].p_id, P[index].p_description, P[index].price, S[i].qty, S[i].amount);
          //  fprintf(pr,"%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", S[i].p_id, S[i].p_description, S[i].price, S[i].qty, S[i].amount);
        }
    }
   // fclose (pr);
	getch();
}



void all_sales_temp(Sales S[max], product P[50], int index){

    printf("\nProduct ID\t\tProduct Name\t\tPrice\t\tQTY\t\tAmount\n");

	int i;

	for (i = 0; i < r_size; i++){
            printf("\n\n%s\t\t\t%s\t\t\t%.2lf\t\t%.2lf\t\t%.2lf\t\t\n", S[i].p_id, S[i].p_description, S[i].price, S[i].qty, S[i].amount);
    }
    all_sales( S,P,index);
    
}

int main(){///=================================>>>>>>>>>>>>>MAIN FUNCTION

    FILE *cs, *pd, *ss;

    cs = fopen("Cashiers__.txt", "r");
    pd = fopen("Products__.txt", "r");
	ss = fopen("Sales__.txt", "r");
	//pr = fopen("pr.txt", "a");
    
    int index1;

    int i, j = 0, counter = 0, index, index_id;
    char menu, ch, ch2, per, ah, sh; 
    char pds;
    char temp_name[max];
	cashier CASHIER[50] = {0};
    product ITEMS[50] = {0};
    sale SALES[50] = {0};
    receipt TEMP[50] = {0};

  

	char id[max], name[max];
	char p_id[max], p_description[max], p_unit[max];
    double price, total = 0, amount = 0;

    char date[max], temp_date[max];
    double qty, s_trans = 1;
    double cash;

   time_t dt;
		time (&dt);
		printf("\n\n%s",ctime(&dt));
		
		if(cs == NULL || pd == NULL){
        getch();
        return 1;
    }else{
        while(!feof(cs)){
            fscanf(cs, "%s %s\n", &id, &name);

                if(strcmp(id, "\n") != 0){
                    CASHIER[size] = create_c(id, name);
                }

                }

        while(!feof(pd)){
            fscanf(pd, "%s %s %lf %s\n", &p_id, &p_description, &price, &p_unit);

                if(strcmp(p_id, "\n") != 0){
                    ITEMS[pd_size] = create_p(p_id, p_description, price, p_unit, qty);
                }

            }
         while(!feof(ss)){
            fscanf(ss, "%s %s %s %s %lf %lf %s %lf\n", &date, &id, &p_id, &p_description, &price, &qty, &amount, &s_trans);

                if(strcmp(p_id, "\n") != 0){
                    SALES[s_size] = create_s(date, id, p_id, p_description, price, qty, amount, s_trans);
                }
            }
            
          /* while(!ferror(pr)){
            	fscanf(pr, "%s %s %s %s %lf %lf %s %lf\n", &date, &id, &p_id, &p_description, &price, &qty, &amount, &s_trans);

                if(strcmp(p_id, "\n") != 0){
                	TEMP[r_size] = create_r(date, id, p_id, p_description, price, qty, amount);
                }
			}*/
        }
    fclose(pd);
    fclose(cs);
    fclose(ss);
   // fclose(pr);
    
  main:
        do{
            fflush(stdin);
            system("cls");
            
		printf("\n[1] Add Cashier: ");
		printf("\n[2] LOGIN AS a Cashier:");
		printf("\n[Esc] Exit\n ");

            sh = getch();

            switch(sh){
            	
            	 case '1':
                	{
                do{
                    system("cls");
                    printf("\n-------ADD CASHIER------- ");
                    printf("\n");

                   
                    
                    printf("\n[1] Add Cashier ");
                    printf("\n[Esc] Exit ");

                    ch = getch();

                    switch(ch){
                       

                        case '1': /// Add Cashier
		                            printf("\n=====(Add Cashier)=====");
		                            printf("\nEnter New Cashier's ID: ");
		                            scanf("%s",id);
		                            printf("\nEnter New Cashier's Name: ");
		                            scanf("%s",name);
		                            CASHIER[size] = create_c(id, name);
		                            cs = fopen("Cashiers__.txt", "a");
		                            fprintf(cs, "%s %s\n", id, name);
		                            fclose(cs);
		                       		 break;
            
		                        default:
		                            printf("Invalid Choices!");
		                    }
		                }while(ch != 27);
		            }
		            getch();
		            break;
		            
		            
		            	case '2':
						            ///Cashier Interface
						            printf("\nEnter ID:");
						            scanf("%s", id);
						            
						index = search_c(CASHIER , id);
				  		if(index >= 0){
                        do{
                            system("cls");
                            printf("\n-------CASHIER------- ");
                            printf("\n[1] Add Product  ");
                            printf("\n[2] Display Product  ");
                            printf("\n[3] Search Cashier by  ID ");
                            printf("\n[4] Display Cashier ");
                    		printf("\n[5] Search Product by ID ");
                            printf("\n[6] Buy Product  ");
                            printf("\n[7] Display Sales");
                            printf("\n[Esc] Exit ");

                            ah = getch();

                            switch(ah){

                        case '1':
                            	fflush(stdin);
                            	printf("\n\nADD PRODUCT");
                            	
                                enter:
    
				                printf("\n\nProduct ID: ");
				                gets(p_id);
				                	
				                	i=check_p_ID(ITEMS, p_id);	
				                                	 
				                              if(i>=0){
				                            	printf("\n\nProduct ID already exist\n\n");
				                            	getch();
				                            	goto enter;
				            }
				                printf("\n\nDescription: ");
				                gets(p_description);
				                printf("\n\nUnit: ");
				                gets(p_unit);
				                printf("\nPrice: ");
				                scanf("%lf", &price);
				
				                ITEMS[pd_size] =  create_p(p_id, p_description, price, p_unit, qty);
				
				                pd = fopen("Products__.txt", "a");
				
				                fprintf(pd,"%s\t%s\t%.2lf\t%s\n", p_id, p_description, price, p_unit);
				
				                fclose (pd);
				                getch();
				            break;
				
				
				case '2':
            		
			               		printf("\n\nDISPLAY PRODUCTS");
			                    display_prod(ITEMS);
			                    getch();
			                break;
		                       		 
		                case '3': ///Search Cashier
		                            printf("\n------Search Cashier------\n");
		                            printf("\nEnter ID:");
		                            scanf("%s",id);
		
		                            index = search_c(CASHIER, id);
		
		                            if(index >= 0){
		                            search_cs(CASHIER[index]);
		                            }else{
		                                printf("Cashier does not exist!");
		                            }
		                            getch();
		                            break;
						case '4': ///DIsplay CAshier
									
									 printf("\n\n\n----------- DISPLAY CASHIERS -----------");
                            		Display_all_cashiers(CASHIER);
									getch();
									break;
								   
						case '5':
		                        	///Search Product
		                            printf("\n------Search Product------\n");
		                            printf("\nEnter Product ID:");
		                            scanf("%s",p_id);
		
		                            index1 = search_p(ITEMS, p_id);
        
		                            if(index1 >= 0){
		                              search_pd(ITEMS[index1]);
		                            }else{
		                                printf("Product does not exist!");
		                            }
		                            getch();
		                            break;
               //============================================>>>
		                case '6':
				                	system("cls");
				                	
				                	printf("\n\n------TRANSACTION------\n\n");
				                    
				                    display_prod(ITEMS);
				                	
				                	printf("\nEnter the Cashier ID: ");
								    scanf("%s", id);
								    index = search_c(CASHIER, id);
								
								    if(index == -1){
								        printf("\n\nCashier ID not found\n");
								        
							
								    }
				                	
				                    do{
									
									jump:
							
				                    printf("\n\nProduct ID: ");
				                    scanf(" %s", p_id);
				                    index1 = search_p(ITEMS, p_id);	
				                    if(index1 >= 0){
				                    	printf("Quantity: ");
									  	scanf("%lf", &qty);
				                   		printf("\n\n");
				                    	index = search_p(ITEMS, p_id);	
									
									  }	
											
									else{
									
									char ans;
	                            	printf("\n\nProduct ID is unavailable!\n\n");
	                            	fflush(stdin);
	                            	goto jump;
	                            		break;
	                            
									}

				                    if(index >= 0){
				
										char ans;
				                        fflush(stdin);
				                        printf("\n\tProduct ID\tDecsription\tPrice\t\tQty\t\tAmount");
				                        printf("\n\n\t%s\t\t%s\t\t%.2lf\t\t%.2lf", ITEMS[index].p_id, ITEMS[index].p_description, ITEMS[index].price, qty);
				
										amount = qty * ITEMS[index].price;
				                        total += amount;
				
				                        printf("\t\t%.2lf\n\n", amount);
				
				
				                      // pr = fopen("pr.txt", "r");
				                        
				                        /*time_t dt;
										time (&dt);
										printf("\n\n%s",ctime(&dt));
						*/
				
				                        fflush(stdin);
				                        SALES[s_size] = create_s(date, CASHIER[index].id, ITEMS[index].p_id, ITEMS[index].p_description, ITEMS[index].price, qty, amount, s_trans);
				                        TEMP[r_size] = create_r(date, CASHIER[index].id, ITEMS[index].p_id, ITEMS[index].p_description, ITEMS[index].price, qty, amount);
				
				                        //all_sales_temp(TEMP, ITEMS, index);
				                      //ss = fopen("Sales__.txt", "r");
					                        
					                	//fprintf(pr,"%s %s %s %s %.2lf %.2lf %.2lf\n", date, id, p_id, p_description, price, qty, amount);
					                	//fclose(pr);

				                        
									
                            printf("\n\n\n\t\t\tAdd another product [Y]Yes or [N] No: \t");
				                        scanf("%c", &ans);
				                        switch(ans){
				                        	
				                        	case 'y':
				                        		goto jump;
				                        		break;
				                        	case 'Y':
				                        		goto jump;
				                        		break;
					                    	case 'n':
				                        		goto jump2;
				                        		break;
				                        	case 'N':
				                        		goto jump2;
				                        		break;
											}
					                        ch2 = getch();
					
					                       //ss = fopen("Sales__.txt", "a");
					                        
					                        //fprintf(ss,"%s %s %s %s %.2lf %.2lf %.2lf\n", date, id, p_id, p_description, price, qty, amount);
					                        
					       
					                        
					
					             		   }                                    
					                        
					              			  } while(ch2 == 121);
					              			  
												jump2:
					              			  	 {
					              			  	printf("\n\n\t\t\tTOTAL:                                 %.2lf\n", total);
							                    printf("\n\t\t\tCASH RECEIVED: \t\t\t\t");
							                    scanf("\t%lf", &cash);
							
							                } 
					                        
										//	fprintf(ss,"%s %s %s %s %.2lf %.2lf %.2lf\n", date, id, p_id, p_description, price, qty, amount);
							            
							                Bill(TEMP, ITEMS, index, cash, total, s_trans);
							               // fprintf(pr,"%s %s %s %s %.2lf %.2lf %.2lf\n", date, id, p_id, p_description, price, qty, amount);
							                total = 0;
							                //fclose (ss);
							                getch();
                break;
						case '7':
							
								        	system("cls");
								            printf("\n\n\t\t\t-------------------- SALES --------------------\n");
								            	//SALES[s_size] =  create_s(date, id, p_id, p_description, price, qty, amount, s_trans);
								            
								            //display_sales_(SALES);
							                display_sales(SALES, index, cash, total);
							                
									
											  ss = fopen("Sales__.txt", "r");
											  
											  //	double amount = 0;
												//	for (int i = 0; i < s_size; i++){
																
															amount = qty * price;
													                        total += amount;
													//	}
											 fprintf(ss,"%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", p_id, p_description, price, qty, amount);
											
												fclose(ss);
				
							                break;
							                //ss = fopen("Sales__.txt", "r");
							                
							                //fclose(ss);
							                //getch(); 
							                
							                default:
                           					printf("Invalid Choices!");
								               
								   		  }
										}	while(ah!= 27);
                       					 	s_trans++;
                   							 }					
											else{
                        					printf("\nCashier Not found!");
                   						 }
            						getch();
            					break;
							} 
						
		   			 
		}	while(sh != 27);
		return 0;
	}