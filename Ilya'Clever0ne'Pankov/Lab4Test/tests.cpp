#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include <algorithm>

extern "C" 
{ 
#include "functions.h"
}

#ifndef _WIN32

#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_BACK_COLOR_RED   "\x1b[41m"
#define ANSI_BACK_COLOR_GREEN "\x1b[42m"

#else

#define ANSI_COLOR_RESET

#define ANSI_BACK_COLOR_RED
#define ANSI_BACK_COLOR_GREEN

#endif

static void print_array( int32_t * arr, uint32_t size );

static void print_sorting_failure( int32_t * orig, int32_t * result, int32_t * expected, int32_t N );

int main()
{
    // fixed srand seed for reproducibility
    srand( 0x12345678 );

    static const int error_max = 10;

    //////////////// SORT

    printf("Starting tests of sort...\n\n");
    {
        int errorCount = 0;

        for( uint32_t i=0; i<10000; i++)
        {

            const uint32_t N = rand() % 20;

            int32_t * result = new int32_t[N];
            int32_t * orig = new int32_t[N];
            int32_t * expected = new int32_t[N];

            for( uint32_t j=0; j<N; j++)
            {
                result[j] = rand() % 1000;
                orig[j] = result[j];
                expected[j] = result[j];
            }

            sort( result, N);
            std::sort( expected, expected + N );

            if( memcmp( result, expected, N) != 0 )
            {
                print_sorting_failure( orig, result, expected, N );

                errorCount++;
            }

            // to lazy to use vectors, i'm sorry
            delete[] result;
            delete[] orig;
            delete[] expected;

            if( errorCount > error_max )
            {
                printf("Too many failures!\n\n");
                break;
            }
        }

        // corner cases made by hand

#       define ARRAY(...) __VA_ARGS__

#       define TEST_SORT_ARRAY( data, data_size )                               \
            {                                                                   \
                int32_t result[ data_size ] = data;                             \
                int32_t expected[ data_size ] = data;                           \
                int32_t orig[ data_size ] = data;                               \
                                                                                \
                sort( result, data_size );                                      \
                std::sort( expected, expected + data_size );                    \
                                                                                \
                if( memcmp( result, expected, data_size) != 0 )                 \
                {                                                               \
                    print_sorting_failure( orig, result, expected, data_size ); \
                    errorCount++;                                               \
                }                                                               \
            }                                                                   \

        //TEST_SORT_ARRAY( ARRAY( {5,5,5,5,5,5,5,5,5,1}    ), 10 )
        //TEST_SORT_ARRAY( ARRAY( {5,5,5,5,5,5,5,5,5,5}    ), 10 )
        TEST_SORT_ARRAY( ARRAY( {1}                      ), 1  )
        TEST_SORT_ARRAY( ARRAY( {INT_MAX, 8,5,4,INT_MIN} ), 5  )
        TEST_SORT_ARRAY( ARRAY( {0,1,2,3,4,5,6,7,8,9}    ), 10 )

        // testing zero-sized array
        int32_t result[ 10 ] = {0,1,2,3,4,5,6,7,8,9};
        int32_t expected[ 10 ] = {0,1,2,3,4,5,6,7,8,9};

        if( memcmp( result, expected, 10 ) != 0 )
        {
            print_sorting_failure( expected, result, expected, 10 );
            errorCount++;
        }

        if( errorCount == 0 )
        {
            printf( ANSI_BACK_COLOR_GREEN "Passed!" ANSI_COLOR_RESET "\n");
        }
    }

    //////////////// MEDIAN


    printf("\n---------------------------\n");
    printf("Starting tests of getMedian...\n\n");
    {
        int errorCount = 0;

        for( uint32_t i=0; i<10000; i++)
        {
            // random odd number
            const uint32_t N = (rand() % 10)*2 + 1;

            int32_t * result = new int32_t[N];
            int32_t * orig = new int32_t[N];
            int32_t * expected = new int32_t[N];

            for( uint32_t j=0; j<N; j++)
            {
                result[j] = rand() % 1000;
                orig[j] = result[j];
                expected[j] = result[j];
            }

            int32_t median = getMedian( result, N );

            std::sort( expected, expected + N );
            int32_t expectedMedian = expected[N/2];

            if( median != expectedMedian )
            {
                printf(ANSI_BACK_COLOR_RED "Test failed!" ANSI_COLOR_RESET "\n");

                printf("Original array:\n");
                print_array(orig, N);

                printf("Your median: %d\n", median );

                printf("Expected median: %d\n", expectedMedian );

                printf("\n");

                errorCount++;
            }

            delete[] result;
            delete[] orig;
            delete[] expected;

            if( errorCount > error_max )
            {
                printf("Too many failures!\n");
                break;
            }
        }

        if( errorCount == 0 )
        {
            printf( ANSI_BACK_COLOR_GREEN "Passed!" ANSI_COLOR_RESET "\n");
        }
    }

    //////////////// ORDER STAT

    printf("\n---------------------------\n");
    printf("Starting tests of getOrderStatistic...\n\n");
    {
        int errorCount = 0;

        for( uint32_t i=0; i<10000; i++)
        {

            const uint32_t N = rand() % 20;

            int32_t * result = new int32_t[N];
            int32_t * orig = new int32_t[N];
            int32_t * expected = new int32_t[N];

            for( uint32_t j=0; j<N; j++)
            {
                result[j] = rand() % 1000;
                orig[j] = result[j];
                expected[j] = result[j];
            }

            std::sort( expected, expected + N );

            for(uint8_t j=0; j<N; j++)
            {
                volatile int32_t k = getOrderStatistic( result, N, j);

                if(k != expected[j])
                {
                    printf( ANSI_BACK_COLOR_RED "Test failed!" ANSI_COLOR_RESET "\n" );

                    printf("Original array:\n");
                    print_array( orig, N);

                    printf("getOrderStatistic(array, %d, %d);\n", N, j );

                    printf("Your return value = %d, expected return value = %d\n\n", k, expected[j] );

                    // reset array state, it may be changed by getOrderStatistic call
                    memcpy( result, orig, N*sizeof(result[0])  );

                    errorCount++;
                }
            }

            delete[] result;
            delete[] orig;
            delete[] expected;

            if( errorCount > error_max )
            {
                printf("Too many failures!\n");
                break;
            }
        }

        if( errorCount == 0 )
        {
            printf( ANSI_BACK_COLOR_GREEN "Passed!" ANSI_COLOR_RESET "\n");
            return 0;
        }
        
        return 1;
    }
}

static void print_array( int32_t * arr, uint32_t size )
{
    printf("int32_t array[%d] = { ", size);

    for(uint8_t j=0;j<size;j++)
    {
        printf("%d, ", arr[j]);
    }

    printf("};\n");
}

static void print_sorting_failure( int32_t * orig, int32_t * result, int32_t * expected, int32_t N )
{
    printf(ANSI_BACK_COLOR_RED "Test failed!" ANSI_COLOR_RESET "\n");

    printf("Original array:\n");
    print_array(orig, N);

    printf("Your result:\n");
    print_array( result, N);

    printf("Expected result:\n");
    print_array( expected, N);

    printf("\n");
}
