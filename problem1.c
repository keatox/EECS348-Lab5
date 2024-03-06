#include <stdio.h>
#include <string.h>

int salesReport(float sales[],char months[][10]){
    FILE* ptr;
    ptr = fopen("salesreport.tsv", "w");
    fprintf(ptr,"Monthly sales report for 2022:\n");
    fprintf(ptr,"Month\tSales\n");
    for (int i = 0;i<12;i++){
        fprintf(ptr,"%s\t$%.2f\n",months[i],sales[i]);
    }
    fclose(ptr);
    return 0;
}

int salesSummary(float sales[],char months[][10]){
    float sum = 0;
    int maxIndex = 0;
    int minIndex = 0;
    FILE* ptr;
    ptr = fopen("salessummary.tsv", "w");
    for (int i = 0;i<12;i++){
        sum += sales[i];
        if (sales[i] < sales[minIndex]){
            minIndex = i;
        } 
        if (sales[i] > sales[maxIndex]){
            maxIndex = i;
        }
    }
    fprintf(ptr,"Sales summary:\n");
    fprintf(ptr,"Minimum sales:\t$%.2f\t(%s)\n",sales[minIndex],months[minIndex]);
    fprintf(ptr,"Maximum sales:\t$%.2f\t(%s)\n",sales[maxIndex],months[maxIndex]);
    fprintf(ptr,"Average sales:\t$%.2f\n",sum/12);
    fclose(ptr);
    return 0;
}

int movingReport(float sales[],char months[][10]){
    FILE* ptr;
    ptr = fopen("movingaverage.tsv", "w");
    fprintf(ptr,"Six-Month Moving Average Report:\n");
    for (int i = 0;i<7;i++){
        float total = 0;
        for (int j = i;j<i+6;j++){
            total += sales[j];
        }
        fprintf(ptr,"%s - %s\t$%.2f\n",months[i],months[i+5],total/6);
    }
    fclose(ptr);
    return 0;
}

int orderedReport(float sales[],char months[][10],int len){
    FILE* ptr;
    ptr = fopen("orderedreport.tsv", "w");
    fprintf(ptr,"Sales Report (Highest to Lowest):\n");
    fprintf(ptr,"Month\tSales\n");
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (sales[j] > sales[j+1]) {
                int temp = sales[j];
                sales[j] = sales[j+1];
                sales[j+1] = temp;
                char temp2[10];
                strcpy(temp2, months[j]);
                strcpy(months[j],months[j+1]);
                strcpy(months[j+1],temp2);
            }
        }
    }
    for (int i = 11;i>=0;i--){
        fprintf(ptr,"%s\t$%.2f\n",months[i],sales[i]);
    }
    fclose(ptr);
    return 0;
}

int main(){
    float sales[12];
    char months[][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    FILE* ptr;
    ptr = fopen("sales.txt", "r");
    for (int i = 0;i<12;i++){
        fscanf(ptr,"%f",&sales[i]);
    }
    fclose(ptr);

    salesReport(sales,months);
    salesSummary(sales,months);
    movingReport(sales,months);
    int len = sizeof(sales)/sizeof(sales[0]);
    orderedReport(sales,months,len);
    return 0;
}


