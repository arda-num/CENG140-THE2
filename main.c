#include "functions.h"

/*
You will not submit this file, just use for testing your code.
All your implementations should be in functions.c
*/

/*
To compile your code, use "make main"
Then "./main" to run.
If you want to compile again, you need to delete the previous executable.
You may do this by "make clean" or simply "rm main"
*/

int main(){

    /*
    Function calls here to test your code
    Example:
    float ***sector_times, **laptimes;
    unsigned int fastest_lap, **positions;
    sector_times = create_sector_times(...);
    positions = create_positions(...);
    lap_times = calculate_lap_times(...);
    fastest_lap = find_fastest_lap(lap_times, ...);
    printf("Printing fastest lap to check the answer: %d\n", fastest_lap);
    */
    int loop1,loop2,loop3;
    unsigned int a,b,c;
    int den1 = 4, den2 = 3;
    float *** arr;
    float** arr2;
    float* arr3;
    float *ar;
    /*
    float ar[25] = {23.29,47.08,52.05,53.76,73.00,68.35 ,36.91, 49.09, 99.94, 82.04, 23.42, 52.26, 57.25, 17.45, 47.09, 94.90, 47.76, 7.69, 31.38, 89.56 ,71.96 ,29.58 ,49.24 ,86.71, 77.50 };
    /*
    unsigned int* arr4;
    unsigned int** arrr;
    /*
    arrr = create_positions(&a,&b);
    arr4 = calculate_total_points(arrr, 2, 3);

    for(loop1=0;loop1<2;loop1++)
    {
        printf("%u ",arr4[loop1]);
    }
    printf("-------------\n");
    c = find_season_ranking(arr4, 2, 0);
    printf("--%u--",c);
    
    arr = create_sector_times(&a,&b);
    for(loop1=0;loop1<den1;loop1++)
    {
        for(loop2=0;loop2<den2;loop2++)
        {
            for(loop3=0;loop3<3;loop3++)
            {
                printf("%f ",arr[loop1][loop2][loop3]);
            }
            printf("\n");
        }
    }
    printf("--------------\n");
    arr2 = calculate_lap_times(arr,2,3);
    
    
    
   
    
    for(loop1=0;loop1<den1;loop1++)
    {
        for(loop2=0;loop2<den2;loop2++)
        {
            printf("%f ",arr2[loop1][loop2]);
        }
        printf("\n");
    }
    
    printf("--------------\n");
    
    printf("%u",find_driver_fastest_lap(arr2, 2));
    
    printf("--------------\n");
    c = find_fastest_lap(arr2, 2, 3);
    printf("%u\n",c);
    
*/
    ar = (float*)malloc(sizeof(float)*25);

    for(loop1=0;loop1<25;loop1++)
    {
        ar[loop1] = 25-loop1;
    }

    for(loop2=0;loop2<100;loop2++)
    {
        printf("--%d--\n",loop2);
    arr3 = selection_sort(ar, 25, 'A');
    for(loop1=0;loop1<25;loop1++)
    {
        printf("%.2f ",arr3[loop1]);
    }
    printf("\n");
    arr3 = selection_sort(ar, 25, 'D');
    for(loop1=0;loop1<25;loop1++)
    {
        printf("%.2f ",arr3[loop1]);
    }
    printf("\n");
    
    }
    
    /*
    arr4 = find_finishing_positions(arr2, 4, 3);
    for(loop1=0;loop1<4;loop1++)
    {
        printf("%u ",arr4[loop1]);
    }
    printf("-------------\n");
    
    arr3 = find_time_diff(arr2, 4, 3, 0,1);
    for(loop1=0;loop1<3;loop1++)
    {
        printf("%f ",arr3[loop1]);
    }
    printf("-------------\n");

*/
    return 0;
}
