#pragma once
#include "glblopts.h"
#include "ecos_bb.h"
typedef struct result
{
	const char* problem_name;

	idxint exitflag;
	pfloat objective;

	enum BRANCHING_STRATEGY branching_strategy;
	idxint iterations;
	double seconds_passed;

} result;

static result* create_result(const char* problem_name, idxint exitflag, pfloat objective, enum BRANCHING_STRATEGY branching_strategy, idxint iterations, double seconds_passed)
{
	result* res = malloc(sizeof(result));
	res->problem_name = problem_name;
	res->iterations = iterations;
	res->objective = objective;
	res->seconds_passed = seconds_passed;
	res->exitflag = exitflag;
	res->branching_strategy = branching_strategy;
	return res;
}


/* pretty print functions */


static char* result_header()
{
	const int table_width = 72;
	char* msg = malloc(table_width * sizeof(char));
	snprintf(msg, table_width * sizeof(char), "%-20s\t%-5s\t%-4s\t%20s\t%5s\t%11s\n", "Problem name", "strat", "exit", "objective", "iter", "time");
	return msg;
}
static void print_result_header()
{
	printf(result_header());
}
static char* result_stats(result* r)
{
	if (r == NULL) {
		return NULL;
	}
	const int table_width = 72;
	char* msg = malloc(table_width * sizeof(char));
	snprintf(msg, table_width * sizeof(char), "%-20s\t%-5d\t%-4d\t%20.4f\t%5d\t%10.1fs\n", r->problem_name, r->branching_strategy, r->exitflag, r->objective, r->iterations, r->seconds_passed);
	return msg;
}
static void print_result_stats(result* r)
{
	if (r == NULL) {
		return;
	}
	printf(result_stats(r));
}

