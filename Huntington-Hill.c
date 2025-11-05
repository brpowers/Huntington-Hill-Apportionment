/*
This Program simulates a Huntington-Hill Apportionment of seats for
the US house of representatives. The numbers are not hard coded, but
I chose to not import from a CSV to save time, since this code won't have
to be reused.

To Compile this C program:
gcc Huntington-Hill.c -o apportion -lm

Then Run:
./apportion

Brendan Powers
brpowers989@gmail.com
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

#define STATES 50
#define TOTAL_SEATS 811

int main(void) {
    char *names[STATES] = {
        "Alabama","Alaska","Arizona","Arkansas","California","Colorado",
        "Connecticut","Delaware","Florida","Georgia","Hawaii","Idaho",
        "Illinois","Indiana","Iowa","Kansas","Kentucky","Louisiana",
        "Maine","Maryland","Massachusetts","Michigan","Minnesota",
        "Mississippi","Missouri","Montana","Nebraska","Nevada",
        "New Hampshire","New Jersey","New Mexico","New York",
        "North Carolina","North Dakota","Ohio","Oklahoma","Oregon",
        "Pennsylvania","Rhode Island","South Carolina","South Dakota",
        "Tennessee","Texas","Utah","Vermont","Virginia","Washington",
        "West Virginia","Wisconsin","Wyoming"
    };

    double pop[STATES] = {
        5024279,733391,7151502,3011524,39538223,5773714,3605944,989948,
        21538187,10711908,1455271,1839106,12812508,6785528,3190369,2937880,
        4505836,4657757,1362359,6177224,7029917,10077331,5706494,2961279,
        6154913,1084225,1961504,3104614,1377529,9288994,2117522,20201249,
        10439388,779094,11799448,3959353,4237256,13002700,1097379,5118425,
        886667,6910840,29145505,3271616,643077,8631393,7705281,1793716,5893718,576851
    };

    int seats[STATES];
    //give each state 1 seat to start
    for (int i = 0; i < STATES; i++){
        seats[i] = 1;
    }
    //total Tracks the number of seats apportioned so far
    int total = STATES;

    //repeat this whole process until all seats have been awarded
    while (total < TOTAL_SEATS) {
        int best = 0;
        double bestPriority = 0.0;
        //find the state witht the highest priority
        for (int i = 0; i < STATES; i++) {
            double v = pop[i] / sqrt(seats[i] * (seats[i] + 1));
            if (v > bestPriority) {
                bestPriority = v;
                best = i;
            }
        }
        //give that state one more seat
        seats[best]++;
        total++;
    }

    printf("Final apportionment for %d seats:\n", TOTAL_SEATS);
    for (int i = 0; i < STATES; i++) {
        printf("%-15s %3d\n", names[i], seats[i]);
    }

    return 0;
}