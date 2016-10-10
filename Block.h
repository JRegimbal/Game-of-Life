#pragma once

class Block
{
	public:
		Block(int x, int y);
		~Block();
		void setStatus(bool status);
		bool getStatus();
	private:
		int x_coord, y_coord;
		bool isAlive;
};
