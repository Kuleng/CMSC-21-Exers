#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct courseTag
{
	char courseTitle[256];
	char courseName[10];
	int	courseNum;
	int units;
	float grade;
} course;

void addCourse(course *courseSubj){

	printf("\tWhat is the course title?  ");
	// scanf("%s",(courseSubj->courseTitle));
	getchar();
	fgets(courseSubj->courseTitle, 256, stdin);
	// courseSubj->courseTitle[strlen(courseSubj->courseTitle) - 1] = '\0';

	printf("\tWhat is the course code?  ");
	scanf("%s %d",(courseSubj->courseName), &(courseSubj->courseNum));

	printf("\tHow many units?  ");
	scanf("%d",&(courseSubj->units));

	printf("\tWhat is your grade?  ");
	scanf("%f",&(courseSubj->grade));

	printf("\t[!] Course successfully added [!]\n");
}

void editGrade(course *courseSubj){
	printf("\tEnter new grade for %s:   ", courseSubj->courseTitle);
	scanf("%f", &(courseSubj->grade));
	printf("\t[!] Grade successfully edited [!]\n");
}

void printCourse(course *courseSubj){

	printf("\tCourse title:\t%s", courseSubj->courseTitle); //No backslash N due to fgets
	printf("\tCourse code:\t%s %d\n", courseSubj->courseName, courseSubj->courseNum);
	printf("\tUnits:\t%d \n", courseSubj->units);
	printf("\tFinal Grade:\t%f \n", courseSubj->grade);

}

int main(){
	int choice = 0, count = 0, toEdit, totalUnits = 0;
	float GWA, WG = 0;
	course subj[6];

//Print the menu
	printf("=========================\n");
	printf("[1] Add a course\n");
	printf("[2] Edit a grade\n");
	printf("[3] GWA Calculator\n");
	printf("[4] Exit\n");
	printf("=========================\n");

//Ask for choice
	while (choice != 4){

		//Ask for choice
		printf("\n \n\t[!] Enter your choice:  ");
		scanf("%d", &choice);
		printf("\n \n");
		if(choice == 1){
			printf("\t[!]Enter course details:  \n \n");
			addCourse(&subj[count]);
			count ++;
			continue;
		}
		else if (choice == 2){
			//SUMMARY
			printf("\n \n \n");
			printf("Your subjects are:\n");
			for (int i = 0; i < count; i++){
				printf("%d.", i+1);
				printCourse(&subj[i]);
			} //SUMMARY
			printf("Which subject would you like to edit?  ");
			scanf("%d", &toEdit);
			editGrade(&subj[toEdit-1]);
			continue;
		}
		else if (choice == 3){
			//SUMMARY
			printf("\n \n \n");
			printf("Your subjects are:\n");
			for (int i = 0; i < count; i++){
				printf("%d.", i+1);
				printCourse(&subj[i]);
			} //SUMMARY

			for (int i = 0; i < count;i++){
				WG += subj[i].grade * subj[i].units;
				totalUnits += subj[i].units;
			}

			GWA = WG / totalUnits;
			printf("Your GWA is: %.2f. \n",GWA);
			continue;
		}
		else {
			printf("Invalid entry!\n");
			continue;
		}
	}
	return 0;
}