
#pragma once

#include <map>
#include <set>
#include "BlockID.h"
#include "Mobs/Monster.h" //this is a side-effect of keeping Mobfamily inside Monster class. I'd prefer to keep both (Mobfamily and Monster) inside a "Monster" namespace MG TODO : do it




// fwd:
class cChunk;





/** This class is used to collect, for each Mob, what is it's family. It was first
being designed to check the caps of the mobs (no more than ... hostile mob in the world)

as side effects : it also know what is the spawnrate of each family : MG TODO relocate
*/
class cMobFamilyCollecter
{
public :
	typedef const std::set<cMonster::eFamily> tMobFamilyList;
	typedef const std::map<cMonster::eFamily,int> tMobSpawRate;

	// collect a mob
	void CollectMob(cMonster & a_Monster);

	// return the number of mobs for this family
	int GetNumberOfCollectedMobs(cMonster::eFamily a_Family);

	static tMobFamilyList & m_AllFamilies(void);

	static tMobSpawRate & m_SpawnRate(void);

protected : 
	std::map<cMonster::eFamily, std::set<cMonster*> > m_Mobs;

	static tMobFamilyList InitMobFamilyBeforeCx11(void);
	static tMobSpawRate InitMobSpawnRateBeforeCx11(void);
} ;



