#include <stdio.h>
#include "../engine/include/game_object.h"


void test_game_object_player1_on_start(cge_game_object* self)
{
    printf("[%s][onstart]\n", self->name);
}

void test_game_object_player1_on_update(cge_game_object* self)
{
    printf("[%s][update]\n", self->name);
}

void test_game_object_player1_on_end(cge_game_object* self)
{
    printf("[%s][end]\n", self->name);
}

void test_game_object()
{
    printf("[game_object][create plyer1][start]\n");
    cge_game_object* player1 = cge_game_object_create("player1", NULL, &test_game_object_player1_on_start, &test_game_object_player1_on_update, & test_game_object_player1_on_end, NULL);
    cge_game_object_call_on_start(player1);
    cge_game_object_call_on_update(player1);
    cge_game_object_call_on_end(player1);
    printf("[game_object][create plyer1][end]\n");

    printf("[game_object][create gun][start]\n");
    cge_game_object* gun = cge_game_object_create("gun", NULL, &test_game_object_player1_on_start, &test_game_object_player1_on_update, & test_game_object_player1_on_end, NULL);
    cge_game_object_call_on_start(gun);
    cge_game_object_call_on_update(gun);
    cge_game_object_call_on_end(gun);
    printf("[game_object][create gun][end]\n");

    printf("[game_object][add gun to player1][start]\n");
    cge_game_object_add_child(player1, gun);
    cge_game_object_call_on_start(player1);
    cge_game_object_call_on_update(player1);
    cge_game_object_call_on_end(player1);
    printf("[game_object][add gun to player1][end]\n");

    printf("[game_object][get gun from player1][start]\n");
    cge_game_object* gun_from_player1 = cge_game_object_get_child_by_name(player1, "gun");
    cge_game_object_call_on_start(gun_from_player1);
    cge_game_object_call_on_update(gun_from_player1);
    cge_game_object_call_on_end(gun_from_player1);
    printf("[game_object][get gun from player1][end]\n");

    printf("[game_object][remove gun from player1][start]\n");
    cge_game_object* gun_removed_from_player1 = cge_game_object_remove_child_by_name(player1, "gun");
    cge_game_object_call_on_start(player1);
    cge_game_object_call_on_update(player1);
    cge_game_object_call_on_end(player1);
    cge_game_object_call_on_start(gun_removed_from_player1);
    cge_game_object_call_on_update(gun_removed_from_player1);
    cge_game_object_call_on_end(gun_removed_from_player1);
    printf("[game_object][remove gun from player1][end]\n");
}

int main() {
    test_game_object();
    return 0;
}