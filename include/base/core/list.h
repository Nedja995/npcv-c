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

#ifndef __NPCV_LISTBASE_H__
#define __NPCV_LISTBASE_H__
/**
*  @brief Base list 
*
*  @file list.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*
*/

#ifdef __cplusplus
extern "C" {
#endif


	/**
	 * @brief	Callback Type for free stored element in list.
	 * @param	itemData	Stored elemnt
	 */
	typedef void(*NListFreeElement_Callback)(void *element);

	/**
	 * @struct	Link
	 * @brief	Item for list.
	 */
	typedef struct Link {
		struct Link *next, *prev;
		const void *data;
	} Link;

	/**
	 * @struct	List
	 * @brief	A list.
	 */
	typedef struct List {
		struct Link *first, *last;
	} List;

	/**
	 * @brief	Contructor of List.
	 * @return	null if it fails, pointer to new allocated List.
	 */
	List *list_create();

	/**
	 * @brief	List put.
	 *
	 * @param [in,out]	list	list.
	 * @param	item			Item for list.
	 */
	void list_put(List *list, const void *item);

	/**
	 * @brief	List count.
	 * @param [in,out]	list	list.
	 *
	 * @return	An int.
	 */
	int list_count(List *list);

	/**
	 * @brief	Constructor for Link element for List.
	 * @param	item	The item.
	 *
	 * @return	null if it fails, else new allocated Link.
	 */
	Link *list_link_create(const void *item);

	/**
	 * @brief	Default link and list free.
	 *
	 * @param [in,out]	list	List to free.
	 */
	void list_free(List *list);

	/**
	 * @brief	Free list and stored elements.
	 * 	Elements free  with default freeN() function
	 * @param [in,out]	list	list.
	 * @param	freeElementCallback	Callback for freed list item.
	 */
	void list_free_default(List *list);

	/**
	 * @brief	Free list and free their elements with custom function.
	 *
	 * @param [in,out]	list	   	If non-null, the list.
	 * @param	freeElementCallback	The free element callback.
	 */
	void list_free_custom(List *list, NListFreeElement_Callback freeElementCallback);

	/**
	 * @brief	Helper macro for iterateing throught list.
	 * @param	list	list.
	 */
#define LIST_FOREACH(list)					\
	for (Link *link = (Link*)list->first;	\
					link != NULL;			\
					link = link->next)  					



#ifdef __cplusplus
}
#endif
#endif
