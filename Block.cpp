#include "Block.h"

Block::Block(int x, int y) : x_coord(x), y_coord(y) {}

Block::~Block() { }

bool Block::getStatus() { return isAlive; }

void Block::setStatus(bool status) : isAlive(status) {}
