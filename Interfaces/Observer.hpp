/*_Created_by_K1ngp1n_*/

#pragma once

#include <map>
#include <set>


class AbstractUnit;
class AbstractState;

class Observer {
	std::map<AbstractUnit*, std::set<AbstractUnit*>> m_list_of_victims;
	static Observer* instance;
	protected:
	Observer();
	
	~Observer();
	
	public:
	static Observer* getInstance();

	void add(AbstractUnit* observer, AbstractUnit* observable);
	void informObserver(AbstractUnit* unit);
	void informObservable(AbstractUnit *unit);

	bool checkSoul(AbstractUnit* victim) const;
};



