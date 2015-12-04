#ifndef __NPCV_LISTBASE_H__
#define __NPCV_LISTBASE_H__

namespace npcore
{
	struct Link;

	typedef void(*NListFree_Callback)(Link *link);


	/* simple subclass of Link--use this when it is not worth defining a custom one... */
	struct Link {
		Link *next, *prev;
		const void *data;
	};

	struct List {
		Link *first, *last;
	};

	List *list_create();

	void list_put(List *list, const void *item);

	int list_count(List *list);

	Link *list_link_create(const void *item);

	void list_free_default(List *list);
	void list_free_default(List *list, NListFree_Callback freeCallback);


#define LIST_FOREACH(list)					\
	for (Link *link = (Link*)list->first;	\
					link != NULL;			\
					link = link->next)  					
	


}
#endif
