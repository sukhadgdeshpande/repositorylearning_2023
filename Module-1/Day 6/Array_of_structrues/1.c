#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int rollno;
   char name[20];
   float marks;
} Student;

void parseInputString(const char *input, Student *student)
{
   const char *delimiter = " ";
   char *token;

   char *inputCopy = strdup(input);
   token = strtok(inputCopy, delimiter);

   if (token != NULL)
   {
      student->rollno = atoi(token);

      token = strtok(NULL, delimiter);
      strncpy(student->name, token, sizeof(student->name) - 1);
      student->name[sizeof(student->name) - 1] = '\0';

      token = strtok(NULL, delimiter);
      student->marks = atof(token);
   }

   free(inputCopy);
}

int main()
{
   int size;

   printf("Enter the number of students: ");
   scanf("%d", &size);
   getchar();

   Student *students = malloc(size * sizeof(Student));

   char input[100];
   for (int i = 0; i < size; i++)
   {
      printf("Enter student %d details (rollno name marks): ", i + 1);
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';

      parseInputString(input, &students[i]);
   }

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