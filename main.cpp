#include <iostream>
#include "Units/Soldier.hpp"
#include "Units/Vampire.hpp"
#include "Units/Rogue.hpp"
#include "Units/Mage.hpp"
#include "Lycanthrope.hpp"
#include "Units/Warlock.hpp"
#include "Units/Necromancer.hpp"
#include "Units/Berserker.hpp"
#include "Units/Priest.hpp"
#include "Units/Daemon.hpp"
#include "Interfaces/SpellBook.hpp"
#include "Units/Healer.hpp"
#include "Controller/GamePlayInterface.hpp"
//#include "Interfaces/AbstractUnit.hpp"
//#include "Interfaces/AbstractState.hpp"

//#include <stdio.h>

int main() {

GamePlayInterface game = GamePlayInterface();
	game.start();
//BattleField::getInstance()->selectUnitOnMField(1.1)
//	GamePlayInterface* game = new GamePlayInterface();
//	game->start();

//BattleField::getInstance()->getTeam()->showUnitsOnField();

//	Mage mage = Mage();
//	mage.getMageState().
//	Vampire *vampire = new Vampire();
//	WereWolf *werewolf = new WereWolf();
//	Rogue rogue1 = Rogue();
//	Rogue rogue2 = Rogue();
//	Rogue rogue3 = Rogue();
//	Rogue *rogue4 = new Rogue();
//	Rogue *rogue5 = new Rogue();
//	Rogue *rogue6 = new Rogue();
//	Rogue *rogue7 = new Rogue();
//	Rogue *rogue8 = new Rogue();
//	Rogue *rogue9 = new Rogue();
//	Rogue *rogue10 = new Rogue();
//	Rogue *rogue11 = new Rogue();
//	Rogue *rogue12 = new Rogue();
//	Rogue *rogue13 = new Rogue();
//	Rogue *rogue14 = new Rogue();
//	Rogue *rogue15 = new Rogue();
//	Rogue *rogue16 = new Rogue();
//	Rogue *rogue17 = new Rogue();
//	Rogue *rogue18 = new Rogue();
//	Rogue *rogue19 = new Rogue();
//	Rogue *rogue20 = new Rogue();
//	Rogue *rogue21 = new Rogue();
//	Rogue *rogue22 = new Rogue();
//	Rogue *rogue23 = new Rogue();
//	Rogue *rogue24 = new Rogue();
//	Rogue *rogue25 = new Rogue();
//	Rogue *rogue26 = new Rogue();
//	Rogue *rogue27 = new Rogue();
//	Rogue *rogue28 = new Rogue();
//	Rogue *rogue29 = new Rogue();
//	Rogue *rogue30 = new Rogue();
//	Rogue *rogue31 = new Rogue();

//	Warlock *warlock = new Warlock();
//	Necromancer *necromancer = new Necromancer();
//	Berserker *berserker = new Berserker();
//	Priest *priest = new Priest();
//	Healer *healer = new Healer();
//	Soldier soldier1 = Soldier();
//	Soldier soldier2 = Soldier();
//	Soldier soldier3 = Soldier();
//	Soldier soldier4 = Soldier();
//	Warlock warlock = Warlock();

//	Soldier *soldier5 = new Soldier();
//	Soldier *soldier6 = new Soldier();
//	Soldier *soldier7 = new Soldier();
//	Soldier *soldier8 = new Soldier();
//	Soldier *soldier9 = new Soldier();
//	Soldier *soldier10 = new Soldier();
//	Soldier *soldier11 = new Soldier();
//	Soldier *soldier12 = new Soldier();
//	Soldier *soldier13 = new Soldier();
//	Soldier *soldier14 = new Soldier();
//	Soldier *soldier15 = new Soldier();
//	Soldier *soldier16 = new Soldier();
//	Soldier *soldier17 = new Soldier();
//	Soldier *soldier18 = new Soldier();
//	Soldier *soldier19 = new Soldier();
//	Soldier *soldier20 = new Soldier();
//	Soldier *soldier21 = new Soldier();
//	Soldier *soldier22 = new Soldier();
//	Soldier *soldier23 = new Soldier();
//	Soldier *soldier24 = new Soldier();
//	Soldier *soldier25 = new Soldier();
//	Soldier *soldier26 = new Soldier();
//	Soldier *soldier27 = new Soldier();
//	Soldier *soldier28 = new Soldier();
//	Soldier *soldier29 = new Soldier();
//	Soldier *soldier30 = new Soldier();
//	Soldier *soldier31 = new Soldier();
//	Soldier *soldier32 = new Soldier();
//	Soldier *soldier33 = new Soldier();
//	Soldier *soldier34 = new Soldier();
//	Soldier *soldier35 = new Soldier();

//	WereWolf *werewolf = new WereWolf();

//
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, &rogue1);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, &rogue2);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, &rogue3);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, &mage);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, &warlock);
//
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, &soldier1);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, &soldier2);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, &soldier3);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, &soldier4);

//	std::cout << BattleField::getInstance()->getLocationTargetX(rogue2) << "." << BattleField::getInstance()->getLocationTargetY(rogue2) << std::endl;

//	BattleField::getInstance()->checkArround(rogue3);
//	BattleField::getInstance()->printBattleField();
//	soldier1.attack(&warlock);
//	BattleField::getInstance()->moveToSector(7,7,rogue3);
//	BattleField::getInstance()->moveToSector(6,6,rogue3);
//	BattleField::getInstance()->moveToSector(5,5,rogue3);
//	BattleField::getInstance()->moveToSector(4,5,rogue3);
//	BattleField::getInstance()->moveToSector(3,5,rogue3);

//	BattleField::getInstance()->moveToSector(5,2,soldier4);
//	BattleField::getInstance()->moveToSector(5,3,soldier4);
//	BattleField::getInstance()->moveToSector(5,4,soldier4);
//	BattleField::getInstance()->moveToSector(6,5,soldier4);
//	BattleField::getInstance()->moveToSector(7,5,soldier4);
//	BattleField::getInstance()->moveToSector(7,6,soldier4);
//	BattleField::getInstance()->moveToSector(8,7,soldier4);

//	BattleField::getInstance()->moveToSector(4,4,soldier4);
//	BattleField::getInstance()->checkWeaponDistance(soldier4, rogue3);
////	BattleField::getInstance()->checkDistanceAttack(rogue3, soldier4);

//	BattleField::getInstance()->printBattleField();
//	soldier4->attack(rogue3);
//	rogue3->attack(soldier4);
//
//	std::cout << *soldier4;
//	std::cout << *rogue3 << std::endl;
//	BattleField::getInstance()->scanEnemies(soldier4);
//		soldier4->attack(rogue2);
//	std::cout << *soldier4;
//	std::cout << *rogue3;
//	rogue2->attack(soldier4);
//
//	std::cout << *soldier4;
//std::cout << *rogue2 << std::endl;
//	std::cout << *mage;
////	mage->castSpell(soldier4,Spell::Blast);
//	BattleField::getInstance()->moveToSector(4,8,mage);
//
////	mage->castSpell(soldier4,Spell::FireBall);
//	BattleField::getInstance()->moveToSector(5,8,mage);
//
////	mage->castSpell(soldier4,Spell::FireBall);
////	mage->attack(soldier4);
////	BattleField::getInstance()->printBattleField();
//	std::cout << *soldier4;
//	BattleField::getInstance()->checkArround(mage);
////	BattleField::getInstance()->printBattleField();
//	std::cout << *warlock;
//	std::cout << *mage;
//	warlock->summonDaemon();
////	BattleField::getInstance()->printBattleField();
////	BattleField::getInstance()->getTeam()->showAllUnitsOnBoard();
//		BattleField::getInstance()->moveToSector(4,7,warlock->getDaemon());
//	BattleField::getInstance()->moveToSector(5,7,warlock->getDaemon());
//	BattleField::getInstance()->moveToSector(6,7,warlock->getDaemon());
//	BattleField::getInstance()->moveToSector(7,7,warlock->getDaemon());
//
//	std::cout << *soldier4;
//
//	warlock->getDaemon()->attack(rogue);
//
//	std::cout << *soldier4;
//	std::cout << *warlock;
//	std::cout << *mage;
////	warlock->getDaemon()->attack(soldier4);
//	std::cout << *warlock->getDaemon();
//	warlock->summonDaemon();
//	mage->castSpell(warlock->getDaemon(),Spell::Blast);
//	mage->castSpell(warlock->getDaemon(),Spell::Blast);
//
//	BattleField::getInstance()->printBattleField();
//	BattleField::getInstance()->moveToSector(7,7,soldier4);
//	BattleField::getInstance()->moveToSector(7,8,soldier4);
//	BattleField::getInstance()->moveToSector(6,7,soldier4);
//	BattleField::getInstance()->moveToSector(5,7,soldier4);
//	BattleField::getInstance()->moveToSector(4,7,soldier4);
//	BattleField::getInstance()->moveToSector(3,7,soldier4);
//
//	warlock->summonDaemon();
//
//	std::cout << *warlock;
//	warlock->summonDaemon();
//	std::cout << *warlock;
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, werewolf);
//	BattleField::getInstance()->printBattleField();
//	std::cout << *werewolf;
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	BattleField::getInstance()->printBattleField();
////	werewolf->attack(soldier4);
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	std::cout << *soldier4;
//
//	werewolf->attack(soldier4);
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	std::cout << *soldier4;
//	soldier4->clickSpecialAbility();
//	std::cout << *soldier4;
////	soldier4->clickSpecialAbility();
////	std::cout << *soldier4;
////	soldier4->attack(werewolf);
////	std::cout << *werewolf;
////	std::cout << *soldier4;
////	soldier4->clickSpecialAbility();
//	werewolf->clickSpecialAbility();
//	std::cout << *werewolf;
//	std::cout << *soldier4;
//	werewolf->attack(soldier4);
//	std::cout << *werewolf;
//	std::cout << *soldier4;
//	std::cout << *mage;
//	BattleField::getInstance()->moveToSector(4,7,soldier4);
//soldier4->clickSpecialAbility();
//
////	std::cout << mage->getState() << std::endl;
////
////	std::cout << mage->getMageState() << std::endl;
//
//	soldier4->attack(mage);
////	std::cout << *soldier4;
//	std::cout << *mage;
//	mage->castSpell(soldier4,Spell::Blast);
//	std::cout << *soldier4;
//	std::cout << *mage;
//	soldier4->getState()->setHp(500);
//	mage->getState()->setHp(500);
//	std::cout << *soldier4;
//	std::cout << *mage;
//	mage->attack(soldier4);
//	soldier4->clickSpecialAbility();
////
//	std::cout << *soldier4;
//	std::cout << *mage;
//	std::cout << mage->getMageState()->getName() << std::endl;
//	mage->getMageState()->getName();
//	mage->castSpell(soldier4,Spell::Blast);
//	mage->attack(soldier4);
//	BattleField::getInstance()->printBattleField();
//	std::cout << *soldier4;
//	std::cout << *mage;
//	mage->getMageState();
//	mage->castSpell(soldier4,Spell::Blast);

//	mage->clickSpecialAbility();
////	mage->castSpell(soldier4,Spell::Blast);
////mage->getSpecialAbility()->specialAbilityActivate();
//	std::cout << mage->getState() << std::endl;
//
//std::cout << mage->getMageState() << std::endl;
//	std::cout << *mage;
//mage->getMageState()->getMana();
//	mage->getMageState();
//	std::cout << BattleField::getInstance()->selectUnitOnMField(2,8)->getState()->getName() << std::endl;
//	BattleField::getInstance()->printBattleField();
//werewolf->attack(BattleField::getInstance()->selectUnitOnMField(3,8));
//std::cout << werewolf->getWeapon()->getDamage() << " " << werewolf->getWeapon()->getTitle() << std::endl;
//	warlock->setDemon(dynamic_cast<Daemon*>(BattleField::getInstance()->selectUnitOnMField(7,7)));
//	mage->castSpell(BattleField::getInstance()->selectUnitOnMField(7,7),Spell::Blast);
//	warlock->getDaemon()->attack(soldier4);
	//	std::cout << BattleField::getInstance()->getTeam()->showPlayerTeam(warlock) << std::endl;

//	std::cout <<  warlock->m_magic_state()->getManaLimit() << std::endl;

//	std::cout << mage->m_magic_state()->getMana();
//	std::cout << mage->getState()->getDamage() << std::endl;
//	std::cout << soldier->getState()->getDamage() << std::endl;

//	BattleField::getInstance()->checkArround(rogue3);

//	BattleField::getInstance()->checkArround(rogue3);

//	BattleField::getInstance()->checkArround(rogue3);
//	BattleField::getInstance()->printBattleField();

//	BattleField::getInstance()->checkDistanceMove(4,6,rogue2);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier5);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier6);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier7);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier8);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier9);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier10);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier11);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier12);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier13);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier14);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier15);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier16);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier17);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier18);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier19);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier20);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier21);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier22);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier23);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier24);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier25);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier26);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier27);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier28);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier29);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier30);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier31);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier32);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier33);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier34);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue,soldier35);


//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue4);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue5);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue6);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue7);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue8);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue9);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue10);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue11);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue12);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue13);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue14);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue15);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue16);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue17);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue18);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue19);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue20);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue21);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue22);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue23);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue24);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue25);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue26);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue27);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue28);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue29);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue30);
//	BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red,rogue31);
//	BattleField::getInstance()->getLocationTargetX(rogue3);
//	BattleField::getInstance()->moveToSector(6,5,rogue);

//	BattleField::getInstance()->tryGet(6,5,rogue);

//	BattleField::getInstance()->arrangeOnBoardTeamA(1, 1, soldier);
//	std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
//	system("cls");
//	system("clear");
//	system("CLS");
//	BattleField::getInstance()->getTeam()->showUnitsOnField();

//	std::cout << *soldier;
//	std::cout << *rogue;
//
//	soldier->getState()->setStrenght(98);
//	rogue->getState()->setStrenght(90);
//	rogue->attack(soldier);
//	soldier->attack(rogue);
//	std::cout << *soldier;



//	rogue->attack(soldier);
//	soldier->attack(rogue);
//	rogue->getState()->setStrenght(98);


//	std::cout << *soldier;
//	std::cout << *rogue;
//	Daemon *demon = new Daemon("demon",66,66,6,warlock);

//	std::cout << *rogue;
//	std::cout << *werewolf;
//	std::cout << *vampire;
//	std::cout << *mage;
//	std::cout << *warlock;
//	std::cout << *necromancer;
//	std::cout << *berserker;
//	std::cout << *priest;
//	std::cout << *healer;
//	std::cout << *soldier << std::endl;
//	soldier->moveTo(8,2);
//	soldier->moveTo(4,0);
//	soldier->moveTo(5,6);
//	mage->moveTo(4,6);
//	mage->moveTo(4,7);
//	soldier->moveTo(8,3);
//	soldier->moveTo(8,4);
//	soldier->moveTo(8,5);
//	mage->moveTo(8,4);
//	std::cout << "step: " << soldier->getState()->getStep() << std::endl;
//	std::cout << "range: " << soldier->getState()->getRange() << std::endl;

//	BattleField::getInstance()->printBattleField();
//	soldier->attack(mage);
//	vampire->attack(werewolf);
//	std::cout << *vampire;

//	mage->castSpell(vampire,Spell::Blast);
//	healer->castSpell(vampire,Spell::Blast);
//werewolf->attack(mage);
//werewolf->attack(soldier);
//	std::cout << *soldier;
//	std::cout << *mage;
//	std::cout << *healer;

//	std::cout << *werewolf;
//	std::cout << *vampire;

//soldier->moveTo(3,2,soldier);
//	BattleField::getInstance()->moveToSector(2,3,soldier);
//	soldier->getBattleField();
//	soldier->getBattleField()->getInstance()->setLocationX(5);
//	soldier->getBattleField()->getInstance()->setLocationY(4);
//	soldier->getBattleField()->getInstance()->getLocation();
//	soldier->getBattleField()->getInstance()->setLocationXY(3,3);
//	soldier->getBattleField()->getInstance()->getLocation();
//	mage->getBattleField()->getInstance()->setLocationXY(6,1);
//	warlock->getBattleField()->getInstance()->setLocationXY(-5,1);
//	warlock->getBattleField()->getInstance()->setLocationXY(3,3);
//	warlock->getBattleField()->getInstance()->setLocationXY(4,3);
//	soldier->getBattleField()->getInstance()->getLocation();
//	mage->getBattleField()->getInstance()->getLocation();


//	BattleField::getInstance()->printBattleField();
//	soldier->getBattleField()->getInstance()->printBattleField();
//	soldier->getBattleField()->setLocationXY(2,4);
//	soldier->getBattleField()->printBattleField();
//	soldier->getBattleField()->getBoard();
//	std::cout << s << std::endl;
//	soldier->getBoard()->showBattleField('S');
//soldier->getBoard()->addMemberToContainer(soldier);
//	soldier->getBattleFieldBox();
//	necromancer->castSpell(soldier,Spell::Blast);
//	necromancer->castSpell(werewolf,Spell::Blast);
//	necromancer->castSpell(vampire,Spell::Blast);
//
//	necromancer->getObservables();
//	warlock->getObservables();
//BattleField::setLocationX(5);
//BattleField::setLocationY(4);
//

//
//	warlock->summonDaemon(soldier);
//	warlock->getObservables();
//	berserker->attack(soldier);
//	std::cout << *demon;
//	priest->castSpell(demon,Spell::FireBall);
//warlock->castSpell(soldier,Spell::SummonDaemon);
//	std::cout << *soldier << std::endl;

//	warlock->castSpell(soldier,Spell::SummonDaemon);
//	std::cout << *soldier << std::endl;
//	vampire->attack(priest);
//	vampire->attack(mage);
//	vampire->attack(soldier);
//	priest->castSpell(soldier,Spell::Blast);
//demon->attack(soldier);
//	necromancer->castSpell(soldier,Spell::Blast);
//	rogue->attack(soldier);
//	rogue->attack(werewolf);
//	rogue->attack(berserker);
//	healer->castSpell(berserker,Spell::Heal);
//	healer->castSpell(berserker,Spell::FireBall);
//
//	necromancer->castSpell(soldier,Spell::Blast);
//	necromancer->castSpell(mage,Spell::Blast);
//	necromancer->castSpell(werewolf,Spell::Blast);
//
//	priest->castSpell(necromancer,Spell::FireBall);
////	priest->castSpell(necromancer,Spell::Blast);
//
//	necromancer->castSpell(soldier,Spell::Blast);
//	warlock->castSpell(soldier,Spell::Blast);
//	warlock->castSpell(mage,Spell::Blast);
//	warlock->castSpell(werewolf,Spell::Blast);
//	warlock->castSpell(berserker,Spell::FireBall);
//	necromancer->getObservables();
//	berserker->getObservers();
//	warlock->castSpell(soldier,Spell::Blast);
//	warlock->castSpell(mage,Spell::Blast);
//	warlock->castSpell(werewolf,Spell::Blast);
	//	warlock->summonDaemon(soldier);
////	warlock->castDaemon(soldier,UndeadSpell::SummonDaemon);
//	priest->castSpell(necromancer,Spell::Blast);
//	priest->castSpell(necromancer,Spell::Heal);
//	priest->castSpell(soldier,Spell::Heal);
//necromancer->castSpell(mage,Spell::FireBall);
//	warlock->castSpell(soldier,Spell::Blast);
//	warlock->castSpell(soldier,Spell::Blast);
////	warlock->castSpell(soldier,SpellType::Blast);
//	warlock->castSpell(soldier,Spell::Heal);
//	warlock->castSpell(soldier,Spell::Heal);
//	warlock->castSpell(soldier,Spell::Heal);
//	warlock->castSpell(soldier,Spell::Heal);
//	werewolf->transform();
//	soldier->attack(rogue);
//	std::cout << *rogue << std::endl;
//	warlock->castSpell(mage,Spell::SummonDaemon);
//	warlock->castSpell(rogue,Spell::Heal);
//	rogue->attack(soldier);
//	rogue->attack(soldier);

//	werewolf->attack(rogue);
//	priest->castSpell(necromancer,Spell::Blast);
//	priest->castSpell(soldier,Spell::Blast);
//	priest->castSpell(mage,Spell::Blast);
//	priest->castSpell(rogue,Spell::Blast);
//	priest->castSpell(necromancer,Spell::FireBall);
//	priest->castSpell(vampire,Spell::FireBall);
//	soldier->attack(berserker);
//	soldier->attack(berserker);
//	std::cout << *berserker << std::endl;
//	healer->castSpell(berserker,Spell::Heal);

//	priest->castSpell(berserker,Spell::Heal);
//
//	mage->castSpell(soldier,Spell::FireBall);
//	mage->castSpell(priest,Spell::FireBall);

//	mage->castSpell(warlock,Spell::FireBall);


//	priest->castSpell(werewolf,Spell::Blast);

//	werewolf->attack(warlock);
//	werewolf->attack(soldier);

//	warlock->attack(soldier);
//	warlock->attack(soldier);
//	necromancer->castSpell(soldier,Spell::FireBall);
//	necromancer->castSpell(warlock,Spell::FireBall);
//	necromancer->castSpell(mage,Spell::FireBall);

//	soldier->attack(necromancer);
//	std::cout << *necromancer;

//vampire->attack(necromancer);

//	necromancer->castSpell(soldier,Spell::FireBall);
//	necromancer->castSpell(werewolf,Spell::FireBall);
//	necromancer->castSpell(werewolf,Spell::FireBall);
//	necromancer->castSpell(mage,Spell::FireBall);
//	necromancer->castSpell(soldier,Spell::FireBall);
//	rogue->attack(soldier);
//	rogue->attack(warlock);
//	rogue->attack(mage);
//	std::cout << *necromancer;

//	necromancer->castSpell(werewolf,Spell::FireBall);

//necromancer->informObservers();
//	soldier->attack(warlock);
//	warlock->castSpell(soldier,Spell::SummonDaemon);
//	warlock->castSpell(soldier,Spell::SummonDaemon);
//	soldier->attack(warlock);

//	mage->castSpell(werewolf,Spell::Blast);
//	mage->castSpell(soldier,Spell::FireBall);
//	mage->castSpell(warlock,Spell::FireBall);
//	warlock->getDaemon()->attack(mage);
//	warlock->controlQuard(mage);
//	warlock->getDaemon()->attack(mage);
//	soldier->attack(vampire);
//	werewolf->human_state->transformation();
//	werewolf->human_state->transformation();
//	werewolf->human_state->transformation();
//	werewolf->transform();
//	werewolf->transform();
//	mage->castSpell(werewolf,Spell::Blast);
//werewolf->attack(mage);
//	werewolf->attack(soldier);
//	soldier->attack(werewolf);

//	vampire->attack(soldier);
//	soldier->attack(vampire);
//	vampire->attack(soldier);
//	werewolf->attack(soldier);

//	std::cout << werewolf->getState()->getName() << std::endl;

//	mage->attack(vampire);
//	vampire->attack(soldier);
//	soldier->attack(vampire);
//	vampire->attack(mage);
//	vampire->attack(soldier);
//	soldier->attack(vampire);
//	mage->castSpell(vampire,Spell::Blast);


//	soldier->attack(rogue);
//	rogue->attack(mage);

//	std::cout << *werewolf;
//	std::cout << *vampire;
//	std::cout << *mage;
//	std::cout << *rogue;
//	std::cout << *warlock;
//	std::cout << *necromancer;
//	std::cout << *berserker;
//	std::cout << *priest;
//	std::cout << *healer;
////	std::cout << *demon;
//	std::cout << *soldier;

//	delete werewolf;
//	delete vampire;
//	delete rogue;
//	delete rogue2;
//	delete rogue3;
//	delete rogue4;
//	delete rogue5;
//	delete rogue6;
//	delete rogue7;
//	delete rogue8;
//	delete rogue9;
//	delete rogue10;
//	delete rogue11;
//	delete rogue12;
//	delete rogue13;
//	delete rogue14;
//	delete rogue15;
//	delete rogue16;
//	delete rogue17;
//	delete rogue18;
//	delete rogue19;
//	delete rogue20;
//	delete rogue21;
//	delete rogue22;
//	delete rogue23;
//	delete rogue24;
//	delete rogue25;
//	delete rogue26;
//	delete rogue27;
//	delete rogue28;
//	delete rogue29;
//	delete rogue30;
//	delete rogue31;

//	delete soldier;
//	delete soldier2;
//	delete soldier3;
//	delete soldier4;
//	delete soldier5;
//	delete soldier6;
//	delete soldier7;
//	delete soldier8;
//	delete soldier9;
//	delete soldier10;
//	delete soldier11;
//	delete soldier12;
//	delete soldier13;
//	delete soldier14;
//	delete soldier15;
//	delete soldier16;
//	delete soldier17;
//	delete soldier18;
//	delete soldier19;
//	delete soldier20;
//	delete soldier21;
//	delete soldier22;
//	delete soldier23;
//	delete soldier24;
//	delete soldier25;
//	delete soldier26;
//	delete soldier27;
//	delete soldier28;
//	delete soldier29;
//	delete soldier30;
//	delete soldier31;
//	delete soldier32;
//	delete soldier33;
//	delete soldier34;
//	delete soldier35;
//	delete werewolf;
//	delete mage;
//	delete warlock;
//	delete necromancer;
//	delete berserker;
//	delete priest;
//	delete healer;

//	delete demon;
//	delete s;
//	delete game;
	return 0;
}