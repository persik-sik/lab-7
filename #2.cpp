#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Book
{
    string Author;
    string Title;
    int Year;
};

void saveToFile(const string& filename, const vector<Book>& data) {
    ofstream file(filename);
    for (const auto& book : data)file << book.Author << endl << book.Title << endl << book.Year << endl;
    file.close();
}

void loadFromFile(const string& filename, vector<Book>& outData)
{
    ifstream file(filename);
    Book book;
    while (getline(file, book.Author) && getline(file, book.Title) && file >> book.Year)
    {
        file.ignore(); 
        outData.push_back(book);
    }
    file.close();
}

int main()
{
    vector<Book> books = {
        {"rom", "book1", 2001},
        {"rompom", "booh2", 2002},
        {"rompompom", "book3", 2052}
    };
    saveToFile("books.txt", books);
    vector<Book> loadBooks;
    loadFromFile("books.txt", loadBooks);
    for (const auto& b : loadBooks) cout << "Author: " << b.Author << endl << "Title: " << b.Title << endl << "Year: " << b.Year << endl;
    return 0;
}
