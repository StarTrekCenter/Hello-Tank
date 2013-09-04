#pragma once
class Item
{
public:
	Item(void);
	~Item(void);

	 virtual void Update(int ms) =0; 
	 virtual void Draw() =0;
};

