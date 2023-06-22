#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int rollno;
   char name[20];
   float marks;
} Student;

void initializeAllStudents(Student *students, int size)
{
   for (int i = 0; i < size; i++)
   {
      students[i].rollno = 0;
      strcpy(students[i].name, "");
      students[i].marks = 0.0;
   }
}

int main()
{
   int size;

   printf("Enter the number of students: ");
   scanf("%d", &size);
   getchar();

   Student *students = malloc(size * sizeof(Student));

   initializeAllStudents(students, size);

   for (int i = 0; i < size; i++)
   {
      printf("\nStudent %d:\n", i + 1);
      printf("Roll No: %d\n", students[i].rollno);
      printf("Name: %s\n", students[i].name);
      printf("Marks: %.2f\n\n", students[i].marks);
   }

   free(students);

   return 0;
}