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

typedef struct semTag
{
	int year;
	char time[2];
	course subj[6];
} semester;	

void addSem(semester *S){
	printf("Enter sem year:  ");
	scanf("%d", &(S->year));

	printf("1st, 2nd, or mid? ");
	getchar();
	fgets(S->time, 4, stdin);
}

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

void printSem(semester *S, int semCount, int courseCount, course *subj){

		printf("School year: %d \n", S->year);
		printf("Semester time: %s \n\n", S->time);
		for (int j = 0; j < courseCount; j++){
				printf("%d.", j+1);
				printCourse(&subj[j]);
		} //SUMMARY
	
}

void courseInSem(){

//Print the menu
	printf("=========================\n");
	printf("[1] Add a course\n");
	printf("[2] Edit a grade\n");
	printf("[3] GWA Calculator\n");
	printf("[4] Exit\n");
	printf("=========================\n");
}

int main(){
	semester S[4];	
	course subj[6];
	int choice = 0, courseCount = 0, semCount = 0, toEdit, totalUnits = 0, semChoice;
	float GWA, WG = 0;

//Print main menu
	printf("=========================\n");
	printf("[1] Add a semester\n");
	printf("[2] Add course in a semester\n");
	printf("[3] Edit grade in a semester\n");
	printf("[4] Calculate over all GWA in a semester\n");
	printf("[5] Calculate GWA of a semester\n");
	printf("=========================\n");

	//Ask for choice
	while (choice != 4){

		//Ask for choice
		printf("\n \n\t[!] Enter your choice:  ");
		scanf("%d", &choice);
		printf("\n \n");
		if (choice == 1){
			addSem(&S[semCount]);
			printSem(&S[semCount], semCount, courseCount, subj);
			semCount ++;
			continue;
		}
		else if(choice == 2){ //Add a course in Semester
			int ask;
			printf("[1] Add a course in Semester\n");
			printf("[2] Edit a grade of Course\n");
			//ask semester
			scanf("%d", &ask);

			//display semester choices
			for (int i = 0; i < semCount; i++)
			{
				printf("\t%d.\n\t", i+1);					
				printSem(&S[i], semCount, courseCount, subj);
			}

			printf("Which semester would you like to add/edit course?\n \n");
			//input
			scanf("%d", &semChoice);
			
			if (ask == 1){
				printf("Which subject would you like to add course?\n \n");

				//add course based on input
				addCourse(&S[semChoice].subj[courseCount]);
				courseCount ++;
				continue;
			}
			else if (ask == 2){
				for (int i = 0; i < courseCount; i++){
					printf("%d.", i+1);
					printCourse(&subj[i]);
				} //SUMMARY
				printf("Which subject would you like to edit?  ");
				scanf("%d", &toEdit);
				editGrade(&S[semChoice].subj[toEdit-1]);
			}
		}
		else if (choice == 3){ //Calculate over all GWA
			//SUMMARY
			printf("\n \n \n");
			//print all semesters
			for (int i = 0; i < semCount; i++)
			{
				(&S[i].course.G)
				} //SUMMARY
			}
			for (int i = 0; i < courseCount; i++){
				printf("%d.", i+1);
				printCourse(&subj[i]);
			} //SUMMARY
			continue;
		}
		else if (choice == 4){
			//SUMMARY
			printf("\n \n \n");
			printf("Your subjects are:\n");
			for (int i = 0; i < courseCount; i++){
				printf("%d.", i+1);
				printCourse(&subj[i]);
			} //SUMMARY

			for (int i = 0; i < courseCount;i++){
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