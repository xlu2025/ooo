#include <iostream>
#include <string>
#include <vector>
#include "ReservationSystem.hpp"

struct Book {
    string title;
    string author;

    bool operator==(const Book& other) const {
        return title == other.title && author == other.author;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title: " << book.title << ", Author: " << book.author;
        return os;
    }
};

struct ConcertTicket {
    string artist;
    string venue;

    bool operator==(const ConcertTicket& other) const {
        return artist == other.artist && venue == other.venue;
    }

    friend ostream& operator<<(ostream& os, const ConcertTicket& ticket) {
        os << "Artist: " << ticket.artist << ", Venue: " << ticket.venue;
        return os;
    }
};

int main() {
    ReservationSystem<int> intSystem;
    intSystem.reserveItem(1, "John Doe", "123", "01-01-1990");
    intSystem.reserveItem(2, "Jane Smith", "124", "02-02-1991");
    cout << "Initial integer reservations:\n" << intSystem;

    ReservationSystem<string> stringSystem;
    stringSystem.reserveItem("A", "Alice", "125", "03-03-1992");
    stringSystem.reserveItem("B", "Bob", "126", "04-04-1993");
    cout << "Initial string reservations:\n" << stringSystem;

    Book book1 = { "The Great Gatsby", "F. Scott Fitzgerald" };
    Book book2 = { "1984", "George Orwell" };
    ReservationSystem<Book> bookSystem;
    bookSystem.reserveItem(book1, "Charlie", "127", "05-05-1994");
    bookSystem.reserveItem(book2, "Dave", "128", "06-06-1995");
    cout << "Initial book reservations:\n" << bookSystem;

    ConcertTicket ticket1 = { "The Beatles", "Wembley" };
    ConcertTicket ticket2 = { "The Rolling Stones", "O2 Arena" };
    ReservationSystem<ConcertTicket> concertSystem;
    concertSystem.reserveItem(ticket1, "Eve", "129", "07-07-1996");
    concertSystem.reserveItem(ticket2, "Frank", "130", "08-08-1997");
    cout << "Initial concert reservations:\n" << concertSystem;

    vector<ReservationSystem<int>::Reservation> intItems = {
        {3, "George", "131", "09-09-1998"},
        {4, "Hannah", "132", "10-10-1999"}
    };
    intSystem.addItems(intItems);
    cout << "Updated integer reservations:\n" << intSystem;

    vector<ReservationSystem<string>::Reservation> stringItems = {
        {"C", "Ivy", "133", "11-11-2000"},
        {"D", "Jack", "134", "12-12-2001"}
    };
    stringSystem.addItems(stringItems);
    cout << "Updated string reservations:\n" << stringSystem;

    cout << "Duration of book1 reservation: " << bookSystem.reservationDuration(book1) << " seconds\n";

    concertSystem.removeItem(ticket1);
    cout << "Concert reservations after removing ticket1:\n" << concertSystem;

    cout << "Total number of book reservations: " << bookSystem.reservationCount() << "\n";

    return 0;
}
