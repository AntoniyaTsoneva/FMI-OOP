#pragma once
#include"Tank.h"

class Army {

private:

	Tank* tanks;
	size_t CurSize;
	size_t Capacity;

public:

	//THE BIG FOUR
	Army();
	Army(size_t);
	~Army();
	Army(const Army&);
	Army& operator=(const Army&);

	//help functions
private:

	void CopyFrom(const Army&);
	void Free();
	void Resize(size_t NewSize);

	
	//interface
public:

	void AddTank(const Tank&);
	
	size_t GetSize()const;
	size_t GetCapacity()const;

private:

	bool CanDestroy(size_t);

	int DestroyWithMinShots(int TargetLifePnts);

public:

	void AttackAt(const Tank&);

	void Serialize(const char*);

	void Deserialize(const char*);
};