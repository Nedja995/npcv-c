#include "npstdlib.h"

int npc_test_memory();
int npc_test_string();
int npc_test_io();
int npc_test_list();
int npc_test_time();
int npc_test_logging();


int main(int argc, char** argv) {
	npc_test_memory();
	npc_test_string();
	//npc_test_io();
	npc_test_list();
	npc_test_time();


	return 0;
}

int npc_test_memory()
{
	char *mem = (char *)mallocN(sizeof(char) * 100);
	freeN(mem);
	return 0;
}

int npc_test_string()
{
	char *str = strmakeN("nedjaa");
	freeN(str);
	return 0;
}

int npc_test_io()
{
	char *input = strmakeN("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	NConsoleInput("%s", input);
	NConsolePrint("NPC Test IO.\ninput: %s", input);
	freeN(input);
	return 0;
}

int npc_test_list() 
{
	NConsolePrint("\nNPC Test List\n");
	List *list = list_create();
	//list_put(list, "static str");
	//list_put(list, "static string");
	//list_put(list, "statString");
	list_put(list, strmakeN("DynString"));
	list_put(list, strmakeN("DynamicS"));
	list_put(list, strmakeN("String dyn"));

	//print them
	//NConsolePrint("\n");
	LIST_FOREACH(list)
	{
		NConsolePrint("%s\n", (char *)link->data);
	}

	list_free_custom(list, freeN); /* with passed callback for free element */
								   //list_free(list); /* clear only list. for list with static elements */

	NConsolePrint("NPC Finish Test List\n\n");
	return 0;
}

int npc_test_time()
{
	NConsolePrint("\nNPCTest start Time\n");

	NTime *nt = time_get_allocN();

	if (nt == NULL) {
		NConsolePrint("Time struct getting error !");
		return -1;
	}

	NConsolePrint("\nTime successfuly used: %02d_%02d_%02d_%02d-%02d-%02d\n", nt->year, nt->month, nt->day, nt->hour, nt->minute, nt->second);

	freeN(nt);
	nt = time_get_allocN();
	freeN(nt);
	NConsolePrint("NPCTest finish Time\n\n");
	return 0;
}