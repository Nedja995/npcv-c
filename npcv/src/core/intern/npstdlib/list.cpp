#include "../../npstdlib/list.h"

#include "../../npstdlib/memory.h"

namespace npcore
{



	List * list_create() {
		List *ret = (List*)mallocN(sizeof(List));
		ret->first = NULL;
		ret->last = NULL;
		return ret;
	}

	void list_put(List *list, const void *item) {
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

	Link * list_link_create(const void * item) {
		Link *ret = (Link*)mallocN(sizeof(Link));
		ret->data = item;
		ret->next = NULL;
		ret->prev = NULL;
		return ret;
	}


	void list_free_default(List * list)
	{
		LIST_FOREACH(list){
			freeN((void *)link->data);
		}
	}

	void list_free_default(List * list, NListFree_Callback freeCallback)
	{
		LIST_FOREACH(list) {
			(*freeCallback)(link);
		}
	}
}