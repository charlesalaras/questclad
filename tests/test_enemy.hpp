
TEST(Enemy, SetsName) {
  Enemy enemy("Name123", 10, 0, 0);

  EXPECT_EQ(enemy.getName(), "Name123");
}

TEST(Enemy, DiesAtHealthZero) {
  Enemy enemy("Enemy", 0, 0, 0);
  
  EXPECT_EQ(enemy.isAlive(), false);

}

TEST(Enemy, DefenseReducesDamage) {
  Enemy enemy1("Enemy", 100, 10, 0);
  Enemy enemy2("Enemy", 100, 0, 0);

  enemy1.takeDamage(10);
  enemy1.takeDamage(10);

  EXPECT_LT(enemy1.getCurrentHealth(), enemy2.getCurrentHealth());
}

TEST(Enemy, MinDamageIsOne) {
  Enemy enemy("Enemy", 100, 10000, 0);

  enemy.takeDamage(1);

  EXPECT_EQ(enemy.getCurrentHealth(), 99); 
}

TEST(Enemy, StrengthIncreasesDamage) {
  
}
