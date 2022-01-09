//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define MAXSIZE 8
//
//struct Record
//{
//    int id;
//    char firstName[31];
//    char lastName[31];
//    char cellPhone[11];
//};
//
//int main(void)
//{
//    struct Record record[MAXSIZE];
//    int numberOfRecords = 0;
//
//    FILE *fp = NULL;
//    int i = 0;
//
//    fp = fopen("myData.txt", "r");
//
//    if (fp != NULL)
//    {
//        while (fp != EOF && i < MAXSIZE)
//        {
//            fscanf(fp, "%s %s %s", record[i].firstName, record[i].lastName, record[i].cellPhone);
//            record[i].id = i + 1;
//            numberOfRecords++;
//            i++;
//        }
//        fp = fopen("myData.txt", "w");
//
//        for (i = 0; i < numberOfRecords; i++)
//        {
//            fprintf(fp, "%d %s %s %s\n", record[i].id, record[i].firstName, record[i].lastName, record[i].cellPhone);
//        }
//        fclose(fp);
//    }
//    
//    return 0;
//}