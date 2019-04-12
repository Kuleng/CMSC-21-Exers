#include<stdio.h>

typedef struct bday_tag {
  int month, day, year;
} bday;

typedef struct student_tag {
  char first_name[30];
  char last_name[30];
  int age;
} student;


int main() {
  student s1 = {"Jose", "Rizal", 35};
  bday birthday;

  birthday.month = 6;
  birthday.day = 19;
  birthday.year = 1861;

  printf("%s %s %d\n", s1.first_name, s1.last_name, s1.age);
  printf("%d/%d/%d\n", birthday.month, birthday.day, birthday.year);


  return 0;
}
