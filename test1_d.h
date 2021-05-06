#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define find(it, key)\
{\
	while(it.has_next(&it) && it.get_value(&it) != key )\
	{\
		it.next(&it);\
	}\
}

#define find_if(it, pred)\
{\
	while(it.has_next(&it) && !pred(it.get_value(&it)) )\
	{\
		it.next(&it);\
	}\
}


#define typename(x) _Generic((x),                   \
        char: TYPENAME_CHAR,                        \
        int: TYPENAME_INT,                          \
        float: TYPENAME_FLOAT,                      \
		double: TYPENAME_DOUBLE,                 	\
        char*: TYPENAME_POINTER_TO_CHAR,        	\       
		double*: TYPENAME_POINTER_TO_DOUBLE,		\
		float*: TYPENAME_POINTER_TO_FLOAT,			\
       	void*: TYPENAME_POINTER_TO_VOID,        	\        
	   	int*: TYPENAME_POINTER_TO_INT,         		\
      	default: TYPENAME_OTHER)


 enum t_typename {
        TYPENAME_CHAR,                  //0
        TYPENAME_FLOAT,                 //1
        TYPENAME_INT,                   //2
        TYPENAME_DOUBLE,                //3
		TYPENAME_POINTER_TO_INT,		//4
		TYPENAME_POINTER_TO_FLOAT,		//5
		TYPENAME_POINTER_TO_CHAR,		//6
        TYPENAME_POINTER_TO_DOUBLE,     //7
        TYPENAME_POINTER_TO_VOID,       //8
        TYPENAME_OTHER                  //9
    };


//LIST

#define init_list(TYPE, variable)								\
{																\
	variable.head = NULL;										\
	variable.tail = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.insert_at_end = insert_at_end_##TYPE;				\
	variable.insert_at_beg = insert_at_beg_##TYPE;				\
	variable.delete_from_beg = delete_from_beg_##TYPE;			\
	variable.delete_from_end = delete_from_end_##TYPE;			\
	variable.delete_key = delete_key_##TYPE;					\
	variable.disp_list = disp_list_##TYPE;						\
}

#define init_list_iterator(TYPE, list, iterator)				\
{																\
	iterator.current = list.head;								\
	iterator.has_next = has_next_list_##TYPE;					\
	iterator.next = next_list_##TYPE;							\
	iterator.get_value = get_value_list_##TYPE;					\
	iterator.set_current = set_current_list_##TYPE;				\
}


#define LIST(list_t, TYPE)      										\
struct node_##TYPE                     									\
{                               										\
	TYPE key;                   										\
	struct node_##TYPE *prev;          									\
	struct node_##TYPE *next;          									\
																		\
};                              										\
typedef struct node_##TYPE node_##TYPE##_t;     						\
																		\
struct list_##TYPE														\
{                               										\
	node_##TYPE##_t *head;               								\
	node_##TYPE##_t *tail;   											\
	int type_; 															\
	void (*insert_at_end) (struct list_##TYPE *l1, TYPE key);           \
	void (*insert_at_beg) (struct list_##TYPE *l1, TYPE key);			\
	void (*delete_from_beg) (struct list_##TYPE *l1);					\
	void (*delete_from_end) (struct list_##TYPE *l1);					\
	void (*delete_key) (struct list_##TYPE *l1, TYPE key);				\
	void (*disp_list) (const struct list_##TYPE *l1);					\
																		\
};                              										\
typedef struct list_##TYPE list_t;     									\
\
\
struct list_iterator_##TYPE												\
{																		\
	node_##TYPE##_t* current;\
	int type_;\
	int (*has_next)(const struct list_iterator_##TYPE *);\
	TYPE (*next)(struct list_iterator_##TYPE *);\
	TYPE (*get_value)(const struct list_iterator_##TYPE *);\
	void (*set_current)(struct list_iterator_##TYPE *, struct list_iterator_##TYPE *);\
};\
\
typedef struct list_iterator_##TYPE list_t##_iterator;\
\
\
int has_next_list_##TYPE(const list_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current != 0;\
}\
\
\
TYPE next_list_##TYPE(list_t##_iterator *ptr_iterator)\
{\
	TYPE key = ptr_iterator->current->key;\
	ptr_iterator->current = ptr_iterator->current->next;\
	return key;\
}									\
\
\
TYPE get_value_list_##TYPE(const list_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current->key;\
}\
void set_current_list_##TYPE(list_t##_iterator *lhs, list_t##_iterator *rhs)\
{\
	if(rhs != NULL)\
	{\
		lhs->current = rhs->current;\
	}\
	else\
	{\
		lhs->current = NULL;\
	}\
}\
																		\
void insert_at_end_##TYPE(list_t* l1, TYPE key)							\
{																		\
	node_##TYPE##_t *temp = (node_##TYPE##_t*)malloc(sizeof(node_##TYPE##_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*list is empty*/													\
	if(l1->head == NULL)												\
	{																	\
		l1->head = temp;												\
		l1->tail = temp;												\
	}																	\
																		\
	else																\
	{																	\
		l1->tail->next = temp;											\
		temp->prev = l1->tail;											\
		l1->tail = temp;												\
	}																	\
}																		\
																		\
void insert_at_beg_##TYPE(list_t *l1, TYPE key)								\
{																		\
	node_##TYPE##_t *temp = (node_##TYPE##_t*)malloc(sizeof(node_##TYPE##_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*list is empty		*/												\
	if(l1->head == NULL)												\
	{																	\
		l1->head = temp;												\
		l1->tail = temp;												\
	}																	\
																		\
	else																\
	{																	\
		temp->next = l1->head;											\
		l1->head->prev = temp;											\
		l1->head = temp;												\
	}																	\
}																		\
																		\
void delete_from_beg_##TYPE(list_t *l1)											\
{																		\
	/*list is not empty	*/												\
	if(l1->head != NULL)												\
	{						                                			\
		node_##TYPE##_t *temp = l1->head;                            			\
																		\
		/*list contains only one element*/								\
		if(l1->head == l1->tail)                            			\
		{                                                   			\
			free(temp);                                     			\
			l1->head = NULL;                                			\
			l1->tail = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                  				\
		   l1->head->next->prev = NULL;                     			\
		   l1->head = l1->head->next;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}																	\
}	                                                        			\
																		\
void delete_from_end_##TYPE(list_t *l1)                              			\
{                                                           			\
	/*list is not empty	*/												\
	if(l1->head != NULL)												\
	{						                                			\
		node_##TYPE##_t *temp = l1->tail;                            			\
																		\
		/* list contains only one element	*/							\
		if(l1->head == l1->tail)                            			\
		{                                                   			\
			free(temp);                                     			\
			l1->head = NULL;                                			\
			l1->tail = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                   			\
		   l1->tail->prev->next = NULL;                     			\
		   l1->tail = l1->tail->prev;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}                                                       			\
}                                                           			\
																		\
void delete_key_##TYPE(list_t *l1, TYPE key)                         			\
{                                                           			\
	if(l1->head->key == key)                                			\
	{                                                       			\
		delete_from_beg_##TYPE(l1);                                			\
	}                                                                   \
																		\
	else                                                                \
	{                                                                   \
		node_##TYPE##_t *trav = l1->head;                                        \
																		\
		while(trav != NULL && trav->key != key)                         \
		{                                                               \
			trav = trav->next;                                          \
		}                                                               \
																		\
		if(trav)                                                        \
		{                                                               \
			/*element to be deleted is the last element */              \
			if(trav == l1->tail)                                        \
			{                                                           \
				delete_from_end_##TYPE(l1);                                    \
			}                                                           \
																		\
			else                                                        \
			{                                                           \
				if(trav->prev != NULL)                                  \
				{                                                       \
					trav->prev->next = trav->next;                      \
				}                                                       \
																		\
				if(trav->next != NULL)                                  \
				{                                                       \
					trav->next->prev = trav->prev;                      \
				}                                                       \
																		\
				free(trav);                                             \
			}                                                           \
		}                                                               \
	}                                                                   \
}																		\
																		\
void disp_list_##TYPE(const list_t *l1)									\
{																		\
	if(l1->head!=NULL)													\
	{																	\
		node_##TYPE##_t *trav = l1->head;								\
		while(trav != NULL)												\
		{																\
			if( l1->type_ == 0 )										\
				printf("%c\n", trav->key);								\
			else if( l1->type_ == 1)									\
				printf("%f\n", trav->key);								\
			else if( l1->type_ == 2 )									\
				printf("%d\n", trav->key);								\
			else if( l1->type_ == 3 )									\
				printf("%lf\n", trav->key);								\
																		\
			trav = trav->next;											\
		}																\
	}																	\
}


//STACK

#define init_stack(TYPE, variable)								\
{																\
	variable.head = NULL;										\
	variable.top = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.push = push_##TYPE;								\
	variable.pop = pop_##TYPE;									\
	variable.disp_stack = disp_stack_##TYPE;					\
	variable.peek_stack = peek_stack_##TYPE;					\
}

#define init_stack_iterator(TYPE, stack, iterator)								\
{																\
	iterator.current = stack.head;										\
	iterator.has_next = has_next_stack_##TYPE;				\
	iterator.next = next_stack_##TYPE;			\
	iterator.get_value = get_value_stack_##TYPE;\
	iterator.set_current = set_current_stack_##TYPE;\
}


#define STACK(stack_t, TYPE)      										\
struct stack_node_##TYPE                     									\
{                               										\
	TYPE key;                   										\
	struct stack_node_##TYPE *prev;          									\
	struct stack_node_##TYPE *next;          									\
																		\
};                              										\
typedef struct stack_node_##TYPE stack_node_##TYPE##_t;     						\
																		\
struct stack_##TYPE														\
{                               										\
	stack_node_##TYPE##_t *head;               								\
	stack_node_##TYPE##_t *top;   											\
	int type_; 															\
	void (*push) (struct stack_##TYPE *ptr_s, TYPE key);           \
	void (*pop) (struct stack_##TYPE *ptr_s);					\
	void (*disp_stack) (const struct stack_##TYPE *ptr_s);					\
	TYPE (*peek_stack) (const struct stack_##TYPE *ptr_s);\
																		\
};                              										\
typedef struct stack_##TYPE stack_t;     									\
																		\
																		\
																		\
																		\
struct stack_iterator_##TYPE\
{\
	stack_node_##TYPE##_t* current;\
	int type_;\
	int (*has_next)(const struct stack_iterator_##TYPE *);\
	TYPE (*next)(struct stack_iterator_##TYPE *);\
	TYPE (*get_value)(const struct stack_iterator_##TYPE *);\
	void (*set_current)(struct stack_iterator_##TYPE *, struct stack_iterator_##TYPE *);\
};\
\
typedef struct stack_iterator_##TYPE stack_t##_iterator;\
\
\
int has_next_stack_##TYPE(const stack_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current != 0;\
}\
\
\
\
TYPE next_stack_##TYPE(stack_t##_iterator *ptr_iterator)\
{\
	TYPE key = ptr_iterator->current->key;\
	ptr_iterator->current = ptr_iterator->current->next;\
	return key;\
}									\
\
\
TYPE get_value_stack_##TYPE(const stack_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current->key;\
}\
\
\
void set_current_stack_##TYPE(stack_t##_iterator *lhs, stack_t##_iterator *rhs)\
{\
	if(rhs != NULL)\
	{\
		lhs->current = rhs->current;\
	}\
	else\
	{\
		lhs->current = NULL;\
	}\
}\
\
\
\
\
void push_##TYPE(stack_t* ptr_s, TYPE key)							\
{																		\
	stack_node_##TYPE##_t *temp = (stack_node_##TYPE##_t*)malloc(sizeof(stack_node_##TYPE##_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*stack is empty*/													\
	if(ptr_s->head == NULL)												\
	{																	\
		ptr_s->head = temp;												\
		ptr_s->top = temp;												\
	}																	\
																		\
	else																\
	{																	\
		ptr_s->top->next = temp;											\
		temp->prev = ptr_s->top;											\
		ptr_s->top = temp;												\
	}																	\
}																		\
																		\
                                                    			\
																		\
void pop_##TYPE(stack_t *ptr_s)                              			\
{                                                           			\
	/*stack is not empty	*/												\
	if(ptr_s->head != NULL)												\
	{						                                			\
		stack_node_##TYPE##_t *temp = ptr_s->top;                            			\
																		\
		/* stack contains only one element	*/							\
		if(ptr_s->head == ptr_s->top)                            			\
		{                                                   			\
			free(temp);                                     			\
			ptr_s->head = NULL;                                			\
			ptr_s->top = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                   			\
		   ptr_s->top->prev->next = NULL;                     			\
		   ptr_s->top = ptr_s->top->prev;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}                                                       			\
}                                                           			\
																		\
																		\
																		\
void disp_stack_##TYPE(const stack_t *ptr_s)									\
{																		\
	if(ptr_s->head!=NULL)													\
	{																	\
		stack_node_##TYPE##_t *trav = ptr_s->head;								\
		while(trav != NULL)												\
		{																\
			if( ptr_s->type_ == 0 )										\
				printf("%c\n", trav->key);								\
			else if( ptr_s->type_ == 1)									\
				printf("%f\n", trav->key);								\
			else if( ptr_s->type_ == 2 )									\
				printf("%d\n", trav->key);								\
			else if( ptr_s->type_ == 3 )									\
				printf("%lf\n", trav->key);								\
																		\
			trav = trav->next;											\
		}																\
	}																	\
}																		\
																		\
																		\
TYPE peek_stack_##TYPE(const stack_t *ptr_s)							\
{																		\
	if(ptr_s->top != NULL)												\
	{																	\
		return ptr_s->top->key;											\
																		\
	}																	\
}


//QUEUE

#define init_queue(TYPE, variable)								\
{																\
	variable.front = NULL;										\
	variable.tail = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.enqueue = enqueue_##TYPE;							\
	variable.dequeue = dequeue_##TYPE;							\
	variable.disp_queue = disp_queue_##TYPE;					\
	variable.peek_queue = peek_queue_##TYPE;					\
}

#define init_queue_iterator(TYPE, queue, iterator)								\
{																\
	iterator.current = queue.front;										\
	iterator.has_next = has_next_queue_##TYPE;				\
	iterator.next = next_queue_##TYPE;			\
	iterator.get_value = get_value_queue_##TYPE;\
	iterator.set_current = set_current_queue_##TYPE;\
}


#define QUEUE(queue_t, TYPE)      										\
struct queue_node_##TYPE                     									\
{                               										\
	TYPE key;                   										\
	struct queue_node_##TYPE *prev;          									\
	struct queue_node_##TYPE *next;          									\
																		\
};                              										\
typedef struct queue_node_##TYPE queue_node_##TYPE##_t;     						\
																		\
struct queue_##TYPE														\
{                               										\
	queue_node_##TYPE##_t *front;               								\
	queue_node_##TYPE##_t *tail;   											\
	int type_; 															\
	void (*enqueue) (struct queue_##TYPE *ptr_q, TYPE key);           \
	void (*dequeue) (struct queue_##TYPE *ptr_q);					\
	void (*disp_queue) (const struct queue_##TYPE *ptr_q);					\
	TYPE (*peek_queue) (const struct queue_##TYPE *ptr_q)						\
																		\
};                              										\
typedef struct queue_##TYPE queue_t;     									\
																		\
																		\
																		\
																		\
struct queue_iterator_##TYPE\
{\
	queue_node_##TYPE##_t* current;\
	int type_;\
	int (*has_next)(const struct queue_iterator_##TYPE *);\
	TYPE (*next)(struct queue_iterator_##TYPE *);\
	TYPE (*get_value)(const struct queue_iterator_##TYPE *);\
	void (*set_current)(struct queue_iterator_##TYPE *, struct queue_iterator_##TYPE *);\
};\
\
typedef struct queue_iterator_##TYPE queue_t##_iterator;\
\
\
int has_next_queue_##TYPE(const queue_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current != 0;\
}\
\
\
\
TYPE next_queue_##TYPE(queue_t##_iterator *ptr_iterator)\
{\
	TYPE key = ptr_iterator->current->key;\
	ptr_iterator->current = ptr_iterator->current->next;\
	return key;\
}									\
\
\
TYPE get_value_queue_##TYPE(const queue_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current->key;\
}\
\
\
void set_current_queue_##TYPE(queue_t##_iterator *lhs, queue_t##_iterator *rhs)\
{\
	if(rhs != NULL)\
	{\
		lhs->current = rhs->current;\
	}\
	else\
	{\
		lhs->current = NULL;\
	}\
}\
\
\
\
\
void enqueue_##TYPE(queue_t* ptr_q, TYPE key)							\
{																		\
	queue_node_##TYPE##_t *temp = (queue_node_##TYPE##_t*)malloc(sizeof(queue_node_##TYPE##_t));						\
	temp->key = key;													\
	temp->prev = NULL;													\
	temp->next = NULL;													\
																		\
	/*queue is empty*/													\
	if(ptr_q->front == NULL)												\
	{																	\
		ptr_q->front = temp;												\
		ptr_q->tail = temp;												\
	}																	\
																		\
	else																\
	{																	\
		ptr_q->tail->next = temp;											\
		temp->prev = ptr_q->tail;											\
		ptr_q->tail = temp;												\
	}																	\
}																		\
																		\
																\
																		\
void dequeue_##TYPE(queue_t *ptr_q)											\
{																		\
	/*queue is not empty*/												\
	if(ptr_q->front != NULL)												\
	{						                                			\
		queue_node_##TYPE##_t *temp = ptr_q->front;                            			\
																		\
		/*queue contains only one element*/								\
		if(ptr_q->front == ptr_q->tail)                            			\
		{                                                   			\
			free(temp);                                     			\
			ptr_q->front = NULL;                                			\
			ptr_q->tail = NULL;                                			\
		}			                                        			\
																		\
		else                                                			\
		{                                                  				\
		   ptr_q->front->next->prev = NULL;                     			\
		   ptr_q->front = ptr_q->front->next;                       			\
		   free(temp);                                      			\
																		\
		}                                                   			\
	}																	\
}	                                                        			\
																		\
															\
																		\
void disp_queue_##TYPE(const queue_t *ptr_q)									\
{																		\
	if(ptr_q->front!=NULL)													\
	{																	\
		queue_node_##TYPE##_t *trav = ptr_q->front;								\
		while(trav != NULL)												\
		{																\
			if( ptr_q->type_ == 0 )										\
				printf("%c\n", trav->key);								\
			else if( ptr_q->type_ == 1)									\
				printf("%f\n", trav->key);								\
			else if( ptr_q->type_ == 2 )									\
				printf("%d\n", trav->key);								\
			else if( ptr_q->type_ == 3 )									\
				printf("%lf\n", trav->key);								\
																		\
			trav = trav->next;											\
		}																\
	}																	\
}\
\
\
TYPE peek_queue_##TYPE(const queue_t *ptr_q)							\
{																		\
	if(ptr_q->front != NULL)												\
	{																	\
		return ptr_q->front->key;											\
																		\
	}																	\
}







//VECTOR

#define init_vector_iterator(TYPE, vector, iterator)								\
{																\
	iterator.current = vector.dt;										\
	iterator.current_ind = 0;										\
	iterator.has_next = has_next_vector_##TYPE;				\
	iterator.next = next_vector_##TYPE;			\
	iterator.get_value = get_value_vector_##TYPE;\
	iterator.set_current = set_current_vector_##TYPE;\
}



#define init_vector(TYPE, variable)								\
{																\
	variable.dt = NULL;										\
	TYPE a;														\
	variable.type_ = typename(a);								\
	variable.make_new_dynamic_table = make_new_dynamic_table_##TYPE;								\
	variable.push_back = push_back_##TYPE;									\
	variable.pop_back = pop_back_##TYPE;					\
	variable.my_free = my_free_##TYPE;					\
	variable.access = access_##TYPE;					\
}


#define VECTOR(vector_t, TYPE)\
typedef struct dynamic_table_##TYPE\
{\
	int size;\
	int cur_size;\
	TYPE d_table[0];\
} d_table_t_##TYPE;\
\
typedef struct vector_##TYPE\
{\
	d_table_t_##TYPE* dt;\
	int type_;\
	void (*make_new_dynamic_table)(struct vector_##TYPE*, int);\
	void (*push_back)(struct vector_##TYPE*, int);\
	void (*pop_back)(struct vector_##TYPE*);\
	void (*my_free)(struct vector_##TYPE*);\
	TYPE (*access)(struct vector_##TYPE*, int);\
} vector_t;\
struct vector_iterator_##TYPE\
{\
	d_table_t_##TYPE* current;\
	int current_ind;\
	int type_;\
	int (*has_next)(const struct vector_iterator_##TYPE *);\
	TYPE (*next)(struct vector_iterator_##TYPE *);\
	TYPE (*get_value)(const struct vector_iterator_##TYPE *);\
	void (*set_current)(struct vector_iterator_##TYPE *, struct vector_iterator_##TYPE *);\
};\
typedef struct vector_iterator_##TYPE vector_t##_iterator;\
int has_next_vector_##TYPE(const vector_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current_ind != ptr_iterator->current->cur_size;\
}\
TYPE next_vector_##TYPE(vector_t##_iterator *ptr_iterator)\
{\
	TYPE key = ptr_iterator->current->d_table[ptr_iterator->current_ind];\
	++ptr_iterator->current_ind;\
	return key;\
}									\
\
\
TYPE get_value_vector_##TYPE(const vector_t##_iterator *ptr_iterator)\
{\
	return ptr_iterator->current->d_table[ptr_iterator->current_ind];\
}\
void set_current_vector_##TYPE(vector_t##_iterator *lhs, vector_t##_iterator *rhs)\
{\
	if(rhs != NULL)\
	{\
		lhs->current = rhs->current;\
	}\
	else\
	{\
		lhs->current = NULL;\
	}\
}\
void make_new_dynamic_table_##TYPE(vector_t* v, int n)\
{\
    /*d_table_t_##TYPE *dt = (d_table_t_##TYPE*)malloc(sizeof(d_table_t_##TYPE) + sizeof(int)*n);*/\
	v->dt = (d_table_t_##TYPE*)malloc(sizeof(d_table_t_##TYPE) + sizeof(int)*n);\
    v->dt->size = n;\
    v->dt->cur_size = 0;\
}\
void my_free_##TYPE(vector_t* v)\
{\
    free(v->dt);\
}\
void push_back_##TYPE(vector_t* v, int a)\
{\
    float r_factor = 1.5;\
    float r_capacity = 1;\
\
    if((v->dt->cur_size) >= (r_capacity * (v->dt->size)))\
    {\
        d_table_t_##TYPE* old_dt = v->dt;\
        int new_size = ceil(r_factor*(old_dt->size));\
        make_new_dynamic_table_##TYPE(v, new_size);\
        v->dt->cur_size = old_dt->cur_size;\
        for(int i = 0; i < v->dt->cur_size; ++i)\
        {\
            v->dt->d_table[i] = old_dt->d_table[i];\
        }\
        free(old_dt);\
    }\
    v->dt->d_table[(v->dt->cur_size)++] = a;\
}\
void pop_back_##TYPE(vector_t* v)\
{\
    float d_factor = 0.25;\
    float d_capacity = 0.25;\
    if(v->dt->cur_size == 0) return;\
    if((v->dt->cur_size) <= (d_capacity * v->dt->size))\
    {\
        d_table_t_##TYPE* old_dt = v->dt;\
        int new_size = floor(d_factor*((old_dt)->size));\
        make_new_dynamic_table_##TYPE(v, new_size);\
        v->dt->cur_size = old_dt->cur_size;\
        for(int i = 0; i < v->dt->cur_size; ++i)\
        {\
            v->dt->d_table[i] = old_dt->d_table[i];\
        }\
        free(old_dt);\
    }\
    --(v->dt->cur_size);\
}\
TYPE access_##TYPE(vector_t *v, int i)\
{\
	return v->dt->d_table[i];\
}\


//HASH MAP

#define init_map(TYPE_key, TYPE_val, size_, variable)\
{\
	variable.size = size_;\
	TYPE_key a;\
	variable.type_key = typename(a);\
	TYPE_val b;\
	variable.type_val = typename(b);\
	variable.map_arr = (map_node_##TYPE_key##_##TYPE_val##_t**)calloc(sizeof(map_node_##TYPE_key##_##TYPE_val##_t*), size_);\
	variable.insert_map = insert_map_##TYPE_key##_##TYPE_val;\
	variable.delete_map = del_map_##TYPE_key##_##TYPE_val;\
	variable.retrieve_map = retrieve_##TYPE_key##_##TYPE_val;\
\
}


#define MAP(map_t, TYPE_key, TYPE_val)\
struct map_node_##TYPE_key##_##TYPE_val\
{\
	TYPE_key key;\
	TYPE_val val;\
	struct map_node_##TYPE_key##_##TYPE_val *next;\
};\
typedef struct map_node_##TYPE_key##_##TYPE_val  map_node_##TYPE_key##_##TYPE_val##_t;\
\
struct map_##TYPE_key##_##TYPE_val\
{\
	int size;\
	int type_key;\
	int type_val;\
	map_node_##TYPE_key##_##TYPE_val##_t **map_arr;\
	void (*insert_map)(struct map_##TYPE_key##_##TYPE_val*, TYPE_key, TYPE_val);\
	void (*delete_map)(struct map_##TYPE_key##_##TYPE_val*, TYPE_key);\
	TYPE_val (*retrieve_map)(struct map_##TYPE_key##_##TYPE_val*, TYPE_key, int*);\
};\
typedef struct map_##TYPE_key##_##TYPE_val  map_t;\
\
\
void insert_map_##TYPE_key##_##TYPE_val(map_t* m, TYPE_key key, TYPE_val val)\
{\
	int index = hash_##TYPE_key##_##TYPE_val(m, key);\
	if(m->map_arr[index] == NULL)\
	{\
		map_node_##TYPE_key##_##TYPE_val##_t *temp = (map_node_##TYPE_key##_##TYPE_val##_t*)malloc(sizeof(map_node_##TYPE_key##_##TYPE_val##_t));\
		temp->key = key;\
		temp->val = val;\
		temp->next = NULL;\
		m->map_arr[index] = temp;\
		return;\
	}\
\
	map_node_##TYPE_key##_##TYPE_val##_t *trav = m->map_arr[index];\
	map_node_##TYPE_key##_##TYPE_val##_t *prev = NULL;\
	while(trav != NULL)\
	{\
		if(trav->key == key)\
		{\
			trav->val = val;\
			break;\
		}\
		prev = trav;\
		trav = trav->next;\
	}\
	if(trav == NULL)\
	{\
		map_node_##TYPE_key##_##TYPE_val##_t *temp = (map_node_##TYPE_key##_##TYPE_val##_t*)malloc(sizeof(map_node_##TYPE_key##_##TYPE_val##_t));\
		temp->key = key;\
		temp->val = val;\
		temp->next = NULL;\
		prev->next = temp;\
	}\
}\
\
\
int hash_##TYPE_key##_##TYPE_val(map_t* m, TYPE_key key)\
{\
	switch(m->type_key)\
	{\
		case 0: return ((int)(key*100))%(m->size); break;\
		case 2: return ((int)(key*100))%(m->size); break;\
		case 1: return ((int)(key*100))%(m->size); break;\
		case 3: return ((int)(key*100))%(m->size); break;\
		default: break;\
	}\
}\
\
\
void del_map_##TYPE_key##_##TYPE_val(map_t* m, TYPE_key key)\
{\
	int index = hash_##TYPE_key##_##TYPE_val(m, key);\
	if(m->map_arr[index] != NULL)\
	{\
		map_node_##TYPE_key##_##TYPE_val##_t *trav = m->map_arr[index];\
		map_node_##TYPE_key##_##TYPE_val##_t *prev = NULL;\
		while(trav != NULL)\
		{\
			if(trav->key == key)\
			{\
				if(prev == NULL)\
				{\
					m->map_arr[index] = trav->next;\
					free(trav);\
					break;\
				}\
				else\
				{\
					prev->next = trav->next;\
					free(trav);\
					break;\
				}\
			}\
			prev = trav;\
			trav = trav->next;\
		}\
	}\
}\
\
TYPE_val retrieve_##TYPE_key##_##TYPE_val(map_t* m, TYPE_key key, int* exists)\
{\
	int index = hash_##TYPE_key##_##TYPE_val(m, key);\
	if(m->map_arr[index] == NULL)\
	{\
		*exists = 0;\
		return -1;\
	}\
\
	map_node_##TYPE_key##_##TYPE_val##_t *trav = m->map_arr[index];\
	while(trav != NULL)\
	{\
		if(trav->key == key)\
		{\
			*exists = 1;\
			return trav->val;\
		}\
		trav = trav->next;\
	}\
	*exists = 0;\
	return -1;\
}
