// LibraryManagement.cpp : Library Book Management system to gain a better understanding of File handling. 
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

// Library class
class Library {
public:
    void MainMenu();
    void AddBook();
    void DisplayBook();
    void FindBook();
    void UpdateLibrary();
    void DeleteBook();
};

// Main Menu
void Library::MainMenu() {
    system("cls");

    std::cout << "=====Main Menu=====";
    std::cout << "1. Add Book";
    std::cout << "2. Display Book(s)";
    std::cout << "3. Find Book";
    std::cout << "4. Update Library";
    std::cout << "5. Delete Book";
    std::cout << "6. Exit";
}

// Add Book
void Library::AddBook() {
    system("cls");

    std::fstream f;

    int numOfBooks;

    std::string bookName;
    std::string bookId;
    std::string authorName;

    std::cout << "Add Books: ";

    std::cout << "Book Id: ";
    std::cin >> bookId;

    std::cout << "Book Name: ";
    std::cin >> bookName;

    std::cout << "Author Name: ";
    std::cin >> authorName;

    std::cout << "Number of Books: ";
    std::cin >> numOfBooks;

    // open file append|output mode
    f.open("D:// books.txt", std::ios::out | std::ios::app);
    f << " " << bookId << " " << bookName << " " << authorName << " " << numOfBooks << "\n";

    // close file
    f.close();
}

void Library::DisplayBook() {
    system("cls");

    std::fstream f;

    int numOfBooks;

    std::string bookName;
    std::string bookId;
    std::string authorName;

    std::cout << "List of All Books";

    f.open("D:// books.txt", std::ios::in);

    if (!f) {
        std::cout << "\nError cannot open file.";
    }
    else {
        std::cout << "Book Id\t\tBook Author\t\tNumber of Books\n";

        f >> bookId >> bookName;
        f >> authorName >> numOfBooks;

        // til end of file
        while (!f.eof()) {
            std::cout << " " << bookId << "\t\t" << bookName << "\t\t" << authorName << "\t\t" << numOfBooks << "\n\n";

            f >> bookId >> bookName;
            f >> authorName >> numOfBooks;
        }

        system("pause");

        // close file
        f.close();
    }
}

void Library::FindBook() {
    system("cls");

    std::fstream f;

    int numOfBooks;
    int count = 0;

    std::string bookId;
    std::string bookName;
    std::string authorName;
    std::string bookID;

    std::cout << "Find Book";

    f.open("D:// books.txt", std::ios::in);

    if (!f) {
        std::cout << "Error cannot open file";
    }
    else {
        std::cout << "Book Id: ";
        std::cin >> bookID;

        f >> bookId >> bookName;
        f >> authorName >> numOfBooks;


    }
}

int main() {
    
}