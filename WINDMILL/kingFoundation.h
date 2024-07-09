#ifndef KINGF_H
#define KINGF_H

#include "pile.h"
class kingFoundation : public pile
{
public:
    kingFoundation() { count = 0; };
    bool isFull() const override { return isRetired(); }
    bool isRetired() const { return count == 13; }
    void addCard(card newCard) override;
    bool canReceive(card newCard) override;
    const card getCard() const override;


};

#endif