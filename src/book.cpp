#include "book.hpp"

#include <stdexcept>  // invalid_argument

// 1. реализуйте конструктор ...
Book::Book(const std::string &title,
           const std::string &content,
           Genre genre,
           Publisher publisher,
           const std::vector<Author> &authors) {

  // валидация аргументов
  if (title.empty()) {
    throw std::invalid_argument("Book::title cannot be empty");
  }

  if (content.empty()) {
    throw std::invalid_argument(
        "Book::content cannot be empty");
  }

  if (authors.empty()) {
    throw std::invalid_argument("Book::authors cannot be empty");
  }

  SetContent(content);
  SetTitle(title);
  SetGenre(genre);
  SetPublisher(publisher);
  authors_ = authors;
}

// 2. реализуйте метод ...
bool Book::AddAuthor(const Author &author) {
  for(Author i: authors_){
      if(i == author) return false;
  }
  authors_.push_back(author);
  // Tip 1: для поиска дубликатов можно использовать цикл for-each
  return true;
}

// РЕАЛИЗОВАНО

const std::string &Book::GetTitle() const {
  return title_;
}

const std::string &Book::GetContent() const {
  return content_;
}

Genre Book::GetGenre() const {
  return genre_;
}

Publisher Book::GetPublisher() const {
  return publisher_;
}

const std::vector<Author> &Book::GetAuthors() const {
  return authors_;
}

void Book::SetTitle(const std::string &title) {
  if (title.empty()) {
    throw std::invalid_argument("Book::title cannot be empty");
  }
  title_ = title;
}

void Book::SetContent(const std::string &content) {
  if (content.empty()) {
    throw std::invalid_argument("Book::content cannot be empty");
  }
  content_ = content;
}

void Book::SetGenre(Genre genre) {
  genre_ = genre;
}

void Book::SetPublisher(Publisher publisher) {
  publisher_ = publisher;
}
