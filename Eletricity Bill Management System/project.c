#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

//admin name- limon
//password- 1234

FILE *name;
FILE *pass;
FILE *loc_id;
FILE *add;
int input;
int id,user_id;
char user_name[30],password[30];
char user_file[30],password_file[30];

login()
{
    printf("===========================   |||           ||||||||    ||||||||   |||||||  ||||     |||   ============================\n");
    printf("===========================   |||          |||    |||  |||    |||    |||    ||||||   |||   ============================\n");
    printf("===========================   |||          |||    |||  |||           |||    ||| |||  |||   ============================\n");
    printf("===========================   |||          |||    |||  |||  |||||    |||    |||  ||| |||   ============================\n");
    printf("===========================   |||     |||  |||    |||  |||    |||    |||    |||   ||||||   ============================\n");
    printf("===========================   |||||||||||   ||||||||    ||||||||   |||||||  |||     ||||   ============================\n\n\n");
}
portal()
{
    system("CLS");
    login();
    printf("\t\t\t\t\t\t1. Admin Portal\n");
    printf("\t\t\t\t\t\t2. local user\n");

    int flag=0;
    int input;
    do
    {
       printf("\t\t\t\t\t\tEnter Your Choice: ");
       scanf("%d",&input);
       if(input>2)
       {
         MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
       }
       else
       {
         flag=1;
       }
    }
    while(flag!=1);

    switch (input)
    {
    case 0:
        MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
        portal();
    case 1:
        ask();
        main_menu();
        navigation();
        break;
    case 2:
        u_ask();
        u_mainmenu();
        navigation();
        break;
    }
}
ask()
{
    int ch=0,i=0;
    user_name[30]=0;
    password[30]=0;

    system("CLS");
    login();

    printf("\t\t\t\t\t\tEnter Admin Name: ");
    scanf("%s",user_name);
    printf("\t\t\t\t\t\tEnter Password: ");

    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            password[i]='\0';
            break;
        }
        else
        {
            password[i]=ch;
            printf("*");
            i++;
        }
    }
    check();
}
check()
{
    user_file[30]=0;
    password_file[30]=0;

    name=fopen("name.txt","r");
    pass=fopen("password.txt","r");

    fscanf(name,"%s",user_file);
    fscanf(pass,"%s",password_file);

    fclose(name);
    fclose(pass);

    if(strcmp(user_name,user_file)==0 && strcmp(password,password_file)==0)
    {
        welcome();
    }
    else
    {
        system("CLS");
        MessageBoxW(NULL,L"User name or Password is Incorrect!\n\t   Try again.",L"Error!",MB_OK);
        ask();
    }
}
setting()
{
    system("CLS");
    setting_design();
    int x;
    printf("\t\t\t\t\t\t1.Create local user\n");
    printf("\t\t\t\t\t\t0.Main Menu\n\n");
    printf("\t\t\t\t\t\tEnter Your Choice: ");
    scanf("%d",&x);

    switch (x)
    {
    case 0:
        main_menu();
        break;
    case 1:
        create_local();
        break;
    }
}
create_local()
{
    system("cls");
    setting_design();
    FILE *loc_id;

    printf("\t\t\t\tUser Id: ");
    scanf("%d",&id);

    loc_id=fopen("locid.txt","a");
    fprintf(loc_id,"%d\n",id);
    fclose(loc_id);

    printf("\n\t\t\t\t\t\tLocal user successfully created\n\n");
    backToTheMain();
    main_menu();
}
u_ask()
{
    user_id;

    system("cls");
    login();

    printf("\t\t\t\t\t\tEnter User Id: ");
    scanf("%d",&user_id);
    u_check();
}
u_check()
{

    loc_id=fopen("locid.txt","r");

    if(user_id==id)
    {
        u_welcome();
    }
        system("cls");
        MessageBoxW(NULL,L"User Id is Incorrect!\n\t   Try again.",L"Error!",MB_OK);
        u_ask();

    fclose(loc_id);
}

welcome()
{
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t    |||          ||| ||||||||| |||        |||||||  ||||||||  |||     ||| |||||||||      \n");
    printf("\t\t    |||   ||||   ||| |||       |||       |||      |||    ||| ||||| ||||| |||            \n");
    printf("\t\t     ||||||  ||||||  ||||||||  |||       |||      |||    ||| ||| ||| ||| ||||||||       \n");
    printf("\t\t      ||||    ||||   |||       |||   ||| |||      |||    ||| |||     ||| |||            \n");
    printf("\t\t       ||      ||    ||||||||| |||||||||  |||||||  ||||||||  |||     ||| |||||||||    \n\n");
    printf("\t\t\t\t\tPress Any Key To Enter The Main Menu");
    getch();
    main_menu();
}
main_menu()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    system("CLS");
    int y;
    printf("===================  ||     ||    |||    |||| ||    ||      ||     || ||||||| ||    || ||     ||  =====================\n");
    printf("===================  |||| ||||   || ||    ||  ||||  ||      |||| |||| ||      ||||  || ||     ||  =====================\n");
    printf("===================  || ||| ||  |||||||   ||  || || ||      || ||| || ||||||  || || || ||     ||  =====================\n");
    printf("===================  ||     || ||     ||  ||  ||  ||||      ||     || ||      ||  |||| ||     ||  =====================\n");
    printf("===================  ||     || ||     || |||| ||    ||      ||     || ||||||| ||    ||  |||||||   =====================\n");
    printf("=======================================================================================================================\n");
    printf("     User: Admin                                Date: %d/%d/%d                                      Time: %d:%d        \n",time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
    printf("=======================================================================================================================\n\n");


    printf("\t\t\t\t\t\t1.Settings\n");
    printf("\t\t\t\t\t\t2.Add Record\n");
    printf("\t\t\t\t\t\t3.Display Record\n");
    printf("\t\t\t\t\t\t4.Search Record\n");
    printf("\t\t\t\t\t\t5.Update Record\n");
    printf("\t\t\t\t\t\t6.Back To Login\n\n");


    int flag=0;
    int input;
    do
    {
       printf("\t\t\t\t\t\tEnter Your Choice: ");
       scanf("%d",&input);
       if(input>6)
       {
         MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
       }
       else
       {
         flag=1;
       }
    }
    while(flag!=1);

    switch (input)
    {
    case 0:
        MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
        main_menu();
    case 1:
        setting();
        break;
    case 2:
        addrecord();
        break;
    case 3:
        disp();
        break;
    case 4:
        search();
        break;
    case 5:
        update();
        break;
    case 6:
        portal();
        break;
    }
}
backToTheMain()
{
   do
    {
        printf("\n\n\t\t\t\t\tPress 0 Back to The Main Menu: ");
        scanf("%d",&input);
        if(input!=0)
        {
           MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
        }
    }
    while(input!=0);
}

navigation()
{
    int flag=0;
    int input;
    do
    {
       printf("\t\t\t\t\t\tEnter Your Choice: ");
       scanf("%d",&input);
       if(input>0)
       {
         MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
       }
       else
       {
         flag=1;
       }
    }
    while(flag!=1);

    switch (input)
    {
    case 0:
        portal();
    }
}

setting_design()
{
    printf("============================    ||||  ||||||| |||||| |||||| |||| ||     ||  ||||||     ================================\n");
    printf("============================   ||  || ||        ||     ||    ||  ||||   || ||          ================================\n");
    printf("============================    ||    ||||||    ||     ||    ||  || ||  || ||          ================================\n");
    printf("============================      ||  ||||||    ||     ||    ||  ||  || || ||  ||||    ================================\n");
    printf("============================   ||  || ||        ||     ||    ||  ||   |||| ||    ||    ================================\n");
    printf("============================    ||||  |||||||   ||     ||   |||| ||     ||  |||||||    ================================\n\n\n");

}
info_design()
{
    printf("\t============================   ||||  ||        ||  |||||||   ||||||||    ================================\n");
    printf("\t============================    ||   ||||      ||  ||       |||    |||   ================================\n");
    printf("\t============================    ||   ||  ||    ||  ||||||   |||    |||   ================================\n");
    printf("\t============================    ||   ||    ||  ||  ||||||   |||    |||   ================================\n");
    printf("\t============================    ||   ||      ||||  ||       |||    |||   ================================\n");
    printf("\t============================   ||||  ||        ||  ||        ||||||||    ================================\n\n\n");

}

struct user
{
    int id;
    char name[30];
    char contact[20];
    char address[50];
    int unit;
    float amt;

};
addrecord()
{
    struct user u, us;
    system("CLS");
    info_design();
    FILE *add;
    add=fopen("Add Record.txt","a");
    printf("\n\n\t\t\t\tEnter User Id: ");
    scanf("%d",&us.id);
    printf("\t\t\t\tEnter User Name: ");
    scanf("%s",&us.name);
    printf("\t\t\t\tEnter User Phone Number: ");
    scanf("%s",&us.contact);
    printf("\t\t\t\tEnter User Address: ");
    scanf("%s",&us.address);
    printf("\t\t\t\tEnter used unit: ");
    scanf("%d",&us.unit);
    fwrite(&us,sizeof(us),1,add);
    printf("\n\t\t\t\t\t1 record successfully added.");
    fclose(add);
    backToTheMain();
    main_menu();
}
disp()
{
    struct user u, us;
    system("CLS");
    info_design();
    float per=5.45;
    FILE *add;
    add=fopen("Add Record.txt","r");
    printf("\t\tUser Id\t\tName\t\tContact\t\tAddress\t\t\tUnit\t\tBill\n\n");
    while (fread(&us,sizeof(us),1,add))
        printf("\t\t%d\t\t%s\t\t%s\t\t%s\t\t\t%d\t\t%.2lf TK\n",us.id,us.name,us.contact,us.address,us.unit,us.unit*per);
    fclose(add);
    backToTheMain();
    main_menu();
}
search()
{
    struct user u,us;
    system("CLS");
    int id;
    FILE *add;
    add=fopen("Add Record.txt","r");
    printf("\n\n\n\t\t\t\t\tSearch by Id: ");
    scanf("%d",&id);
    while(fread(&us,sizeof(us),1,add))
	{
		if(us.id==id)
		{	system("CLS");
			printf("\n\n\n\t\t\t\t\tRecord Found ");
			printf("\n\n\t\tId\t\tName\t\tContact\t\tAddress\t\t\tUnit\n");
			printf("\t\t%d\t\t%s\t\t%s\t\t%s\t\t\t%d\n",us.id,us.name,us.contact,us.address,us.unit);
			break;
		}
		else
		{	system("CLS");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tGiven ID Not found in our database");
		}
	}
    fclose(add);
    backToTheMain();
    main_menu();
}
update_design()
{
    printf("\t====================   ||     || ||||||   ||||||       |||    |||||||| ||||||||   ====================\n");
    printf("\t====================   ||     || ||    || ||    ||    || ||      ||    ||         ====================\n");
    printf("\t====================   ||     || ||    || ||     ||  |||||||     ||    |||||      ====================\n");
    printf("\t====================   ||     || ||||||   ||    ||  ||     ||    ||    ||         ====================\n");
    printf("\t====================    |||||||  ||       ||||||    ||     ||    ||    ||||||||   ====================\n\n\n");
}
update()
{
    system("CLS");
    update_design();
    int input;
    printf("\t\t\t\t\t\tFor ID Update Enter(1).\n");
    printf("\t\t\t\t\t\tFor Name Update Enter(2).\n");
    printf("\t\t\t\t\t\tFor Contact Update Enter(3).\n");
    printf("\t\t\t\t\t\tFor Address Update Enter(4).\n");
    printf("\t\t\t\t\t\tFor Unit Update Enter(5).\n");
    printf("\t\t\t\t\t\tFor All Information Update Enter(6).\n\n");
    printf("\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d",&input);
    switch(input)
    {
    case 1:
        u_id();
        break;
    case 2:
        u_name();
        break;
    case 3:
        u_contact();
        break;
    case 4:
        u_address();
        break;
    case 5:
        u_unit();
        break;
    case 6:
        all_info();
        break;
    default:
        printf("Invalid Input!!Please Enter Correct Input.\n");
        break;
    }
}
u_id()
{
    char another;
    struct user u, us;
    int l_id;
    FILE *add;
    add=fopen("Add Record.txt","r+");
    another='y';
    while(another=='y')
    {
        printf("\t\t\t\t\t\t\tEnter The User Id To Modify: ");
        scanf("%d",&l_id);
        rewind(add);
        while(fread(&us,sizeof(us),1,add)==1)
        {
            if(us.id==l_id)
            {
                printf("\n\t\t\t\t\t\t\tEnter New User Id: ");
                scanf("%d",&us.id);
                fseek(add,-sizeof(us),SEEK_CUR);
                fwrite(&us,sizeof(us),1,add);
                break;
            }
        }
        printf("\n\n\t\t\t\t\t\t\tModify another record(y/n)");
        fflush(stdin);
        another=getche();
        if(another=='y')
        {
            update();
            break;
        }
    }
}

u_name()
{
    char another;
    struct user u, us;
    char nm[30];
    FILE *add;
    add=fopen("Add Record.txt","r+");
    another='y';
    while(another=='y')
    {
        printf("\t\t\t\t\t\t\tEnter The User Name To Modify: ");
        scanf("%s",&nm);
        rewind(add);
        while(fread(&us,sizeof(us),1,add)==1)
        {
            if(strcmp(us.name,nm)==0)
            {
                printf("\n\t\t\t\t\t\t\tEnter New User Name: ");
                scanf("%s",&us.name);
                fseek(add,-sizeof(us),SEEK_CUR);
                fwrite(&us,sizeof(us),1,add);
                break;
            }
        }
        printf("\n\n\t\t\t\t\t\t\tModify another record(y/n)");
        fflush(stdin);
        another=getche();
        if(another=='y')
        {
            update();
            break;
        }
    }
}

u_contact()
{
    char another;
    struct user u, us;
    char cont[20];
    FILE *add;
    add=fopen("Add Record.txt","r+");
    another='y';
    while(another=='y')
    {
        printf("\t\t\t\t\t\t\tEnter The User Contact To Modify: ");
        scanf("%s",&cont);
        rewind(add);
        while(fread(&us,sizeof(us),1,add)==1)
        {
            if(strcmp(us.contact,cont)==0)
            {
                printf("\n\t\t\t\t\t\t\tEnter New User Contact: ");
                scanf("%s",&us.contact);
                fseek(add,-sizeof(us),SEEK_CUR);
                fwrite(&us,sizeof(us),1,add);
                break;
            }
        }
        printf("\n\n\t\t\t\t\t\t\tModify another record(y/n)");
        fflush(stdin);
        another=getche();
        if(another=='y')
        {
            update();
            break;
        }
    }
}

u_address()
{
    char another;
    struct user u, us;
    char adres[50];
    FILE *add;
    add=fopen("Add Record.txt","r+");
    another='y';
    while(another=='y')
    {
        printf("\t\t\t\t\t\t\tEnter The User Address To Modify: ");
        scanf("%s",&adres);
        rewind(add);
        while(fread(&us,sizeof(us),1,add)==1)
        {
            if(strcmp(us.address,adres)==0)
            {
                printf("\n\t\t\t\t\t\t\tEnter New User Address: ");
                scanf("%s",&us.address);
                fseek(add,-sizeof(us),SEEK_CUR);
                fwrite(&us,sizeof(us),1,add);
                break;
            }
        }
        printf("\n\n\t\t\t\t\t\t\tModify another record(y/n)");
        fflush(stdin);
        another=getche();
        if(another=='y')
        {
            update();
            break;
        }
    }
}
u_unit()
{
    char another;
    struct user u, us;
    int u_unit;
    FILE *add;
    add=fopen("Add Record.txt","r+");
    another='y';
    while(another=='y')
    {
        printf("\t\t\t\t\t\t\tEnter The User Unit To Modify: ");
        scanf("%d",&u_unit);
        rewind(add);
        while(fread(&us,sizeof(us),1,add)==1)
        {
            if(us.unit==u_unit)
            {
                printf("\n\t\t\t\t\t\t\tEnter New User Unit: ");
                scanf("%d",&us.unit);
                fseek(add,-sizeof(us),SEEK_CUR);
                fwrite(&us,sizeof(us),1,add);
                break;
            }
        }
        printf("\n\n\t\t\t\t\t\t\tModify another record(y/n)");
        fflush(stdin);
        another=getche();
        if(another=='y')
        {
            update();
            break;
        }
    }
}
all_info()
{
    char another;
    struct user u, us;
    int uid;
    FILE *add;
    add=fopen("Add Record.txt","r+");
    another='y';
    while(another=='y')
    {
        printf("\t\t\t\t\t\t\tEnter The User Id To Modify All Data: ");
        scanf("%d",&uid);
        rewind(add);
        while(fread(&us,sizeof(us),1,add)==1)
        {
            if(us.id==uid)
            {
                printf("\n\t\t\t\t\t\t\tEnter New User Id,User Name,User Contact,User Address, Unit:\n\t\t\t\t\t\t\t");
                scanf("%d",&us.id);
                fseek(add,-sizeof(us),SEEK_CUR);
                fwrite(&us,sizeof(us),1,add);
                break;
            }
        }
        printf("\n\n\t\t\t\t\t\t\tModify Another Record(y/n)");
        fflush(stdin);
        another=getche();
        if(another=='y')
        {
            update();
            break;
        }
    }
}

u_welcome()
{
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t    |||          ||| ||||||||| |||        |||||||  ||||||||  |||     ||| |||||||||      \n");
    printf("\t\t    |||   ||||   ||| |||       |||       |||      |||    ||| ||||| ||||| |||            \n");
    printf("\t\t     ||||||  ||||||  ||||||||  |||       |||      |||    ||| ||| ||| ||| ||||||||       \n");
    printf("\t\t      ||||    ||||   |||       |||   ||| |||      |||    ||| |||     ||| |||            \n");
    printf("\t\t       ||      ||    ||||||||| |||||||||  |||||||  ||||||||  |||     ||| |||||||||    \n\n");
    printf("\t\t\t\t\tPress Any Key To Enter The Main Menu");
    getch();
    u_mainmenu();
}

u_mainmenu()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    system("CLS");
    int y;
    printf("===================  ||     ||    |||    |||| ||    ||      ||     || ||||||| ||    || ||     ||  =====================\n");
    printf("===================  |||| ||||   || ||    ||  ||||  ||      |||| |||| ||      ||||  || ||     ||  =====================\n");
    printf("===================  || ||| ||  |||||||   ||  || || ||      || ||| || ||||||  || || || ||     ||  =====================\n");
    printf("===================  ||     || ||     ||  ||  ||  ||||      ||     || ||      ||  |||| ||     ||  =====================\n");
    printf("===================  ||     || ||     || |||| ||    ||      ||     || ||||||| ||    ||  |||||||   =====================\n");
    printf("=======================================================================================================================\n");
    printf("     User: Local User                                Date: %d/%d/%d                                      Time: %d:%d        \n",time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
    printf("=======================================================================================================================\n\n");


    printf("\t\t\t\t\t\t1.Bill\n");
    printf("\t\t\t\t\t\t2.Payment\n");
    printf("\t\t\t\t\t\t3.Back To Login\n");


    int flag=0;
    int input;
    do
    {
       printf("\t\t\t\t\t\tEnter Your Choice: ");
       scanf("%d",&input);
       if(input>2)
       {
         MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
       }
       else
       {
         flag=1;
       }
    }
    while(flag!=1);

    switch (input)
    {
    case 0:
        MessageBoxW(NULL,L"Please Enter the Right Value",L"Error!",MB_OK);
        u_mainmenu();
    case 1:
        bill();
        break;
    case 2:
        payment();
        break;
    }
}
bill_design()
{
    printf("\t====================    ||||||||  |||||||| ||       ||          ====================\n");
    printf("\t====================    ||     ||    ||    ||       ||          ====================\n");
    printf("\t====================    |||||||      ||    ||       ||          ====================\n");
    printf("\t====================    ||     ||    ||    ||    || ||    ||    ====================\n");
    printf("\t====================    |||||||   |||||||| |||||||| ||||||||    ====================\n\n");
}
bill()
{
    struct user u, us;
    system("CLS");
    bill_design();
    float per=5.45;
    FILE *add;
    add=fopen("Add Record.txt","r");
    printf("\t\tUser Id\t\tName\t\tContact\t\tAddress\t\t\tUnit\t\tBill\n\n");
    while (fread(&us,sizeof(us),1,add))
        printf("\t\t%d\t\t%s\t\t%s\t\t%s\t\t\t%d\t\t%.2lf TK\n",us.id,us.name,us.contact,us.address,us.unit,us.unit*per);
    fclose(add);
    backToTheMain();
    u_mainmenu();
}
payment()
{
    struct user u,us;
    FILE *add;
    int pay_id;
    float amt;
    add=fopen("Add Record.txt","a");
    system("CLS");
    printf("Enter the user id for payment: ");
    scanf("%d",&pay_id);
    while(fread(&us,sizeof(us),1,add)==1)
    {
        if(pay_id==id)
        {
            system("CLS");
            printf("\nUser id\t\tName\t\tCurrent balance\n");
            printf("%d\t\t%s\t\t%.2lf",us.id,us.name,us.amt);
            printf("\n\nEnter the amount: ");
            scanf("%f",&amt);
            fwrite(&us,sizeof(us),1,add);
            break;
        }
    }
    system("cls");
	printf("THANK YOU %s FOR YOUR TIMELY PAYMENTS",us.name);
	getch();
	fclose(add);
}

main()
{
    struct user u, us;
    portal();
}
