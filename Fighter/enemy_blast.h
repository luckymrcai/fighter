#ifndef ENEMY_BLAST_H
#define ENEMY_BLAST_H

#include "my_item.h"
class Enemy_Blast: public My_item
{
public:
    Enemy_Blast(const QString & filename,QGraphicsScene *scene);
    void advance(int phase);
};

#endif // ENEMY_BLAST_H
