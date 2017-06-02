#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

// thread args
struct _thread_data_t {
    int tid;
    unsigned long long floor;
    unsigned long long ceiling;
    unsigned long long thread_sum;
};
typedef struct _thread_data_t thread_data_t;

// shared data
unsigned long long sum;
pthread_mutex_t lock_sum;

// functions 
void error( char * msg )
{
    perror( msg );
    exit( 1 );
}

void * thr_func( void * arg )
{
    thread_data_t * data = (thread_data_t *) arg;

    // do computation and do to thread
}

void init_longs( unsigned long long to_factorialize, unsigned long long * half, unsigned long long * three_fourths, unsigned long long * seven_eighths )
{
    unsigned long long two, three, four, seven, eight;
    two = 2;
    three = 3;
    four = 4;
    seven = 7;
    eight = 8;
    *half = to_factorialize / two;
    *three_fourths = (to_factorialize * three) / four;
    *seven_eighths  = (to_factorialize * seven) / eight;
}

int main( int argc, char *argv[] ) 
{
    pthread_t threads[4];
    thread_data_t thr_data[4];
    unsigned long long to_factorialize;
    unsigned long long half, three_fourths, seven_eighths;

    sum = 0;
    pthread_mutex_init( &lock_sum, NULL );

    to_factorialize = strtoull( argv[1], NULL, 10 );
    if( errno )
        error( "Converting to ull failed" );
    init_longs( to_factorialize, &half, &three_fourths, &seven_eighths );

    fprintf( stderr, "Num: %llu\nHalf: %llu\n3/4: %llu\n7/8: %llu\n", to_factorialize, half, three_fourths, seven_eighths );

    // four threads, handle from 0-0.5, 0.5-0.75, 0.75-0.875. 0.875-1

    // for( int i = 0; i < 4; ++i )
    // {

        

    return 0;
}
