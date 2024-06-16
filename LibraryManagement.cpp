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

    std::cout << "=====Main Menu=====\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Display Book(s)\n";
    std::cout << "3. Find Book\n";
    std::cout << "4. Update Library\n";
    std::cout << "5. Delete Book\n";
    std::cout << "6. Exit\n\n";
}

// Add Book
void Library::AddBook() {
    system("cls");

    std::fstream f;

    int numOfBooks;

    std::string bookName;
    std::string bookId;
    std::string authorName;

    std::cout << "Add Books: \n";

    std::cout << "Book Id: ";
    std::cin >> bookId;

    std::cout << "Book Name: ";
    std::cin >> bookName;

    std::cout << "Author Name: ";
    std::cin >> authorName;

    std::cout << "Number of Books: ";
    std::cin >> numOfBooks;

    // open file append|output mode
    f.open("books.txt", std::ios::out | std::ios::app);
    f << " " << bookId << " " << bookName << " " << authorName << " " << numOfBooks << "\n";

    // close file
    f.close();
}

// show list of books
void Library::DisplayBook() {
    system("cls");

    std::fstream f;

    int numOfBooks;

    std::string bookName;
    std::string bookId;
    std::string authorName;

    std::cout << "List of All Books";

    f.open("books.txt", std::ios::in);

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

// find books
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

    f.open("books.txt", std::ios::in);

    // open in input mode
    if (!f) {
        std::cout << "Error cannot open file";
    }
    else {
        std::cout << "Book Id: ";
        std::cin >> bookID;

        f >> bookId >> bookName;
        f >> authorName >> numOfBooks;

        // till end of file
        while (!f.eof()) {
            if (bookID == bookId) {
                system("cls");

                std::cout << "Find Specific Book";
                std::cout << "Book Id: " << bookId;
                std::cout << "Book Name: " << bookName;
                std::cout << "Author Name: " << authorName;
                std::cout << "Number of Books: " << numOfBooks;

                count++;
                break;
            }

            f >> bookId >> bookName;
            f >> authorName >> numOfBooks;
        }

        system("pause");

        f.close();

        if (count == 0) {
            std::cout << "Error Book Not Found";
        }
    }
}

// update library
void Library::UpdateLibrary() {
    system("cls");

    std::fstream f;
    std::fstream fCopy;

    int numOfBooks;
    int numOfBooksCopy;
    int count = 0;

    std::string bookName;
    std::string bookNameCopy;
    std::string authorName;
    std::string authorNameCopy;
    std::string bookId;
    std::string bookIdCopy;

    std::cout << "Update Library record";

    fCopy.open("bookcopy.txt", std::ios::app | std::ios::out);
    f.open("book.txt", std::ios::in);

    if (!f) {
        std::cout << "Error Cannot Open file";
    }
    else {

    }
}

void Library::DeleteBook() {

}

void LibraryRecord() {
    int choice;

    char x;

    Library l;

    while (1) {
        l.MainMenu();

        std::cout << "Enter Your Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            do {
                l.AddBook();
                std::cout << "Want to add another book? (y/n): ";
                std::cin >> x;
            } while (x == 'y');

            break;

        case 2:
            l.DisplayBook();
            break;

        case 3:
            l.FindBook();
            break;
        }
    }
}

int main() {
    LibraryRecord();

    return 0;
}