/**
 * Author: Pascal Lüscher
 *
 * File to run basic BB example
 */

#include <stdio.h>
#include <time.h> 

#include "ecos.h"

#include <ecos_bb.h>
#include "problem_instances.h"

int main(void)
{
	result* result_pseudo_branching = NULL;
	result* result_most_infeasible = NULL;
	result* result_strong_branching = NULL;
	result* result_random_branching = NULL;
	result* result_hybrid_branching = NULL;

	settings_bb* settings = get_default_ECOS_BB_settings();
	settings->maxit = 5000;
	settings->branching_strategy = BRANCHING_STRATEGY_RELIABILITY;
	settings->reliable_eta = 1;
	settings->node_selection_method = DIVE_UPPER_NODE;

		
	PRINTTEXT("Calling with branching strategy 3\n");
	result_hybrid_branching = ilp_gen_ip054(settings);
	
	PRINTTEXT("Calling with branching strategy 3\n");
	settings->reliable_eta = 4;
	result_hybrid_branching = ilp_gen_ip054(settings);
	
	PRINTTEXT("Calling with branching strategy 3\n");
	settings->reliable_eta = 6;
	result_hybrid_branching = ilp_gen_ip054(settings);
	
	PRINTTEXT("Calling with branching strategy 3\n");
	settings->reliable_eta = 8;
	result_hybrid_branching = ilp_gen_ip054(settings);

	PRINTTEXT("Calling with branching strategy 3\n");
	settings->reliable_eta = 20;
	result_hybrid_branching = ilp_gen_ip054(settings);

	
	PRINTTEXT("Calling with branching strategy 2\n");
	settings->branching_strategy = BRANCHING_STRATEGY_PSEUDOCOST_BRANCHING;
	result_pseudo_branching = ilp_gen_ip054(settings);


	PRINTTEXT("Calling with branching strategy 4\n");
	settings->branching_strategy = BRANCHING_STRATEGY_RANDOM;
	result_random_branching = ilp_gen_ip054(settings);
	
	PRINTTEXT("Calling with branching strategy 0\n");
	settings->branching_strategy = BRANCHING_STRATEGY_MOST_INFEASIBLE;
	result_most_infeasible = ilp_gen_ip054(settings);
	
	PRINTTEXT("Calling with branching strategy 1\n");
	settings->branching_strategy = BRANCHING_STRATEGY_STRONG_BRANCHING;
	//settings->maxit /= 2;
	result_strong_branching = ilp_gen_ip054(settings);
	
	print_result_header();

	time_t rawtime = time(NULL);
	char filename[255];
	char time_str[26];
	struct tm tm_info;
	localtime_s(&tm_info, &rawtime);
	strftime(time_str, sizeof(time_str), "%Y_%m_%d_%H_%M_%S", &tm_info);
	sprintf_s(filename, sizeof(filename), "%s_benchmark.csv", time_str);

	FILE *fp;
	errno_t retVal = fopen_s(&fp, filename, "w");
	if (retVal != 0)
	{
		printf("error opening file\n");
		print_result_stats(result_most_infeasible);
		print_result_stats(result_strong_branching);
		print_result_stats(result_pseudo_branching);
		print_result_stats(result_hybrid_branching);
		print_result_stats(result_random_branching);

	}
	else
	{
		print_result_stats(result_most_infeasible);
		print_result_stats(result_strong_branching);
		print_result_stats(result_pseudo_branching);
		print_result_stats(result_hybrid_branching);
		print_result_stats(result_random_branching);

		fprintf_s(fp, result_header());
		fprintf_s(fp, result_stats(result_most_infeasible));
		fprintf_s(fp, result_stats(result_strong_branching));
		fprintf_s(fp, result_stats(result_pseudo_branching));
		fprintf_s(fp, result_stats(result_hybrid_branching));
		fprintf_s(fp, result_stats(result_random_branching));
		fclose(fp);
	}

	return (int)1;
}