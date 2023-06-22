#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int rollno;
   char name[20];
   float marks;
} Student;

int compareByMarks(const void *a, const void *b)
{
   const Student *studentA = (const Student *)a;
   const Student *studentB = (const Student *)b;

   if (studentA->marks < studentB->marks)
      return 1;
   else if (studentA->marks > studentB->marks)
      return -1;
   else
      return 0;
}

void sortStudents(Student *students, int size)
{
   qsort(students, size, sizeof(Student), compareByMarks);
}

int main()
{
   int size;

   printf("Enter the number of students: ");
   scanf("%d", &size);
   getchar();

   Student *students = malloc(size * sizeof(Student));

   for (int i = 0; i < size; i++)
   {
      printf("Enter student %d details (rollno name marks): ", i + 1);
      scanf("%d %s %f", &(students[i].rollno), students[i].name, &(students[i].marks));
      getchar();
   }

   sortStudents(students, size);

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