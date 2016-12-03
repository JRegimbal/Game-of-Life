#include "Block.h"

Block::Block() { isAlive = false; queue = false;}

Block::~Block() { }

bool Block::getStatus() { return isAlive; }

void Block::setStatus(bool status) { isAlive = status; }

void Block::queueStatus(bool status) { queue = status; }

void Block::updateStatus() { isAlive = queue; }
