#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, pair<string, int>> menu = {
        {1, {"Pepperoni", 799}},
        {2, {"Margherita", 699}},
        {3, {"Veggie", 749}},
        {4, {"Meat Lovers", 999}},
        {5, {"Hawaiian", 899}}
    };

    vector<string> payments = {"Cash on Delivery", "Online Payment", "UPI", "Card Payment"};
    vector<string> orderedPizzas;
    int totalCost = 0;
    int choice;

    cout << "\nWelcome to Snehal's Pizza Chatbot!\n";
    for (auto item : menu) {
        cout << item.first << ". " << item.second.first << " - Rs." << item.second.second << endl;
    }

    // Loop for multiple orders
    while (true) {
        cout << "\nEnter the pizza you want to order (0 to finish): ";
        cin >> choice;

        if (choice == 0) break;

        if (menu.find(choice) != menu.end()) {
            orderedPizzas.push_back(menu[choice].first);
            totalCost += menu[choice].second;
            cout << menu[choice].first << " added to your order.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    if (orderedPizzas.empty()) {
        cout << "No pizzas ordered. Exiting.\n";
        return 0;
    }

    cout << "\nPayment Methods:\n";
    for (int i = 0; i < payments.size(); i++) {
        cout << i + 1 << ". " << payments[i] << endl;
    }

    int paymentChoice;
    cout << "\nEnter the number for your payment method: ";
    cin >> paymentChoice;

    if (paymentChoice < 1 || paymentChoice > payments.size()) {
        cout << "Invalid payment method. Exiting.\n";
        return 0;
    }

    // Final Receipt
    cout << "\nGenerating receipt...\n";
    cout << "You ordered:\n";
    for (auto pizza : orderedPizzas) {
        cout << "- " << pizza << endl;
    }
    cout << "Total Cost: Rs." << totalCost << endl;
    cout << "Payment Method: " << payments[paymentChoice - 1] << ".\n";
    cout << "Thank you for ordering at Snehal's Pizza!\n";

    return 0;
}
