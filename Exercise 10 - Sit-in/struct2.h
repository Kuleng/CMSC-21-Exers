#include<stdio.h>
#include<string.h>
#define YEAR_NOW 2019


typedef struct bday_tag {
  int month;
  int day;
  int year;
} bday;

typedef struct student_tag {
  char first_name[30];
  char last_name[30];
  int age;
  bday birthday;
  struct student_tag *friend_ptr;

} student;

//structures are usually defined first before function prototypes since they can be used as parameters
void scanBirthday(bday *);
void printBirthdayStruct(bday b);
void printBirthday(int, int, int);
void printStudent(student);
void printFriend(student *);


void scanBirthday(bday *b) {
  printf("Birthday (MM/DD/YYYY): ");
  scanf("%d/%d/%d", &(b->month), &(b->day), &(b->year));

  //if we change the formal parameter as student*, what should be the parameters/arguments for scanf?
}

void printBirthdayStruct(bday b) {
  printf("%d/%d/%d\n", b.month, b.day, b.year);
}

void printBirthday(int month, int day, int year) {
  printf("%d/%d/%d\n", month, day, year);
}

void printStudent(student s) {
  printf("Name: %s %s\n", s.first_name, s.last_name);
  printf("Birthday: ");
  printBirthday(s.birthday.month, s.birthday.day, s.birthday.year);
  //printBirthdayStruct(__________)
  printf("Age: %d\n", s.age);
}

void printFriend(student *s) {
  printf("Name: %s %s\n", s->first_name, s->last_name);
  printf("Birthday: ");
  printBirthday(s->birthday.month, s->birthday.day, s->birthday.year);
  printf("Age: %d\n", s->age);

  /*
  printf("Name: %s %s\n", (*s).first_name, (*s).last_name);
  printf("Birthday: ");
  printBirthday((*s).birthday.month, (*s).birthday.day, (*s).birthday.year);
  printf("Age: %d\n", (*s).age);
  */
}
