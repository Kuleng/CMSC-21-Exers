#include <stdio.h>
#include <string.h>
#define YEAR_NOW 2019

typedef struct bday_tag {
	int month;
	int day;
	int year;
} bday;

typedef struct student_tag
{
	char first_name[30];
	char last_name[30];
	int age;
	bday birthday;

	struct student_tag *friend_ptr;
} student;

int main(){
	student s1, s3, students[20];
	struct student_tag s2, *sptr; //These declarations are the same.

	printf("Enter values for s1...\n");
	printf("First name: ");
	scanf("%s", s1.first_name);
	printf("Last name:");
	scanf("%s", s1.last_name);
/*	printf("Age:  ");
	scanf("%d", &s1.age);
*/

	printf("Birthday (MM/DD/YYYY) \n");
	scanf("%d/%d/%d", &s1.birthday.month, &s1.birthday.day, &s1.birthday.year);

	printf("%s \n", s1.first_name);
	printf("%s \n", s1.last_name);

	printf("%d/%d/%d \n", s1.birthday.month, s1.birthday.day, s1.birthday.year);
	s1.age = YEAR_NOW - s1.birthday.year;

	printf("Your age today is: %d \n", s1.age);	

	s2 = s1;

	printf("Student information of s2\n");
	printf("Name: %s %s \n", s2.first_name, s2.last_name);
	printf("Birthday: ");
	printf("%d/%d/%d\n", s2.birthday.month, s2.birthday.day, s2.birthday.year);
	printf("Age: ");
	printf("%d \n", s2.age);


	strcpy(s3.first_name, "Juan"); //to change the value
	strcpy(s3.last_name, "Luna"); //we cannot change a string directly so we do it via strcpy
	s3.birthday.month = 10;
	s3.birthday.day = 23;
	s3.birthday.year = 1857;
	s3.age = YEAR_NOW - s3.birthday.year;
	s3.friend_ptr = &s1;

	printf("Student information of s3\n");
	printf("Name: %s %s \n", s3.first_name, s3.last_name);
	printf("Birthday: ");
	printf("%d/%d/%d\n", s3.birthday.month, s3.birthday.day, s3.birthday.year);
	printf("Age: ");
	printf("%d \n", s3.age);


	return 0;
}