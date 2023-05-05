// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
    Cage* temp = new Cage;
    temp->light = light;
    temp->next = temp->prev = nullptr;
    if (first == nullptr) {
        first = temp;
        first->next = temp;
        temp->prev = first;
    } else {
        temp->next = first->next;
        temp->prev = first;
        first->next->prev = temp;
        first->next = temp;
    }
}
int Train::getLength() {
    Cage* cur = first;
    cur->light = true;
    int count = 1;
    while (true) {
        cur = cur->next;
        if (cur->light == false) {
            count++;
            countOp++;
        }  else {
            countOp++;
            cur->light = false;
            for (int i = count; i > 0; i--) {
                cur = cur->prev;
                countOp++;
            }
            if (cur->light == false)
                return count;
            count = 1;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
