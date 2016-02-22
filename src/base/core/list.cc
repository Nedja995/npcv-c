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


#include "datatypes.h"
#include "list.h"

#include "npmemory.h"

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
		for (Link *iter = list->first;
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

	void list_free(List * list)
	{
		Link *link, *next;

		link = list->first;
		while (link) {
			next = link->next;
			freeN(link);
			link = next;
		}
		freeN(list);
	}

	void list_free_default(List * list)
	{
		Link *link, *next;

		link = list->first;
		while (link) {
			next = link->next;
			freeN((void *)link->data);
			freeN(link);
			link = next;
		}
		freeN(list);
	}

	void list_free_custom(List * list, NListFreeElement_Callback freeElementCallback)
	{			
		Link *link, *next;

		link = list->first;
		while (link) {
			next = link->next;
			freeElementCallback((void*)link->data);
			freeN(link);
			link = next;
		}
		freeN(list);
	}
