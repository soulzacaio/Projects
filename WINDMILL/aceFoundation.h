#ifndef ACEF_H
#define ACEF_H

#include "pile.h"
class aceFoundation : public pile
{
public:
    aceFoundation(deck<card> &d);

    bool isFull() const override { return count == 52; }
    void addCard(card newCard) override;
    bool canReceive(card newCard) override;
    const card getCard() const override;


};
#endif