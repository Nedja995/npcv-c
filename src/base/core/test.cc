/*
* Copyright (c) 2016 Nedeljko Pejasinovic (nedjaunity@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


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