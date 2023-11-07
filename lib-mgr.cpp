#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool checkedOut = false;
};

struct Borrower {
    string name;
    string id;
};

struct Transaction {
    Book book;
    Borrower borrower;
    string checkoutDate;
    string returnDate;
};

vector<Book> books;
vector<Borrower> borrowers;
vector<Transaction> transactions;

void displayMenu() {
    cout << "---- Library Management System ----" << endl;
    cout << "1. Add Book\n2. Add Borrower\n3. Search Books\n4. Check Out Book\n5. Return Book\n6. View Transactions\n7. Quit\n";
}

void addBook() {
    Book b;
    cout << "Enter title: ";
    getline(cin, b.title);
    cout << "Enter author: ";
    getline(cin, b.author);
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    books.push_back(b);
    cout << "Book added to the library!" << endl;
}

void addBorrower() {
    Borrower br;
    cout << "Enter name: ";
    getline(cin, br.name);
    cout << "Enter ID: ";
    getline(cin, br.id);
    borrowers.push_back(br);
    cout << "Borrower added!" << endl;
}

void searchBooks() {
    cout << "Search by (1. Title, 2. Author, 3. ISBN): ";
    int opt;
    cin >> opt;
    cin.ignore();
    string term;
    cout << "Enter search term: ";
    getline(cin, term);

    cout << "Search Results:" << endl;
    for (const Book& b : books) {
        bool match = false;
        if ((opt == 1 && b.title.find(term) != string::npos) ||
            (opt == 2 && b.author.find(term) != string::npos) ||
            (opt == 3 && b.isbn.find(term) != string::npos)) {
            cout << "Title: " << b.title << ", Author: " << b.author << ", ISBN: " << b.isbn << (b.checkedOut ? " (Checked Out)" : "") << endl;
        }
    }
}

void transactBook(bool checkOut) {
    cout << "Enter borrower ID: ";
    string id;
    getline(cin, id);

    Borrower* br = nullptr;
    for (Borrower& b : borrowers) {
        if (b.id == id) {
            br = &b;
            break;
        }
    }

    if (br == nullptr) {
        cout << "Borrower not found." << endl;
        return;
    }

    cout << "Enter ISBN of the book to " << (checkOut ? "check out" : "return") << ": ";
    string isbn;
    getline(cin, isbn);

    Book* b = nullptr;
    for (Book& book : books) {
        if (book.isbn == isbn && (checkOut ? !book.checkedOut : book.checkedOut)) {
            b = &book;
            break;
        }
    }

    if (b == nullptr) {
        cout << "Book not found or already " << (checkOut ? "checked out." : "returned.") << endl;
        return;
    }

    b->checkedOut = checkOut;

    Transaction t = { *b, *br, "", "" };
    if (checkOut) {
        transactions.push_back(t);
        cout << "Book checked out successfully!" << endl;
    } else {
        cout << "Book returned successfully!" << endl;
        for (Transaction& trans : transactions) {
            if (trans.book.isbn == isbn && trans.returnDate.empty()) {
                trans.returnDate = "Today"; // Implement date system
                break;
            }
        }
    }
}

void viewTransactions() {
    cout << "Transaction History:" << endl;
    for (const Transaction& t : transactions) {
        cout << "Title: " << t.book.title << ", Author: " << t.book.author;
        cout << ", Borrower: " << t.borrower.name << ", Check Out Date: " << t.checkoutDate;
        if (!t.returnDate.empty()) {
            cout << ", Return Date: " << t.returnDate;
        }
        cout << endl;
    }
}

int main() {
    displayMenu();
    while (true) {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addBorrower();
                break;
            case 3:
                searchBooks();
                break;
            case 4:
                transactBook(true); // Check out
                break;
            case 5:
                transactBook(false); // Return
                break;
            case 6:
                viewTransactions();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
