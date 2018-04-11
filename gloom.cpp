#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-all-loops")
#pragma GCC optimize("inline")

using namespace std;
#define ATTACK (2)

enum cardType { MINUS_ONE, MINUS_TWO, PLUS_ONE, PLUS_TWO, ZERO, MISS, DOUBLE, DRAW, PLUS_ONE_AND_DRAW, NB_CARD_TYPE };

static vector<cardType> cards_basic = {MINUS_ONE, MINUS_ONE, MINUS_ONE, MINUS_ONE, MINUS_ONE, MINUS_TWO, PLUS_ONE,
                                       PLUS_ONE,  PLUS_ONE,  PLUS_ONE,  PLUS_ONE,  PLUS_TWO,  ZERO,      ZERO,
                                       ZERO,      ZERO,      ZERO,      ZERO,      MISS,      DOUBLE};

static map<cardType, string> cardTypeText = {{MINUS_ONE, "-1"},
                                             {MINUS_TWO, "-2"},
                                             {PLUS_ONE, "+1"},
                                             {PLUS_TWO, "+2"},
                                             {ZERO, "+0"},
                                             {MISS, "MISS"},
                                             {DOUBLE, "x2"},
                                             {DRAW, "Draw"},
                                             {PLUS_ONE_AND_DRAW, "+1&Draw"}};

static int attack_s = ATTACK;

template <typename ContainerType>
void SwapAndPopAtIndex(ContainerType &container, size_t index) {
  if ((index + 1) >= container.size()) return;
  swap(container[index], container.back());
  container.pop_back();
}

int addAttack(int a, cardType c) {
  switch (c) {
    case MINUS_ONE:
      return a - 1;
    case MINUS_TWO:
      return a - 2;
    case PLUS_ONE:
      return a + 1;
    case PLUS_TWO:
      return a + 2;
    case ZERO:
      return a;
    case MISS:
      return 0;
    case DOUBLE:
      return a * 2;
    case DRAW:
      return a;
    case PLUS_ONE_AND_DRAW:
      return a + 1;
    case NB_CARD_TYPE:
      return a;
  }
}

cardType drawCard(int &attack, vector<cardType> &cards, vector<int> &counters) {
  int      k    = rand() % cards.size();
  cardType card = cards[k];
  SwapAndPopAtIndex(cards, k);
  counters[card]++;
  attack = addAttack(attack, card);
  return card;
}

void printSimuResults(vector<int> &counters, int nbTurn, double totalAttack) {
  cout << "  >> -1         -2         +1         +2         +0         Miss       x2         Draw       +1&Draw"
       << endl;
  cout << "  >> ";
  int nc = 0;
  for (auto c : counters) {
    cout << left << setw(10) << c << " ";
    nc += c;
  }
  cout << endl;
  cout << "  >> ";
  for (auto c : counters) {
    double       p = ((double)c / (double)nc)       *100;
    stringstream stream;
    stream << fixed << setprecision(2) << p << "%";
    string s = stream.str();
    cout << left << setw(10) << s << " ";
  }
  cout << endl;
  cout << "average attack = " << totalAttack / nbTurn << endl << endl;
}

void simuCards(int nbTurn, vector<cardType> &ref_cards) {
  cout << "SIMU FOR [";
  for (auto c : ref_cards) {
    cout << cardTypeText.at(c) << ",";
  }
  cout << "]" << endl;
  vector<cardType> cards       = ref_cards;
  vector<int>      counters    = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  double           totalAttack = 0;
  for (int i = 0; i < nbTurn; i++) {
    int      attack = attack_s;
    cardType card   = drawCard(attack, cards, counters);
    while (card == DRAW || card == PLUS_ONE_AND_DRAW) {
      card = drawCard(attack, cards, counters);
    }
    if (card == MISS || card == DOUBLE) {
      cards = ref_cards;
    }
    totalAttack += attack;
  }

  printSimuResults(counters, nbTurn, totalAttack);
}

int main() {
  int         nbTurn;
  vector<int> inputNbCards = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << "*** GLOOMHAVEN ATTACK DECK CARDS SIMULATOR ***" << endl << endl;
  cout << "Please enter the following (one line input) :" << endl;
  cout << "  Number of : SimulationTurn , attack, -1 , -2 , +1 , +2 , +0 , Miss , x2 , Draw , +1&Draw" << endl << endl;
  cin >> nbTurn >> attack_s >> inputNbCards[0] >> inputNbCards[1] >> inputNbCards[2] >> inputNbCards[3] >>
      inputNbCards[4] >> inputNbCards[5] >> inputNbCards[6] >> inputNbCards[7] >> inputNbCards[8];
  cin.ignore();
  vector<vector<cardType> > ref_cards;
  ref_cards.push_back(cards_basic);
  vector<cardType> cards;
  for (int c = MINUS_ONE; c < NB_CARD_TYPE; c++) {
    cards.insert(cards.end(), inputNbCards[c], (cardType)c);
  }
  ref_cards.push_back(cards);
  for (auto &c : ref_cards) {
    simuCards(nbTurn, c);
  }
}
