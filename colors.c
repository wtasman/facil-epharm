#include <stdio.h>

#define WARNING     "\x1b[31m"
#define OK   "\x1b[32m"
#define INSTRUCTIONS  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define DRUG_NAME "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


//Print drug name
//WARNING: conflict with OTHER DRUG
//Print instructions
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

void	all_clear()
{
	printf(OK "OK\n" ANSI_COLOR_RESET);
}

int main (int argc, char const *argv[])
{
	char *drug = "insulin";
	char *con1;
	con1 = "Advil";
	char *con2 = "Low Blood Pressure";
	char *inst = "Apply directly to the forehead.";
	drug_name(drug);
	drug_conflict(con1);
	side_conflict(con2);
	instructions(inst);
	all_clear();
	//print_conflict(con2);
  //printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
  //printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
  //printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
  //printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");

  return 0;
}