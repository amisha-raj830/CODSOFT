#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Movie {
private:
    string title;
    double price;
    int seatsAvailable;

public:
    Movie(const string& _title, double _price, int _seatsAvailable)
        : title(_title), price(_price), seatsAvailable(_seatsAvailable) {}

    const string& getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }

    int getSeatsAvailable() const {
        return seatsAvailable;
    }

    void bookSeats(int numSeats) {
        if (numSeats <= seatsAvailable) {
            seatsAvailable -= numSeats;
            cout << numSeats << " seat(s) booked successfully.\n";
        } else {
            cout << "Insufficient seats available.\n";
        }
    }
};

class BookingSystem {
private:
    vector<Movie> movies;

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void showMovieList() const {
        cout << "Movie Listings:\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". " << movies[i].getTitle()
                      << " | Price: Rs. " << movies[i].getPrice()
                      << " | Seats Available: " << movies[i].getSeatsAvailable()
                      << "\n";
        }
    }

    void bookTickets(size_t movieIndex, int numSeats) {
        if (movieIndex >= 0 && movieIndex < movies.size()) {
            movies[movieIndex].bookSeats(numSeats);
        } else {
            cout << "Invalid movie selection.\n";
        }
    }
};

int main() {
    BookingSystem bookingSystem;
    bookingSystem.addMovie(Movie("Avengers: Endgame", 250, 100));
    bookingSystem.addMovie(Movie("The Lion King", 210, 75));

    int choice;
    do {
        cout << "1. Show Movie Listings\n";
        cout << "2. Book Tickets\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.showMovieList();
                break;
            case 2: {
                size_t movieIndex;
                int numSeats;
                cout << "Enter movie index: ";
                cin >> movieIndex;
                cout << "Enter number of seats to book: ";
                cin >> numSeats;
                bookingSystem.bookTickets(movieIndex - 1, numSeats);  // Adjust index for 0-based vector
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 3);
    return 0;
}