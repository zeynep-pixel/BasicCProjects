#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct person
{
    char name[30];
    char surname[30];
    char number[4];
    char department[150];

    };
void menu();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
 menu();
}

void menu()
{
 
    printf("Please select an option:\n");
    printf("1. Add a number\n");
    printf("2. Search by\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("5. List\n");
    printf("6. Exit\n");


switch(getch())
{
    case '1':

     addrecord();
    break;
   case '2': 
     searchrecord();
    break;
    case '3': 
     modifyrecord();
    break;
    case '4': 
     deleterecord();
    break;
    case '5': 
     listrecord();
    break;
    case '6': 
     exit(0);
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();

menu();
}
}

void addrecord()
{
   system("cls");
    FILE *f;
    struct person p;

    f = fopen("project", "ab+");
    if(f == NULL) {
        printf("\nfile opening error in listing :");
        exit(1);
    }

    printf("\nEnter name: ");
    scanf("%s", p.name);
    printf("\nEnter surname: ");
    scanf("%s", p.surname); 
    printf("\nEnter number: ");
    scanf("%s", p.number);
    printf("\nEnter department: ");
    scanf("%s", p.department);
    fflush(stdin);

    fwrite(&p, sizeof(p), 1, f);
    printf("\nRecord saved.");

    fclose(f);
    printf("\n\nEnter any key");
    getchar();

    system("cls");
    menu();
}

void listrecord()
{
 struct person p;
    FILE *f;
    f=fopen("project","rb");
    if(f==NULL)
    {
        printf("\nfile opening error in listing :");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,f)==1)
    {
        printf("Your Person");
        printf("\nName: %s\nSurname: %s\nNumber: %s\nDepartman: %s\n",p.name,p.surname,p.number,p.department);
    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}



void searchrecord()
{
    
    struct person p;
    FILE *f;
    char number[4];
    int found = 0;

    f = fopen("project", "rb");
    if (f == NULL)
    {
        printf("\nError in opening file.");
        exit(1);
    }

    printf("\nEnter number of person to search: ");
    scanf("%s", number);

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(p.number, number) == 0)
        {
            printf("\n\tDetail Information About %s", number);
            printf("\nName: %s\nSurname: %s\nNumber: %s\nDepartment: %s\n", p.name, p.surname, p.number, p.department);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nRecord not found.");
    }

    fclose(f);
    printf("\nPress any key to continue...");
    getch();
    system("cls");
    menu();
}






void modifyrecord()
{
    FILE *f;
    struct person p, s;
    char number[4];
    int flag = 0;

    f = fopen("project", "rb+");
    if (f == NULL)
    {
        printf("\nError: could not open file.");
        exit(1);
    }

    printf("\nEnter number of person to modify: ");
    scanf("%s", number);

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(p.number, number) == 0)
        {
            printf("\nEnter new name: ");
            scanf("%s", s.name);
            printf("Enter new surname: ");
            scanf("%s", s.surname);
            printf("Enter new number: ");
            scanf("%s", s.number);
            printf("Enter new department: ");
            scanf("%s", s.department);

            fseek(f, sizeof(p), SEEK_CUR);
            fwrite(&s, sizeof(p), 1, f);

            flag = 1;
            printf("\nRecord has been modified.\n");
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nRecord not found.\n");
    }

    fclose(f);
    printf("\nPress any key to continue...");
    getch();
    system("cls");
    menu();

}


void deleterecord()
{
    FILE *f, *temp;
    struct person p;
    char number[4];
    int found = 0;

    f = fopen("project", "rb");
    if (f == NULL)
    {
        printf("\nError: could not open file.");
        exit(1);
    }

    temp = fopen("temp", "wb");
    if (temp == NULL)
    {
        printf("\nError: could not open temporary file.");
        fclose(f);
        exit(1);
    }

    printf("\nEnter number of person to delete: ");
    scanf("%s", number);

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(p.number, number) != 0)
        {
            fwrite(&p, sizeof(p), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(f);
    fclose(temp);

    if (!found)
    {
        printf("\nRecord not found.");
        remove("temp");
    }
    else
    {
        remove("project");
        rename("temp", "project");
        printf("\nRecord has been deleted.\n");
    }

    printf("\nPress any key to continue...");
    getch();
    system("cls");
    menu();
}





