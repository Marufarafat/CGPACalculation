#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void calculateCGPA();
void method();
struct Students studentInfo();
float findGP(int point);

struct Subjects {
   char name[100];
   float point;
   float credit;
};

struct Students{
    char name[50];
    char id[8];
    int numOfSubject;
};


int main(){

    system("cls");

    int input;
    printf("--------------------------------------------------------------------------\n");
    printf("                           CGPA Calculator                                \n");
    printf("--------------------------------------------------------------------------\n");
    printf("            MENU:\n");
    printf("                   1. Calculate CGPA\n");
    printf("                   2. Method that is applied here for calculate\n");
    printf("                   3. Exit Application\n");
    printf("--------------------------------------------------------------------------\n");

    sub:
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input){
            case 1:
                    calculateCGPA();
                    break;
            case 2:
                    method();
                    break;
            case 3:
                    exit(EXIT_SUCCESS);
                    break;
            default:
                printf("You have entered wrong input.Try again!\n");
                goto sub;
                break;
        }
}

struct Students studentInfo(){

    struct Students student;
    printf("Enter Student name(100): ");
    scanf(" %[^\t\n]s", &student.name);

    printf("Enter Student id(8): ");
    scanf("%s", &student.id);

    printf("Enter Number of subjects completed : ");
    scanf("%d", &student.numOfSubject);

    printf("\n\n\n");

    return student;

}

float findGP(int point){

    if(point < 40 ){
        return 0;
    } else if(point < 45){
        return 2;
    } else if(point < 50){
        return 2.25;
    } else if(point < 55){
        return 2.5;
    } else if(point < 60){
        return 2.75;
    } else if(point < 65){
        return 3;
    } else if(point < 70){
        return 3.25;
    } else if(point < 75){
        return 3.5;
    } else if(point < 80){
        return 3.75;
    } else if(point <= 100){
        return 4;
    } else{
        return 0;
    }
}

void calculateCGPA(){

    system("cls");
    printf("-------------- CGPA Calculating -----------------\n\n\n");

    /* taking student information from console */
    struct Students student = studentInfo();

    /* taking subjects information from console */
    struct Subjects subjectInfo[student.numOfSubject];

    float allSubjectSum = 0;
    float allSubjectCredit = 0;

    float totalCGPA = 0;

    int i;
    for(i = 0;i < student.numOfSubject;i++){
        printf("Enter subject name(100): ");
        scanf("%s", &subjectInfo[i].name);

        printf("Enter %s point: ", subjectInfo[i].name);
        scanf("%f", &subjectInfo[i].point);

        printf("Enter %s credit: ", subjectInfo[i].name);
        scanf("%f", &subjectInfo[i].credit);
        printf("\n\n");
    }

    /* showing information to console */
    system("cls");
    printf("Student Name: %s\n", student.name);
    printf("Student Id: %s\n", student.id);
    printf("Number of subject completed: %d\n\n", student.numOfSubject);
    printf("Subject \t point \t\t credit \n");
    printf("---------------------------------------\n");

    int j;
    for(j = 0;j < student.numOfSubject;j++){
        allSubjectSum += subjectInfo[j].credit * findGP(subjectInfo[j].point);
        allSubjectCredit += subjectInfo[j].credit;

        printf("%s \t %.2f \t\t %.2f\n", subjectInfo[j].name, subjectInfo[j].point, subjectInfo[j].credit);
        printf("---------------------------------------\n");
    }

    totalCGPA = allSubjectSum/allSubjectCredit;

    //printf("Total \t\t %.2f \t %.2f", allSubjectSum, allSubjectCredit);

    printf("\n\nCGPA: %.2f \n", totalCGPA);

    /* creating file and writing data to file */
    // creating file name
    char studentFileName[8];
    strcpy(studentFileName, student.id);
    strcat(studentFileName,".txt");

    FILE *fp;
    fp = fopen(studentFileName, "w+");
    fprintf(fp, "Student Name: %s\n", student.name);
    fprintf(fp, "Student Id: %s\n", student.id);
    fprintf(fp, "Number of subject completed: %d\n\n", student.numOfSubject);
    fprintf(fp, "Subject \t point \t\t credit \n");
    fprintf(fp, "---------------------------------------\n");

    int k;
    for(k = 0;k < student.numOfSubject;k++){

        fprintf(fp, "%s \t %.2f \t\t %.2f\n", subjectInfo[k].name, subjectInfo[k].point, subjectInfo[k].credit);
        fprintf(fp, "---------------------------------------\n");
    }
    //fprintf(fp, "Total \t\t %.2f \t %.2f", allSubjectSum, allSubjectCredit);
    fprintf(fp, "\n\nCGPA: %.2f \n", totalCGPA);

    fclose(fp); // closing file

    sub:
        printf("\n\n\n1. Calculate Again\n");
        printf("2. Go Back to Main Menu\n");
        printf("3. Exit This App \n\n\n");
        printf("Your Input: \n");

        int inmenu;
        scanf("%d", &inmenu);

        switch(inmenu){
            case 1:
                    calculateCGPA();
                    break;
            case 2:
                    main();
                    break;
            case 3:
                    exit(EXIT_SUCCESS);

            default:
                printf("\n\nYou have Entered Wrong Input!Please Choose Again!\n");
                goto sub;
        }

}

void method(){
    system("cls");
    printf("--------------- Method of Calculating CGPA ---------------\n\n\n");
    printf(" For a subject, point is equal to credit of that subject multiply by obtained grade point \n\n");
    printf(" Calculate the sum of all subject’s point (PS)  \n\n");
    printf(" Calculate the sum of credit’s (CR) \n\n");
    printf(" Equation for calculating CGPA:  \n");
    printf(" CGPA = (sum * PS)  / (sum * CR)  \n");
    printf("-----------------------------------------------------------------\n\n\n");

    sub:
        printf("1. Go Back to Main Menu\n");
        printf("2. Exit This App \n\n\n");
        printf("Your Input: \n");
        int inmenu;
        scanf("%d", &inmenu);

        switch(inmenu){
            case 1:
                    main();
                    break;
            case 2:
                    exit(EXIT_SUCCESS);

            default:
                  printf("\n\nYou have Entered Wrong Input!Please Choose Again!\n");
                  goto sub;
    }
}
