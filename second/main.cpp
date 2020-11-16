#include "../second/Ant/ant.h"
int main(int argc, char *argv[]) {
  Ant ant(2, 2, 2);
  ant.run(*(new Particle));
  ant.getParameters();
  return 0;
}
