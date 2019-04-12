#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
	//structure tags
struct student
{
	char firstname[50];
	char surname[20];
	int age;
};
	//type definitions
typedef struct{
	char firstname[5];
	char surname;
	int age;
} student;

typedef struct student
{
	char firstname;
	char surname;
	int age;
} student;


struct birthdate
{
	int month, day, year;
};

struct student
{
	char firstname[50];
	char surname[39];
	struct birthdate birthday;
	struct student *sptr;

};


int main(){
	//structure tags

	return 0;
}