#pragma once

class Block
{
	public:
		Block();
		~Block();
		void setStatus(bool status);
		bool getStatus();
		void queueStatus(bool status);
		void updateStatus();
	private:
		bool isAlive;
		bool queue;
};
