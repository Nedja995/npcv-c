/*
* Modified by Nedeljko Pejasinovic for NPCV image processing lib
*
*
*
* ***** BEGIN GPL LICENSE BLOCK *****
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
* The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
* All rights reserved.
*
* The Original Code is: most
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*
*
*/

/** \file list.h
*  \brief These structs are the foundation for all linked lists in the
*         library system.
*
* Doubly-linked lists start from a ListBase and contain elements beginning
* with Link.
*/

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