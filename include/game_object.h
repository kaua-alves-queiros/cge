#ifndef CGE_GAMEOBJECT_H
#define CGE_GAMEOBJECT_H

typedef struct cge_game_object cge_game_object;
typedef struct cge_game_object_list_node cge_game_object_list_node;

struct cge_game_object
{
    char* name;
    cge_game_object_list_node* children;
    void(*on_start)(cge_game_object* self);
    void(*on_update)(cge_game_object* self);
    void(*on_end)(cge_game_object* self);
    void* model;
};

struct cge_game_object_list_node
{
    cge_game_object* child;
    cge_game_object_list_node* next;
};

cge_game_object* cge_game_object_create(
    char* name,
    cge_game_object_list_node* children,
    void(*on_start)(cge_game_object* self),
    void(*on_update)(cge_game_object* self),
    void(*on_end)(cge_game_object* self),
    void* model
);
void cge_game_object_add_child(cge_game_object* self, cge_game_object* child);
cge_game_object* cge_get_child_by_name(cge_game_object* self, char* name);
cge_game_object* cge_game_object_remove_child_by_name(cge_game_object* self, char* name);
void cge_game_object_free(cge_game_object* self);

void cge_game_object_call_on_start(cge_game_object* self);
void cge_game_object_call_on_update(cge_game_object* self);
void cge_game_object_call_on_end(cge_game_object* self);

#endif