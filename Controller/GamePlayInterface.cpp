/*_Created_by_K1ngp1n_*/

#include <zconf.h>
#include "GamePlayInterface.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Controller/Question.hpp"


bool onChoiceAnsweredFillTeams(int answer) {

	if ( answer == 1 ) {
		BattleField::getInstance()->getTeam()->randomFillUnitsOnBoard();
		return true;
	} else if ( answer == 2 ) {
		BattleField::getInstance()->manualFactory();
		return true;
	}
	return false;
}

bool onChoiceAnsweredSelectTeam(int answer) {

	if ( answer == 0 ) {
		BattleField::getInstance()->getTeam()->showUnitsOnField(0);
		return true;
	} else if ( answer == 1 ) {
		BattleField::getInstance()->getTeam()->showUnitsOnField(1);
		return true;
	} else if ( answer == 2 ) {
		BattleField::getInstance()->getTeam()->showUnitsOnField(2);
		return true;
	} else if ( answer == 3 ) {
		/********************AUTO FIGHT***********************/
//		BattleField::getInstance()->getTeam()->showUnitsOnField(2);
		return true;
	}
	return false;
}

bool onChoiceAnsweredSelectUnit(int answer) {

	if ( BattleField::getInstance()->getSelectUnit(answer)) {
		return true;
	}
	return false;
}

bool selectAction(int answer) {

	if ( BattleField::getInstance()->m_actions.count(answer) ) {
		std::cout << "Action "
		<< BattleField::getInstance()->m_actions.find(answer)->second->getType()
		<< " selected." << std::endl;

		BattleField::getInstance()->actionOfSelectedUnit(answer);
		return true;
	}
	return false;
}

void askSomeQuestion(const std::string& question, const std::function<bool(int)>& answerHandler) {
	int answer = askQuestion(question);
	if ( !answerHandler(answer)) {
		std::cout << "try again" << std::endl;
		askSomeQuestion(question, answerHandler);
	}
}

GamePlayInterface::GamePlayInterface() {}

GamePlayInterface::~GamePlayInterface() {}

void GamePlayInterface::start() {
	std::cout << "GamePlayInterface *start*." << std::endl;
/***************************************************************/

	std::string question = "*1* (auto) // \n"
	                       "*2* (by hand)\n"
	                       "Enter your choice: \n";

	askSomeQuestion(question, &onChoiceAnsweredFillTeams);
	BattleField::getInstance()->printBattleField();
/***************************************************************/
	question = "      Select team.\n"
	           "*0* - show all units.\n"
	           "*1* - show BLUE team units.\n"
	           "*2* - show RED team units.\n"
			   "*3* - <automatic fight> (NOT WORKING)\n\n"
	           "      Enter your choice: \n";
	askSomeQuestion(question, &onChoiceAnsweredSelectTeam);
/***************************************************************/
	for ( int circle = 1; BattleField::getInstance()->getTeam()->checkTeam(); ) {


		question = "      Select unit: \n";
		askSomeQuestion(question, &onChoiceAnsweredSelectUnit);
/***************************************************************/
		question = "      Select action of this unit: \n";
		askSomeQuestion(question, &selectAction);
/***************************************************************/
		std::cout << "                                                circle " << circle << std::endl;
		circle++;

		BattleField::getInstance()->m_free_points_to_move.clear();
		BattleField::getInstance()->m_actions.clear();
		BattleField::getInstance()->m_selected_units.clear();
		BattleField::getInstance()->m_available_targets.clear();
		BattleField::getInstance()->m_available_spells.clear();
		BattleField::getInstance()->m_inventory.clear();

		BattleField::getInstance()->printBattleField();
		sleep(1);

		question = "      Select team.\n"
		           "*0* - show all units.\n"
		           "*1* - show BLUE team units.\n"
		           "*2* - show RED team units.\n"
		           "*3* - <automatic fight> (NOT WORKING)\n\n"
		           "      Enter your choice: \n";
		askSomeQuestion(question, &onChoiceAnsweredSelectTeam);
	}
	std::cout << std::endl <<  std::endl <<  "-----------==== G A M E - O V E R ====-----------" << std::endl;
}

