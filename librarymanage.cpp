#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued = false;
    string issuedTo;
    string dueDate;
};

struct Member {
    int id;
    string name;
    string contact;
};

vector<Book> books;
vector<Member> members;

void addBook() {
    Book b;
    cout << "Enter Book ID: "; cin >> b.id;
    cin.ignore();
    cout << "Enter Title: "; getline(cin, b.title);
    cout << "Enter Author: "; getline(cin, b.author);
    books.push_back(b);
    cout << "Book added.\n";
}

void displayAllBooks() {
    if (books.empty()) { cout << "No books found.\n"; return; }
    for (Book b : books) {
        cout << "ID: " << b.id << ", Title: " << b.title << ", Author: " << b.author;
        if (b.isIssued) cout << " [Issued to: " << b.issuedTo << ", Due: " << b.dueDate << "]";
        cout << endl;
    }
}

void searchBookByID() {
    int id;
    cout << "Enter Book ID: "; cin >> id;
    for (Book b : books) {
        if (b.id == id) {
            cout << "Found - Title: " << b.title << ", Author: " << b.author << endl;
            return;
        }
    }
    cout << "Book not found.\n";
}

void updateBook() {
    int id;
    cout << "Enter Book ID to update: "; cin >> id;
    for (Book &b : books) {
        if (b.id == id) {
            cin.ignore();
            cout << "Enter new title: "; getline(cin, b.title);
            cout << "Enter new author: "; getline(cin, b.author);
            cout << "Updated.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: "; cin >> id;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            cout << "Deleted.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void addMember() {
    Member m;
    cout << "Enter Member ID: "; cin >> m.id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, m.name);
    cout << "Enter Contact: "; getline(cin, m.contact);
    members.push_back(m);
    cout << "Member added.\n";
}

void issueBook() {
    int bookID, memberID;
    cout << "Enter Book ID: "; cin >> bookID;
    cout << "Enter Member ID: "; cin >> memberID;
    for (Book &b : books) {
        if (b.id == bookID && !b.isIssued) {
            for (Member m : members) {
                if (m.id == memberID) {
                    b.isIssued = true;
                    b.issuedTo = m.name;
                    cin.ignore();
                    cout << "Enter Due Date (DD-MM-YYYY): "; getline(cin, b.dueDate);
                    cout << "Book issued to " << m.name << endl;
                    return;
                }
            }
            cout << "Member not found.\n";
            return;
        }
    }
    cout << "Issue failed (Book may not exist or is already issued).\n";
}

void returnBook() {
    int bookID;
    cout << "Enter Book ID to return: "; cin >> bookID;
    for (Book &b : books) {
        if (b.id == bookID && b.isIssued) {
            b.isIssued = false;
            b.issuedTo = "";
            b.dueDate = "";
            cout << "Book returned.\n";
            return;
        }
    }
    cout << "Return failed.\n";
}

void showIssuedBooks() {
    bool any = false;
    for (Book b : books) {
        if (b.isIssued) {
            cout << "Book ID: " << b.id << ", Title: " << b.title
                 << ", Issued to: " << b.issuedTo << ", Due: " << b.dueDate << endl;
            any = true;
        }
    }
    if (!any) cout << "No books are currently issued.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====== LIBRARY MAIN MENU ======\n";
        cout << "1. Add Book\n2. Display All Books\n3. Search Book\n4. Update Book\n";
        cout << "5. Delete Book\n6. Add Member\n7. Issue Book\n8. Return Book\n";
        cout << "9. Show Issued Books\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayAllBooks(); break;
            case 3: searchBookByID(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: addMember(); break;
            case 7: issueBook(); break;
            case 8: returnBook(); break;
            case 9: showIssuedBooks(); break;
            case 10: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    return 0;
}
