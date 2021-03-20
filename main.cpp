#include <iostream>
#include <vector>

#include "author.hpp"
#include "book.hpp"
#include "book_store.hpp"

using namespace std;


// 1. константность const и constexpr
// 2. строки в стиле Си и класс std::string
// 3. перечисления и структуры
// 4. указатели и ссылки


int main(int argc, char **argv) {
    Publisher publisher = Publisher::RUS;
    Author autor("Толстой", 67, Sex::MALE);
    Book book("Gfdhbvn", "svc", Genre::ACTION_AND_ADVENTURE, publisher, {autor});
    Book book2("Gfdhbvn", "svc", Genre::ACTION_AND_ADVENTURE, publisher, {autor});

    auto storage = new Book[1];
    const vector<Book> books;
    copy(books.data(), books.data() + 1, storage);
    cout << (books[0] == storage[0]) << endl;
  return 0;
}