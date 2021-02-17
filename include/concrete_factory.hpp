#ifndef __CONCRETE_FACTORY_HPP__
#define __CONCRETE_FACTORY_HPP__

class CavernFactory: public EnemyFactory {
public:
   virtual Enemy getWarrior() override;
   virtual Enemy getArcher() override;
   virtual Enemy getWizard() override;
};

class DesertFactory: public EnemyFactory {
public:
   virtual Enemy getWarrior() override;
   virtual Enemy getArcher() override;
   virtual Enemy getWizard() override;
};

class MountainFactory: public EnemyFactory {
public:
   virtual Enemy getWarrior() override;
   virtual Enemy getArcher() override;
   virtual Enemy getWizard() override;
};

#endif // __CONCRETE_FACTORY_HPP__