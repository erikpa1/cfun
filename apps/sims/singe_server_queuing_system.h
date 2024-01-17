//
// Created by erikp on 1/17/2024.
//

#include <stdio.h>

#define Q_LIMIT 100
#define BUSY 1
#define IDLE 0


//Single server queuing system
struct SSQSData {
    int next_event_type;
    int num_custs_delayed;
    int num_delays_required;
    int num_events;
    int num_in_q;
    int server_status;

    float area_num_in_q;
    float area_server_status;
    float mean_interarrival;
    float mean_service;
    float sim_time;
    float time_arrival[Q_LIMIT + 1];
    float time_last_event;
    float time_next_event[3];
    float total_of_delays;

    FILE *infile, *outfile;

};

void _sims_timing(struct SSQSData *data);

void _sims_arrive(struct SSQSData *data);

void _sims_depart(struct SSQSData *data);

void _sims_report(struct SSQSData *data);

void _sims_update_time_avg_stats(struct SSQSData *data);




struct SSQSData sims_new_ssqsdata();


void sims_run_single_server_queuing_system();