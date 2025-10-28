#include <iostream>
#include <string>
using namespace std;

int main() {

    // --- Node Structure ---
    struct Node {
        int id;
        string name;
        string choice;
        bool hasVoted;
        Node* next;
    };

    Node* head = NULL;
    Node* token = NULL;

    auto addVoter = [&](int id, string name) {
        Node* nn = new Node{id, name, "None", false, NULL};
        if (!head) {
            head = nn;
            nn->next = head;
            token = head;
        } else {
            Node* temp = head;
            bool exists = false;
            do {
                if (temp->id == id) exists = true;
                temp = temp->next;
            } while (temp != head);

            if (exists) {
                cout << "Duplicate ID ignored for " << name << endl;
                delete nn;
                return;
            }

            while (temp->next != head) temp = temp->next;
            temp->next = nn;
            nn->next = head;
        }
        cout << "Added Voter: " << name << " (ID " << id << ")\n";
    };

    auto displayCircle = [&]() {
        if (!head) { cout << "No voters in the circle.\n"; return; }
        Node* temp = head;
        cout << "Circle: ";
        do {
            cout << temp->name;
            if (temp->next != head) cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " -> (back to " << head->name << ")\n";
    };

    auto passToken = [&](int steps) {
        if (!token) { cout << "No voters to pass token.\n"; return; }
        for (int i = 0; i < steps; i++) token = token->next;
        cout << "Token now at: " << token->name << endl;
    };

    auto castVote = [&](string choice) {
        if (!token) { cout << "No token holder.\n"; return; }
        if (token->hasVoted) {
            cout << token->name << " has already voted.\n";
            return;
        }
        token->choice = choice;
        token->hasVoted = true;
        cout << token->name << " casts vote: " << choice << endl;
    };

    auto tallyVotes = [&]() {
        if (!head) { cout << "No voters to tally.\n"; return string("None"); }
        int yes = 0, no = 0, abstain = 0;
        Node* temp = head;
        do {
            if (temp->choice == "Yes") yes++;
            else if (temp->choice == "No") no++;
            else if (temp->choice == "Abstain") abstain++;
            temp = temp->next;
        } while (temp != head);

        cout << "\nTALLY RESULTS:\n";
        cout << "Yes: " << yes << " | No: " << no << " | Abstain: " << abstain << endl;

        string result = "None";
        if (yes > no && yes > abstain) result = "Yes";
        else if (no > yes && no > abstain) result = "No";
        else if (yes == no && yes > abstain) result = "Tie";
        else result = "NoMajority";

        return result;
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
                cout << "Removed voter ID " << id << " (" << curr->name << ")\n";
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    };

    auto resetVotes = [&]() {
        if (!head) return;
        Node* temp = head;
        do {
            temp->choice = "None";
            temp->hasVoted = false;
            temp = temp->next;
        } while (temp != head);
        cout << "Votes reset for next round.\n";
    };

    auto runRound = [&]() {
        if (!head) { cout << "Empty circle.\n"; return; }
        cout << "\n--- New Voting Round ---\n";
        Node* start = token;
        do {
            if (!token->hasVoted) {
                string ch;
                cout << token->name << "'s turn (Yes/No/Abstain): ";
                cin >> ch;
                token->choice = ch;
                token->hasVoted = true;
            }
            token = token->next;
        } while (token != start);

        string result = tallyVotes();
        if (result == "Tie" || result == "NoMajority") {
            cout << "\nNo majority detected (result=" << result << "). Chair (" 
                 << token->name << ") will cast tie-breaker.\n";
            cout << token->name << " (Chair) cast final vote (Yes/No): ";
            string chairVote; 
            cin >> chairVote;
            cout << "Final Winner: " << chairVote << endl;
        } else {
            cout << "\nWinner: " << result << endl;
        }
    };

    // ---------------- DEMO -----------------
    cout << "\n--- Circular Election Voting System ---\n";
    addVoter(1, "Alice");
    addVoter(2, "Bob");
    addVoter(3, "Carol");
    displayCircle();

    cout << "\nRound 1:\n";
    token = head; 
    castVote("Yes");
    passToken(1);
    castVote("No");
    passToken(1);
    castVote("Abstain");

    string r1 = tallyVotes();
    if (r1 == "Tie" || r1 == "NoMajority") {
        cout << "\nNo majority -> removing lowest voter (Bob)\n";
        removeVoter(2);
    }

    resetVotes();

    cout << "\nRound 2:\n";
    token = head; 
    castVote("Yes");
    passToken(1);
    castVote("Yes");

    string r2 = tallyVotes();
    if (r2 == "Tie" || r2 == "NoMajority") {
        cout << "\nTie again, chair vote needed.\n";
        runRound();
    } else {
        cout << "\nFinal Winner: " << r2 << endl;
    }

    cout << "\n--- End of Simulation ---\n";
    return 0;
}
