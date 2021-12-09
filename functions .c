#include <stdlib.h>
#include <stdio.h>

#define n_sector 3
#define epsilon 0.0001

/* Fill in the functions and define helper functions if you need to */

float*** create_sector_times(unsigned int* n_drivers, unsigned int* n_laps)
{
    int loop1,loop2,loop3;
    float*** sector_times;
    float temp;
    
    scanf(" %u",n_drivers);
    scanf(" %u",n_laps);
    sector_times = (float***)malloc(sizeof(float**)*(*n_drivers));
    for(loop1=0;loop1<*n_drivers;loop1++)
    {
        sector_times[loop1] = (float**)malloc(sizeof(float*)*(*n_laps)); 
        for(loop2=0;loop2<*n_laps;loop2++)
        {
            sector_times[loop1][loop2] = (float*)malloc(sizeof(float)*3);
        }
    }
    
    for(loop1=0;loop1<*n_drivers;loop1++)
    {
        
        for(loop2=0;loop2<*n_laps;loop2++)
        {
            
            for(loop3=0;loop3<3;loop3++)
            {
                scanf(" %f",&temp);
                sector_times[loop1][loop2][loop3] = temp;
            }
        }
    }
    return sector_times;
}


unsigned int** create_positions(unsigned int* p_drivers, unsigned int* n_races)
{
    int loop1,loop2;
    unsigned int **positions;
    unsigned int temp;
    scanf(" %u",p_drivers);
    scanf(" %u",n_races);
    positions = (unsigned int**)malloc(sizeof(unsigned int*)*(*p_drivers));
    for(loop1=0;loop1<*p_drivers;loop1++)
    {
        positions[loop1] = (unsigned int*)malloc(sizeof(unsigned int)*(*n_races));
    }

    for(loop1=0;loop1<*p_drivers;loop1++)
    {
        for(loop2=0;loop2<*n_races;loop2++)
        {
            scanf(" %u",&temp);
            positions[loop1][loop2] = temp;
        }
    }
    return positions;
}


float** calculate_lap_times(float*** sector_times, unsigned int n_drivers, unsigned int n_laps)
{
    int loop1,loop2,loop3;
    float sum;
    float** arr;
    
    arr = (float**)malloc(sizeof(float*)*n_drivers);
    for(loop1=0;loop1<n_drivers;loop1++)
    {
        arr[loop1] = (float*)malloc(sizeof(float)*n_laps);
    }
    
    for(loop1=0;loop1<n_drivers;loop1++)
    {
        for(loop2=0;loop2<n_laps;loop2++)
        {
            sum = 0;
            for(loop3=0;loop3<3;loop3++)
            {
                sum += sector_times[loop1][loop2][loop3];
            }
            arr[loop1][loop2] = sum;
        }
    }
    return arr;
}


unsigned int find_fastest_lap(float** lap_times, unsigned int n_drivers, unsigned int n_laps)
{
    int loop1,loop2,controller=1;
    unsigned int fastest_id;
    float fastest_lap;
    
    for(loop1=0;loop1<n_drivers;loop1++)
    {
        for(loop2=0;loop2<n_laps;loop2++)
        {
            if(controller)
            {
                controller = 0;
                fastest_id = loop1;
                fastest_lap = lap_times[loop1][loop2];
            }
            else
            {
                if(epsilon < fastest_lap - lap_times[loop1][loop2])
                {
                    fastest_id = loop1;
                    fastest_lap = lap_times[loop1][loop2];
                }
            }
        }
    }
    return fastest_id;
}


unsigned int find_driver_fastest_lap(float** sector_times_of_driver, unsigned int n_laps)
{
    int loop1,loop2,controller=1;
    unsigned int fastest_lap_no;
    float fastest_lap,sum;

    for(loop1=0;loop1<n_laps;loop1++)
    {
        sum = 0;
        if(controller)
        {
            controller = 0;
            for(loop2=0;loop2<3;loop2++)
            {
                sum += sector_times_of_driver[loop1][loop2];
            }
            fastest_lap_no = loop1;
            fastest_lap = sum;
        }
        else
        {
            for(loop2=0;loop2<3;loop2++)
            {
                sum += sector_times_of_driver[loop1][loop2];
            }
            if(epsilon < fastest_lap - sum)
            {
                fastest_lap = sum;
                fastest_lap_no = loop1;
            }
        }
    }
    return fastest_lap_no;
}


float* selection_sort(float* arr, unsigned int len, char ord)
{
    float *copy_arr;
    int loop1,loop2;
    float temp;
    

    copy_arr = (float*)malloc(sizeof(float)*len);
    for(loop1=0;loop1<len;loop1++)
    {
        copy_arr[loop1] = arr[loop1];
    }
    
    switch(ord)
    {
        case 'A':
        {
            int current_index=0,current_minimum=0,sorted_arr=0;

            while(sorted_arr < len-1)
            {
                while(current_index < len)
                {
                    if(copy_arr[current_index] < copy_arr[current_minimum])
                    {
                        current_minimum = current_index;
                    }
                    current_index++;
                }
                temp = copy_arr[sorted_arr];
                
                copy_arr[sorted_arr] = copy_arr[current_minimum];
                copy_arr[current_minimum] = temp;
                sorted_arr++;
                current_index = sorted_arr;
                current_minimum = sorted_arr;
            }
            break;
        }
        case 'D':
        {
            int current_index=0,current_maximum=0,sorted_arr=0;

            while(sorted_arr < len-1)
            {
                while(current_index < len)
                {
                    if(copy_arr[current_index] > copy_arr[current_maximum])
                    {
                        current_maximum = current_index;
                    }
                    current_index++;
                }
                temp = copy_arr[sorted_arr];
                
                copy_arr[sorted_arr] = copy_arr[current_maximum];
                copy_arr[current_maximum] = temp;
                sorted_arr++;
                current_index = sorted_arr;
                current_maximum = sorted_arr;
            }
            break;
        }
    }
    return copy_arr;
}


unsigned int* find_finishing_positions(float** lap_times, unsigned int n_drivers, unsigned int n_laps)
{
    unsigned int *results;
    int loop1,loop2,loop3;
    float sum;
    float *total_times;
    float max_time=0;
    int max_index=0;

    results = (unsigned int*)malloc(sizeof(unsigned int)*n_drivers);

    total_times = (float*)malloc(sizeof(float)*n_drivers);

    for(loop1=0;loop1<n_drivers;loop1++)
    {
        sum = 0;
        for(loop2=0;loop2<n_laps;loop2++)
        {
            sum += lap_times[loop1][loop2];
        }
        total_times[loop1] = sum;
    }

    for(loop3=n_drivers-1;loop3>=0;loop3--)
    {
        
        for(loop2=0;loop2<n_drivers;loop2++)
        {
            if(total_times[loop2] - max_time >= -epsilon)
            {
                max_time = total_times[loop2];
                max_index = loop2;
            }
        }
        results[loop3] = max_index;
        total_times[max_index] = -1;
        max_time = 0;
    }
    free(total_times);
    return results;
}


float* find_time_diff(float** lap_times, unsigned int n_drivers, unsigned int n_laps, unsigned int driver1,unsigned int driver2)
{
    float *difference;
    int loop1,loop2;
    float diff,previous=0;

    difference = (float*)malloc(sizeof(float)*n_laps);

    for(loop1=0;loop1<n_laps;loop1++)
    {
        diff = lap_times[driver1][loop1] - lap_times[driver2][loop1];
        difference[loop1] = diff + previous;
        previous = diff+previous;
    }
    return difference;
}


unsigned int* calculate_total_points(unsigned int** positions, unsigned int p_drivers, unsigned int n_races)
{
    int loop1,loop2,loop3;
    unsigned int **copy_positions;
    unsigned int *return_arr;
    unsigned int temp,sum;

    copy_positions = (unsigned int**)malloc(sizeof(unsigned int*)*(p_drivers));
    for(loop1=0;loop1<p_drivers;loop1++)
    {
        copy_positions[loop1] = (unsigned int*)malloc(sizeof(unsigned int)*n_races);
    }

    for(loop1=0;loop1<p_drivers;loop1++)
    {
        for(loop2=0;loop2<n_races;loop2++)
        {
            copy_positions[loop1][loop2] = positions[loop1][loop2];
        }
    }

    for(loop1=1;loop1<p_drivers+1;loop1++)
    {
        scanf(" %u",&temp);
        for(loop2=0;loop2<p_drivers;loop2++)
        {
            for(loop3=0;loop3<n_races;loop3++)
            {
                if(positions[loop2][loop3] == loop1)
                {
                    copy_positions[loop2][loop3] = temp;
                }
            }
        }
    }
    
    return_arr = (unsigned int*)malloc(sizeof(unsigned int)*p_drivers);

    for(loop1=0;loop1<p_drivers;loop1++)
    {
        sum = 0;
        for(loop2=0;loop2<n_races;loop2++)
        {
            sum += copy_positions[loop1][loop2];
        }
        return_arr[loop1] = sum;
    }
    free(copy_positions);
    return return_arr;
}


unsigned int find_season_ranking(unsigned int* total_points, unsigned int p_drivers, unsigned int id)
{
    int loop1;
    unsigned int driv_point,how_m=0;
    

    driv_point = total_points[id];

    for(loop1=0;loop1<p_drivers;loop1++)
    {
        if(loop1 == id)
        {continue;}
        else if(total_points[loop1]>driv_point)
        {
            how_m++;
        }
        else if(total_points[loop1]==driv_point)
        {
            if(loop1<id)
            {how_m++;}
        }
    }
    return how_m+1;
}
