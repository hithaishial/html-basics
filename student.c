#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct Student { 
int id; 
char name[50]; 
char dept[20]; 
int marks; 
}; 
struct Student *students = NULL; 
int count = 0; 
void addStudent() { 
    students = realloc(students, (count + 1) * sizeof(struct Student)); 
    printf("Enter ID: "); 
    scanf("%d", &students[count].id); 
    printf("Enter Name: "); 
    scanf("%s", students[count].name); 
    printf("Enter Department: "); 
    scanf("%s", students[count].dept); 
    printf("Enter Marks: "); 
    scanf("%d", &students[count].marks); 
    count++; 
    printf("Student added successfully!\n"); 
} 
 
void deleteStudent(int id) { 
    int i, found = 0; 
    for(i = 0; i < count; i++) { 
        if(students[i].id == id) { 
            found = 1; 
            for(int j = i; j < count - 1; j++) { 
                students[j] = students[j+1]; 
            } 
            count--; 
            students = realloc(students, count * sizeof(struct Student)); 
            printf("Student deleted successfully!\n"); 
            break; 
        } 
    } 
    if(!found) printf("Student not found!\n"); 
} 
 
void searchStudentByID(int id) { 
    for(int i = 0; i < count; i++) { 
        if(students[i].id == id) { 
            printf("Found: %d %s %s %d\n", students[i].id, students[i].name, 
students[i].dept, students[i].marks); 
            return; 
        } 
    } 
    printf("Student not found!\n"); 
} 
 
void searchStudentByName(char name[]) { 
    for(int i = 0; i < count; i++) { 
        if(strcmp(students[i].name, name) == 0) { 
            printf("Found: %d %s %s %d\n", students[i].id, students[i].name, 
students[i].dept, students[i].marks); 
            return; 
        } 
    } 
    printf("Student not found!\n"); 
} 
 
void displayByDepartment(char dept[]) { 
    printf("Students in %s department:\n", dept); 
    for(int i = 0; i < count; i++) { 
        if(strcmp(students[i].dept, dept) == 0) { 
            printf("%d %s %s %d\n", students[i].id, students[i].name, 
students[i].dept, students[i].marks); 
        } 
    } 
} 
 
void updateMarks(int id, int newMarks) { 
    for(int i = 0; i < count; i++) { 
        if(students[i].id == id) { 
            students[i].marks = newMarks; 
            printf("Marks updated successfully!\n"); 
            return; 
        } 
    } 
    printf("Student not found!\n"); 
} 
 
void displayAllStudents() { 
    printf("All Students:\n"); 
    for(int i = 0; i < count; i++) { 
printf("%d 
%s 
%s %d\n", students[i].id, students[i].name, 
students[i].dept, students[i].marks); 
} 
} 
void saveToFile() { 
FILE *fp = fopen("students.txt", "w"); 
if(fp == NULL) { 
printf("Error opening file!\n"); 
return; 
} 
for(int i = 0; i < count; i++) { 
fprintf(fp, "%d %s %s %d\n", students[i].id, students[i].name, 
students[i].dept, students[i].marks); 
} 
fclose(fp); 
printf("Data saved to file successfully!\n"); 
} 
void loadFromFile() { 
FILE *fp = fopen("students.txt", "r"); 
if(fp == NULL) { 
printf("No existing file found.\n"); 
return; 
} 
while(!feof(fp)) { 
        students = realloc(students, (count + 1) * sizeof(struct Student)); 
        if(fscanf(fp, "%d %s %s %d", &students[count].id, 
students[count].name, students[count].dept, &students[count].marks) == 4) 
{ 
            count++; 
        } 
    } 
    fclose(fp); 
    printf("Data loaded from file successfully!\n"); 
} 
 
int main() { 
    int choice, id, marks; 
    char name[50], dept[20]; 
    loadFromFile(); 
    while(1) { 
        printf("\n--- Student Record Management ---\n"); 
        printf("1. Add Student\n2. Delete Student\n3. Search by ID\n4. Search 
by Name\n5. Display by Department\n6. Update Marks\n7. Display All\n8. 
Save & Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
        switch(choice) { 
            case 1: addStudent(); break; 
            case 2: printf("Enter ID to delete: "); scanf("%d", &id); 
deleteStudent(id); break; 
            case 3: printf("Enter ID to search: "); scanf("%d", &id); 
searchStudentByID(id); break; 
case 4: printf("Enter Name to search: "); scanf("%s", name); 
searchStudentByName(name); break; 
case 5: printf("Enter Department: "); scanf("%s", dept); 
displayByDepartment(dept); break; 
case 6: printf("Enter ID to update marks: "); scanf("%d", &id); 
printf("Enter new marks: "); scanf("%d", &marks); updateMarks(id, marks); 
break; 
case 7: displayAllStudents(); break; 
case 8: saveToFile(); free(students); return 0; 
default: printf("Invalid choice!\n");  
} 
} 
} 
2