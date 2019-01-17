#include "status.h"
typedef void* G_VECTOR;


G_VECTOR g_vector_init_default(Status(*item_assignment)(Item_ptr, Item),
	void(*item_destroy)(Item_ptr));
void g_vector_destroy(G_VECTOR* phG_Vector);

Status g_vector_push_back(G_VECTOR hVector, Item item);

Status g_vector_pop_back(G_VECTOR hVector);

Item g_vector_at(G_VECTOR hVector, int index);

int g_vector_get_size(G_VECTOR hVector);

//check capacity
int g_vector_get_capacity(G_VECTOR hVector);
