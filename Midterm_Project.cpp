#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib> 
#include <random>

using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::sort;

class Card {
public:
    string suit;
    string label;
    int value;
    int alternateValue;
    int sortValue;

    Card(string s, string l, int v, int av, int sv)
        {
            suit = s;
            label = l;
            value = v;
            alternateValue = av;
            sortValue = sv;
        }

    bool operator==(const Card& other) const {
        return suit == other.suit && label == other.label && value == other.value &&
               alternateValue == other.alternateValue && sortValue == other.sortValue;
    }

    bool operator<(const Card& other) const {
        return sortValue < other.sortValue;
    }

    void DisplayCard() const {
        cout << "[" << label << " of " << suit << "] ";
    }
};

class Deck {
private:
    vector<Card> cards;
    vector<Card> initialCards;

public:
    Deck() {
        const string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        const string labels[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        int sortValue = 0;
        for (int s = 0; s < 4; s++) {
            for (int v = 2; v <= 14; v++) {
                Card newCard(suits[s], labels[v-2], v, v, sortValue); 
                cards.push_back(newCard);
                initialCards.push_back(newCard);
                sortValue++;
            }
        }
    }

    Deck(const vector<Card>& cardsSubset) 
    {
        cards = cardsSubset;
        initialCards = cardsSubset;
    }

    void addCard(const Card& new_card) {
        cards.push_back(new_card);
    }

    Card dealCard() {
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
    }

   pair<Deck, Deck> splitDeck() 
   {
        size_t mid = cards.size() / 2;
        vector<Card> half1(cards.begin(), cards.begin() + mid);
        vector<Card> half2(cards.begin() + mid, cards.end());
        return {Deck(half1), Deck(half2)};
    }

    bool isOriginalOrder() {
        return cards == initialCards;
    }

    void riffleShuffle(bool isInShuffle) {
        vector<Card> shuffledDeck;
        size_t halfSize = cards.size() / 2;
        auto it = cards.begin();

        for (size_t i = 0; i < halfSize; i++) {
            if (isInShuffle) {
                shuffledDeck.push_back(*(it + halfSize + i)); 
                shuffledDeck.push_back(*(it + i));
            } else {
                shuffledDeck.push_back(*(it + i));
                shuffledDeck.push_back(*(it + halfSize + i));
            }
        }

        cards = shuffledDeck;
    }

    void randomShuffle() {
        vector<Card> shuffledDeck;
        size_t halfSize = cards.size() / 2;
        vector<Card> firstHalf(cards.begin(), cards.begin() + halfSize);
        vector<Card> secondHalf(cards.begin() + halfSize, cards.end());

        size_t i = 0, j = 0;
        while (i < firstHalf.size() || j < secondHalf.size()) {
            int n = rand() % 4 + 1;
            for (int k = 0; k < n && i < firstHalf.size(); k++, i++) {
                shuffledDeck.push_back(firstHalf[i]);
            }
            for (int k = 0; k < n && j < secondHalf.size(); k++, j++) {
                shuffledDeck.push_back(secondHalf[j]);
            }
        }

        cards = shuffledDeck;
    }

    void shuffleUntilOriginal() {
        int count = 0;
        do {
            randomShuffle();
            count++;
        } while (!isOriginalOrder());
        cout << "It took " << count << " random riffle shuffles to return to its original state.\n";
    }

     int cardCount() const {
        return cards.size();
    }

    void displayDeck() const {
        for (const auto& card : cards) {
            card.DisplayCard();
        }
        cout << "\n\n";
    }

    void sortDeck() {
        sort(cards.begin(), cards.end());
    }
};

int main() {
    srand(time(NULL)); 

    Deck deck;
    cout << "Initial deck:\n";
    deck.displayDeck();

    auto [subdeck1, subdeck2] = deck.splitDeck();
    cout << "\nSubdeck 1:\n";
    subdeck1.displayDeck();
    cout << "Subdeck 2:\n";
    subdeck2.displayDeck();

    for (int i = 0; i < 8; i++) {
        deck.riffleShuffle(false); 
        cout << "After " << i + 1 << " out-shuffles:\n";
        deck.displayDeck();
    }

    Deck deckForInShuffle;
    for (int i = 0; i < 52; i++) {
        deckForInShuffle.riffleShuffle(true);
        cout << "After " << i + 1 << " in-shuffles:\n";
        deckForInShuffle.displayDeck();
    }

    Deck randomShuffleDeck;
    randomShuffleDeck.shuffleUntilOriginal();
    
    deck.sortDeck();

    return 0;
}
