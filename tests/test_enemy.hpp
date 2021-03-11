
TEST(Enemy, SetsName) {
  Enemy enemy("Name123", 0, 0, 0, 0);

  EXPECT_EQ(enemy.getName(), "Name123");
}

TEST(Enemy, DiesAtHealthZero) {
  Enemy enemy("Enemy", 0, 0, 0, 0);
  
  EXPECT_EQ(enemy.isAlive(), false);

}

TEST(Enemy, DefenseReducesDamage) {
  Enemy enemy1("Enemy", 0, 100, 0, 0);
  Enemy enemy2("Enemy", 0, 100, 0, 0);

  enemy1.takeDamage(10);
  enemy1.takeDamage(10);

  EXPECT_LT(enemy1.getCurrentHealth(), enemy2.getCurrentHealth());
}

TEST(Enemy, MinDamageIsOne) {
  Enemy enemy("Enemy", 0, 100, 10000, 0);

  enemy.takeDamage(1);

  EXPECT_EQ(enemy.getCurrentHealth(), 99); 
}

TEST(Enemy, StrengthIncreasesDamage) {
  Enemy enemy1("Enemy", 0, 100, 0, 0);
  Enemy enemy2("Enemy", 0, 100, 0, 10);
  Enemy target1("Enemy", 0, 100, 0, 0);
  Enemy target2("Enemy", 0, 100, 0, 0);

  enemy1.simpleAttack(&target1);
  enemy2.simpleAttack(&target2);

  EXPECT_GT(target1.getCurrentHealth(), target2.getCurrentHealth());
}
