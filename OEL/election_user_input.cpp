#include <iostream>
#include <string>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand
using namespace std;

int main() {
    struct Node {
        int id;
        string name;
        string choice;
        bool hasVoted;
        Node* next;
    };

    Node* head = NULL;
    Node* token = NULL;

    srand(time(0));

    auto addVoter = [&](int id, string name) {
        Node* nn = new Node{id, name, "None", false, NULL};
        if (!head) {
            head = nn;
            nn->next = head;
            token = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = nn;
            nn->next = head;
        }
        cout << "Added voter: " << name << " (ID " << id << ")\n";
    };

    auto displayCircle = [&]() {
        if (!head) { cout << "No voters in circle.\n"; return; }
        Node* temp = head;
        cout << "\nCurrent Circle: ";
        do {
            cout << temp->name;
            if (temp->next != head) cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " -> (back to " << head->name << ")\n";
    };

    auto passToken = [&](int steps) {
        if (!token) { cout << "No token holder.\n"; return; }
        for (int i = 0; i < steps; i++) token = token->next;
        cout << "Token now at: " << token->name << endl;
    };

    auto castVote = [&](string choice) {
        if (!token) return;
        if (token->hasVoted) {
            cout << token->name << " has already voted.\n";
            return;
        }
        token->choice = choice;
        token->hasVoted = true;
        cout << token->name << " votes: " << choice << endl;
    };

    auto tallyVotes = [&]() {
        int yes = 0, no = 0, abstain = 0;
        Node* temp = head;
        do {
            if (temp->choice == "Yes") yes++;
            else if (temp->choice == "No") no++;
            else if (temp->choice == "Abstain") abstain++;
            temp = temp->next;
        } while (temp != head);

        cout << "\nTALLY RESULTS:\nYes: " << yes << " | No: " << no << " | Abstain: " << abstain << endl;

        if (yes > no && yes > abstain) return string("Yes");
        else if (no > yes && no > abstain) return string("No");
        else if (yes == no && yes > abstain) return string("Tie");
        else return string("NoMajority");
    };

    auto resetVotes = [&]() {
        Node* temp = head;
        do {
            temp->choice = "None";
            temp->hasVoted = false;
            temp = temp->next;
        } while (temp != head);
    };

    auto removeVoter = [&](int id) {
        if (!head) return;
        Node* curr = head;
        Node* prev = NULL;
        do {
            if (curr->id == id) {
                if (curr == head && curr->next == head) {
                    head = NULL;
                    token = NULL;
                    delete curr;
                    cout << "Removed last voter.\n";
                    return;
                }
                if (curr == head) {
                    while (head->next != curr) head = head->next;
                    head->next = curr->next;
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                if (token == curr) token = curr->next;
                cout << "Removed voter ID " << id << endl;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    };

    // ---- MAIN PROGRAM LOOP ----
    cout << "\n--- Circular Election Voting System ---\n";
    int n;
    cout << "Enter number of voters: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string name;
        cout << "Enter name for voter " << i << ": ";
        cin >> name;
        addVoter(i, name);
    }

    displayCircle();

    int choiceMode;
    cout << "\nChoose voting mode:\n1. Manual Voting (user inputs Yes/No/Abstain)\n2. Automatic Random Voting\nEnter: ";
    cin >> choiceMode;

    int rounds;
    cout << "Enter number of rounds to simulate: ";
    cin >> rounds;

    for (int round = 1; round <= rounds; round++) {
        cout << "\n========== ROUND " << round << " ==========\n";
        Node* start = token;

        do {
            if (!token->hasVoted) {
                string vote;
                if (choiceMode == 1) {
                    cout << token->name << "'s turn (Yes/No/Abstain): ";
                    cin >> vote;
                } else {
                    int r = rand() % 3;
                    if (r == 0) vote = "Yes";
                    else if (r == 1) vote = "No";
                    else vote = "Abstain";
                    cout << token->name << " votes automatically: " << vote << endl;
                }
                castVote(vote);
            }
            token = token->next;
        } while (token != start);

        string result = tallyVotes();

        if (result == "Tie" || result == "NoMajority") {
            cout << "\nNo majority detected (result=" << result << ")\n";
            cout << "Chairperson (" << token->name << ") will cast tie-breaker vote.\n";
            string chairVote;
            if (choiceMode == 1) {
                cout << "Chair (" << token->name << ") vote (Yes/No): ";
                cin >> chairVote;
            } else {
                chairVote = (rand() % 2) ? "Yes" : "No";
                cout << "Chair automatically votes: " << chairVote << endl;
            }
            cout << "\nFINAL WINNER (by chair): " << chairVote << "\n";
        } else {
            cout << "\nMajority Winner: " << result << "\n";
        }

        resetVotes();

        char nextRound;
        cout << "\nDo you want to remove any voter before next round? (y/n): ";
        cin >> nextRound;
        if (nextRound == 'y' || nextRound == 'Y') {
            int remId;
            cout << "Enter voter ID to remove: ";
            cin >> remId;
            removeVoter(remId);
            displayCircle();
        }

        cout << "\nContinue to next round? (y/n): ";
        cin >> nextRound;
        if (nextRound == 'n' || nextRound == 'N') break;
    }

    cout << "\n--- Election Simulation Ended ---\n";
    return 0;
}
