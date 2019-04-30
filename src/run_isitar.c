/**
 * Author: Pascal L�scher
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

	idxint iterations = 1000;

	/*PRINTTEXT("Calling with branching strategy 2\n");
	result_pseudo_branching = ilp_misc07(BRANCHING_STRATEGY_PSEUDOCOST_BRANCHING, iterations);

	PRINTTEXT("Calling with branching strategy 0\n");
	result_most_infeasible = ilp_misc07(BRANCHING_STRATEGY_MOST_INFEASIBLE, iterations);
	
	PRINTTEXT("Calling with branching strategy 1\n");
	result_strong_branching = ilp_misc07(BRANCHING_STRATEGY_STRONG_BRANCHING, iterations);
	*/

	PRINTTEXT("Calling with branching strategy 4\n");
	result_random_branching = ilp_misc07(BRANCHING_STRATEGY_RANDOM, iterations);

	print_result_header();

	time_t rawtime = time(NULL);
	char filename[255];
	char time_str[26];
	struct tm tm_info;
	localtime_s(&tm_info, &rawtime);
	strftime(time_str, sizeof(time_str), "%Y_%m_%d_%H_%M_%S", &tm_info);
	sprintf_s(filename,sizeof(filename), "%s_benchmark.csv", time_str);

	FILE *fp;
	errno_t retVal = fopen_s(&fp, filename, "w");
	if (retVal != 0)
	{
		printf("error opening file\n");
		print_result_stats(result_most_infeasible);
		print_result_stats(result_strong_branching);
		print_result_stats(result_pseudo_branching);
		print_result_stats(result_random_branching);
		
	} else
	{
		print_result_stats(result_most_infeasible);
		print_result_stats(result_strong_branching);
		print_result_stats(result_pseudo_branching);
		print_result_stats(result_random_branching);
		
		fprintf_s(fp, result_header());
		fprintf_s(fp, result_stats(result_most_infeasible));
		fprintf_s(fp, result_stats(result_strong_branching));
		fprintf_s(fp, result_stats(result_pseudo_branching));
		fprintf_s(fp, result_stats(result_random_branching));
		fclose(fp);
	}
	
	return (int)1;
}