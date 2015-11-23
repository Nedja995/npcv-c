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

	void list_put(List *list, void *item) {
		LinkData *link = list_link_create(item);

		link->next = NULL;
		link->prev = list->last;

		if (list->last) list->last->next = link;
		if (list->first == NULL) list->first = link;
		list->last = link;
	}

	int list_count(List * list)
	{
		int ret = 0;
		for (npcore::LinkData *iter = list->first;
			iter != list->last;
			iter = iter->next) {
			ret++;
		}
		return ret;
	}

	LinkData * list_link_create(void * item) {
		LinkData *ret = (LinkData*)mallocN(sizeof(LinkData));
		ret->data = item;
		ret->next = NULL;
		ret->prev = NULL;
		return ret;
	}

}