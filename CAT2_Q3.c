/*

Name:Samuel nganga 
Reg no:CT100/G/26223/25
Description:A program that reads a list of integers from a file,process them and write the results to a different file
*/
#include <stdio.h>
#include <stdlib.h>

void writeInputFile();
void calculateAndWrite();
void displayFiles();

int main() {
    writeInputFile();
    calculateAndWrite();
    displayFiles();
    return 0;
}

// 1. Write 10 integers to input.txt
void writeInputFile() {
    FILE *fp;
    int num, i;

    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open input.txt for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }

    fclose(fp);
    printf("Data successfully written to input.txt\n\n");
}

// 2. Read integers, calculate sum & average, write to output.txt
void calculateAndWrite() {
    FILE *in, *out;
    int num, sum = 0, count = 0;
    float avg;

    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: Cannot open input.txt for reading.\n");
        exit(1);
    }

    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Cannot open output.txt for writing.\n");
        fclose(in);
        exit(1);
    }

    while (fscanf(in, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    avg = (float)sum / count;

    fprintf(out, "Sum = %d\n", sum);
    fprintf(out, "Average = %.2f\n", avg);

    fclose(in);
    fclose(out);

    printf("Sum & average written to output.txt\n\n");
}

// 3. Display contents of both files
void displayFiles() {
    FILE *fp;
    char ch;

    // Display input.txt
    printf("📂 Contents of input.txt:\n");
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input.txt\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    // Display output.txt
    printf("\n\n📂 Contents of output.txt:\n");
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error opening output.txt\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    printf("\n");
}