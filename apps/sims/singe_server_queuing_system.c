//
// Created by erikp on 1/17/2024.
//
#include "singe_server_queuing_system.h"


#include <math.h>
#include <stdlib.h>


#include "../../mat/lcgrand.h"


float expon(float mean) {
    return -mean * log(lcgrand(1));
}

struct SSQSData sims_new_ssqsdata() {
    struct SSQSData tmp;

    // Initialize the simulation clock.
    tmp.server_status = 0;

    // Initilize the statistical counters.
    tmp.sim_time = 0.0;
    tmp.num_in_q = 0;
    tmp.time_last_event = 0.0;

    // Initialize statistical counters;
    tmp.num_custs_delayed = 0;
    tmp.next_event_type = 0;
    tmp.num_delays_required = 0;
    tmp.num_events = 0;

    //Initialize the statistical counters
    tmp.area_num_in_q = 0.0;
    tmp.area_server_status = 0.0;
    tmp.mean_interarrival = 0.0;
    tmp.mean_service = 0.0;

    tmp.total_of_delays = 0.0;

    tmp.time_next_event[1] = tmp.sim_time * expon(tmp.mean_interarrival);
    tmp.time_next_event[2] = 1.0e+30;

    return tmp;
}


void sims_run_single_server_queuing_system() {

    printf("Starting simulation\n");

    struct SSQSData data = sims_new_ssqsdata();

    data.num_events = 2;

    data.mean_interarrival = 4.0;
    data.mean_service = 3.0;
    data.num_delays_required = 5;

    printf("| Single-server queueing system\n");
    printf("| Mean interarrival time %11.3f minutes \n", data.mean_interarrival);
    printf("| Mean service time %16.3f minutes \n", data.mean_service);
    printf("| Number of customers %14d \n", data.num_delays_required);

    while (data.num_custs_delayed < data.num_delays_required) {
        // Determine the next event.
        _sims_timing(&data);
        _sims_update_time_avg_stats(&data);
        //Invoke the appropriate event function

        if (data.next_event_type == 1) {
            _sims_arrive(&data);
        } else if (data.next_event_type == 2) {
            _sims_depart(&data);
        }
    }

    _sims_report(&data);

    printf("End simulation\n");
}

void _sims_timing(struct SSQSData *data) {
    float min_time_next_event = 1.0e+29;

    data->next_event_type = 0;

    //Determine the event type of the next event to occur
    for (int i = 1; i < data->num_events; i++) {
        if (data->time_next_event[i] < min_time_next_event) {
            min_time_next_event = data->time_next_event[i];
            data->next_event_type = i;
        }
    }

    //Check to see whether the event list is empty
    if (data->next_event_type == 0) {
        printf("Event list empty at time %f", data->sim_time);
        exit(1);
    }

    //The event list is not empty, so advance the simulation clock.
    data->sim_time = min_time_next_event;
}

void _sims_arrive(struct SSQSData *data) {
    float delay = 0.0;
    data->time_next_event[1] = data->sim_time + expon(data->mean_interarrival);
    if (data->server_status == BUSY) {
        ++data->num_in_q;
        if (data->num_in_q > Q_LIMIT) {
            printf("Overflow of the array time_arrival at");
            printf("time %f", data->sim_time);
            exit(2);
        }
    } else {
        delay = 0.0;
        data->total_of_delays += delay;
        ++data->num_custs_delayed;
        data->server_status = BUSY;
        data->time_next_event[2] = data->sim_time + expon(data->mean_service);
    }
}

void _sims_depart(struct SSQSData *data) {
    float delay = 0.0;

    //Check to see whether the queue is empty
    if (data->num_in_q == 0) {
        data->server_status = IDLE;
        data->time_next_event[2] = 1.0e+30;
    } else {
        //The queue is nonempty, so decrement the number of customers in queue
        --data->num_in_q;
        //Compute the dlay of the customer who is beginning service and update total delay accumulator
        delay = data->sim_time - data->time_arrival[1];
        data->total_of_delays += delay;

        //Increment the number of customers delayed, and schedule departure
        ++data->num_custs_delayed;
        data->time_next_event[2] = data->sim_time + expon(data->mean_service);

        //Move each customer in queue (if any) up one place.
        for (int i = 1; i <= data->num_in_q; i++) {
            data->time_arrival[i] = data->time_arrival[i + 1];
        }
    }
}

void _sims_report(struct SSQSData *data) {

}

void _sims_update_time_avg_stats(struct SSQSData *data) {

    // Compute time isnce last event, and update last-event-time marker
    float time_since_last_event = data->sim_time - data->time_last_event;
    data->time_last_event = data->sim_time;

    // Update area under number-in-queue function
    data->area_num_in_q += data->num_in_q * time_since_last_event;

    // Update area under server-busy indicator function.
    data->area_server_status += data->server_status * time_since_last_event;


}

float _sims_expon(float mean) {
    return 0;
}
