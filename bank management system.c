#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
struct user
{
    char name[20],address[30],aadhar[13],phone_num[10];
    int cr_date,cr_month,cr_year;
    int dob_date,dob_month,dob_year;
    int age,acc_type;
    char p_name[20],password[20];
    float amt;
    int acc_no;
    int dc,points;
    float loan;
    int loan_type;
};
char password1[20];
char* my()
{
    int k=0;
    char c;
    while(1)
    {
        c= getch();
        if(c==32 ||c==13 )
        {
            password1[k]='\0';
            break;
        }
        else if(c==8)
        {
            if(k>0)
            {
                k--;
                printf("\b \b");
            }
        }
        else
        {
            password1[k]=c;
            k+=1;
            printf("*");
        }
    }
    return password1;
}
void menu();
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}

void new_acc()
{
    printf("Create account!!!\n");
    struct user add;
    FILE *fp;
    int ch,acc1,num=0,l=0,u=0,s=0,dc1;
L2: fp=fopen("account_details.dat","a+");
    system("cls");
    srand(time(NULL));
    acc1=rand()%10001+10000;
    srand(time(NULL));
    dc1=rand()%100000000000+100000000000;
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if (add.acc_no==acc1 || add.dc==dc1)
        {
            fclose(fp);
            goto L2;
        }
    }
    add.acc_no=acc1;
    add.dc=dc1;
L11:printf("Enter your name:");
    scanf("%s",add.name);
    for (int i=0;i<strlen(add.name);i++)
    {
            if ( (add.name[i]>=65 && add.name[i]<=90) || (add.name[i]>=97 && add.name[i]<=122))
                continue;
            else
            {
                printf("Your name contains invalid characters.\n");
                goto L11;
            }
    }
L12:printf("Enter parent's name:");
    scanf("%s",add.p_name);
    for (int i=0;i<strlen(add.p_name);i++)
    {
            if ( (add.p_name[i]>=65 && add.p_name[i]<=90) || (add.p_name[i]>=97 && add.p_name[i]<=122))
                continue;
            else
            {
                printf("Your name contains invalid characters.\n");
                goto L12;
            }
    }
L6: printf("Enter your aadhar number:");
    scanf("%s",add.aadhar);
    if (strlen(add.aadhar)!=12)
    {
        printf("Entered aadhar number is incorrect.\n");
        goto L6;
    }
L7: printf("Enter phone number:");
    scanf("%s",add.phone_num);
    if (strlen(add.phone_num)!=10)
    {
        printf("Entered phone number is incorrect.\n");
        goto L7;
    }
L17:printf("Enter today's date(dd mm yyyy):");
    scanf("%d%d%d",&add.cr_date,&add.cr_month,&add.cr_year);
    if( !(add.cr_date>=1 && add.cr_date<=31 && add.cr_month>=1 && add.cr_month<=12 && add.cr_year>=1900 && add.cr_year<=2050))
    {
        printf("Entered date is incorrect.\n");
        goto L17;
    }
L18:printf("Enter your dob(dd mm yyyy):");
    scanf("%d%d%d",&add.dob_date,&add.dob_month,&add.dob_year);
    if (!(add.dob_date>=1 && add.dob_date<=31 && add.dob_month>=1 && add.dob_month<=12 && add.dob_year>=1900 && add.dob_year<=2050))
    {
        printf("Entered date is incorrect.\n");
        goto L18;
    }
    printf("Enter your city:");
    scanf("%s",add.address);
L5: printf("Enter password (Your password should contain at least one number,one lowercase letter ,one special character and one uppercase letter):");
    strcpy(add.password,my());
    for (int i=0;i<strlen(add.password);i++)
    {
        if(add.password[i]>='0' && add.password[i]<='9')
            num=1;
        if(add.password[i]>='a' && add.password[i]<='z')
            l=1;
        if(add.password[i]>='A' && add.password[i]<='Z')
            u=1;
        if(add.password[i]=='!' || add.password[i]=='@' || add.password[i]=='#' || add.password[i]=='$' ||add.password[i]=='%' || add.password[i]=='*')
            s=1;
    }
    if(num==1 && l==1 && u==1 && s==1)
        printf("\n");
    else
    {
        printf("Invalid Password\n");
        goto L5;
    }
 L8:printf("Enter the amount to be deposited:");
    scanf("%f",&add.amt);
    printf("\nChoose your account type:\n");
    printf("Enter 1 for savings account\n");
    printf("Enter 2 for Current account\n");
    printf("Enter 3 for fixed (1 year)\n");
    printf("Enter 4 for fixed(2 years)\n");
    printf("Enter 5 for fixed(3 years)\n");
    scanf("%d",&add.acc_type);
    if (add.acc_type>=6 || add.acc_type<0)
    {
        printf("Chosen account type is incorrect.\n");
        goto L8;
    }
    printf("Your account no is %d.\n",acc1);
    printf("Your debit card number is %d.\n",dc1);
    printf("Account opened successfully!\n");
    fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,0,0,0);
    fclose(fp);
L9: printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);
    else
    {
        printf("Chosen option is incorrect.\n");
        goto L9;
    }
}


void check_details()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1,rate;
    float time;
    float intrst;
    FILE *fp;
    fp=fopen("account_details.dat","r");
    system("cls");
    printf("Enter account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                printf("\nAccount no:%d\nName:%s\nParent name:%s\nAadhar number:%s\nPhone Number:%s\nToday's date:%d %d %d\nDate of birth:%d %d %d\nCity:%s\nAmount deposited:%0.2f\nDebit Card: %d\nCIBIL score:%d\n",add.acc_no,add.name,add.p_name,add.aadhar,add.phone_num,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.address,add.amt,add.dc,add.points);
                if(add.acc_type==1)
                {
                    printf("Account type:Savings");
                    time = 1.0/12.0;
                    rate = 4;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);

                }
                else if(add.acc_type==2)
                {
                    printf("Account type:Current");
                    printf("\nYou will not get any interest for current account");
                }
                else if(add.acc_type==3)
                {
                    printf("Account type:Fixed for 1 year");
                    time = 1/12.0;
                    rate = 7;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);
                }
                else if(add.acc_type==4)
                {
                    printf("Account type: Fixed for 2 years");
                    time = 1/12.0;
                    rate = 9;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);
                }
                else if(add.acc_type==5)
                {
                    printf("Account type: Fixed for 3 years");
                    time = 1/12.0;
                    rate = 11;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);
                }
            }
            else
            {
                printf("Entered password is incorrect.\n");
            }
        }
    }
    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("\nEnter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);


}

void view_db()
{
    struct user add;
    int ch;
    FILE *fp;
    char username[20];
	char password[20];

	printf("Enter the username: ");
	scanf("%s",username);

	printf("\nEnter the password: ");
	strcpy(password,my());

    fp=fopen("account_details.dat","r");
    if(strcmp(username, "abc") == 0)
    {
        if(strcmp(password, "123") == 0)
        {
            printf("\n%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","ACC. NO.","NAME","PARENT NAME","AADHAR","PHONE NUMBER","CITY","AMOUNT","DEBIT CARD","ACCOUNT TYPE");

            while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
            {
                printf("%-20d%-20s%-20s%-20s%-20s%-20s%-20.2f%-20d",add.acc_no,add.name,add.p_name,add.aadhar,add.phone_num,add.address,add.amt,add.dc);
                if(add.acc_type==1)
                {
                    printf("Savings\n");
                }
                else if(add.acc_type==2)
                {
                    printf("Current\n");
                }
                else if(add.acc_type==3 || add.acc_type==4 || add.acc_type==5)
                {
                    printf("Fixed\n");
                }
            }
        }
        else
            printf("Entered incorrect password.\n");
    }
    else
        printf("Entered username is incorrect.\n");
    fclose(fp);
    printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);

}
void account_transfer()
{
    struct user add;
    char pass[20];
    int ch,acc2,acc3,flag=1,flag1=1,flag2=1;
    float amt1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    printf("\nEnter the account number of the receiver:");
    scanf("%d",&acc3);
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if (acc3==add.acc_no)
        {
            flag1=0;
        }
        if (acc2==add.acc_no)
        {
            flag=0;
        }
    }
    rewind(fp);
    if (flag1==0 && flag==0)
    {
        while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
        {
            if(acc2==add.acc_no)
            {
                if (strcmp(pass,add.password)==0)
                {
                    printf("Enter the amount of money to be transfered:");
                    scanf("%f",&amt1);
                    if (add.amt>=amt1)
                    {
                        add.amt-=amt1;
                        flag2=0;
                    }
                    else
                    {
                        printf("Insufficient funds.\n");
                    }
                    goto L1;
                }
                else if(strcmp(pass,add.password)!=0)
                {
                    printf("Entered password is incorrect.\n");
                    goto L1;
                }
            }
L1:    fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
        }
        fclose(fp);
        fclose(fi);
        fp=fopen("account_details.dat","w");
        fi=fopen("newacc_details.dat","r");
        while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
        {
            if (acc3==add.acc_no && flag2==0)
            {
                add.amt+=amt1;
                printf("Money is transfered successfully.\n");
            }
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
        }
        fclose(fp);
        fclose(fi);
    }
    if (flag==1)
    {
        printf("User Account does not exist.\n");
    }
    if (flag1==1)
    {
        printf("Receiver's account does not exist.\n");
    }
    printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);
}
void withdraw_money()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1;
    float amt1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    printf("\n");
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                printf("Enter the amount of money to be withdrawn:");
                scanf("%f",&amt1);
                if (add.amt>=amt1)
                {
                    add.amt-=amt1;
                    printf("Withdrawal of money is successful.\n");
                }
                else
                {
                    printf("Insufficient funds.\n");
                }
                goto L1;
            }
            else if(strcmp(pass,add.password)!=0)
            {
                printf("Entered password is incorrect.\n");
                goto L1;
            }
        }
L1:    fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);
    fp=fopen("account_details.dat","w");
    fi=fopen("newacc_details.dat","r");
    while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);

    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);


}

void deposit_money()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1;
    float amt1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    printf("\n");
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                printf("Enter the amount of money to be added:");
                scanf("%f",&amt1);
                add.amt+=amt1;
                printf("Money is added to your account.\n");
                goto L1;
            }
            else if(strcmp(pass,add.password)!=0)
            {
                printf("Entered password is incorrect.\n");
                goto L1;
            }
        }
L1:    fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);
    fp=fopen("account_details.dat","w");
    fi=fopen("newacc_details.dat","r");
    while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);

    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);

}

void modify()
{
    struct user add;
    char pass[20];
    int ch,ch1,acc2,flag=1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                printf("Enter 1 to change phone number.\n");
                printf("Enter 2 to change city.\n");
                printf("Enter 3 to change password.\n");
                printf("Enter 4 to change the name.\n");
                scanf("%d",&ch1);
                if (ch1==1)
                {
                    printf("Enter the new phone number:");
                    scanf("%s",add.phone_num);
                    goto L1;
                }
                else if (ch1==2)
                {
                    printf("Enter the new city:");
                    scanf("%s",add.address);
                    goto L1;
                }
                else if (ch1==3)
                {
                    printf("Enter the new password:");
                    scanf("%s",add.password);
                    goto L1;
                }
                else if (ch1==4)
                {
                    printf("Enter your name:\n");
                    scanf("%s",add.name);
                    goto L1;
                }
            }
            else if(strcmp(pass,add.password)!=0)
            {
                printf("Entered password is incorrect.\n");
                goto L1;
            }
        }
L1:    fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);
    fp=fopen("account_details.dat","w");
    fi=fopen("newacc_details.dat","r");
    while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);

    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("\nEnter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);

}

void remove1()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number to remove the account:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                continue;
            }
            else if(strcmp(pass,add.password)!=0)
            {
                printf("Entered password is incorrect.\n");
                goto L1;
            }
        }
L1:     fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type);
    }
    fclose(fp);
    fclose(fi);
    fp=fopen("account_details.dat","w");
    fi=fopen("newacc_details.dat","r");
    while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);

    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("\nEnter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);

}
void avail_loan()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1;
    float amt1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    printf("\n");
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                printf("1) Personal loan    (avail at 5 percent pa)\n");
                printf("2) Home loan        (avail at 7 percent pa)\n");
                printf("3) Education loan   (avail at 9 percent pa)\n");
                printf("4) Business loan    (avail at 11 percent pa)\n");
                printf("Enter your choice:");
                scanf("%d",&add.loan_type);
                printf("Maximum amount available for loan is %.2f\n",add.amt*2);
                printf("Enter the amount required for loan:");
                scanf("%f",&add.loan);
                float time,intrst;
                int rate;
                if(add.loan_type==1)
                {
                    printf("Loan type:Personal loan\n");
                    time = 1.0/12.0;
                    rate = 5;
                    intrst = interest(time,add.loan,rate);
                    add.loan = add.loan+intrst;
                    printf("\nYou should repay %.2f rupees in total at interest amount of %.2f\n",add.loan,intrst);
                }
                else if(add.loan_type==2)
                {
                    printf("Loan type:Home loan\n");
                    time = 1.0/12.0;
                    rate = 7;
                    intrst = interest(time,add.loan,rate);
                    add.loan = add.loan+intrst;
                    printf("\nYou should repay %.2f rupees in total at interest amount of %.2f\n",add.loan,intrst);
                }
                else if(add.loan_type==3)
                {
                    printf("Loan type:Education loan\n");
                    time = 1.0/12.0;
                    rate = 9;
                    intrst = interest(time,add.loan,rate);
                    add.loan = add.loan+intrst;
                    printf("\nYou should repay %.2f rupees in total at interest amount of %.2f\n",add.loan,intrst);
                }
                else if(add.loan_type==4)
                {
                    printf("Loan type:Business loan\n");
                    time = 1.0/12.0;
                    rate = 11;
                    intrst = interest(time,add.loan,rate);
                    add.loan = add.loan+intrst;
                    printf("\nYou should repay %.2f rupees in total at interest amount of %.2f\n",add.loan,intrst);
                }
                goto L1;
            }
            else if(strcmp(pass,add.password)!=0)
            {
                printf("Entered password is incorrect.\n");
                goto L1;
            }
        }
L1:    fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);
    fp=fopen("account_details.dat","w");
    fi=fopen("newacc_details.dat","r");
    while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);

    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);
}
void repay_loan()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1;
    float amt1;
    FILE *fp,*fi;
    fp=fopen("account_details.dat","r");
    fi=fopen("newacc_details.dat","w");
    printf("Enter your account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    printf("\n");
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                if(add.loan_type==0)
                {
                    printf("You have no loan to repay\n");
                }
                else
                {
                    printf("Amount of money to be repaid is %.2f\n",add.loan);
                    printf("Enter the amount of money you wish to repay:");
                    scanf("%f",&amt1);
                    add.loan-=amt1;
                    printf("Amount of money yet to be repaid is %.2f\n",add.loan);
                    add.points+=(int)amt1/1000;
                }
                if(add.loan==0)
                {
                    printf("You have successfully repaid your loan !\n");
                    add.loan_type=0;
                }
                goto L1;
            }
            else if(strcmp(pass,add.password)!=0)
            {
                printf("Entered password is incorrect.\n");
                goto L1;
            }
        }
L1:    fprintf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);
    fp=fopen("account_details.dat","w");
    fi=fopen("newacc_details.dat","r");
    while(fscanf(fi,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d\n",add.name,add.p_name,add.aadhar,add.phone_num,add.acc_no,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.password,add.address,add.amt,add.acc_type,add.dc,add.loan,add.points,add.loan_type);
    }
    fclose(fp);
    fclose(fi);

    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("Enter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);

}
void report()
{
    struct user add;
    char pass[20];
    int ch,acc2,flag=1,rate;
    float time;
    float intrst;
    FILE *fp;
    fp=fopen("account_details.dat","r");
    system("cls");
    printf("Enter account number:");
    scanf("%d",&acc2);
    printf("Enter the password:");
    strcpy(pass,my());
    while(fscanf(fp,"%s %s %s %s %d %d %d %d %d %d %d %s %s %f %d %d %f %d %d",add.name,add.p_name,add.aadhar,add.phone_num,&add.acc_no,&add.cr_date,&add.cr_month,&add.cr_year,&add.dob_date,&add.dob_month,&add.dob_year,add.password,add.address,&add.amt,&add.acc_type,&add.dc,&add.loan,&add.points,&add.loan_type)!=EOF)
    {
        if(acc2==add.acc_no)
        {
            flag=0;
            if (strcmp(pass,add.password)==0)
            {
                printf("\nREPORT\nAccount no:%d\nName:%s\nParent name:%s\nAadhar number:%s\nPhone Number:%s\nToday's date:%d %d %d\nDate of birth:%d %d %d\nCity:%s\nAmount deposited:%0.2f\nDebit Card: %d\nCIBIL score:%d\n",add.acc_no,add.name,add.p_name,add.aadhar,add.phone_num,add.cr_date,add.cr_month,add.cr_year,add.dob_date,add.dob_month,add.dob_year,add.address,add.amt,add.dc,add.points);
                if(add.acc_type==1)
                {
                    printf("Account type:Savings");
                    time = 1.0/12.0;
                    rate = 4;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);

                }
                else if(add.acc_type==2)
                {
                    printf("Account type:Current");
                    printf("\nYou will not get any interest for current account");
                }
                else if(add.acc_type==3)
                {
                    printf("Account type:Fixed for 1 year");
                    time = 1/12.0;
                    rate = 7;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);
                }
                else if(add.acc_type==4)
                {
                    printf("Account type: Fixed for 2 years");
                    time = 1/12.0;
                    rate = 9;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);
                }
                else if(add.acc_type==5)
                {
                    printf("Account type: Fixed for 3 years");
                    time = 1/12.0;
                    rate = 11;
                    intrst = interest(time,add.amt,rate);
                    printf("\nYour interest will be Rupees %.2f every month\n",intrst);
                }
            }
            else
            {
                printf("Entered password is incorrect.\n");
            }
        }
    }
    if (flag==1)
    {
        printf("Account does not exist.\n");
    }
    printf("\nEnter 1 to go to the main menu,0 to exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if (ch==0)
        exit(0);


}

void menu()
{
    int choice;
    printf("\n\tBANKING MANAGEMENT SYSTEM");
    printf("\n\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\tEnter 1 to create new account\n");
    printf("\t\tEnter 2 for viewing information of existing account\n");
    printf("\t\tEnter 3 for viewing database\n");
    printf("\t\tEnter 4 to make changes in the account details\n");
    printf("\t\tEnter 5 to deposit money\n");
    printf("\t\tEnter 6 to withdraw money\n");
    printf("\t\tEnter 7 for making a transfer funds\n");
    printf("\t\tEnter 8 to removing an account\n");
    printf("\t\tEnter 9 to avail loan\n");
    printf("\t\tEnter 10 to repay loan\n");
    printf("\t\tEnter 11 to generate report\n");
    printf("\t\tEnter 12 to exit\n\n");
    printf("\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:check_details();
        break;
        case 3:view_db();
        break;
        case 4:modify();
        break;
        case 5:deposit_money();
        break;
        case 6:withdraw_money();
        break;
        case 7:account_transfer();
        break;
        case 8:remove1();
        break;
        case 9:avail_loan();
        break;
        case 10:repay_loan();
        break;
        case 11:report();
        break;
        case 12:exit(0);
        break;
    }
}

int main()
{
	char username[20];
	char password[20];

	printf("Enter the username: ");
	scanf("%s",username);

	printf("\nEnter the password: ");
	strcpy(password,my());

	if(strcmp(username, "abc") == 0)
    {
        if(strcmp(password, "123") == 0)
        {
			printf("\nAdmin successfully logged in...");
			menu();
		}
        else
        {
			printf("\nPassword entered is invalid.");
		}
	}
	else
    {
		printf("\nUsername entered is invalid.");
	}
}
