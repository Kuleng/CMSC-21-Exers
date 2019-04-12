#include "struct2.h"


int main() {
  student s1, s3, students[20];
  struct student_tag s2, *sptr;

  printf("Enter values for s1...\n");
  printf("First name: ");
  scanf("%s", s1.first_name);
  printf("Last name: ");
  scanf("%s", s1.last_name);
  scanBirthday(&s1.birthday);
  s1.age = YEAR_NOW - s1.birthday.year;

  printf("\n==========================\n");
  printf("Student Information of s1:\n");
  printStudent(s1);
  printf("==========================\n");

  /*
  s2 = s1;
  printf("\n==========================\n");
  printf("Student Information of s2:\n");
  printStudent(s2);
  printf("==========================\n");
  */

  strcpy(s3.first_name, "Juan");
  strcpy(s3.last_name,"Luna");
  s3.birthday.month = 10;
  s3.birthday.day = 23;
  s3.birthday.year = 1857;
  s3.age = YEAR_NOW - s3.birthday.year;
  s3.friend_ptr = &s1;
  s1.friend_ptr = &s3;

  printf("\n==========================\n");
  printf("Student Information of s3:\n");
  printStudent(s3);
  printf("==========================\n");

  printf("\n==========================\n");
  printf("Student Information of s3.friend_ptr:\n");
  printFriend(s3.friend_ptr);
  printf("==========================\n");

  /*
    is printFriend(s3.friend_ptr->friend_ptr) valid? what will it print?
    how about printFriend(s3.friend_ptr->friend_ptr->friend_ptr) valid? what will it print?
  */

  /* only the members of the structure can be used as operands on logical and relational operations
     is s1 == s3 valid?
  */
  if (s1.age > s3.age) {
    printf("%s is %d older than %s!\n", s1.first_name, s1.age - s3.age, s3.first_name);
  }
  else if (s3.age > s1.age) {
    printf("%s is %d older than %s!\n", s3.first_name, s3.age - s1.age, s1.first_name);
  }
  else {
    printf("%s and %s have the same age!\n", s1.first_name, s3.first_name);
  }

  students[0] = s1; //we now have 1 student in the array
  students[1] = s3; //we now have 2 students in the array
  /*
     structure arrays are initially filled with uninitialized structures.
     because of this, we need to keep track how many "real" elements are in the array.

     introducing a new variable is going to be helpful in this scenario.
  */

  return 0;
}
