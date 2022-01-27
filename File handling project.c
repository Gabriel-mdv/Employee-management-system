#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
delware: a  function to help deleting thing in file
del: this function deleter things on screen only
#the sorting works does it by order of salary
*/
typedef struct employee{
	char name[20];
	int age;
	int salary;
	int rolno;
} emp;

void record(void);
void display(void);
void append(void);
void search(void);
void norc(void);
void del(void);
void delware(void);
void update(void);
void sort(void);
void sortware(void);

int main(){
	int choice;
	printf("\t");
	do{
	printf("\tChoose how we can help you\n\t1.Record\n\t2.Display\n\t3.Add one more\n\t4.Search\n\t5.NO of records\n\t6.Delete on screen only\n\t7.Delete in file\n\t8.Update\n\t9.Sort on screen\n\t10.Sort in file\n\t0.Exit\n\t\t");
	scanf("%d",&choice);	
	
	switch(choice){
		case 1:
			record();
			break;
		case 2:
		    display();
			break;
		case 3:
		    append();
			break;	
		case 4:
		    search();
			break;
	    case 5:
		    norc();
			break;	
		case 6:
		    del();
			break;	
		case 7: 
		    delware();
			break;	
		case 8: 
		    update();
			break;	
		case 9: 
		    sort();
			break;	
		case 10:
		    sortware();
			break;				
		case 0: 
		    exit(1);
			break;	
	} 
	
    }while(choice!=0);	
	return 0;
}
void record(){
	FILE*fp;
	fp=fopen("Handling.txt","wb");
	if(fp==NULL){
		printf("the file cannot be opened");
	    exit(1);
	}
	struct employee q1;
	int n,i;
	printf("how many employees do you want to registe? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the details for employee %d\n",i+1);
	    fflush(stdin);
	    printf("Enter the name: ");
	    gets(q1.name);
	    printf("Enter the age: ");
	    scanf("%d",&q1.age);
		printf("Enter the salary: ");
	    scanf("%d",&q1.salary);
	    printf("Enter the Rol number: ");
	    scanf("%d",&q1.rolno);
	    fwrite(&q1,sizeof(q1),1,fp);
	    printf("\n");
	}
	printf("\nYour data is sucessfully saved.\n");
	fclose(fp);
}
void display(){
	
	FILE*fp;
	fp=fopen("Handling.txt","rb");
	if(fp==NULL){
		printf("the file cannot be opened!");
		exit(1);
	}
	struct employee disp;
	printf("\nName\t\tAge\t\tSalary\t\tRolno\n\n");
	while(fread(&disp,sizeof(disp),1,fp)==1){
		printf("%s\t\t%d\t\t%d\t\t%d\n",disp.name,disp.age,disp.salary,disp.rolno);
	}
	printf("\n");
	fclose(fp);
};
void append(){
	FILE*fp;
	struct employee a1;
	fp=fopen("Handling.txt","ab");
	if(fp==NULL){
		printf("the file cannot be opened!");
		exit(1);
	}
	int n,i;
	printf("How many more more employees do you want to add?\n\t");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter data for the new employee %d\n",i+1);
		fflush(stdin);
		printf("Enter the name: ");
		gets(a1.name);
		printf("Enter the age: ");
		scanf("%d",&a1.age);
		printf("Enter the salary: ");
		scanf("%d",&a1.salary);
		printf("Enter the rolno: ");
		scanf("%d",&a1.rolno);
		fwrite(&a1,sizeof(a1),1,fp);
		
	}
	printf("Successfully added!\n\n");
	fclose(fp);
};
void search(){
	
	int rol,sea;
	int count=0;
	char nam[20];
	struct employee s1;
	FILE*fp;
	fp=fopen("Handling.txt","rb");
	if(fp==NULL){
		printf("The file cannot be opened!");
		exit(1);
	}
	printf("Choose Search by: 1.Name or 2.Rol number? ");
	scanf("%d",&sea);
	if(sea==1){
		printf("Whose data do you want to view? ");
		scanf("%s",nam);
		
		while(fread(&s1,sizeof(s1),1,fp)==1){
			if(strcmp(nam,s1.name)==0){
				printf("Name\t\tAge\t\tSalary\t\tRolno\n");
				printf("%s\t\t%d\t\t%d\t\t%d\n",s1.name,s1.age,s1.salary,s1.rolno);
				count++;
			}
		}
	
		
	    }
	else if(sea==2){
	
	printf("The info you want corresponds to which rol number? ");
	scanf("%d",&rol);
	
	while(fread(&s1,sizeof(s1),1,fp)==1){
		if(s1.rolno==rol){
			count++;
		printf("Name\t\tAge\t\tSalary\t\tRolno\n\n");
		printf("%s\t\t%d\t\t%d\t\t%d\n\n",s1.name,s1.age,s1.salary,s1.rolno);
	    }
	    else{
	    	continue;
		}
	}
	
    }
	if(count==0){
		    printf("\nThat person is not among our employees!\n\n");
    }
	};
void norc(){
	FILE*fp;
	fp=fopen("Handling.txt","rb");
	if(fp==NULL){
		printf("the file cannot be opened!");
		exit(1);
	}
    emp e1;
//    while(fread(&e1,sizeof(e1),1,fp)==1);
    fseek(fp,0,SEEK_END);
    int n;
    n=ftell(fp)/sizeof(e1);
	printf("the number of records is %d\n\n",n);
	fclose(fp);

	};  
void del(void){
     emp e1;
     FILE*fp;
    
     emp s1;
     fp=fopen("Handling.txt","rb");

     if(fp==NULL){
     	printf("this file cannot be opened!");
     	exit(1);
	 }
	 int rol;
	 printf("What roll number that corresponds to what you want to delete? ");
	 scanf("%d",&rol);
	 printf("Name\t\tAge\t\tSalary\t\tRolno\n");
	 while(fread(&s1,sizeof(s1),1,fp)==1){
	 	if(s1.rolno!=rol){
	 	    printf("%s\t\t%d\t\t%d\t\t%d\n",s1.name,s1.age,s1.salary,s1.rolno);
		 }
	 }
	 fclose(fp);
 }
void delware(void){
	
     FILE*fp;
     FILE*pt;
     emp s1;
     fp=fopen("Handling.txt","rb");
     pt=fopen("ext.txt","wb");
     if(fp==NULL||pt==NULL){
     	printf("this file cannot be opened!");
     	exit(1);
	 }
	 int rol;
	 printf("What roll number that corresponds to what you want to delete? ");
	 scanf("%d",&rol);

	 while(fread(&s1,sizeof(s1),1,fp)==1){
	 	if(s1.rolno!=rol){
	 	    fwrite(&s1,sizeof(s1),1,pt);
		 }
	 }
	 fclose(fp);
	 fclose(pt);
	 fp=fopen("Handling.txt","wb");
	 pt=fopen("ext.txt","rb");
	 if(fp==NULL||pt==NULL){
	 	printf("the file cannot be opned!");
	 	exit(1);
	 }
	 while(fread(&s1,sizeof(s1),1,pt)==1){
	 	fwrite(&s1,sizeof(s1),1,fp);
	 }
	 printf("The data that corresponds to the rolno %d was successfully deleted in the file.\n\n",rol);
	 
	 fclose(fp);
	 fclose(pt);
}	
void update(){
	FILE*fp;
	FILE*pt;
	emp s1;
	fp=fopen("Handling.txt","rb");
	pt=fopen("ext.txt","wb");
	if(fp==NULL||pt==NULL){
		printf("the file cannot be opened!\n");
		exit(1);
	}
	int rol;
    printf("What rolno corrresonds to the data you want to update? ");
	scanf("%d",&rol);
	while(fread(&s1,sizeof(s1),1,fp)==1){
		if(s1.rolno!=rol){
		fwrite(&s1,sizeof(s1),1,pt);
	    }
	else{
		fflush(stdin);
		printf("Enter new name: ");
		scanf("%[^\n]s",s1.name);
		printf("Enter new age: ");
		scanf("%d",&s1.age);
		printf("Enter new salary: ");
		scanf("%d",&s1.salary);
		printf("Enter new rolno: ");
		scanf("%d",&s1.rolno);
	    fwrite(&s1,sizeof(s1),1,pt);
	}
    }
	
	fclose(fp);
	fclose(pt);
	fp=fopen("Handling.txt","wb");
	pt=fopen("ext.txt","rb");
	if(fp==NULL||pt==NULL){
		printf("the file cannot be opened!");
		exit(1);
	}
	printf("\tUPDATED LIST(same in file)\n");
	printf("Name\t\tAge\t\tSalary\t\tRolno\n");
	while(fread(&s1,sizeof(s1),1,pt)==1){
		fwrite(&s1,sizeof(s1),1,fp);
		printf("%s\t\t%d\t\t%d\t\t%d\n",s1.name,s1.age,s1.salary,s1.rolno);
	}
	
	printf("\nsuccessfully updated!\n\n");
	
	fclose(fp);
	fclose(pt);
}
void sort(){
	FILE*fp;
	emp*s1,d1;
	int n,i,j;
	
	fp=fopen("Handling.txt","rb");
    if(fp==NULL){
    	printf("The file cannot be opened!\n");
    	exit(1);
	}
	
	fseek(fp,0,SEEK_END);
    n=ftell(fp)/sizeof(emp);
    s1=(emp*)calloc(n,sizeof(emp));
	rewind(fp);
    
    
    while(fread(s1,sizeof(emp),n,fp)==n){
	};

    //now let sort the data in order of salary
    for(i=0;i<n;i++){
    	for(j=i+1;j<n;j++){
    		if(s1[i].salary>s1[j].salary){
    		    d1=s1[i];
    		    s1[i]=s1[j];
    		    s1[j]=d1;
			}
		}
	}
	printf("Name\t\tAge\t\tSalary\t\tRolno\n");
	//now let print the data
	for(i=0;i<n;i++){
		printf("%s\t\t%d\t\t%d\t\t%d\n",s1[i].name,s1[i].age,s1[i].salary,s1[i].rolno);
	}
  
    
    fclose(fp);
}
void sortware(){
	FILE*fp;
	FILE*pt;
    //let first sort and see if we still remember;
    fp=fopen("Handling.txt","rb");
    pt=fopen("ext.txt","wb");
    if(fp==NULL||pt==NULL){
    	printf("The file cannot be opened!");
    	exit(1);
	}
    emp *s1;
    emp d1;
    int n,i,j;
	fseek(fp,0,SEEK_END);
    n=ftell(fp)/sizeof(emp);
    s1=(emp*)calloc(n,sizeof(emp));
    rewind(fp);
    
    while(fread(s1,sizeof(emp),n,fp)==n){
	};
	//let now sort things;
	
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if(s1[j].salary>=s1[i].salary){
				d1=s1[i];
				s1[i]=s1[j];
				s1[j]=d1;
			}
		}
	}
    
	for(i=0;i<n;i++){
		fwrite(&d1,sizeof(d1),1,pt);
	}
	
	fclose(fp);
	fclose(pt);
	
	fp=fopen("Handling.txt","wb");
	pt=fopen("ext.txt","rb");
	if(fp==NULL||pt==NULL){
		printf("the file cannot be opend!");
		exit(1);
	}
	while(fread(&d1,sizeof(d1),1,pt)==1){
		fwrite(&d1,sizeof(d1),1,fp);
	}
	fclose(fp);
	fclose(pt);
}



