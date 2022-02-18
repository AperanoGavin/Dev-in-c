#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"




struct user{
    char name[50];
    int C1;
    int C2;
    int C3;
    char C;

};



void takeinput(char ch[50]){
    fflush(stdin);
    fgets(ch,50,stdin);
    ch[strlen(ch)-1] = 0;
}

void takeinputIt(int *It){
    fflush(stdin);
    scanf("%d",It);
}





int main(){
    FILE *fp;
    int pr;
    int usrFound = 0;
    char opt;
    char opt1;
    char nm;
    struct user *user;
    struct user usr;
    struct user usr1;
    struct user usr2;


    char c;

    do {
        printf("\n\t\t\t\t%s----------Welcome ----------",KNRM);
        printf("\nPlease choose your operation");
        printf("\n1.add data in file");
        printf("\n2.remove data in file");
        printf("\n4.Print  project  Y and N for students ");
        printf("\n5.Program with most Y and N");
        printf("\n5.print program with most Y :");
        printf("\n\t\t\t\t%s!!!!BECAUSE IS NOT AUTOMATIC LIKE(SQL) PLEASE EXIT MENU TO SEE FILE CHANGE:!!!!",KRED);
        printf("\n7.Exit");

        printf("\n\n%sYour choice:\t",KNRM);
        scanf("%s", &opt);
        fgetc(stdin);

        switch (opt) {
            case '1':

                printf("Enter your name: ");
                takeinput(&(user->name));


                printf("Enter number between 1 and 130:\t");
                takeinputIt(&(user->C1));
                if( (((user->C1)) >= 1) && (((user->C1)) <= 130)  ){

                        printf("");

                    }else{
                    printf("try again ,wrong number ,please Enter number between 1 and 130:\t");
                    break;
                }

                printf("Enter number between 1 and 10\t");
                takeinputIt(&(user->C2));
                if( (((user->C2)) >= 1) && (((user->C2)) <= 10)  ){

                    printf("");

                }else{
                    printf("try again ,wrong number ,please Enter number between 1 and 10\t");
                    break;
                }

                printf("Enter the time (it  should be an minutes)\t");
                takeinputIt(&(user->C3));
                if( (((user->C3)) >= 0) && (((user->C3)) <= 359)  ){

                    printf("");

                }else{
                    printf("try again ,wrong number ,please Enter time  remember (it  should be an minutes and between 0 and 359)\t");
                    break;
                }

                printf("Specifies whether it works(Y) or not(N): ");
                takeinput(&(user->C));
                if( (((user->C)) == 'Y') || (((user->C)) == 'N')  ){

                    printf("");

                }else{
                    printf("try again ,wrong number ,please Enter Y or N\t");
                    break;
                }


                if ( (((user->C1)) != 0) ){
                    fp = fopen("Users.bin", "ab+");
                    fwrite(&user, sizeof(struct user), 1, fp);
                    if (fwrite != 0) {
                        printf("\n\nData register ");
                    } else {
                        printf("\n\nSorry! Something went wrong :(");
                    }
                    fclose(fp);
                } else {
                    printf("\n\ntry again");

                }
                break;

            case '2':
                system("rm /Users/macbook/CLionProjects/untitled29/cmake-build-debug/Users.bin");
                printf("Bye-bye ;') , you're welcome");

            case '3':

                fp = fopen("Users.bin", "rb");
                printf("print program to check (between 1 and 10) :");
                scanf("%d",&pr);


                while(fread(&usr, sizeof(struct user), 1, fp), !feof(fp)) {
                    if (strcmp(pr, usr.C2) == 0) {
                        printf("Programs solved ");
                        break;
                    } else{
                        printf("Programs not solved ");
                        break;
                    }
                }


                fclose(fp);
                break;


            case '4':
                printf("\nPlease Enter your name");
                scanf("%s",&nm);

                fp = fopen("Users.bin", "rb");
                if(fread(&usr1, sizeof(struct user), 1, fp)){
                    if (strcmp(nm, usr1.name) == 0){
                        c = fgetc(fp);
                        while (c != EOF) {
                            printf("%c", c);
                            printf("\t");
                            c = fgetc(fp);
                        }
                    }

                }




                fclose(fp);
                break;




            case '5':
                printf("print program with most Y and N:");
                fp = fopen("Users.bin", "rb");

                while(fread(&usr2, sizeof(struct user), 1, fp), !feof(fp)) {
                    if (strcmp(pr, usr2.C2) == 0) {
                        printf("Programs solved ");
                        break;
                    } else{
                        printf("Programs not solved ");
                        break;
                    }
                }


                fclose(fp);
                break;


            case '6':


                fp = fopen("Users.bin", "rb");

                fread(&usr, sizeof(struct user), 1, fp);

                c = fgetc(fp);
                while (c != EOF) {
                    printf("%c", c);
                    printf("\t");
                    c = fgetc(fp);
                }


                fclose(fp);
                break;






        }


    }while (opt != '7');

    printf("Bye-bye ;') , you're welcome");

    return 0;
}