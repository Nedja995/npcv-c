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


namespace npcore
{
	struct Link;

	/**
	 * @brief	Callback Type for free list.
	 * @param	link	Link item
	 */
	typedef void(*NListFree_Callback)(Link *link);

	/**
	 * @struct	Link
	 * @brief	Item for list.
	 */
	struct Link {
		Link *next, *prev;
		const void *data;
	};

	/**
	 * @struct	List
	 * @brief	A list.
	 */
	struct List {
		Link *first, *last;
	};

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
	void list_put(List *list, void *item);

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
	Link *list_link_create(void *item);

	/**
	 * @brief	Free list and elements.
	 * @param [in,out]	list	list.
	 */
	void list_free_default(List *list);

	/**
	 * @brief	List free default.
	 * @param [in,out]	list	list.
	 * @param	freeCallback	Callback for freed list item.
	 */
	void list_free_default(List *list, NListFree_Callback freeCallback);

/**
 * @brief	Helper macro for iterateing throught list.
 * @param	list	list.
 */
#define LIST_FOREACH(list)					\
	for (Link *link = (Link*)list->first;	\
					link != NULL;			\
					link = link->next)  					
	


}
#endif
