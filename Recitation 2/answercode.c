#include <stdio.h>

typedef struct Student
{
int id;
float gpa;
} Student;

void printGpas(Student**, int);

int main(int argc, char** argv)
{
        Student alice;
        alice.id = 12345;
        alice.gpa = 4.0;

        Student bob;
        bob.id = 55555;
        bob.gpa = 3.75;

        Student* studs[2] = {&alice, &bob};

        printGpas(studs,2);
}

void printGpas(Student** studs, int num)
{
        int i = 0;
        for(i = 0; i < num; i++)
        {
                float gpa = studs[i]->gpa;
                printf("%.2f\n", gpa);
        }

}

