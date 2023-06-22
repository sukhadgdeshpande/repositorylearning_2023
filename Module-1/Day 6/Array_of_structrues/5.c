#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int rollno;
   char name[20];
   float marks;
} Student;

void searchStudent(const Student *students, int size, const char *searchName)
{
   int found = 0;
   for (int i = 0; i < size; i++)
   {
      if (strcmp(students[i].name, searchName) == 0)
      {
         found = 1;
         printf("\nStudent found:\n");
         printf("Roll No: %d\n", students[i].rollno);
         printf("Name: %s\n", students[i].name);
         printf("Marks: %.2f\n\n", students[i].marks);
      }
   }

   if (!found)
   {
      printf("\nStudent not found.\n");
   }
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

   char searchName[20];
   printf("Enter the name of the student to search: ");
   scanf("%s", searchName);

   searchStudent(students, size, searchName);

   free(students);

   return 0;
}