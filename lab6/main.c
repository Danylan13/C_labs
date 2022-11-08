#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void title_page() {
  printf("\n┌────────────────────────────────────────────────────────────────────────────────────────────┐");
  printf("\n│                                  Laboratory work No8                                        │");
  printf("\n│                                                                                            │");
  printf("\n│                      Theme: 'Working with binary and text files'                           │");
  printf("\n│                                                                                            │");
  printf("\n│  Completed by Danyliuk Danylo, KM-13                                Lubashenko N.D.        │");
  printf("\n│                                                                                            │");
  printf("\n│                                                                                            │");
  printf("\n│                                         2022                                               │");
  printf("\n└────────────────────────────────────────────────────────────────────────────────────────────┘\n");
}

//First task
int check_file(FILE *file) {

    char buf[1000];
    if ((!file) || fgets(buf,1000, file) == NULL){
        printf("File is empty.\n");
        printf("--------------\n");
        return 1;}
    fseek(file, 0, SEEK_SET);
    return 0;
}

void first_line_size(char *name) {
    char first_str[1000];
    FILE *file;
    int size = 0;

    file = fopen(name, "r");
    fgets(first_str, 1000, file);
    fclose(file);

    for (int i = 0; i < strlen(first_str); i++) {
    if (first_str[i] == ' ' || first_str[i] == '\n')
      i = strlen(first_str);
    size++;
    }

    printf("--------------\n");
    printf("Amount of characters in the first word of F2 is %d.\n", size-1);
    printf("--------------\n");
}

void main_task1(FILE *ptr_file, char* file_name) {
    FILE *ptr_file_write;
    char name[30], buf[1000];
    fseek(ptr_file, 0, SEEK_SET);

    if (check_file(ptr_file))
        return;

    printf("Copying lines from F1 to the F2 file, except those starting with the letter 'A' and counting \namount of characters in the first word of F2.\n");
    printf("F1 - current file.\n");

    do {
        printf("Enter a name of file F2:\n-> ");
        scanf("%s", name);
        if (strcmp(name, file_name) == 0) printf("--------------\nThe F2 file cannot be the F1 file. Enter the name of another file.\n");
    } while(strcmp(name, file_name) == 0);

    ptr_file_write = fopen(name,"w");

    while (fgets(buf,1000, ptr_file)!=NULL) {
        if (buf[0] != 'A' && buf[0] != 'a') {
            fputs(buf, ptr_file_write);
        }
    }

    fclose(ptr_file_write);

    first_line_size(name);
}

char* create_file() {
    FILE *file;
    static char name[40];
    printf("Enter a name for a new file(format \"name.txt\"):\n-> ");
    scanf("%s", name);

    file = fopen(name,"w");
    fclose(file);

    return name;
}

char* open_file(){
    static char name[40];
    printf("Enter a file name to open(format \"name.txt\"):\n-> ");
    scanf("%s", name);

    return name;
}

int file_exist_check(char *name){
    if (access(name, F_OK) == 0 ) {
        return 1;
    }  // file exists
    else {
        printf("There isn't any file with such name. Try to create or open file again.\n");
        printf("--------------\n");
        return 0;
    }  // file doesn't exist
}

void view_file(FILE *file) {
    char current_line[1000], first_line[1000], last_line[1000];
    int choise, last_line_size;
    int stop = 1, position = 1, file_size = 1;

    fseek(file, 0, SEEK_SET);
    if (check_file(file)) {
        return;}

    fgets(first_line,1000, file);
    printf("Current line:\n%s", first_line);
    printf("--------------\n");

    while (fgets(last_line,1000, file)!=NULL) {
        last_line_size = strlen(last_line);
        file_size++;
    }
    fseek(file, strlen(first_line), SEEK_SET);

    while (stop != 0){
        printf("Select a function:\n");
        printf("(1) Flip forward;\n");
        printf("(2) Flip back;\n");
        printf("(3) Flip to the end of the file;\n");
        printf("(4) Flip to the beginning of the file;\n");
        printf("(0) Exit.\n-> ");
        scanf("%d", &choise);
        printf("--------------\n");

    if (choise == 1) {
        if (fgets(current_line,1000, file) == NULL) {
            printf("This is the last line of the file.\n");
            printf("Current line:\n%s\n", last_line);}
        else if(strcmp(current_line, last_line) == 0){
            printf("Current line:\n%s\n", last_line);
            position++;
        }
        else{
            printf("Current line:\n%s", current_line);
            position++;}
    }
    else if (choise == 2) {
        fseek(file, strlen(first_line), SEEK_SET);
        if(position > 2) {
            for (int i = 2; i != position; i++)
            fgets(current_line, 1000, file);
            printf("Current line:\n%s", current_line);
            position--;}
        else{
            printf("This is the first line of the file.\nCurrent line:\n%s", first_line);
            position = 1;
        }
    }
    else if (choise == 3) {
        fseek(file, last_line_size, SEEK_END);
        printf("Current line:\n%s\n", last_line);
        position = file_size;
    }
    else if (choise == 4) {
        fseek(file, strlen(first_line), SEEK_SET);
        printf("Current line:\n%s", first_line);
        position = 1;
    }
    else if (choise == 0)
        return;
    printf("--------------\n");
    }
}

int choose_position(FILE *file) {
    char current_line[1000], first_line[1000], last_line[1000];
    int choise, last_line_size;
    int stop = 1, position = 1, file_size = 1;

    fseek(file, 0, SEEK_SET);

    fgets(first_line,1000, file);
    printf("Current line:\n%s", first_line);
    printf("--------------\n");

    while (fgets(last_line,1000, file)!=NULL) {
        last_line_size = strlen(last_line);
        file_size++;}
    fseek(file, strlen(first_line), SEEK_SET);

    while (stop != 0) {
        printf("Select a function:\n");
        printf("(1) Flip forward;\n");
        printf("(2) Flip back;\n");
        printf("(3) Flip to the end of the file;\n");
        printf("(4) Flip to the beginning of the file;\n");
        printf("(0) Choose this line.\n-> ");
        scanf("%d", &choise);
        printf("--------------\n");

    if (choise == 1) {
        if (fgets(current_line,1000, file) == NULL) {
            printf("This is the last line of the file.\nCurrent line:\n%s\n", last_line);
            position = file_size;}
        else if(strcmp(current_line, last_line) == 0) {
            printf("Current line:\n%s\n", last_line);
            position++;}
        else {
            printf("Current line:\n%s", current_line);
            position++;}
        }
        else if (choise == 2) {
        fseek(file, 0, SEEK_SET);
        if(position > 1) {
            for (int i = 1; i != position; i++)
                fgets(current_line, 1000, file);
            printf("Current line:\n%s", current_line);
            position--;}
        else {
            printf("This is the first line of the file.\nCurrent line:\n%s", first_line);
            position = 1;
        }
    }
    else if (choise == 3) {
        fseek(file, last_line_size, SEEK_END);
        printf("Current line:\n%s\n", last_line);
        position = file_size;
    }
    else if (choise == 4) {
        fseek(file, strlen(first_line), SEEK_SET);
        printf("Current line:\n%s", first_line);
        position = 1;
    }
    else if (choise == 0) {
        fseek(file, 0, SEEK_SET);
        stop = 0;}
    if (stop != 0) printf("--------------\n");
  }
  return position;
}

FILE* delete_line(FILE *fptr1, char *name) {
    FILE *fptr2;
    char file2[] ="temp.txt";
    char curr;
    int del, line_number = 0;

    fseek(fptr1, 0, SEEK_SET);
    if (check_file(fptr1)) {
        return fptr1;}

    del = choose_position(fptr1);

    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);

    if(curr!=EOF) {line_number =1;}

    while(1) {
        if (del == 1 && line_number == 2 && curr =='\n') curr = getc(fptr1);
        if(del != line_number)
            putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }

    fclose(fptr1);
    fclose(fptr2);

    remove(name);
    rename("temp.txt", name);
    fptr1 = fopen(name, "a+");
    return fptr1;
}

void add_line(FILE *file, char* name) {
    char line[1000], c;

    printf("Enter a new line to add to the file:\n-> ");
    scanf("%s", line);
    int l = strlen(line);
    do {
        scanf("%c", &c);
        line[l++] = c;
    } while (c != '\n');
    line[l - 1] = 0;
    printf("--------------\n");

    fputs("\n", file);
    fputs(line, file);

    file = freopen(name, "a+", file);
}

FILE* edit_line(FILE *fptr1, char* name) {
    FILE *fptr2;
    char file2[] ="temp.txt";
    char curr;
    int add, line_number = 0;

    fseek(fptr1, 0, SEEK_SET);
    if (check_file(fptr1)){
        return fptr1;}

    add = choose_position(fptr1);

    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);

    if(curr!=EOF) {line_number =1;}

    char line[1000], c;
    printf("Enter an edited line:\n-> ");
    scanf("%s", line);
    int l = strlen(line);
    do {
        scanf("%c", &c);
        line[l++] = c;
    } while (c != '\n');
    line[l - 1] = 0;
    printf("--------------\n");
    while(1) {
        if(add != line_number)
            putc(curr, fptr2);

        curr = getc(fptr1);
        if(add == line_number) {
            if (add != 1) putc('\n', fptr2);
            fputs(line, fptr2);
            while(curr != '\n' && curr != EOF)
                curr = getc(fptr1);}

        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }

    fclose(fptr1);
    fclose(fptr2);

    remove(name);
    rename("temp.txt", name);
    fptr1 = fopen(name, "a+");
    return fptr1;
}

FILE* file_correction(FILE *file, char *name) {
    int choise;
    int exit = 1;
    fseek(file, 0, SEEK_SET);

    printf("Select a function:\n");
    printf("(1) Adding a line;\n");
    printf("(2) Editing a line;\n");
    printf("(3) Deleting a line;\n");
    printf("(0) Exit.\n-> ");
    scanf("%d", &choise);
    printf("--------------\n");

    if (choise == 1)
        add_line(file, name);
    else if (choise == 2)
        file = edit_line(file, name);
    else if (choise == 3)
        file = delete_line(file, name);
    else if (choise == 0)
        exit = 0;
    return file;
}

void save_file(FILE *file1, char* name1) {
    FILE *file2;
    char name[40], buf[1000];

    printf("Enter a name for a new file(format \"name.txt\"):\n-> ");
    scanf("%s", name);
    while (strcmp(name, name1) == 0) {
        printf("The new file name can't be the same as the working file name. Enter another name:\n-> ");
        scanf("%s", name);}
    printf("--------------\n");

    file2 = fopen(name,"w");

    fseek(file1, 0, SEEK_SET);
    while (fgets(buf,1000, file1)!=NULL){
        fputs(buf, file2);}

    fclose(file2);
}

void close_file(FILE *file) {
  fclose(file);
}

void first_task() {
    int choise;
    FILE *file;
    char *name;
    int status = 0;
    int exit = 1;

    while (status != 1) {
        printf("Select the file presentation way:\n");
        printf("(1) Create a new file;\n");
        printf("(2) Open file.\n-> ");
        scanf("%d", &choise);
        printf("--------------\n");

        if (choise == 1)
            name = create_file();
        else if (choise == 2)
            name = open_file();
        printf("--------------\n");

        status = file_exist_check(name);
    }

    file = fopen(name, "a+");

    while (exit != 0) {
        int choise2;
        printf("Select a task to run:\n");
        printf("(1) File view;\n");
        printf("(2) File correction;\n");
        printf("(3) Main task;\n");
        printf("(4) Save file as;\n");
        printf("(0) Save and close file.\n-> ");
        scanf("%d", &choise2);
        printf("--------------\n");

        if (choise2 == 1)
            view_file(file);
        else if (choise2 == 2)
            file = file_correction(file, name);
        else if (choise2 == 3)
            main_task1(file, name);
        else if (choise2 == 4)
            save_file(file, name);
        else if (choise2 == 0){
            close_file(file);
            exit = 0;}
    }
}

//Second task
typedef struct {
    char name[100];
    char position[100];
    int year;
    int wage;
    int status;
} worker;

char* create_binary_file() {
    FILE *file;
    static char name[40];
    printf("Enter a name for a new file(format \"name.dat\"):\n-> ");
    scanf("%s", name);

    file = fopen(name,"wb");
    fclose(file);

    return name;
}

char* open_binary_file() {
    static char name[40];
    printf("Enter a file name to open(format \"name.dat\"):\n-> ");
    scanf("%s", name);

    return name;
}

void view_binary_file(FILE* fp) {
    int i = 1;
    int choise;
    int n = 0;
    worker t1;
    fread(&t1, sizeof(t1), 1, fp);

    printf("Select data to view:\n");
    printf("(1) Active enteries;\n");
    printf("(2) Marked as deleted.\n-> ");
    scanf("%d", &choise);
    printf("--------------\n");

    if (choise == 2)
        n = 1;

    while (!feof(fp)) {
        if (t1.status == n){
            if (choise != 3){
                printf("%12s %16s %13s %10s %9s\n", "Surname", "Position", "Year", "Wage", "Status");
                choise = 3;}
            printf("%d)", i);
            printf("%-20s", t1.name);
            printf("%-17s", t1.position);
            printf("%-11d", t1.year);
            printf("%-10d", t1.wage);
            printf("%d\n", t1.status);
            i++;
        }
        fread(&t1, sizeof(t1), 1, fp);
    }

    if (i == 1){
        if (n == 0)
            printf("There are no active structures (with status %d).\n", n);
        else
            printf("There are no deleted structures (with status %d).\n", n);}

    getchar();
    printf("--------------\n");
    fseek(fp, 0, SEEK_SET);
}

FILE* add_binary_structure(FILE* fp, char *name) {
    char ch;
    printf("Entering data:\n");
    worker t1;

    do{
        printf("Surname: ");
        scanf("%s", t1.name);
        printf("Position: ");
        scanf("%s", t1.position);
        printf("Birthday year: ");
        scanf("%d", &t1.year);
        printf("Wage: ");
        scanf("%d", &t1.wage);
        t1.status = 0;

        fwrite(&t1, sizeof(worker), 1, fp);
        printf("Continue? (Y/N)\n-> ");
        scanf("%c", &ch);
        printf("--------------\n");
    } while(ch != 'N');

    fclose(fp);
    fp = fopen(name, "ab+");
    return fp;
}

int choose_binary_position(FILE* fp, int n) {
    int position;
    int i = 1;
    int choise = 0;
    worker t1;
    fread(&t1, sizeof(t1), 1, fp);

    while (!feof(fp)) {
        if (t1.status == n){
            if (choise != 3){
            printf("%12s %16s %13s %10s %9s\n", "Surname", "Position", "Year", "Wage", "Status");
            choise = 3;}
            printf("%d)", i);
            printf("%-20s", t1.name);
            printf("%-17s", t1.position);
            printf("%-11d", t1.year);
            printf("%-10d", t1.wage);
            printf("%d\n", t1.status);
            i++;
        }
        fread(&t1, sizeof(t1), 1, fp);
    }

    printf("--------------\n");
    printf("Select a position number of the structure:\n-> ");
    scanf("%d", &position);

    getchar();
    printf("--------------\n");
    fseek(fp, 0, SEEK_SET);
    return choise;
}

int check_active_structures(FILE* file, char *name) {
    worker t1;
    fseek(file, 0, SEEK_SET);

    fread(&t1, sizeof(t1), 1, file);
    while (!feof(file)){
        if (t1.status == 0){
            fseek(file, 0, SEEK_SET);
            return 1;}
        fread(&t1, sizeof(t1), 1, file);}
    fseek(file, 0, SEEK_SET);
    printf("There are no active structures.\n--------------\n");
    return 0;
}

int check_deleted_structures(FILE* file, char *name) {
    worker t1;
    fseek(file, 0, SEEK_SET);

    fread(&t1, sizeof(t1), 1, file);
    while (!feof(file)){
        if (t1.status == 1){
            fseek(file, 0, SEEK_SET);
            return 1;}
    fread(&t1, sizeof(t1), 1, file);}
    printf("There are no structures to recover.\n--------------\n");
    fseek(file, 0, SEEK_SET);
    return 0;
}

FILE* delete_binary_structure(FILE* fptr1, char *name) {
    FILE *fptr2;
    char file2[] ="temp.dat";
    worker t1;
    int del, count = 0;

    if (fptr1 == NULL) {
        printf("File not found.\n");
        return NULL;
    }

    del = choose_binary_position(fptr1, 0);

    fptr2 = fopen(file2, "wb");
    fread(&t1, sizeof(t1), 1, fptr1);
    if (t1.status == 0)
        count = 1;

    while(!feof(fptr1)){
        if (del == count && t1.status == 0)
            t1.status = 1;

        fwrite(&t1, sizeof(worker), 1, fptr2);

        fread(&t1, sizeof(t1), 1, fptr1);
        if (t1.status == 0)
            count++;
    }

    fclose(fptr1);
    fclose(fptr2);

    remove(name);
    rename("temp.dat", name);
    fptr1 = fopen(name, "ab+");
    return fptr1;
}

FILE* recover_binary_structure(FILE* fptr1, char *name) {
    FILE *fptr2;
    char file2[] ="temp.dat";
    worker t1;
    int rec, count = 0;

    if (check_deleted_structures(fptr1, name) == 0)
        return fptr1;

    rec = choose_binary_position(fptr1, 1);

    fptr2 = fopen(file2, "wb");
    fread(&t1, sizeof(t1), 1, fptr1);
    if (t1.status == 1)
        count = 1;

    while(!feof(fptr1)){
        if (rec == count && t1.status == 1)
            t1.status = 0;

        fwrite(&t1, sizeof(worker), 1, fptr2);

        fread(&t1, sizeof(t1), 1, fptr1);
        if (t1.status == 1)
            count++;
    }

    fclose(fptr1);
    fclose(fptr2);

    remove(name);
    rename("temp.dat", name);
    fptr1 = fopen(name, "ab+");
    return fptr1;
}

FILE* binary_file_correction(FILE* file, char *name){
    int choise;
    fseek(file, 0, SEEK_SET);

    printf("Select a function:\n");
    printf("(1) Adding a structure;\n");
    printf("(2) Deleting a structure;\n");
    printf("(3) Recovering deleted structure;\n");
    printf("(0) Exit.\n-> ");
    scanf("%d", &choise);
    printf("--------------\n");

    if (choise == 1)
        add_binary_structure(file, name);
    else if (choise == 2)
        file = delete_binary_structure(file, name);
    else if (choise == 3)
        file = recover_binary_structure(file, name);
    return file;
}

FILE* save_binary_file(FILE* file, char* name){
    int choise, i = 0;
    printf("Select a way to save the file:\n");
    printf("(1) Structures marked as deleted will be discarded;\n");
    printf("(2) All structures with statuses will be saved.\n-> ");
    scanf("%d", &choise);
    printf("--------------\n");
    fseek(file, 0, SEEK_SET);

    if(choise == 1){
        FILE *fptr2;
    char file2[] ="temp.dat";
        worker t1;;

    fptr2 = fopen(file2, "wb+");
    fread(&t1, sizeof(t1), 1, file);
    while (t1.status == 1 && !feof(file)){
      i++;
      fread(&t1, sizeof(t1), 1, file);}

    while(!feof(file)){
      i++;
      fwrite(&t1, sizeof(worker), 1, fptr2);
      fread(&t1, sizeof(t1), 1, file);
      while (t1.status == 1 && !feof(file))
        fread(&t1, sizeof(t1), 1, file);
    }

    fclose(file);
    fclose(fptr2);

    remove(name);
    rename("temp.dat", name);
    file = fopen(name, "ab+");
  }

  if (i == 0 && choise == 1)
    printf("File is empty.\n--------------\n");
  return file;
}

FILE* save_binary_file_as(FILE *file1, char* name1) {
    FILE *file2;
    char name[40], buf[1000];

    printf("Enter a name for a new file(format \"name.dat\"):\n-> ");
    scanf("%s", name);
    while (strcmp(name, name1) == 0){
        printf("The new file name can't be the same as the working file name. Enter another name:\n-> ");
        scanf("%s", name);}
    printf("--------------\n");

    file2 = fopen(name,"wb+");
    fseek(file1, 0, SEEK_SET);

    int choise;
    worker t1;;
    printf("Select a way to save the file:\n");
    printf("(1) Structures marked as deleted will be discarded;\n");
    printf("(2) All structures with statuses will be saved.\n-> ");
    scanf("%d", &choise);
    printf("--------------\n");

    if(choise == 1){

        fread(&t1, sizeof(t1), 1, file1);
        while (t1.status == 1 && !feof(file1)){
            fread(&t1, sizeof(t1), 1, file1);}

        while(!feof(file1)){
        fwrite(&t1, sizeof(worker), 1, file2);
        fread(&t1, sizeof(t1), 1, file1);
        while (t1.status == 1 && !feof(file1))
            fread(&t1, sizeof(t1), 1, file1);
        }

        fclose(file1);
        fclose(file2);

        file1 = fopen(name1, "ab+");
        return file1;
    }

    fread(&t1, sizeof(t1), 1, file1);
    while(!feof(file1)){
        fwrite(&t1, sizeof(worker), 1, file2);
        fread(&t1, sizeof(t1), 1, file1);
    }

    fclose(file1);
    fclose(file2);
    file1 = fopen(name1, "ab+");
    return file1;
}

void choose_binary_surname(FILE* fp, char *surname) {
    int position, i = 1;
    worker t1;
    fseek(fp, 0, SEEK_SET);
    fread(&t1, sizeof(t1), 1, fp);

    printf("%12s %16s %13s %10s %9s\n", "Surname", "Position", "Year", "Wage", "Status");
    while (!feof(fp)) {
        if (t1.status == 0) {
            printf("%d)", i);
            printf("%-20s", t1.name);
            printf("%-17s", t1.position);
            printf("%-11d", t1.year);
            printf("%-10d", t1.wage);
            printf("%d\n", t1.status);
            i++;
        }
        fread(&t1, sizeof(t1), 1, fp);
    }

    printf("--------------\n");
    printf("Enter a surname to delete the structure that contains it:\n-> ");
    scanf("%s", surname);

    printf("--------------\n");
    fseek(fp, 0, SEEK_SET);
}

FILE* delete_structure_by_surname(FILE *file, char* name) {
    FILE *fptr2;
    char file2[] ="temp.dat";
    static char surname[30];
    worker t1;
    int count = 0;

    if (check_active_structures(file, name) == 0)
        return file;

    choose_binary_surname(file, surname);

    fptr2 = fopen(file2, "wb");
    fread(&t1, sizeof(t1), 1, file);

    while(!feof(file)){
        if (strcmp(t1.name, surname) == 0)
            t1.status = 1;
        fwrite(&t1, sizeof(worker), 1, fptr2);
        fread(&t1, sizeof(t1), 1, file);
    }

    fclose(file);
    fclose(fptr2);

    remove(name);
    rename("temp.dat", name);
    file = fopen(name, "ab+");
    return file;
}

FILE* add_structure_after_number(FILE* file, char *name) {
    int position;

    if (check_active_structures(file, name) == 0)
        return file;
    position = choose_binary_position(file, 0);

    char ch;
    printf("Entering data:\n");
    worker t2;

    printf("Surname: ");
    scanf("%s", t2.name);
    printf("Position: ");
    scanf("%s", t2.position);
    printf("Birthday year: ");
    scanf("%d", &t2.year);
    printf("Wage: ");
    scanf("%d", &t2.wage);
    t2.status = 0;
    printf("--------------\n");

    FILE *fptr2;
    char file2[] ="temp.dat";
    worker t1;
    int del, count = 0;

    fptr2 = fopen(file2, "wb");
    fread(&t1, sizeof(t1), 1, file);
    if (t1.status == 0)
        count = 1;

    while(!feof(file)) {
        if (position == count && t1.status == 0) {
            fwrite(&t1, sizeof(worker), 1, fptr2);
            fwrite(&t2, sizeof(worker), 1, fptr2);}
        else
            fwrite(&t1, sizeof(worker), 1, fptr2);

        fread(&t1, sizeof(t1), 1, file);
        if (t1.status == 0)
            count++;
    }

    fclose(file);
    fclose(fptr2);

    remove(name);
    rename("temp.dat", name);
    file = fopen(name, "ab+");
    return file;
}

void second_task() {
    int choise;
    FILE *file;
    char *name;
    int status = 0, exit = 1;

    while (status != 1) {
        printf("Select the file presentation way:\n");
        printf("(1) Create a new file;\n");
        printf("(2) Open file.\n-> ");
        scanf("%d", &choise);
        printf("--------------\n");

        if (choise == 1)
            name = create_binary_file();
        else if (choise == 2)
            name = open_binary_file();
        printf("--------------\n");

        status = file_exist_check(name);
    }

    file = fopen(name, "ab+");

    while (exit != 0) {
        int choise2;
        printf("Select a task to run:\n");
        printf("(1) File view;\n");
        printf("(2) File correction;\n");
        printf("(3) Save file;\n");
        printf("(4) Save file as;\n");
        printf("(5) Delete the element with the specified surname;\n");
        printf("(6) Add element after element with the specified number;\n");
        printf("(0) Close file.\n-> ");
        scanf("%d", &choise2);
        printf("--------------\n");

        if (choise2 == 1)
            view_binary_file(file);
        else if (choise2 == 2)
            file = binary_file_correction(file, name);
        else if (choise2 == 3)
            file = save_binary_file(file, name);
        else if (choise2 == 4)
            file = save_binary_file_as(file, name);
        else if (choise2 == 5)
            file = delete_structure_by_surname(file, name);
        else if (choise2 == 6)
            file = add_structure_after_number(file, name);
        else if (choise2 == 0){
            close_file(file);
            exit = 0;}
    }
}

void menu() {
    printf("--------------\n");
    printf ("What task do you want to run? (1-2) \n");
    printf ("1 - Lines from F1, except those starting with the letter 'A', will be copied to the F2 file. \nAmount of characters in the first word of F2 will be counted.\n");
    printf ("2 - Entering structure WORKER data into the binary file. Deleting structure by surname. Adding \nstructure after structure with specified position number.\n");
    printf("--------------\n-> ");

    int task;
    scanf("%d", &task);
    printf("--------------\n");
    if (task == 1){
        first_task();
    }
    else if (task == 2){
        second_task();
    }

    char end;
    printf("Do you want to try again?(Y/N)\n-> ");
    scanf("%s", &end);
    if (end == 'Y'){
        menu();
    }
    else if (end == 'N'){
        exit(0);
    }
}

int main() {
    title_page();
    menu();
}
