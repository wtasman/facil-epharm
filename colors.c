#include "project.h"

void	drug_name(char *drug)
{
	printf(DRUG_NAME "Prescribed Drug: %s" ANSI_COLOR_RESET "\n", drug);
}

void	drug_conflict(char *conflict)
{
	printf(WARNING "WARNING: conflict with %s" ANSI_COLOR_RESET "\n", conflict);
}

void	side_conflict(char *conflict)
{
	printf(WARNING "WARNING: patent already has %s" ANSI_COLOR_RESET "\n", conflict);
}

void	instructions(char *instructions)
{
	printf(INSTRUCTIONS "%s" ANSI_COLOR_RESET "\n", instructions);
}

void	drug_clear(void)
{
	printf(OK "No drug conflicts!" ANSI_COLOR_RESET "\n");
}

void	side_clear(void)
{
	printf(OK "No side effect conflicts!" ANSI_COLOR_RESET "\n");
}