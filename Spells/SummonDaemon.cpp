/*_Created_by_K1ngp1n_*/

#include "SummonDaemon.hpp"

SummonDaemon::SummonDaemon(const std::string name, int cost, int points, int range)
	: AbstractSpell(name, cost, points, range) {

}

SummonDaemon::~SummonDaemon() {

}

void SummonDaemon::castSpell(AbstractUnit *master) {
	Warlock* warlock = static_cast<Warlock*>(master);

		warlock->setDemon(new Daemon(warlock));
	
	Daemon* daemon = warlock->getDaemon();

	int team = BattleField::getInstance()->getTeam()->showPlayerTeam(warlock);
	switch(team){
		case 1 : {
			BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, daemon);
			break;
		}
		case 2 : {
			BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, daemon);
			break;
		}
	}
	std::cout << *daemon << std::endl;
}
