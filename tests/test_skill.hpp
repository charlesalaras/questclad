#include "character/skill.hpp"
#include "character/user.hpp"

TEST(Skill, Name) {
  Skill skill("Name123", 0, 0);
  
  EXPECT_EQ(skill.getName(), "Name123");
}

TEST(Skill, DealsDamage) {
  Skill skill("Name", 10, 0);
  
  Enemy enemy("Enemy", 0, 100, 0, 0);
  skill.use(&enemy);

  EXPECT_LT(enemy.getCurrentHealth(), enemy.getHealth());
}

TEST(Skill, UserHasFour) {
  User user("Name", 0);

  EXPECT_EQ(user.getSkills().size(), 4);
}

TEST(Skill, DoesCorrectDamage) {
  Skill skill("Name", 10, 0);
  
  Enemy enemy("Enemy", 0, 100, 0, 0);
  skill.use(&enemy);

  EXPECT_EQ(enemy.getCurrentHealth(), 90);
}
