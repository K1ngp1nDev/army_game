QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += Abilities \
               Armour \
Controller\
Exceptions\
Interfaces\
Spells\
States\
Units\
Weapons

SOURCES += \
        main.cpp \
    Abilities/ClassicAttack.cpp \
    Abilities/DaemonAttack.cpp \
    Abilities/NecromancerAttack.cpp \
    Abilities/RogueAttack.cpp \
    Abilities/SourceAttack.cpp \
    Abilities/SpecialAbility.cpp \
    Abilities/Transformation.cpp \
    Abilities/VampireAttack.cpp \
    Abilities/WereWolfAttack.cpp \
    Armour/Shield.cpp \
    Controller/AnswerByHandFillAll.cpp \
    Controller/AnswerOfActionSelectedUnit.cpp \
    Controller/AnswerOfChoiseUnit.cpp \
    Controller/AnswerOfSelectTeam.cpp \
    Controller/AnswerQuestionChoiceStart.cpp \
    Controller/GamePlayInterface.cpp \
    Controller/ListOfActions.cpp \
    Controller/QuestionChoiceStart.cpp \
    Controller/QuestionOfActionSelectedUnit.cpp \
    Controller/QuestionOfSelectTeam.cpp \
    Controller/QuestionOfSelectUnit.cpp \
    Controller/RandomFillAnswer.cpp \
    Interfaces/AbstractAttack.cpp \
    Interfaces/AbstractCaster.cpp \
    Interfaces/AbstractMagicState.cpp \
    Interfaces/AbstractPhysician.cpp \
    Interfaces/AbstractSpell.cpp \
    Interfaces/AbstractState.cpp \
    Interfaces/AbstractUnit.cpp \
    Interfaces/AbstractWeapon.cpp \
    Interfaces/BattleField.cpp \
    Interfaces/Team.cpp \
    Spells/Blast.cpp \
    Spells/FireBall.cpp \
    Spells/GreaterHeal.cpp \
    Spells/Heal.cpp \
    Spells/SummonDaemon.cpp \
    States/DaemonState.cpp \
    States/HumanWolfState.cpp \
    States/MageState.cpp \
    States/RogueState.cpp \
    States/SoldierState.cpp \
    States/SourceState.cpp \
    States/VampireState.cpp \
    States/WarlockState.cpp \
    States/WereWolfState.cpp \
    Units/Berserker.cpp \
    Units/Daemon.cpp \
    Units/Healer.cpp \
    Units/Mage.cpp \
    Units/Necromancer.cpp \
    Units/Priest.cpp \
    Units/Rogue.cpp \
    Units/Soldier.cpp \
    Units/Vampire.cpp \
    Units/Warlock.cpp \
    Units/WereWolf.cpp \
    Weapons/BlackStaff.cpp \
    Weapons/Claws.cpp \
    Weapons/Dagger.cpp \
    Weapons/Fists.cpp \
    Weapons/SourceWeapon.cpp \
    Weapons/Teeth.cpp \
    Weapons/VikingSword.cpp \
    actionfactory.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Abilities/ClassicAttack.hpp \
    Abilities/DaemonAttack.hpp \
    Abilities/NecromancerAttack.hpp \
    Abilities/RogueAttack.hpp \
    Abilities/SourceAttack.hpp \
    Abilities/SpecialAbility.hpp \
    Abilities/Transformation.hpp \
    Abilities/VampireAttack.hpp \
    Abilities/WereWolfAttack.hpp \
    Armour/Shield.hpp \
    Controller/Action.hpp \
    Controller/ActionMageCast.hpp \
    Controller/ActionUnitMove.hpp \
    Controller/Answer.hpp \
    Controller/AnswerByHandFillAll.hpp \
    Controller/AnswerOfActionSelectedUnit.hpp \
    Controller/AnswerOfChoiseUnit.hpp \
    Controller/AnswerOfSelectTeam.hpp \
    Controller/AnswerQuestionChoiceStart.hpp \
    Controller/GamePlayInterface.hpp \
    Controller/ListOfActions.hpp \
    Controller/Question.hpp \
    Controller/QuestionChoiceStart.hpp \
    Controller/QuestionOfActionSelectedUnit.hpp \
    Controller/QuestionOfSelectTeam.hpp \
    Controller/QuestionOfSelectUnit.hpp \
    Controller/RandomFillAnswer.hpp \
    Exceptions/DaemonDoesNotExistException.hpp \
    Exceptions/OutOfManaException.hpp \
    Exceptions/UnitIsDeadException.hpp \
    Interfaces/AbstractAttack.hpp \
    Interfaces/AbstractCaster.hpp \
    Interfaces/AbstractMagicState.hpp \
    Interfaces/AbstractPhysician.hpp \
    Interfaces/AbstractSpell.hpp \
    Interfaces/AbstractState.hpp \
    Interfaces/AbstractUnit.hpp \
    Interfaces/AbstractWeapon.hpp \
    Interfaces/BattleField.hpp \
    Interfaces/Point.hpp \
    Interfaces/SpellBook.hpp \
    Interfaces/Team.hpp \
    Interfaces/Undead.hpp \
    Spells/Blast.hpp \
    Spells/FireBall.hpp \
    Spells/GreaterHeal.hpp \
    Spells/Heal.hpp \
    Spells/SummonDaemon.hpp \
    States/DaemonState.hpp \
    States/HumanWolfState.hpp \
    States/MageState.hpp \
    States/RogueState.hpp \
    States/SoldierState.hpp \
    States/SourceState.hpp \
    States/VampireState.hpp \
    States/WarlockState.hpp \
    States/WereWolfState.hpp \
    Units/Berserker.hpp \
    Units/Daemon.hpp \
    Units/Healer.hpp \
    Units/Mage.hpp \
    Units/Necromancer.hpp \
    Units/Priest.hpp \
    Units/Rogue.hpp \
    Units/Soldier.hpp \
    Units/Vampire.hpp \
    Units/Warlock.hpp \
    Units/WereWolf.hpp \
    Weapons/BlackStaff.hpp \
    Weapons/Claws.hpp \
    Weapons/Dagger.hpp \
    Weapons/Fists.hpp \
    Weapons/SourceWeapon.hpp \
    Weapons/Teeth.hpp \
    Weapons/VikingSword.hpp \
    Controller/ActionMeleeAttack.hpp \
    actionfactory.h
