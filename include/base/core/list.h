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
	 * @brief	Callback Type for free stored element in list.
	 * @param	itemData	Stored elemnt
	 */
	typedef void(*NListFreeElement_Callback)(void *element);

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
	


}
#endif
