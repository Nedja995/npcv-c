#include "..\..\..\include\base\core\list.h"
#include "list.h"
#include "memory.h"

namespace npcore
{



	List * list_create() {
		List *ret = (List*)mallocN(sizeof(List));
		ret->first = NULL;
		ret->last = NULL;
		return ret;
	}

	void list_put(List *list, void *item) {
		Link *link = list_link_create(item);

		link->next = NULL;
		link->prev = list->last;

		if (list->last) list->last->next = link;
		if (list->first == NULL) list->first = link;
		list->last = link;
	}

	int list_count(List * list)
	{
		int ret = 0;
		for (npcore::Link *iter = list->first;
			iter != list->last;
			iter = iter->next) {
			ret++;
		}
		return ret;
	}

	Link * list_link_create(void * item) {
		Link *ret = (Link*)mallocN(sizeof(Link));
		ret->data = item;
		ret->next = NULL;
		ret->prev = NULL;
		return ret;
	}

	void list_free(List * list)
	{
		LIST_FOREACH(list) {
			if (link->prev != NULL) {
				freeN((void *)link->prev);
				link->prev = NULL;
			}
		}
		freeN(list);
	}


	void list_free_default(List * list)
	{
	//	LIST_FOREACH(list){
		for (Link *link = (Link*)list->first; link != NULL; link = link->next) {
			free((void *)link->data);
			if (link->prev != NULL) {
				free((void *)link->prev);
			}
		}
		//}
		freeN(list);
	}

	void list_free_default(List * list, NListFree_Callback freeCallback)
	{
		LIST_FOREACH(list) {
			(*freeCallback)(link);
		}
	}
}
