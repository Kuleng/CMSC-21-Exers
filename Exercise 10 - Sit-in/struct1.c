#include<stdio.h>
#define YEAR_NOW 2019
#include <string.h>
/*
   (typdef) struct <structure_tag> {
      members go here
        members can be various data types, including other structures
        a structure can be a member of itself if it is declared as pointer
   } (<synonym>)

   typedef and synonym go together and are optional
   struct and structure_tag go together and (usually) are required
    the structure_tag can be ommited if only the typedef-synonym pair is used

   we will be focusing on having both struct and typedef definition
   you can refer to the handout for more declaration examples
*/


typedef struct bday_tag {
  int month;
  int day;
  int year;
} bday;

typedef struct student_tag {
  char first_name[30];
  char last_name[30];
  int age;
  bday birthday; //the ordering of structure definition still matters
  struct student_tag *friend_ptr;

} student;


int main() {
  student s1, s3, students[20];
  struct student_tag s2, *sptr;

  printf("Enter values for s1...\n");
  printf("First name: ");
  scanf("%s", s1.first_name);
  printf("Last name: ");
  scanf("%s", s1.last_name);
  /* take note that the structure variable should be prepended by &, not the member
  printf("Age: ");
  scanf("%d", &s1.age);
  */
  printf("Birthday (MM/DD/YYYY): ");
  scanf("%d/%d/%d", &s1.birthday.month,&s1.birthday.day,&s1.birthday.year);
  s1.age = YEAR_NOW - s1.birthday.year;

  printf("\n==========================\n");
  printf("Student Information of s1\n");
  printf("Name: %s %s\n", s1.first_name, s1.last_name);
  printf("Birthday: ");
  printf("%d/%d/%d\n", s1.birthday.month, s1.birthday.day, s1.birthday.year);
  printf("Age: %d\n", s1.age);
  printf("==========================\n");


  s2 = s1;
  printf("\n==========================\n");
  printf("Student Information of s2\n");
  printf("Name: %s %s\n", s2.first_name, s2.last_name);
  printf("Birthday: ");
  printf("%d/%d/%d\n", s2.birthday.month, s2.birthday.day, s2.birthday.year);
  printf("Age: %d\n", s2.age);
  printf("==========================\n");

  strcpy(s3.first_name, "Juan");
  strcpy(s3.last_name, "Luna");
  // s3.first_name = "Juan";
  // s3.last_name = "Luna";
  s3.birthday.month = 10;
  s3.birthday.day = 25;
  s3.birthday.year = 2019;
  s3.age = YEAR_NOW - s3.birthday.year;
  s3.friend_ptr = &s1;

  printf("\n==========================\n");
  printf("Student Information of s3\n");
  printf("Name: %s %s\n", s3.first_name, s3.last_name);
  printf("Birthday: ");
  printf("%d/%d/%d\n", s3.birthday.month, s3.birthday.day, s3.birthday.year);
  printf("Age: %d\n", s3.age);
  printf("==========================\n");

  /*
  sptr = ___;
  printf("\n==========================\n");
  printf("Student Information of sptr\n");
  printf("Name: %s %s\n", (*sptr).first_name, (*sptr).last_name);
  printf("Birthday: ");
  printf("%d/%d/%d\n", (*sptr).birthday.month, (*sptr).birthday.day, (*sptr).birthday.year);
  printf("Age: %d\n", (*sptr).age);
    //or alternatively using the arrow operator
    //printf("Name: %s %s\n", sptr->first_name, sptr->last_name);
    //printf("Birthday: ");
    //printf("%d/%d/%d\n", sptr->birthday.month, sptr->birthday.day, sptr->birthday.year);
    //printf("Age: %d\n", sptr->age);
  printf("==========================\n");
  */

  /*
    what if we want to print the first name of friend_ptr?
      is s3.(*friend_ptr).first_name?
      how about s3.friend_ptr->first_name valid?

    how do we know if a structure is initialized?

    since s2 = s1 is valid, what will happen if we change one member of s2?
  */
}
