void	drug_name(char *drug)
{
	printf(DRUG_NAME "Prescribed Drug: %s\n" ANSI_COLOR_RESET, drug);
}

void	drug_conflict(char *conflict)
{
	printf(WARNING "WARNING: conflict with %s\n" ANSI_COLOR_RESET, conflict);
}

void	side_conflict(char *conflict)
{
	printf(WARNING "WARNING: patent already has %s\n" ANSI_COLOR_RESET, conflict);
}

void	instructions(char *instructions)
{
	printf(INSTRUCTIONS "%s\n" ANSI_COLOR_RESET, instructions);
}

void	drug_clear()
{
	printf(OK "No drug conflicts!\n" ANSI_COLOR_RESET);
}

void	side_clear()
{
	printf(OK "No side effect conflicts!\n" ANSI_COLOR_RESET);
}