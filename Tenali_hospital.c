#include<stdio.h>
#include<time.h>
#include<encryption.h>
#include<decryption.h>
#include<stringcomp.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
///
int valid=0;
int ok,ko;
int c=14;
void exits();
void process();
void delete_record();
void operation(char ch);
void Add_rec(void);
void main_menu(void);
void title();
void edit_record();
void change(char user[10], char password[10]);
void log_in();
void gotoxy(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct p{
    char First_Name[10];
    char Last_Name[10];
    int age;
    char contact[10];
    char user_name[10];
    char password[10];
    char email[25];
    char gender;
    char address[20];

}p;
void title()
{
    system("cls");
    printf("\n\t\t\t\t\t######################################################################\n");
    printf("\n\t\t\t\t\t\t\t\t''' TENALI-HOSPITAL '''\n\t\t\t\t\t\t\t\t    DAUSA");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t(Monu Saini)");
    printf("\n\t\t\t\t\t######################################################################\n");

}

void change(char user[10], char password[10])
{
    // record(user,password);
    FILE *ptr;
    ptr = fopen("text/tenali.txt","w");
    encryption(user,password);
    fprintf(ptr,"%s%s",user , password);
}


void log_in()
{
    char name[10],us[10],pass[10];
    
    title();
    fflush(stdin);
    printf("\n\n\t\t\t\t\tuser name-:");
    gets(name); 
    printf("\n\n\t\t\t\t\tpassword-:");
    gets(pass);
    char u[10];
    char   p[10];
   
    FILE *ptr;
    ptr = fopen("text/tenali.txt","r");
   
    fscanf(ptr,"%s%s",u,p);
    decryption(u);
    decryp(p);
    printf("%s",u);
    printf("%s",p);

    int uk = compare(name,u);
    int pa = compare(pass,p);
    // record(name,pass);
    if(uk==0 && pa==0)
    {
        printf("\n\n\t\t\t\t\t\t\t\t...Log in Succesfully...\n");
        printf("\n\n\n\t...press any key to continue...\n");
        getch();
        main_menu();
    }
    else
    {
        printf("\n\t\t\t\t\t|||Invailid username and password|||");
        printf("\n\n\n\t...press any key to continue...\n");
        getch();
        log_in();
    }
}

void main_menu(void)
{
    FILE *ptr;
    title();
    char ch;
    char username[10];
    char new_pass[10];
    char u[10];
    char p[10];
   
    ptr = fopen("text/tenali.txt","r");
    char new_password[10];
    // printf("\n\t\t\t\t\t1. 'c' For Credit");
    // printf("\n\t\t\t\t\t1. 'd' For Debit");
    // printf("\n\t\t\t\t\t3. 'b' For Check balance");
    printf("\n\n\n\t\t\t\t\t1. 'v' View uer record data");
    printf("\n\t\t\t\t\t2. 'n' For New Ragistration");
    printf("\n\t\t\t\t\t3. 's' For Search Record by Name");
    printf("\n\t\t\t\t\t4. 'u' For Update Record by username");
    printf("\n\t\t\t\t\t4. 'd' For Delete Record by username");
    printf("\n\t\t\t\t\t5. 'l' For Lock your account");
    printf("\n\t\t\t\t\t6. 'e' For Exit");

    printf("\n\n\n\t\t\t\t\tChoose option operetion-:");
    scanf("\n%c",&ch);
    operation(ch);
}

/*****************************************"Declaration of Search_rec() FUnction"*************************************/
void search_reco()
{   title();
    p na;
    FILE *ptr;
    FILE *str;
    int g,row=14;
    str= fopen("text/c.txt","r");
    fscanf(str,"%d",&g);
    ptr = fopen("text/tenali_reco.txt","r");
    char more;
    char name[10];
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Search User Record Data!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\nUser Name-:");
    scanf("%s",name);
    fflush(stdin);
    title();
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if(compare(name,na.user_name)==0)
        {
            gotoxy(1,12);
            printf("Full Name");
            gotoxy(20,12);
            printf("Gender");
            gotoxy(32,12);
            printf("Age");
            gotoxy(37,12);
            printf("Address");
            gotoxy(49,12);
            printf("Contact");
            gotoxy(68,12);
            printf("Email");
            gotoxy(88,12);
            printf("Username");
            gotoxy(98,12);
            printf("Password");
            printf("\n================================================================================================================");

            gotoxy(1,row);
            printf("%s %s",na.First_Name,na.Last_Name);
            gotoxy(20,row);
            printf("%c",na.gender);
            gotoxy(32,row);
            printf("%d",na.age);
            gotoxy(37,row);
            printf("%s",na.address);
            gotoxy(49,row);
            printf("%s",na.contact);
            gotoxy(68,row);
            printf("%s",na.email);
            gotoxy(88,row);
            printf("%s",na.user_name);
            gotoxy(98,row);
            printf("%s",na.password);
            break;
        }
        row++;
        
    }
    if (compare(na.First_Name,name)!=0)
    {
        gotoxy(5,10);
        printf("Rcord Not Found");
    }
    fclose(ptr);
    fclose(str);
    X:
    printf("\n\n\n\t\t..Do You Want To Search More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        search_reco();
    }
    else{
        if(toupper(more)=='N')
        {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        ////////
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
                main_menu();
            }
            else{
                exit(0);
            }
        //////////
        }
        else{
            printf("\n\n\n\t\t^^^Invailid containt charactor^^^");
            goto X;
        }
         
            
    }
}

/*****************************************"Declaration of View_record() FUnction"*************************************/


void view_record()
{   int  row,g;
    char more;
    p na;
    title();
    FILE *ptr;
    ptr = fopen("text/tenali_reco.txt","r");
    printf("\n\n\t\t\t\t\t..!!!!!!!!!!!!!!!!!!!!!!!!!!!!!View Users Record!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!..");
    gotoxy(1,12);
    printf("Full Name");
    gotoxy(20,12);
    printf("Gender");
    gotoxy(32,12);
    printf("Age");
    gotoxy(37,12);
    printf("Address");
    gotoxy(49,12);
    printf("Contact");
    gotoxy(68,12);
    printf("Email");
    gotoxy(88,12);
    printf("Username");
    gotoxy(98,12);
    printf("Password");
    printf("\n================================================================================================================");
    FILE *str;
    str = fopen("text/c.txt","r");
    fscanf(str,"%d",&g);
    row =14;
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        gotoxy(1,row);
        printf("%s %s",na.First_Name,na.Last_Name);
        gotoxy(20,row);
        printf("%c",na.gender);
        gotoxy(32,row);
        printf("%d",na.age);
        gotoxy(37,row);
        printf("%s",na.address);
        gotoxy(49,row);
        printf("%s",na.contact);
        gotoxy(68,row);
        printf("%s",na.email);
        gotoxy(88,row);
        printf("%s",na.user_name);
        gotoxy(98,row);
        printf("%s",na.password);
        row++;
    }
    fclose(ptr);
    X:
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
                main_menu();
            }
            else{
                exit(0);
            }
   

}

////////////////////////////////////////////////////////Delete_reco() Function/////////////////////////////////////////////////////

void delete_record()
{   title();
    p na;
    int a=14,c,delete=0;
    char name[10],more;
    title();
    FILE *ptr,*str,*ctr,*otr;
    str = fopen("temp.txt","w+");
    ptr = fopen("text/tenali_reco.txt","r");
    ctr  = fopen("text/c.txt","r");
    fscanf(ctr,"%d",&c);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!! ): Delete user Record :( !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(12,8);
    printf("\n\n\t\t\tEnter username-:");
    scanf("%s",name);
    while (a!=c)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if (strcmp(name,na.user_name)!=0)
        {
            fprintf(str,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
        }
        else{
            delete=1;
            printf("%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
        }
        a++;
    }

    if (delete==0)
    {
        printf("\n\n\t\t\t______Record not found________");
        printf("\n\n\n\n\t\t,,.........press any key to continue......,,");
        getch();
        delete_record();
    }
    else{
        otr = fopen("text/c.txt","w");
        c--;
        fprintf(otr,"%d",c);
        fclose(ptr);
        fclose(str);
        fclose(otr);
        fclose(ctr);
        remove("text/tenali_reco.txt");
        rename("temp.txt","text/tenali_reco.txt");
        printf("\n\n\t\t........Record Delete Successfully..........");
    }
    
    
        
    X:
    printf("\n\n\n\t\t..Do You Want To Delete More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        delete_record();
    }
    else
    {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%c",&more);
        fflush(stdin);
        if (toupper(more)=='Y')
        {
           main_menu();
        }
        else
        {   
            printf("\n\n\n\t\t\t\t\t\t\t\t<<<< !! Thanks For Visiting !! >>>\n\n\n\n\n");

            exit(0);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////



void operation(char ch)
{
    float x=0,y=0;
    switch (ch)
    {
        case 'n':
        {
            Add_rec();
            break;
        }
        case 'v':
        {
            view_record();
            break;
        }
        case 's':
        {
            search_reco();
            break;
        }
        case 'u':
        {
            edit_record();
            break;
        }
        case 'l':
        {
            log_in();
            break;
        }
        case 'd':
        {
            delete_record();
            break;
        }
        case 'e':
        {
            exits();
            break;
        }
        default:
        {

            break;
        }
    }
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"Declaration of Update_record() function"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
void edit_record()
{   title();
    p na;
    int i,b,crass=0;
    FILE *utr;
    FILE *ptr,*otr;
    FILE *str;
    int g,row=14;
    utr = fopen("temp.txt","w+");
    str= fopen("text/c.txt","r");
    fscanf(str,"%d",&g);
    ptr = fopen("text/tenali_reco.txt","r");
    char more;
    char name[10];
    if (ptr==NULL)
    {   
        printf("\n\n\t\t\t\t):Can Not Open File:(");
        printf("......press any key to continue........");
        getch();
        
    }
    
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!# :(   ):# # :(   ):# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(12,13);
    printf("Enter User Name-:");
    scanf("%s",name);
    fflush(stdin);
    // name[0] = toupper(na.First_Name);
    if (utr==NULL)
    {
        printf("\n\n\t\t\t\t):Can Not Open File:(");
        printf("......press any key to continue........");
        getch();

    }

    
    title();
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if(compare(name,na.user_name)==0)
        {
            crass=1;
            gotoxy(1,13);
            printf("Full Name");
            gotoxy(20,13);
            printf("Gender");
            gotoxy(32,13);
            printf("Age");
            gotoxy(37,13);
            printf("Address");
            gotoxy(49,13);
            printf("Contact");
            gotoxy(68,13);
            printf("Email");
            gotoxy(88,13);
            printf("Username");
            gotoxy(98,13);
            printf("Password");
            printf("\n================================================================================================================");

            gotoxy(1,row);
            printf("%s %s",na.First_Name,na.Last_Name);
            gotoxy(20,row);
            printf("%c",na.gender);
            gotoxy(32,row);
            printf("%d",na.age);
            gotoxy(37,row);
            printf("%s",na.address);
            gotoxy(49,row);
            printf("%s",na.contact);
            gotoxy(68,row);
            printf("%s",na.email);
            gotoxy(88,row);
            printf("%s",na.user_name);
            gotoxy(98,row);//***************///***************
            printf("%s",na.password);
            printf("\n\n\n*********************88888888888888888888888888 ):Enter New Record:( 888888888888888888888888888888********************");

//-----------------------------------------------------------------------------------------------------------------------------------------------------
/************************************************"First_Name"**********************************************/
            B:
            printf("\n\n\t\t\t\t\tFirst_Name-:");
            scanf("%s",na.First_Name);
            na.First_Name[0] = toupper(na.First_Name[0]);
            if (strlen(na.First_Name)>8 || strlen(na.First_Name)<2)
            {
                printf("\n\n\t\t\t\t\t.....The arange of first_name maximu is 8 and minimum is 2.....\n");
                goto B;
            }
            else
            {
                for (int i = 0; i < strlen(na.First_Name); i++)
                {
                    if (isalpha(na.First_Name[i]))
                    {
                        valid =1;
                    }
                    else{
                        valid = 0;
                        break;
                    }
                }
                if (!valid)
                {
                    printf("\n\n\t\t\t\t\t.....first_name containt unvailid charactor......\n\n");
                    goto B;
                }
                
            }
            
            /************************************************"Last_Name"**********************************************/

            C:
            printf("\n\n\t\t\t\t\tLast_Name-:");
            scanf("%s",na.Last_Name);
            na.Last_Name[0] = toupper(na.Last_Name[0]);
            if (strlen(na.Last_Name)>8 || strlen(na.Last_Name)<2)
            {
                printf("\n\n\t\t\t\t\t.....The arange of Last_Name maximu is 8 and minimum is 2.....\n");
                goto C;
            }
            else
            {
                for (int i = 0; i < strlen(na.Last_Name); i++)
                {
                    if (isalpha(na.Last_Name[i]))
                    {
                        valid =1;
                    }
                    else{
                        valid = 0;
                        break;
                    }
                }
                if (!valid)
                {
                    printf("\n\n\t\t\t\t\t.....Last_Name containt unvailid charactor......\n\n");
                    goto C;
                }
                
            }
            /************************************************"Age"**********************************************/
            printf("\n\n\t\t\t\t\tEnter Age-:");
            scanf("%d",&na.age);

            /************************************************"gender"**********************************************/

            do
            {
                fflush(stdin);
                printf("\n\n\t\t\t\t\tGender(F/M)-:");
                scanf("%c",&na.gender);
                na.gender = toupper(na.gender);
                if (na.gender=='M' || na.gender=='F')
                {
                    ok =1;
                }
                else{
                    ok=0;
                }
                if (!ok)
                {
                    printf("\n\n\t\t\t\t\t!!Gender cantain invailid charactor:(Enter Either F or M):!!");
                }
                
                

            } while (!ok);

            /************************************************"address"**********************************************/
            
            do
            {   
                printf("\n\n\t\t\t\t\tEnter Address-:");
                scanf("%s",na.address);
                na.address[0] = toupper(na.address[0]);
                if (strlen(na.address)<20 || strlen(na.address)>3)
                {
                    ko= 1;
                }
                else{
                    ko=0;
                }
                if(!ko)
                {
                    printf("\n\n\t\t\t\tAddress containt invailid charactor") ; 
                            
                }
                
            } while (!ko);
            
            /************************************************"contact Number"**********************************************/
            do
            {   D:
            printf("\n\n\t\t\t\t\tEnter contact-:");
            scanf("%s",na.contact);
            if (strlen(na.contact)>10|| strlen(na.contact)!=10){
                printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!");
                goto D;
            }
            else
            {for (int i = 0; i < strlen(na.contact); i++)
                {   if (!isalpha(na.contact[i]))
                    {
                        valid =1;
                    }
                    else
                    {
                        valid=0;
                    }
                    if (!valid)
                    {
                        printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!\n\n");
                        goto D;
                    }
                }
            }
            }while (!valid);   

            /************************************************"Email_I'd"**********************************************/
            do
            {   
            printf("\n\n\t\t\t\t\tEnter Email_I'd-:");
            scanf("%s",na.email);
            if (strlen(na.email)>12 || strlen(na.email)<5)
            {
                printf("\n\n\t\t\t\tEmail containt invailid charactor") ; 
                            
            }
                
            } while(strlen(na.email)>12 || strlen(na.email)<5);

            /************************************************"User_Name"**********************************************/
            do
            {   
                printf("\n\n\t\t\t\t\tuser_name-:");
                scanf("%s",na.user_name);
                if (strlen(na.user_name)>10 || strlen(na.user_name)<3)
                {
                    printf("\n\n\t\t\t\tuser_name containt invailid charactor") ; 
                            
                }
                
            } while (strlen(na.user_name)>10 || strlen(na.user_name)<3);

            /************************************************"Password"**********************************************/

            do
            {   
                printf("\n\n\t\t\t\t\tPasswod-:");
                scanf("%s",na.password);
                if (strlen(na.password)>6|| strlen(na.password)!=6)
                {
                    printf("\n\n\t\t\t\tpassword containt invailid charactor") ; 
                }
                
            } while (strlen(na.password)>6 || strlen(na.password)!=6);


            /************************************************"Finishing"**********************************************/

           /**************"Clossing"**********************************************/



//-----------------------------------------------------------------------------------------------------------------------------------------------------

            
            printf(")): Press 'U' to confirm updatw :((");
            char ch=getche();
            if (ch=='u' || ch=='U')
            {
                fprintf(utr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
                printf("\n\n\t\t!!!!!!!! ): Update Successfuly :( !!!!!!!!!");
            }
            
        }
        else
        {
            fprintf(utr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);

        }
    row++;
        
    }
    if (!crass)
    {
        
        printf("\n\n\t\t\t#____##___Rcord Not Found____##___#");
    }
    
    fclose(ptr);
    fclose(str);
    fclose(utr);
    remove("text/tenali_reco.txt");
    rename("temp.txt","text/tenali_reco.txt");
    remove("temp.txt");
    X:
    printf("\n\n\n\t\t..Do You Want To Update More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        edit_record();
    }
    else if(toupper(more)=='N')
    {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
                main_menu();
            }
            else{
                exit(0);
            }
    }
    else{
        printf("*-*-*-*-*-**-*- ): INVAILID-INPUT :( -*-*-*-*-*-*-*-*");
        printf("\t\t\t\t\t...press any key to continue...\n");

        getch();
        goto X;
    }
}
            
/*****************************************"Declaration of Add_rec() FUnction"*************************************/
void Add_rec()
{   
    p na;
    title();
    
    FILE *atm;
    FILE *ctr;
    FILE *utr;
    ctr = fopen("text/c.txt","r");
    fscanf(ctr,"%d",&c);
    fclose(ctr);
    
    char name[1][1];
    printf("\n\n\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!New User Rajistration!!!!!!!!!!!!!!!!!!!!");
    
    /************************************************"First_Name"**********************************************/

    B:
    printf("\n\n\t\t\t\t\tFirst_Name-:");
    scanf("%s",na.First_Name);
    na.First_Name[0] = toupper(na.First_Name[0]);
    if (strlen(na.First_Name)>8 || strlen(na.First_Name)<2)
    {
        printf("\n\n\t\t\t\t\t.....The arange of first_name maximu is 8 and minimum is 2.....\n");
        goto B;
    }
    else
    {
        for (int i = 0; i < strlen(na.First_Name); i++)
        {
            if (isalpha(na.First_Name[i]))
            {
                valid =1;
            }
            else{
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\n\t\t\t\t\t.....first_name containt unvailid charactor......\n\n");
            goto B;
        }
        
    }
    
    /************************************************"Last_Name"**********************************************/

    C:
    printf("\n\n\t\t\t\t\tLast_Name-:");
    scanf("%s",na.Last_Name);
    na.Last_Name[0] = toupper(na.Last_Name[0]);
    if (strlen(na.Last_Name)>8 || strlen(na.Last_Name)<2)
    {
        printf("\n\n\t\t\t\t\t.....The arange of Last_Name maximu is 8 and minimum is 2.....\n");
        goto C;
    }
    else
    {
        for (int i = 0; i < strlen(na.Last_Name); i++)
        {
            if (isalpha(na.Last_Name[i]))
            {
                valid =1;
            }
            else{
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\n\t\t\t\t\t.....Last_Name containt unvailid charactor......\n\n");
            goto C;
        }
        
    }
    /************************************************"Age"**********************************************/
    printf("\n\n\t\t\t\t\tEnter Age-:");
    scanf("%d",&na.age);

    /************************************************"gender"**********************************************/

    do
    {
        fflush(stdin);
        printf("\n\n\t\t\t\t\tGender(F/M)-:");
        scanf("%c",&na.gender);
        na.gender = toupper(na.gender);
        if (na.gender=='M' || na.gender=='F')
        {
            ok =1;
        }
        else{
            ok=0;
        }
        if (!ok)
        {
            printf("\n\n\t\t\t\t\t!!Gender cantain invailid charactor:(Enter Either F or M):!!");
        }
        
        

    } while (!ok);

    /************************************************"address"**********************************************/
    
    do
    {   
        printf("\n\n\t\t\t\t\tEnter Address-:");
        scanf("%s",na.address);
        na.address[0] = toupper(na.address[0]);
        if (strlen(na.address)<20 || strlen(na.address)>3)
        {
            ko= 1;
        }
        else{
            ko=0;
        }
        if(!ko)
        {
            printf("\n\n\t\t\t\tAddress containt invailid charactor") ; 
                       
        }
        
    } while (!ko);
    
    /************************************************"contact Number"**********************************************/
    do
    {   D:
    printf("\n\n\t\t\t\t\tEnter contact-:");
    scanf("%s",na.contact);
    if (strlen(na.contact)>10|| strlen(na.contact)!=10){
        printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!");
        goto D;
    }
    else
    {for (int i = 0; i < strlen(na.contact); i++)
        {   if (!isalpha(na.contact[i]))
            {
                valid =1;
            }
            else
            {
                valid=0;
            }
            if (!valid)
            {
                printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!\n\n");
                goto D;
            }
        }
    }
    }while (!valid);   

    /************************************************"Email_I'd"**********************************************/
    do
    {   
    printf("\n\n\t\t\t\t\tEnter Email_I'd-:");
    scanf("%s",na.email);
    if (strlen(na.email)>12 || strlen(na.email)<5)
    {
        printf("\n\n\t\t\t\tEmail containt invailid charactor") ; 
                       
    }
        
    } while(strlen(na.email)>12 || strlen(na.email)<5);

    /************************************************"User_Name"**********************************************/
    do
    {   
        printf("\n\n\t\t\t\t\tuser_name-:");
        scanf("%s",na.user_name);
        if (strlen(na.user_name)>10 || strlen(na.user_name)<3)
        {
            printf("\n\n\t\t\t\tuser_name containt invailid charactor") ; 
                       
        }
        
    } while (strlen(na.user_name)>10 || strlen(na.user_name)<3);

    /************************************************"Password"**********************************************/

    do
    {   
        printf("\n\n\t\t\t\t\tPasswod-:");
        scanf("%s",na.password);
        if (strlen(na.password)>6|| strlen(na.password)!=6)
        {
            printf("\n\n\t\t\t\tpassword containt invailid charactor") ; 
        }
        
    } while (strlen(na.password)>6 || strlen(na.password)!=6);


    c++;
    utr = fopen("text/c.txt","w");
    fprintf(utr,"%d",c);
    fclose(utr);
    /************************************************"Finishing"**********************************************/
    atm = fopen("text/tenali_reco.txt", "a");
    fprintf(atm,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
    fclose(atm);
    
   
    title();
    printf("\n\n\n\t\t\t\t\t...press any key to continue...\n");
   
   
    sd:
    getch();
    title();
    printf("\n\n\t\t\t\t\t!!Do you want to Add more Record!![Y/N]");
    scanf("%s",name);
    char option = name[0][0];
    
    if (toupper(option)=='Y')
    {
        Add_rec();
    }
    else{
        title();
        printf("\n\n\t\t\t\t\t\t.......ThankYou........");
        printf("\n\n\n\t\t\t\t\t...press any key to continue...\n");
        getch();
        title();
        main_menu();

    }
    
    /************************************************"Clossing"**********************************************/

    
}


void exits()
{
    title();
    printf("\n\n\n\t\t\t\t\t\t\t\t<<<< !! Thanks For Visiting !! >>>\n\n\n\n\n");
    exit(0);
}

void process()
{
    int i=0;
    system("cls");
    title();
    printf("\n\t");
    gotoxy(57,15);
    printf("|||******||WELCOME||******|||");
    for (int j = 52; j < 103; j++)
    {
        gotoxy(j,20);
        printf("!!");
        delay(123);
        gotoxy(52,19);
        printf("%d",i);
        i=i+2;
        
    }
    gotoxy(58,25);
    printf("......Press any key to continue.........");
    getch();
    log_in();
    
}
int main()
{
    

    process();

return 0;
}