#include "game_object.h"
#include <stdlib.h>
#include <string.h>

cge_game_object* cge_game_object_create(
    char* name,
    cge_game_object_list_node* children,
    void(*on_start)(cge_game_object* self),
    void(*on_update)(cge_game_object* self),
    void(*on_end)(cge_game_object* self),
    void* model
) {
    cge_game_object* self = (cge_game_object*)malloc(sizeof(cge_game_object));
    self->name = name;
    self->children = children;
    self->on_start = on_start;
    self->on_update = on_update;
    self->on_end = on_end;
    self->model = model;
    return self;
}

void cge_game_object_add_child(cge_game_object* self, cge_game_object* child)
{
    cge_game_object_list_node* child_wrapper = (cge_game_object_list_node*)malloc(sizeof(cge_game_object_list_node));
    child_wrapper->child = child;
    child_wrapper->next = self->children;
    self->children = child_wrapper;
}

cge_game_object* cge_get_child_by_name(cge_game_object* self, char* name)
{
    cge_game_object_list_node* current_child_node = self->children;

    while(current_child_node != NULL)
    {
        if(strncmp(current_child_node->child->name, name) == 0)
        {
            return current_child_node->child;
        }

        current_child_node = current_child_node->next;
    }
}

cge_game_object cge_game_object_remove_child_by_name(cge_game_object* self, char* name)
{
    cge_game_object* to_remove;
    cge_game_object* current = self->children;
}

void cge_game_object_free(cge_game_object* self)
{

}

void cge_game_object_call_on_start(cge_game_object* self);
void cge_game_object_call_on_update(cge_game_object* self);
void cge_game_object_call_on_end(cge_game_object* self);